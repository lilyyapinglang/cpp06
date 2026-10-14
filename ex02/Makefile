SRCS = main.cpp A.cpp B.cpp C.cpp Base.cpp
INCLUDES = A.hpp B.hpp C.hpp Base.hpp
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -g

OBJ_DIR = obj
OBJS = ${SRCS:%.cpp=$(OBJ_DIR)/%.o}

NAME = identify

all: $(NAME)

$(OBJ_DIR)/%.o: %.cpp $(INCLUDES)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

test: re
	python test.py

.PHONY: all clean fclean re
