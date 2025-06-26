CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = megaphone.cpp
OBJS = $(SRCS:%.cpp=build/%.o)
NAME = megaphone
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME); 
	@echo "Compiled!"

build/%.o: %.cpp
	@mkdir -p build; $(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf build
	@echo "Cleaned build files!"

fclean: clean
	@$(RM) $(NAME)
	@echo "Cleaned executable!"

re: fclean all

.PHONY: all clean fclean re
