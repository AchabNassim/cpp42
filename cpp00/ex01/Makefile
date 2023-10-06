NAME = phonebook

CXX = g++

FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = program.cpp phoneBookUtils.cpp contactUtils.cpp

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
