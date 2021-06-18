/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 18:29:26 by rarias-p          #+#    #+#             */
/*   Updated: 2021/06/18 19:01:26 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - s2[i]);
		i++;
	}
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, int len)
{
	char	*dest;
	int		i;

	if (!s)
		return (0);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	dest = (char *)malloc(((int)len + 1) * sizeof(char));
	if (dest == '\0')
		return (dest);
	i = start;
	while (s[i] && len > 0)
	{
		dest[i - start] = s[i];
		i++;
		len--;
	}
	dest[i - start] = '\0';
	return (dest);
}

char	*ft_strdup(const char *s)
{
	char	*ret;
	int		i;
	int		len;

	len = ft_strlen(s);
	ret = malloc(len * sizeof(char) + 1);
	if (!ret)
		return (0);
	i = 0;
	while (i < len)
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
