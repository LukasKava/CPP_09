# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkavalia <lkavalia@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/12 10:56:36 by lkavalia          #+#    #+#              #
#    Updated: 2023/06/12 18:02:37 by lkavalia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = btc

CC = c++

CPP_FLAGS = -Wall -Werror -Wextra -std=c++98 -fsanitize=address

SRC = main.cpp BitcoinExchange.cpp

all: $(NAME)

$(NAME): $(SRC)
		$(CC) $(CPP_FLAGS) $(SRC) -o $(NAME)

fclean:
	rm -f $(NAME)
	@echo "force cleaning!"

re: fclean all
	@echo "remaking files!"