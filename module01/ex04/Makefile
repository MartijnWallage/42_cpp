# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 14:21:06 by mwallage          #+#    #+#              #
#    Updated: 2024/02/22 14:21:07 by mwallage         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPP		:= c++
FLAGS	:= -std=c++98 -Wall -Wextra -Werror
SRC		:= main.cpp
OBJ		:= $(SRC:.cpp=.o)
EXEC	:= SedForLosers

all: $(EXEC)

$(EXEC): $(OBJ)
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
