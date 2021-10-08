# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/08 16:25:49 by rarias-p          #+#    #+#              #
#    Updated: 2021/10/08 16:43:26 by rarias-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=pipex

CC=gcc

FLAGS=-Wall -Wextra -Werror

RM=rm -f

SRC= main.c split.c utils.c utils2.c

OBJ= $(SRC:.c=.o)

$(NAME):
	@$(CC) $(FLAGS) $(SRC) -o $(NAME)