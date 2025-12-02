# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/02 13:53:53 by mwojtcza          #+#    #+#              #
#    Updated: 2025/12/02 13:53:54 by mwojtcza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = RPN

FILES = main.cpp RPN.cpp
OBJS = $(FILES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
