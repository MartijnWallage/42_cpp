# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 14:22:58 by mwallage          #+#    #+#              #
#    Updated: 2024/03/25 15:54:22 by mwallage         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPP		:= c++
FLAGS	:= -std=c++98 -Wall -Wextra -Werror
SRC		:= main.cpp \
			Dog.cpp \
			Cat.cpp \
			Animal.cpp \
			Brain.cpp
OBJ		:= $(SRC:.cpp=.o)
HPP		:= Dog.hpp \
			Cat.hpp \
			Animal.hpp \
			Brain.hpp
EXEC	:= AnimalFarm

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
