CC      = cc
CFLAGS  = -Wall -Wextra -Werror
NAME    = so_long
SRCS    = main.c \
	  init_map.c
OBJS    = $(SRCS:.c=.o)

MLX_DIR = ./minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAG = -I$(MLX_DIR) -L$(MLX_DIR) -lmlx -lm -lXext -lX11

PRINTF_DIR = ./ft_libft/ft_printf
PRINTF_LIB = $(PRINTF_DIR)/libft.a
PRINTF_FLAG = -I$(PRINTF_DIR) -L$(PRINTF_DIR) -lft

all: $(MLX_LIB) $(PRINTF_LIB) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX_FLAG) $(PRINTF_FLAG)

$(PRINTF_LIB):
	$(MAKE) -C $(PRINTF_DIR)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(PRINTF_DIR) fclean
	$(MAKE) -C $(MLX_DIR) clean

re: fclean all

.PHONY: all clean fclean re
