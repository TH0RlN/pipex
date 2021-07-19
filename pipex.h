/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 17:58:29 by rarias-p          #+#    #+#             */
/*   Updated: 2021/07/19 16:57:33 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_pipex
{
	pid_t	pid;
	int		fd1;
	int		fd2;
	int		fd3;
	int		pipe_fd[2];
	int		status;
	char	**paths1;
	char	**paths2;
	char	**splitted1;
	char	**splitted2;
}				t_pipex;

void 	check_leaks(void); ///////////////////////////////////////////////////////////////////////////

char	**get_paths		(char *const *env, char **splitted);
void	get_splits		(t_pipex *pipex, char const **argv, char *const *env);
char	**join_paths	(char **paths, char **splitted);
void	first_command	(t_pipex *pipex, int i, char const **argv,
			char *const *env);
void	second_command	(t_pipex *pipex, int i, char const **argv,
			char *const *env);
void	ft_free_arr		(char **arr);

/*                                 LIBFT                                      */

char	**ft_split		(char const *s, char c);
char	*ft_strchr		(const char *s, int c);
int		ft_strcmp		(const char *s1, const char *s2);
char	*ft_strdup		(const char *s);
char	*ft_strjoin		(char const *s1, char const *s2);
size_t	ft_strlen		(const char *str);
char	*ft_substr		(char const *s, unsigned int start, int len);
#endif
