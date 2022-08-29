# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/22 00:14:29 by aparolar          #+#    #+#              #
#    Updated: 2022/08/29 10:10:08 by aparolar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LISTS_PATH	=	lists/
CHAR_PATH	=	char/
PUTFD_PATH	=	putfd/
STR_PATH	=	str/
MEM_PATH	=	mem/
ARRAY_PATH	=	array/
OTHERS_PATH	=	others/

SRC			=	get_next_line

-include $(LISTS_PATH)sources.mk
-include $(CHAR_PATH)sources.mk
-include $(PUTFD_PATH)sources.mk
-include $(STR_PATH)sources.mk
-include $(MEM_PATH)sources.mk
-include $(ARRAY_PATH)sources.mk
-include $(OTHERS_PATH)sources.mk

SRCS		=	$(addsuffix .c, $(SRC))

OBJS		=	$(SRCS:.c=.o)

CC			=	gcc $(FLAGS) -I. #-O3

FLAGS		=	-Wall -Wextra -Werror

DBGFLAGS	=	$(FLAGS) -g3

DBGFLAGSX	=	$(FLAGS) -g3 -fsanitize=address

NAME		=	libft.a

$(NAME):	$(OBJS)
			@echo "\033[1;1;42m                                                                    \033[0m"
			@echo "\033[1;1;44m                                                                    \033[0m"
			@echo "\033[1;1;44m                                                                    \033[0m"
			@echo "\033[1;1;44m                           Making LIBFT                             \033[0m"
			@echo "\033[1;1;44m                                                                    \033[0m"
			@echo "\033[1;1;44m                                                                    \033[0m"
			@echo "\033[1;1;42m                                                                    \033[0m"
			@echo ""
			@ar rcs $(NAME) $(OBJS)
			#@make -s clean

all:		$(NAME)

clean:
			@echo "\033[1;1;42m                                                                    \033[0m"
			@echo "\033[1;1;44m                                                                    \033[0m"
			@echo "\033[1;1;44m                                                                    \033[0m"
			@echo "\033[1;1;44m                          Cleaning LIBFT                            \033[0m"
			@echo "\033[1;1;44m                                                                    \033[0m"
			@echo "\033[1;1;44m                                                                    \033[0m"
			@echo "\033[1;1;42m                                                                    \033[0m"
			@echo ""
			@rm -f $(OBJS)

debug:		fclean
			make re FLAGS="$(DBGFLAGS)"

# for test with
test:		re
			gcc $(DBGFLAGS) -I. libft.a mmain.c -o a.out
			./a.out
			@rm -f *.o

# for linux
so:			re
			$(CC) -fPIC $(CFLAGS) $(SRCS)
			gcc -shared -o libft.so $(OBJS)

fclean:		clean
			@echo "\033[1;1;42m                                                                    \033[0m"
			@echo "\033[1;1;44m                                                                    \033[0m"
			@echo "\033[1;1;44m                                                                    \033[0m"
			@echo "\033[1;1;44m                         Removing libft.a                           \033[0m"
			@echo "\033[1;1;44m                                                                    \033[0m"
			@echo "\033[1;1;44m                                                                    \033[0m"
			@echo "\033[1;1;42m                                                                    \033[0m"
			@echo ""
			@rm -rf $(NAME)

re:			clean fclean all

git_push:	fclean
			git add .
			git status
			git commit -m "Update $(shell date)"
			git push

.PHONY: 	all clean fclean re
