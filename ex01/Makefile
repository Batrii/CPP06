CC = c++
FLAGS = -Wall -Wextra -Werror
SRCS = Serializer.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

NAME = Serializer

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all