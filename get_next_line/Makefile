# Nome della libreria
NAME = gnl.a

# Compilatore e flag
CC = cc
CFLAGS = -Wall -Wextra -Werror -fPIC
AR = ar rcs
RM = rm -f

# File sorgente
SRCS = get_next_line.c \
       get_next_line_utils.c

# File oggetto
OBJS = $(SRCS:.c=.o)

# Regole phony (SPOSTATE IN ALTO)
.PHONY: all clean fclean re

# Regola principale
all: $(NAME)

# Creazione della libreria
$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

# Compilazione file oggetto
%.o: %.c get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

# Pulizia file oggetto
clean:
	$(RM) $(OBJS)

# Pulizia completa
fclean: clean
	$(RM) $(NAME)

# Ricompilazione completa
re: fclean all