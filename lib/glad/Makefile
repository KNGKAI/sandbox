NAME = libglad.dylib

COMPILER = gcc
FLAGS = -w -Werror -Wextra -Wall

INC = -I include

SRC = src/glad.c
OBJ = glad.o

all: $(OBJ)
	@$(COMPILER) -w -dynamiclib -o $(NAME) $(OBJ) $(INC)

$(OBJ):
	@echo "COMPILING GLAD"
	@$(COMPILER) -w -c $(SRC) $(FLAGS) $(INC)
	@echo "DONE"

clean:
	@echo "CLEAN GLAD"
	@rm -f $(OBJ)

re: clean all