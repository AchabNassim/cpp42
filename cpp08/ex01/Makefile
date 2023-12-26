NAME = span

CXX = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Span2.cpp
HDR = Span.hpp

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