# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdupeux <rdupeux@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/25 11:10:00 by rdupeux           #+#    #+#              #
#    Updated: 2023/12/03 17:56:05 by rdupeux          ###   ########.fr        #
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
	$(CC) -g3 -gdwarf-4 $(CFLAGS) $^ -o $(DEBUG)
# Clean Up Objects, Exectuables, Dumps out of source directory
clean:
	rm -f $(OBJS)

fclean: clean
	make -C libft/ clean
	rm -f $(NAME) a.out core $(name) $(DEBUG)

.PHONY: all clean fclean re
