CPP		:= c++
FLAGS	:= -std=c++98 -Wall -Wextra -Werror
SRC		:= Account.cpp test.cpp
HPP		:= Account.hpp
OBJ		:= $(SRC:.cpp=.o)
EXEC	:= Account

all: $(EXEC)

$(EXEC): $(OBJ) $(HPP)
	$(CPP) $(FLAGS) $^ -o $@

%.o: %.cpp
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(EXEC)

re: fclean
	make

.PHONY: all, clean, fclean, re
