NAME=btc
CXX=c++
CPPFLAGS=-Wall -Werror -Wextra -std=c++98
SRC=src/main.cpp src/BitcoinExchange.cpp src/utils.cpp
OBJ=$(SRC:%.cpp=%.o)
RM=rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

