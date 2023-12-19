NAME = iter

CXX = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp
HDR = iter.hpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(FLAGS) $^ -o $@

%.o: %.cpp $(HDR)
	$(CXX) $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all