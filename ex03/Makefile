NAME = materia

CXX = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp srcs/AMateria.cpp srcs/Cure.cpp srcs/Ice.cpp srcs/Character.cpp

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
