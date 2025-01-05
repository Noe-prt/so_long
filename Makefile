CC = gcc
CFLAGS = -I/usr/include -Imlx_linux -Ift_printf -Iinclude -O3 -Wall -Wextra -Werror -g
LDFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -Lft_printf -lftprintf
NAME = so_long
SRC = src/main.c src/init.c src/game.c src/player.c src/check_map.c src/utils.c src/parsing.c \
      get_next_line/get_next_line_utils.c get_next_line/get_next_line.c
OBJ = $(SRC:.c=.o)

# Cible par défaut
all: $(NAME)

# Compilation des fichiers objets
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Compilation de so_long
$(NAME): $(OBJ) ft_printf/libftprintf.a
	$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)

# Compilation de ft_printf
ft_printf/libftprintf.a:
	$(MAKE) -C ft_printf

# Nettoyage des fichiers objets
clean:
	rm -f $(OBJ)
	$(MAKE) -C ft_printf clean

# Nettoyage complet
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ft_printf fclean

# Récompilation complète
re: fclean all
