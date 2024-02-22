# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 14:19:21 by mwallage          #+#    #+#              #
#    Updated: 2024/02/22 14:19:23 by mwallage         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPP		:= c++
FLAGS	:= -std=c++98 -Wall -Wextra -Werror
SRC		:= main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
HPP		:= Zombie.hpp
OBJ		:= $(SRC:.cpp=.o)
EXEC	:= Zombie

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
