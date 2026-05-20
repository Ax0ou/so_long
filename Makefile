NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

OBJ_DIR = obj

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = src/main.c \
	   src/parsing.c \
	   src/check_map.c \
	   src/check_content.c \
	   src/flood_fill.c \
	   src/init_mlx.c \
	   src/game.c \
	   src/error.c \
	   src/utils.c

OBJS = $(SRCS:src/%.c=$(OBJ_DIR)/%.o)

OS = $(shell uname -s)

ifeq ($(OS), Darwin)
	MLX_DIR = mlx_macos
	MLX = $(MLX_DIR)/libmlx.a
	MLX_FLAGS = -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
else
	MLX_DIR = mlx_linux
	MLX = $(MLX_DIR)/libmlx.a
	MLX_FLAGS = -L $(MLX_DIR) -lmlx -lXext -lX11 -lm
endif

INCLUDES = -I include -I $(LIBFT_DIR) -I $(MLX_DIR)

all: $(LIBFT) $(MLX) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(MLX)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
