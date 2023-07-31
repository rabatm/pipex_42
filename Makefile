# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrabat <mrabat@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/03 17:51:43 by mrabat            #+#    #+#              #
#    Updated: 2023/06/21 16:20:16 by mrabat           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
DEF_COLOR = \033[0;39m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m

NAME = pipex
LIBFT = ./lib/libft/libft.a
# Dossiers
SRCDIR = src
OBJDIR = obj
BINDIR = bin
LIBDIR = lib/libft

# Compilateur et options
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I$(LIBDIR)

# Noms des fichiers
NAME = $(BINDIR)/pipex
LIBFT = $(LIBDIR)/libft.a

# Fichiers sources et objets
SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))

# Règle par défaut
all: $(NAME)

# Création du dossier bin s'il n'existe pas
$(shell mkdir -p $(BINDIR))

# Création du dossier obj s'il n'existe pas
$(shell mkdir -p $(OBJDIR))

# Règle de construction de l'exécutable
$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@
	@echo "$(BLUE)PIPEX READY IN BIN FOLDER$(DEF_COLOR)"

# Règle de compilation des fichiers objets
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(YELLOW)OBJ CREDD$(DEF_COLOR)"

# Règle de construction de la bibliothèque libft.a
$(LIBFT):
	$(MAKE) -C $(LIBDIR)
	@echo "$(YELLOW)LIBFT COMPILED$(DEF_COLOR)"

# Règle de nettoyage des fichiers objets
clean:
	$(MAKE) clean -C $(LIBDIR)
	rm -rf $(OBJDIR)
	@echo "$(BLUE)cleaned!$(DEF_COLOR)"

# Règle de nettoyage complet
fclean: clean
	$(MAKE) fclean -C $(LIBDIR)
	rm -rf $(BINDIR)
	@echo "$(RED)cleaned!$(DEF_COLOR)"

# Règle de recompilation complète
re: fclean all

.PHONY: all clean fclean re

