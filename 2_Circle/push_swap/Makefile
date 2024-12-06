# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/20 23:38:16 by takwak            #+#    #+#              #
#    Updated: 2024/12/06 23:31:58 by takwak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Wextra -Werror -g

NAME = push_swap

SRCS = util_stack1.c	\
	   util_stack2.c	\
	   util_stack3.c	\
	   utils.c			\
	   utils_greedy.c	\
	   utils_push.c		\
	   merge_sort.c		\
	   indexing.c		\
	   input_data.c		\
	   reverse_stack.c	\
	   find.c			\
	   divide.c			\
	   push_greedy.c	\
	   counting_cost.c	\
	   validate_data.c	\
	   debugging.c	\
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
