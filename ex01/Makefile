CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS =	Contact.cpp \
		PhoneBook.cpp \
		main.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = phonebook
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:	
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
.PHONY: all clean fclean re