CC = c++ 
CFLAGS = -Wall -Wextra -std=c++98

SRCS =  Account.cpp \
		tests.cpp

OBJS = $(SRCS:.cpp=.o)

NAME = tests

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re