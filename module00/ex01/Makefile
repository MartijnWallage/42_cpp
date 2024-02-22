# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 14:18:10 by mwallage          #+#    #+#              #
#    Updated: 2024/02/22 14:18:13 by mwallage         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPP		:= c++
FLAGS	:= -std=c++98 -Wall -Wextra -Werror
SRC		:= PhoneBook.cpp Contact.cpp main.cpp
HPP		:= PhoneBook.hpp Contact.hpp
OBJ		:= $(SRC:.cpp=.o)
EXEC	:= PhoneBook

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
