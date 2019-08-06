NAME = sandbox

TARGET_DIR = ./bin/
TARGET = $(TARGET_DIR)$(NAME)


COMPILER = clang++
FLAGS = -w -Werror -Wextra -Wall -framework Opengl

DEP_DIR = ~/.brew/Cellar/glfw/3.3
DEP = -I include -I $(DEP_DIR)/include/ $(DEP_DIR)/lib/libglfw.3.3.dylib -framework OpenGL

SRC = src/*.cpp
OBJ = obj/*.o

all: $(NAME)

$(NAME): $(OBJ)
	@echo "COMPILING MAIN"
	@mkdir -p bin
	@$(COMPILER) -w main.cpp -o $(TARGET) $(OBJ) $(FLAGS) $(DEP)
	@echo "DONE"

$(OBJ):
	@echo "COMPILING OBJECTS"
	@$(COMPILER) -w -c $(SRC) $(FLAGS) $(DEP)
	@mkdir -p obj
	@mv *.o ./obj
	@echo "DONE"

clean:
	@echo "CLEAN"
	@rm -f $(OBJ)
	@rm -rf ./obj

fclean: clean
	@echo "FULL CLEAN"
	@rm -f $(TARGET)
	@rm -rf ./bin

re: fclean all

run: re
	@echo "RUN"
	@echo "---"
	@$(TARGET)

SH = curl -fsSL https://raw.githubusercontent.com/Tolsadus/42homebrewfix/master/install.sh

install:
	sh -c "$(SH)"
	brew install glfw