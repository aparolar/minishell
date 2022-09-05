# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/28 14:55:48 by aparolar          #+#    #+#              #
#    Updated: 2022/09/05 20:36:25 by aparolar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


################################################################################
# 						MINISHELL APAROLAR & ICASTELL						   #
################################################################################

-include src/parser/sources.mk
-include src/env/sources.mk
-include src/lexer/sources.mk
-include src/builtins/sources.mk
-include src/executor/sources.mk
-include src/expander/sources.mk
-include src/errors/sources.mk
-include src/signals/sources.mk

NAME			=	minishell
LIBFT			=	libft
SRC				=	minishell info clean input print exit_controlled
SRCS			=	$(addprefix src/, $(addsuffix .c, $(SRC))) \
					$(addprefix src/env/, $(addsuffix .c, $(SRC_ENV))) \
					$(addprefix src/parser/, $(addsuffix .c, $(SRC_PARSER))) \
					$(addprefix src/builtins/, $(addsuffix .c, $(SRC_BUILTINS))) \
					$(addprefix src/lexer/, $(addsuffix .c, $(SRC_LEXER))) \
					$(addprefix src/executor/, $(addsuffix .c, $(SRC_EXECUTOR))) \
					$(addprefix src/expander/, $(addsuffix .c, $(SRC_EXPANDER))) \
					$(addprefix src/errors/, $(addsuffix .c, $(SRC_ERRORS))) \
					$(addprefix src/signals/, $(addsuffix .c, $(SRC_SIGNALS)))
OBJS			=	$(SRCS:.c=.o)
DBFLAGS			=	-g3 -fsanitize=address
FLAGS			=	-Wall -Werror -Wextra
LDFLAGS			=	-L /Volumes/sgoinfre/students/$(USER)/homebrew/Cellar/readline/8.1.2/lib
#LDFLAGS			=	-L /usr/local/Cellar/readline/8.1.2/lib
CPPFLAGS		=	-I /Volumes/sgoinfre/students/$(USER)/homebrew/Cellar/readline/8.1.2/include
#CPPFLAGS		=	-I /usr/local/Cellar/readline/8.1.2/include
CC				=	gcc $(FLAGS)

$(NAME):	$(OBJS)
	make -s -C $(LIBFT)
	$(CC) $(SRCS) -lft -L$(LIBFT) -lreadline $(LDFLAGS) $(CPPFLAGS) -o $(NAME)
	printf "Completed\n"

all:		$(NAME)

re:			fclean all

clean:
	make clean -s -C $(LIBFT)
	rm -f $(OBJS)

fclean:		clean
	make fclean -s -C $(LIBFT)
	rm -f $(NAME)

test:		re
	./$(NAME)

git_push:	fclean
	rm -rf minishell.dSYM
	git add .
	git status
	git commit -m "Update $(shell date)"
	git push

git_pull:
	git pull --recurse-submodules

.SILENT:	$(NAME)
.PHONY:		all re clean fclean
