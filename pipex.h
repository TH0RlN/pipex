/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 17:58:29 by rarias-p          #+#    #+#             */
/*   Updated: 2021/06/18 19:32:38 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

/*                                 LIBFT                                      */

char	**ft_split	(char const *s, char c);
char	*ft_strchr	(const char *s, int c);
int		ft_strcmp	(const char *s1, const char *s2);
char	*ft_strdup	(const char *s);
char	*ft_strjoin	(char const *s1, char const *s2);
size_t	ft_strlen	(const char *str);
char	*ft_substr	(char const *s, unsigned int start, int len);
#endif
