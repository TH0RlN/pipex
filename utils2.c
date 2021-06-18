/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 19:30:45 by rarias-p          #+#    #+#             */
/*   Updated: 2021/06/18 19:32:02 by rarias-p         ###   ########.fr       */
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
