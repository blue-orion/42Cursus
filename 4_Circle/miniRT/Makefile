NAME = miniRT

CC = cc
FLAGS = -g

SRC_DIR = srcs/
SRCS = main.c	\
	   hook.c	\
	   canvas.c	\
	   object_create.c	\
	   object_utils.c	\
	   print.c	\
	   ray.c	\
	   scene.c	\
	   vec3_utils.c	\
	   normal.c	\
	   hit.c	\
	   phong_lighting.c

OBJ_DIR = objs/
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

MLX_DIR = minilibx-linux/
MLX = mlx

LIBFT_DIR = libft/
LIBFT = ft

all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C $(MLX_DIR)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(FLAGS) $^ -L$(MLX_DIR) -l$(MLX) -L$(LIBFT_DIR) -l$(LIBFT) -lXext -lX11 -lm -lz -o $@

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(FLAGS) -c $^ -o $@

$(OBJ_DIR) :
	mkdir $@

clean :
	$(MAKE) -C $(MLX_DIR) clean
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all
