/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 17:25:19 by rarias-p          #+#    #+#             */
/*   Updated: 2021/06/18 19:55:41 by rarias-p         ###   ########.fr       */
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
	pid_t	pid;
	int		i;
	int		fd;
	char	**paths;
	char	**splitted;

	if (argc == 3)
	{
		splitted = ft_split(argv[2], ' ');
		paths = get_paths(env, splitted);
		fd = open(argv[1], O_RDONLY);
		dup2(fd, 0);
		i = -1;
		pid = fork();
		if (pid == 0)
			while (paths[++i])
				execve(paths[i], splitted, env);
	}
	system("leaks a.out");
}
