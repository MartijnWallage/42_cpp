CPP		:= c++
FLAGS	:= -std=c++98 -Wall -Wextra -Werror
SRC		:= main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJ		:= $(SRC:.cpp=.o)
HPP		:= Weapon.hpp HumanA.hpp HumanB.hpp
EXEC	:= Weapon

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CPP) $(FLAGS) $^ -o $@

%.o: %.cpp $(HPP)
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(EXEC)

re: fclean
	make

.PHONY: all, clean, fclean, re
