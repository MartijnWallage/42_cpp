CPP		:= c++
FLAGS	:= -std=c++98 -Wall -Wextra -Werror
SRC		:= main.cpp Harl.cpp
OBJ		:= $(SRC:.cpp=.o)
HPP		:= Harl.hpp
EXEC	:= Harl

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
