CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME     = phonebook

SRCS     = main.cpp PhoneBook.cpp Contact.cpp
HDRS     = PhoneBook.hpp Contact.hpp
OBJS     = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
