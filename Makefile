# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akliek <akliek@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/18 14:52:56 by akliek            #+#    #+#              #
#    Updated: 2021/08/19 12:24:26 by akliek           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC = pipex.c	\
	path.c	\
	clear.c	\
	ft_split.c	\
	ft_strjoin.c	\
	ft_strdup.c	\
	ft_strlen.c	\
	ft_strncmp.c

OBJ :=  $(SRC:.c=.o)

all: $(NAME)

$(NAME):
		$(CC) -c $(CFLAGS) $(SRC)
		$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re:	
		make fclean
		make all
