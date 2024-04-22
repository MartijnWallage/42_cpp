# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 14:22:58 by mwallage          #+#    #+#              #
#    Updated: 2024/04/22 13:48:58 by mwallage         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPP		:= c++
FLAGS	:= -std=c++98 -Wall -Wextra -Werror
SRC		:= main.cpp \
			RPN.cpp
OBJ		:= $(SRC:.cpp=.o)
HPP		:= RPN.hpp
EXEC	:= RPN

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
