# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/02 17:09:55 by lorphan           #+#    #+#              #
#    Updated: 2021/09/02 19:30:37 by lorphan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADER			= minitalk.h

LIBFT_DIR		= ./libft
LIBFT			= libft.a

SERVER			= server
SERVER_SRCS		= server.c
SERVER_OBJS		= server.o

CLIENT			= client
CLIENT_SRCS		= client.c
CLIENT_OBJS		= client.o

$(NAME):	

all:

clean:

fclean:

re:			fclean all

