# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpacheco <vpacheco@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/02 15:50:05 by vpacheco          #+#    #+#              #
#    Updated: 2022/06/06 12:52:52 by vpacheco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= server.c client.c ft_atoi.c

OBJS		= $(SRCS:.c=.o)

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
RM 			= rm -f
AR			= ar rcs

all: server client

server: server.o
	$(CC) $(CFLAGS)  server.o ft_atoi.c -o server
	
client: client.o
	$(CC) $(CFLAGS) client.o ft_atoi.c -o client

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) server client

re:			fclean all

.PHONY:		all clean fclean re