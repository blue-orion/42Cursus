# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/18 13:49:47 by takwak            #+#    #+#              #
#    Updated: 2025/05/06 19:23:53 by takwak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zombie

CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp	\
	   Zombie.cpp	\
		 zombieHorde.cpp	

OBJ_DIR = objs/
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.cpp=.o))

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)%.o : %.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $^ -o $@

$(OBJ_DIR) :
	mkdir -p $@

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
