# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/30 16:42:50 by myakoven          #+#    #+#              #
#    Updated: 2025/01/17 14:20:00 by myakoven         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#***************#
#* INGREDIENTS *#
#***************#

SRC = Contact.class.cpp PhoneBook.class.cpp phoneBook.cpp
OBJ = $(addprefix obj/, $(SRC:.cpp=.o))
CC = g++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

NAME = phonebook

#****************#
#*    RECIPE   *#
#****************#

all: $(NAME)

obj/%.o: %.cpp
	mkdir -p obj
	$(CC) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf obj
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
