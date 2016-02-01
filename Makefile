# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/05/30 11:06:29 by tettouat          #+#    #+#              #
#    Updated: 2016/02/01 11:40:47 by ddela-cr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a

NAMEBASE =	libftprintf

LIB = ./libft/libft.a

FLAG =	-Wall -Wextra -Werror -I./includes

SRC =	apply_flags.c												\
				apply_jz_modifier.c											\
				apply_lh_modifier.c											\
				apply_precision.c											\
				color.c														\
				flags.c														\
				format.c													\
				get_int_args.c												\
				get_other_args.c											\
				modifiers.c													\
				precision.c													\
				printf.c													\
				proceed.c													\
				proceed_int.c												\
				proceed_ptr.c												\
				proceed_str.c												\
				proceed_wide.c												\
				utils_wstr.c												\
				width.c

OBJ = $(SRC:.c=.o)

.SILENT:

all: $(NAME)
	echo "\033[38;5;44m☑️  ALL    $(NAMEBASE) is done\033[0m\033[K"

$(OBJ): $(SRC)
	gcc $(FLAG) -c $(SRC)

$(NAME): $(LIB) $(OBJ)
	printf "\r\033[38;5;11m⌛  MAKE   $(NAMEBASE) please wait ...\033[0m\033[K"
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	echo -en "\r\033[38;5;22m☑️  MAKE   $(NAMEBASE)\033[0m\033[K"
	echo "\r\033[38;5;184m👥  GROUP MEMBER(S):\033[0m\033[K"
	echo "\r\033[38;5;15m`cat auteur | sed s/^/\ \ \ \ /g`\033[0m\033[K"

$(LIB):
	make -C libft/ fclean
	make -C libft/
	cp $(LIB) $(NAME)

clean:
	printf "\r\033[38;5;11m⌛  CLEAN  $(NAMEBASE) please wait ...\033[0m\033[K"
	rm -f $(OBJ)
	make -C libft/ clean
	printf "\r\033[38;5;11m☑️  CLEAN  $(NAMEBASE) is done\033[0m\033[K"

fclean: clean
	printf "\r\033[38;5;11m⌛  FCLEAN $(NAMEBASE) please wait ...\033[0m\033[K"
	rm -f $(NAME)
	make -C libft/ fclean
	printf "\r\033[38;5;11m☑️  FCLEAN  $(NAMEBASE) is done\033[0m\033[K"

cp:
	cp ../ft_printf/srcs/* .
	cp -rf ../ft_printf/libft/* ./libft
	cp -rf ../ft_printf/includes/* ./includes
	printf "\r\033[38;5;11m☑️  Copied files\033[0m\033[K"

re: fclean all

.PHONY: fclean clean re
