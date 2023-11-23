NAME = bureaucrat

CXX = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp src/Bureaucrat.cpp src/Form.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(FLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all