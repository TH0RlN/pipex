/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 17:25:19 by rarias-p          #+#    #+#             */
/*   Updated: 2021/06/17 19:18:34 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char const **argv, char const **env)
{
	int		fd;
	char	**splitted;

	if (argc == 3)
	{
		fd = open(argv[1]);
		dup2(fd, 0);
		splitted = ft_split(argv[2], ' ');
		execve("/usr/bin/grep", &splitted[1], env);
	}
}
