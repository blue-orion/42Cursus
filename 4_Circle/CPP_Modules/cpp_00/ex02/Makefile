# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/17 23:11:50 by takwak            #+#    #+#              #
#    Updated: 2025/04/17 23:25:57 by takwak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = log

CC = c++
FLAGS = -std=c++98 -Wall -Werror -Wextra

SRC = Account.cpp	\
	  tests.cpp

OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $^ -o $@

%.o : %.cpp
	$(CC) $(FLAGS) -c $^ -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
