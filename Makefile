CC      = cc
CFLAGS  = -Wall -Wextra -Werror
NAME    = so_long

# File sorgente
SRCS    = main.c \
          init_map.c

OBJS    = $(SRCS:.c=.o)

# Directory delle librerie
MLX_DIR     = ./minilibx-linux
LIBFT_DIR   = ./ft_libft/ft_printf
GNL_DIR     = ./get_next_line

# File delle librerie
MLX_LIB     = $(MLX_DIR)/libmlx.a
LIBFT_LIB   = $(LIBFT_DIR)/libft.a
GNL_LIB     = $(GNL_DIR)/gnl.a

# Flag di linking
MLX_FLAG    = -I$(MLX_DIR) -L$(MLX_DIR) -lmlx -lm -lXext -lX11
LIBFT_FLAG  = -I$(LIBFT_DIR)/includes -L$(LIBFT_DIR) -lft
GNL_FLAG    = -I$(GNL_DIR) -L$(GNL_DIR) -lgnl

# Flag per la compilazione (include directories)
INCLUDES    = -I$(LIBFT_DIR)/includes -I$(GNL_DIR) -I$(MLX_DIR)

all: $(MLX_LIB) $(LIBFT_LIB) $(GNL_LIB) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX_FLAG) $(LIBFT_FLAG) $(GNL_FLAG)

# Compila le librerie
$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

$(GNL_LIB):
	$(MAKE) -C $(GNL_DIR)

# Compila i file oggetto con gli include necessari
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(GNL_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(GNL_DIR) fclean

re: fclean all

.PHONY: all clean fclean re