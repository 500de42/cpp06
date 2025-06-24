SRC = main.cpp Base.cpp
NAME = Base
FLAGS = c++ -Wall -Werror -Wextra -std=c++11

all : $(NAME)

$(NAME) : $(SRC)
	$(FLAGS) $(SRC) -o $@

clear :

fclean : clear
	rm -rf $(NAME)

re : fclean all
