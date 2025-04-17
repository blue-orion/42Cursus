# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: takwak <takwak@student.42gyoengsan.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/12 18:08:17 by takwak            #+#    #+#              #
#    Updated: 2025/04/12 18:13:10 by takwak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = megaphone.cpp
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $^ -o $@

%.o : %.c
	$(CC) $(FLAGS) -c $^ -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
