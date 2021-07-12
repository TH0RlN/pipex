/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 17:25:19 by rarias-p          #+#    #+#             */
/*   Updated: 2021/07/12 17:52:09 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_command(t_pipex *pipex, int i, char const **argv,
		char *const *env)
{
	pipex->splitted = ft_split(argv[2], ' ');
	pipex->paths = get_paths(env, pipex->splitted);
	pipex->fd1 = open(argv[1], O_RDONLY);
	dup2(pipex->fd1, 0);
	close(pipex->pipe_fd[0]);
	dup2(pipex->pipe_fd[1], 1);
	close(pipex->pipe_fd[1]);
	while (pipex->paths[++i])
		execve(pipex->paths[i], pipex->splitted, env);
}

void	second_command(t_pipex *pipex, int i, char const **argv,
		char *const *env)
{
	pipex->splitted = ft_split(argv[3], ' ');
	pipex->paths = get_paths(env, pipex->splitted);
	pipex->fd2 = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC);
	dup2(pipex->pipe_fd[0], 0);
	close(pipex->pipe_fd[0]);
	dup2(pipex->fd2, 1);
	while (pipex->paths[++i])
		execve(pipex->paths[i], pipex->splitted, env);
}

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
	char	*aux;
	char	**split;
	char	**paths;

	i = -1;
	while (env[++i])
	{
		if (ft_strchr(env[i], '='))
		{
			aux = ft_substr(env[i], 0, 5);
			if (!ft_strcmp("PATH=", aux))
			{
				split = ft_split(env[i], '=');
				paths = ft_split(split[1], ':');
				ft_free_arr(split); //TO DO: Function to kill does fckn leaks
			}
			free(aux);
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
		i = -1;
		pipe(pipex->pipe_fd);
		pipex->pid = fork();
		if (pipex->pid == 0)
		{
			first_command(pipex, i, argv, env);
			ft_free_arr(pipex->paths);
		}
		else
		{
			close(pipex->pipe_fd[1]);
			//free(pipex->splitted);
			pipex->pid = fork();
			if (pipex->pid == 0)
			{
				waitpid(pipex->pid, &pipex->status, 0);
				second_command(pipex, i, argv, env);
				ft_free_arr(pipex->paths);
			}
			else
			{
				close(pipex->pipe_fd[0]);
				free(pipex);
			}
		}
	}
	//system("leaks debug.out");
}
