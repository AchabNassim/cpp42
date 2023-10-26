NAME = animals

CXX = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp srcs/Animal.cpp srcs/WrongAnimal.cpp srcs/Cat.cpp srcs/WrongCat.cpp srcs/Dog.cpp srcs/Brain.cpp

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
