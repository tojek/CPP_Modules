CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = FragTrap

FILES = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
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
