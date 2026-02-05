CC      = gcc
CFLAGS  = -Wall -Wextra -Werror
NAME    = so_long

SRCS = src/main.c \
       src/init_map.c \
       src/init.c \
       src/checks.c \
       src/checks_elements.c \
       src/flood_fill.c \
       src/render.c \
       src/player_movement.c \
       src/hooks.c \
       src/load_images.c \
       src/exit_game.c

OBJS    = $(SRCS:.c=.o)

MLX_DIR     = ./minilibx-linux
LIBFT_DIR   = ./ft_libft
GNL_DIR     = ./get_next_line
PRINTF_DIR	= ./ft_printf

MLX_LIB     = $(MLX_DIR)/libmlx.a
LIBFT_LIB   = $(LIBFT_DIR)/libft.a
GNL_LIB     = $(GNL_DIR)/gnl.a
PRINTF_LIB	= $(PRINTF_DIR)/libftprintf.a

INCLUDES    = -I$(LIBFT_DIR) -I$(GNL_DIR) -I$(MLX_DIR) -I$(PRINTF_DIR)

LIBS        = $(GNL_LIB) $(PRINTF_LIB) $(LIBFT_LIB) $(MLX_LIB)

LDFLAGS     = -L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm

.PHONY: all clean fclean re

all: $(MLX_LIB) $(LIBFT_LIB) $(GNL_LIB) $(PRINTF_LIB) $(NAME)

$(NAME): $(OBJS) $(LIBS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME) $(LDFLAGS)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

$(GNL_LIB):
	$(MAKE) -C $(GNL_DIR)

$(PRINTF_LIB):
	$(MAKE) -C $(PRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(GNL_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(GNL_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all