/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 19:30:45 by rarias-p          #+#    #+#             */
/*   Updated: 2021/09/27 16:39:22 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	if (!s1)
		return ((char *)s2);
	s = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!(s))
		return (NULL);
	i = -1;
	while (s1[++i])
		s[i] = s1[i];
	j = -1;
	while (s2[++j])
		s[i + j] = s2[j];
	s[i + j] = '\0';
	return (s);
}

void	get_splits(t_pipex *pipex, char const **argv, char *const *env)
{
	pipex->splitted1 = ft_split(argv[2], ' ');
	pipex->paths1 = get_paths(env, pipex->splitted1);
	pipex->splitted2 = ft_split(argv[3], ' ');
	pipex->paths2 = get_paths(env, pipex->splitted2);
}

void	ft_free_arr(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

void	freer(t_pipex *pipex)
{
	ft_free_arr(pipex->paths1);
	ft_free_arr(pipex->paths2);
	ft_free_arr(pipex->splitted1);
	ft_free_arr(pipex->splitted2);
	free(pipex);
}
