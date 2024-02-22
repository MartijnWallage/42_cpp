# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 14:17:41 by mwallage          #+#    #+#              #
#    Updated: 2024/02/22 14:17:44 by mwallage         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPP 		:= c++
CPPFLAGS 	:= -std=c++98 -Wall -Wextra -Werror
SRC 		:= megaphone.cpp
OBJ			:= $(SRC:.cpp=.o)
EXEC 		:= megaphone

all: $(EXEC)

$(EXEC): $(OBJ) $(HPP)
	$(CPP) $(CPPFLAGS) $^ -o $@

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(EXEC)

re: fclean
	make

.PHONY: all, clean, fclean, re
