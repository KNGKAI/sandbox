NAME = sandbox

TARGET_DIR = ./bin/
TARGET = $(TARGET_DIR)$(NAME)


COMPILER = clang++
FLAGS = -w -Werror -Wextra -Wall -framework Opengl

OPENGL_DEP = -framework OpenGL
GLFW_DEP = ./lib/glfw/lib/libglfw.3.3.dylib
GLAD_DEP = ./lib/glad/glad.o
JSON_DEP = ./lib/json/jsoncpp.cpp

DEP = $(OPENGL_DEP) $(GLFW_DEP) $(GLAD_DEP) $(JSON_DEP)

GLFW_INC = -I ./lib/glfw/include/
GLAD_INC = -I ./lib/glad/include/
JSON_INC = -I ./lib/json/include/
GLM_INC = -I ./lib/glm/

INC = -I include $(GLFW_INC) $(GLAD_INC) $(JSON_INC) $(GLM_INC)

SRC = src/*.cpp
OBJ = obj/*.o

all: $(NAME)

$(NAME): $(OBJ)
	@echo "COMPILING MAIN"
	@mkdir -p bin
	@$(COMPILER) -w main.cpp -o $(TARGET) $(OBJ) $(FLAGS) $(INC) $(DEP)
	@echo "DONE"

$(OBJ):
	@echo "COMPILING OBJECTS"
	@$(COMPILER) -w -c $(SRC) $(FLAGS) $(INC)
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
	brew install glew