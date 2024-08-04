# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omakran <omakran@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/30 19:54:39 by omakran           #+#    #+#              #
#    Updated: 2024/08/03 19:35:44 by omakran          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe

SRC = main.cpp PmergeMe.cpp

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 

CXX = c++

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp PmergeMe.hpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re