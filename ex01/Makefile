CPP	:= c++
FLAGS	:= -std=c++98 -Wall -Wextra -Werror
SRC	:= PhoneBook.cpp, Contact.cpp
OBJ	:= $(SRC:.cpp=.o)
EXEC	:= PhoneBook

all : $EXEC

$(EXEC)	: $(OBJ)
	$(CPP) $(FLAGS) $^ -o $@

%.o	: %.cpp %.hpp
	$(CPP) $(FLAGS) -c $< -o $@

clean	:
	rm -f *.o

fclean	: clean
	rm -f $(EXEC)

re	: fclean
	make

.PHONY	: all, clean, fclean, re
