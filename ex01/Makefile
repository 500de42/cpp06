SRC = main.cpp Serializer.cpp
NAME = Serializer
FLAGS = c++ -Wall -Werror -Wextra -std=c++98

all : $(NAME)

$(NAME) : $(SRC)
	$(FLAGS) $(SRC) -o $@

clear :

fclean : clear
	rm -rf $(NAME)

re : fclean all
