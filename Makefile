NAME = a.out
CC = g++
FLAGS = -std=c++11
SRC = main.cpp \
Boyer-Moore.cpp \
naiveOptimizedSearch.cpp \
stringGenerator.cpp \

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY: clean fclean all re