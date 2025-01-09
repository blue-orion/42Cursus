NAME = temp

CC = clang
CFLAGS = -g

INCLUDES = includes
SRC_DIR = srcs/
OBJ_DIR = objs/

SRCS = $(wildcard *.c $(SRC_DIR)*.c) 
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)%.o : %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $^ -I$(INCLUDES) -o $@ -MJ $@.part.json


$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $^ -I$(INCLUDES) -o $@ -MJ $@.part.json

$(OBJ_DIR) :
	mkdir -p $@

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -rf $(NAME)

re : fclean all

comile_commands.json :
	-$(MAKE) --always-make --keep-going all
	(echo '[' && cat $(OBJ_DIR)*.part.json && echo ']') > $@

.PHONY: NAME all clean fclean re compie_commands.json
