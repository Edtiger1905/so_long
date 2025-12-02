CC      = gcc
CFLAGS  = -Wall -Wextra -Werror
NAME    = so_long

# File sorgente
SRCS    = main.c \
          init_map.c

OBJS    = $(SRCS:.c=.o)

# Directory delle librerie
MLX_DIR     = ./minilibx-linux
LIBFT_DIR   = ./ft_libft
GNL_DIR     = ./get_next_line
PRINTF_DIR	= ./ft_printf

# File delle librerie
MLX_LIB     = $(MLX_DIR)/libmlx.a
LIBFT_LIB   = $(LIBFT_DIR)/libft.a
GNL_LIB     = $(GNL_DIR)/gnl.a
PRINTF_LIB	= $(PRINTF_DIR)/libftprintf.a

# Flag per la compilazione (include directories)
INCLUDES    = -I$(LIBFT_DIR) -I$(GNL_DIR) -I$(MLX_DIR) -I$(PRINTF_DIR)

# Librerie da linkare (ordine importante!)
LIBS        = $(GNL_LIB) $(PRINTF_LIB) $(LIBFT_LIB) $(MLX_LIB)

# Flag di linking (dopo le librerie)
LDFLAGS     = -L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm

.PHONY: all clean fclean re

all: $(MLX_LIB) $(LIBFT_LIB) $(GNL_LIB) $(PRINTF_LIB) $(NAME)

$(NAME): $(OBJS) $(LIBS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME) $(LDFLAGS)

# Compila le librerie
$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

$(GNL_LIB):
	$(MAKE) -C $(GNL_DIR)

$(PRINTF_LIB):
	$(MAKE) -C $(PRINTF_DIR)

# Compila i file oggetto con gli include necessari
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