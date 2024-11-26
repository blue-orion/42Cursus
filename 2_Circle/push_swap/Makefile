# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/20 23:38:16 by takwak            #+#    #+#              #
#    Updated: 2024/11/26 01:10:51 by takwak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Wextra -Werror -g

NAME = push_swap

SRCS = util_stack1.c	\
	   util_stack2.c	\
	   util_stack3.c	\
	   noprint_cmd.c	\
	   utils.c			\
	   merge_sort.c		\
	   indexing.c		\
	   radix_sort.c		\
	   reverse_stack.c	\
	   greedy.c			\
	   interval.c		\
	   find.c			\
	   divide.c			\
	   main.c

#Libft path
LIBFT = libft

OBJS_DIRECTORY = objs/
OBJS = $(addprefix $(OBJS_DIRECTORY), $(SRCS:.c=.o))

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIBFT)
	$(CC) $(FLAGS) $^ -I$(LIBFT) -L$(LIBFT) -lft -o $@

objs/%.o : %.c | $(OBJS_DIRECTORY)
	$(CC) $(FLAGS) -I$(LIBFT) -c $< -o $@

$(OBJS_DIRECTORY) :
	mkdir -p objs

clean :
	make -C $(LIBFT) clean
	rm -rf $(OBJS)

fclean : clean
	make -C $(LIBFT) fclean
	rm -rf $(NAME)

re : fclean all

.PHONY : NAME all clean fclean re
