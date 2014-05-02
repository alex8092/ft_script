# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amerle <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/05/02 05:00:20 by amerle            #+#    #+#              #
#    Updated: 2014/05/02 05:10:11 by amerle           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -Iinclude -g3

LDFLAGS =

SRCS =	ft_bzero.c \
		ft_puterror.c \
		ft_strlen.c \
		main.c \
		ft_ptsname.c \
		pty_open.c \
		pty_fork.c \
		pty_script.c \
		pty_script2.c \
		ft_grantpt.c \
		ft_unlockpt.c \
		ft_init.c \
		pty_signals.c \
		ft_strncmp.c \
		ft_getenv.c \
		ft_putstr.c \
		pty_exit.c \
		ft_gettime.c \
		ft_getshell.c \
		ft_arg.c

OBJS = $(addprefix obj/,$(SRCS:.c=.o))

NAME = ft_script

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $@ $^

obj/%.o: src/%.c
	mkdir -p $(dir $@)
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf obj

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
