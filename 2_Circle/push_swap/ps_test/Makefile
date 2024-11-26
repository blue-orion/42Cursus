CC = cc
FLAG = -g

NAME = rand.exe

SRCS = random_num.c
OBJS = $(SRCS:%.c=%.o)
LIBFT = ../libft

PUSH_SWAP = ../push_swap
NUM = 20

all : $(NAME)

$(NAME) : $(OBJS) | $(PUSH_SWAP)
	$(CC) $(FLAG) $^ -I$(LIBFT) -L$(LIBFT) -lft -o $@
	./$(NAME) $(NUM)
	cat rand.txt | xargs ./../push_swap

$(PUSH_SWAP) :
	make -C ../

%.o : %.c
	$(CC) $(FLAG) -I$(LIBFT) -c $^ -o $@

src :
	./$(NAME) $(NUM)

test :
	cat rand.txt | xargs ./../push_swap

val :
	cat rand.txt | xargs valgrind --leak-check=full ./../push_swap

text :
	cat rand.txt | xargs ./../push_swap > result.txt

clean :
	rm -rf $(OBJS)

fclean :
	make -C ../ fclean
	rm -rf $(NAME)

re : clean fclean all

.PHONY : all clean fclean re test src
