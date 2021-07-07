/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 17:25:19 by rarias-p          #+#    #+#             */
/*   Updated: 2021/07/07 13:35:02 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**join_paths(char **paths, char **splitted)
{
	int		i;
	char	*aux;

	i = -1;
	while (paths[++i])
	{
		aux = ft_strdup(paths[i]);
		free(paths[i]);
		paths[i] = ft_strjoin(aux, "/");
		free(aux);
		aux = ft_strdup(paths[i]);
		free(paths[i]);
		paths[i] = ft_strjoin(aux, splitted[0]);
		free(aux);
	}
	return (paths);
}

char	**get_paths(char *const *env, char **splitted)
{
	int		i;
	char	**split;
	char	**paths;

	i = -1;
	while (env[++i])
	{
		if (ft_strchr(env[i], '='))
		{
			if (!ft_strcmp("PATH", ft_substr(env[i], 0, 4)))
			{
				split = ft_split(env[i], '=');
				paths = ft_split(split[1], ':');
				//ft_free_arr(split); TO DO: Function to kill does fckn leaks
			}
		}
	}
	return (join_paths(paths, splitted));
}

int	main(int argc, char const **argv, char *const *env)
{
	t_pipex	*pipex;
	int		i;

	pipex = malloc(sizeof(t_pipex));
	if (argc == 5)
	{
		pipex->splitted = ft_split(argv[2], ' ');
		pipex->paths = get_paths(env, pipex->splitted);
		pipex->fd1 = open(argv[1], O_RDONLY);
		dup2(pipex->fd1, 0);
		i = -1;
		pipe(pipex->pipe_fd);
		pipex->pid = fork();
		dup2(pipex->pipe_fd[1], 1);
		dup2(pipex->pipe_fd[0], 0);
		if (pipex->pid == 0)
		{
			while (pipex->paths[++i])
				execve(pipex->paths[i], pipex->splitted, env);
		}
		else
		{
			free(pipex->splitted);
			free(pipex->paths);
			pipex->splitted = ft_split(argv[3], ' ');
			pipex->paths = get_paths(env, pipex->splitted);
			pipex->fd2 = open(argv[4], O_CREAT | O_WRONLY);
			dup2(pipex->fd2, 1);
			pipex->pid = fork();
			if (pipex->pid == 0)
			{
				while (pipex->paths[++i])
					execve(pipex->paths[i], pipex->splitted, env);
			}
			close(pipex->pipe_fd[0]);
			close(pipex->pipe_fd[1]);
			close(pipex->fd1);
			close(pipex->fd2);
		}		
	}
}
