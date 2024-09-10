NAME = phone_book

SRCS = main.cpp Contact/Contact.cpp PhoneBook/PhoneBook.cpp
OBJS = $(SRCS:.cpp=.o)

COMP = g++
FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(COMP) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(COMP) $(FLAGS) -o $@ -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re