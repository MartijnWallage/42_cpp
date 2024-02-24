# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwallage <mwallage@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 14:17:41 by mwallage          #+#    #+#              #
#    Updated: 2024/02/24 16:17:59 by mwallage         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPP 		:= c++
CPPFLAGS 	:= -std=c++98 -Wall -Wextra -Werror
SRC 		:= megaphone.cpp
OBJ			:= $(SRC:.cpp=.o)
EXEC 		:= megaphone

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CPP) $(CPPFLAGS) $^ -o $@

%.o: %.cpp $(HPP)
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(EXEC)

re: fclean
	make

.PHONY: all, clean, fclean, re
