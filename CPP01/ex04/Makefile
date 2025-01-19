
#***************#
#* INGREDIENTS *#
#***************#

SRC = main.cpp
OBJ = $(addprefix obj/, $(SRC:.cpp=.o))
CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

NAME = replace

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