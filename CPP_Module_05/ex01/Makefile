# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/15 13:32:26 by mwojtcza          #+#    #+#              #
#    Updated: 2025/05/15 13:32:27 by mwojtcza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = Bureaucrat

FILES = main.cpp Bureaucrat.cpp Form.cpp
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
