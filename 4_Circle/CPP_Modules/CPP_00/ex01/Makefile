# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: takwak <takwak@student.42gyoengsan.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/12 18:08:17 by takwak            #+#    #+#              #
#    Updated: 2025/04/16 21:03:41 by takwak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook 

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp	\
	   Phonebook.cpp	\
	   Contact.cpp
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $^ -o $@

%.o : %.cpp
	$(CC) $(FLAGS) -c $^ -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
