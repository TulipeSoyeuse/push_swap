# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdupeux <rdupeux@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/25 11:10:00 by rdupeux           #+#    #+#              #
#    Updated: 2023/11/27 17:14:17 by rdupeux          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS= $(wildcard *.c)
OBJS= $(SRCS:.c=.o)

# Compiler, Linker Defines
CC		= cc
CFLAGS 	= -Wall -Wextra -Werror
NAME	= push_swap
LIBFT 	= libft/libft.a
DEBUG	= push_swap_debug
# Link all Object Files with external Libraries into Binaries
all: $(NAME)

re: fclean all

$(LIBFT) :
	make -C libft/

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $(NAME)

debug: $(SRCS) $(LIBFT)
	$(CC) -g3 $(CFLAGS) $^ -o $(DEBUG)
# Clean Up Objects, Exectuables, Dumps out of source directory
clean:
	rm -f $(OBJS)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME) a.out core $(name) $(DEBUG)

.PHONY: all clean fclean re
