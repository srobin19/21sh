# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srobin <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/13 16:43:10 by srobin            #+#    #+#              #
#    Updated: 2020/02/07 15:34:56 by srobin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 21sh

FLAG = -ltermcap

SOURCE = main.c termcaps_init.c termcaps_keys.c input.c 
LIBFT_DIR = libft/

COMP_OBJ = ./obj/*.o

OBJ_DIR = ./obj
SRC_DIR = ./
INCLUDE = ./

GGCOLORCYAN = \033[96m
GGCOLORGREEN = \033[32m
GGCOLORRED = \033[31m
GGMAG = \033[1;35m
GGRESET = \033[39m

SRC = $(addprefix $(SRC_DIR)/, $(SOURCE))
OBJ = $(addprefix $(OBJ_DIR)/, $(subst .c,.o, $(SOURCE)))

all: comp
	@mkdir -p $(OBJ_DIR)
	@make $(NAME)

comp:
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	@gcc $(FLAG) $(COMP_OBJ) -I $(INCLUDE) -L $(LIBFT_DIR) -lft  -o $(NAME)
	@echo "$(GGCOLORCYAN)Creation$(GGRESET) du binaire $(GGMAG)21sh$(GGRESET)..."
	@echo "$(GGCOLORGREEN)Success!$(GGRESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "[$(GGCOLORGREEN)✔$(GGRESET)] "$(subst .c,,$<)
	@mkdir -p $(dir $@) && gcc $(FLAG) -I $(INCLUDE) -o $@ -c $<

clean:
	@make -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -rf $(NAME)
	@echo "$(GGCOLORRED)Suppresion$(GGRESET) de 21sh..."

re: fclean all

.PHONY: clean fclean re all
