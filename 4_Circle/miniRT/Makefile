NAME = miniRT

CC = cc
FLAGS = -g

SRCS = main.c

OBJ_DIR = objs/
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

MLX_DIR = minilibx-linux/
MLX = mlx

all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(FLAGS) $^ -L$(MLX_DIR) -l$(MLX) -lXext -lX11 -lm -lz -o $@

$(OBJ_DIR)%.o : %.c | $(OBJ_DIR)
	$(CC) $(FLAGS) -c $^ -o $@

$(OBJ_DIR) :
	mkdir $@

clean :
	$(MAKE) -C $(MLX_DIR) clean
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all
