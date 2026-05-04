NAME=PmergeMe
CXX=c++
CPPFLAGS=-Wall -Werror -Wextra -std=c++98
SRC=vect.cpp deque.cpp main.cpp sort_vector.cpp sort_deque.cpp
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

