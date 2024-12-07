# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/20 23:38:16 by takwak            #+#    #+#              #
#    Updated: 2024/12/07 22:13:29 by takwak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
MAKEFLAGS += --no-print-directory

CC = cc
FLAGS = -Wall -Wextra -Werror -g

SRC_MAIN = main.c

SRCS = util_stack1.c	\
	   util_stack2.c	\
	   util_stack3.c	\
	   utils.c			\
	   utils2.c			\
	   utils_greedy.c	\
	   utils_push.c		\
	   merge_sort.c		\
	   indexing.c		\
	   input_data.c		\
	   find.c			\
	   divide.c			\
	   greedy.c			\
	   counting_cost.c	\
	   validate_data.c	\
	   debugging.c

SRCS_BONUS = checker_bonus.c		\
			 check_instruct_bonus.c

#Libft path
LIBFT = libft

OBJS_DIR = objs/
OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))
OBJS_BONUS = $(addprefix $(OBJS_DIR), $(SRCS_BONUS:.c=.o))

ifdef WITH_BONUS
	OBJ = $(OBJS) $(OBJS_BONUS)
	NAME = checker
else
	OBJ = $(OBJS) objs/main.o
	NAME = push_swap
endif

all : $(NAME)

$(NAME) : $(OBJ)
	make -C $(LIBFT)
	$(CC) $(FLAGS) $^ -I$(LIBFT) -L$(LIBFT) -lft -o $@

objs/%.o : %.c | $(OBJS_DIR)
	$(CC) $(FLAGS) -I$(LIBFT) -c $< -o $@

$(OBJS_DIR) :
	mkdir -p objs

clean :
	make -C $(LIBFT) clean
	rm -rf $(OBJS_DIR)

fclean : clean
	make -C $(LIBFT) fclean
	rm -rf push_swap
	rm -rf checker

re : fclean all

bonus :
	@make WITH_BONUS=1 all

.PHONY : NAME all clean fclean re bonus
