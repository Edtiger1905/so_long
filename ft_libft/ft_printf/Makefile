# Nome della libreria
NAME		= libft.a

# Compilatore e flag
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs
RM			= rm -f

# Directory
OBJ_DIR		= obj

# ============================================================================ #
# AGGIUNGI QUI LE TUE FUNZIONI                                                #
# ============================================================================ #

SRCS		= src/ft_atol.c \
			  src/ft_strlen.c \
			  src/ft_strchr.c \
			  src/ft_substr.c \
			  src/ft_split.c \
			  src/ft_bzero.c \
			  src/ft_calloc.c

# File oggetto
OBJS		= $(SRCS:%.c=$(OBJ_DIR)/%.o)

# Colori
GREEN		= \033[0;32m
RED			= \033[0;31m
RESET		= \033[0m

# Regola principale
all: $(NAME)

# Creazione della libreria
$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(GREEN)✓ $(NAME) creata con successo!$(RESET)"

# Compilazione file oggetto
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)✓$(RESET) Compilato: $<"

# Pulizia file oggetto
clean:
	@$(RM) -r $(OBJ_DIR)
	@echo "$(RED)✗ File oggetto rimossi$(RESET)"

# Pulizia completa
fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)✗ $(NAME) rimossa$(RESET)"

# Ricompilazione completa
re: fclean all

# Regole phony
.PHONY: all clean fclean re