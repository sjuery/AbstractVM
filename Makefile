# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjuery <sjuery@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/04 14:33:42 by sjuery            #+#    #+#              #
#    Updated: 2018/10/20 18:20:16 by sjuery           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= abstractVM

SRC		= 	srcs/abstractVM.cpp \
			srcs/IOperand.cpp \
			srcs/VirtualMachine.cpp \

OBJ 	= $(SRC:.c=.o)
CFLAG	= -Wall -Wextra -Werror -fsanitize=address -fsanitize=undefined
			-O3 -march=native -flto=thin

all: $(NAME)

$(NAME): $(OBJ)
	@printf '\033[31m[...] %s\n\033[0m\033[33m' "Creating AbstractVM"
	clang++ $(CFLAG) $^ -o $(NAME)
	@printf '\033[32m[ ✔ ] %s\n\033[0m' "Created AbstractVM"

clean:
	@printf '\033[31m[...] %s\n\033[0m' "Cleaning AbstractVM"
	@/bin/rm -f *.o
	@printf '\033[32m[ ✔ ] %s\n\033[0m' "Cleaned AbstractVM"

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all test
