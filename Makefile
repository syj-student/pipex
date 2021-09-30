# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yusong <42.4.yusong@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/19 09:38:24 by yusong            #+#    #+#              #
#    Updated: 2021/08/19 09:38:24 by yusong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex
CC		= gcc
CFLAGS	= -Wextra -Wall -Werror

SRCS	= main.c
OBJS	= $(SRCS:.c=.o)

all		: $(NAME)

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o		: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
