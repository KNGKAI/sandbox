NAME = sandbox

TARGET_DIR = ./bin/
TARGET = $(TARGET_DIR)$(NAME)


COMPILER = clang++
FLAGS = -w -Werror -Wextra -Wall -framework Opengl

DEP_DIR = ~/.brew/Cellar

ASSIMP_DEP = ./lib/assimp/lib/libassimp.4.0.1.dylib 
GLAD_DEP = ./lib/glad/glad.o
GLFW_DEP = $(DEP_DIR)/glfw/3.3/lib/libglfw.3.3.dylib
JSON_DEP = ./lib/json/jsoncpp.cpp
OPENGL_DEP = -framework OpenGL

DEP = $(ASSIMP_DEP) $(GLAD_DEP) $(GLFW_DEP) $(JSON_DEP) $(OPENGL_DEP)

ASSIMP_INC = -I ./lib/assimp/include/
GLAD_INC = -I ./lib/glad/include/
GLFW_INC = -I ./lib/glfw/include/
GLM_INC = -I ./lib/glm
JSON_INC = -I ./lib/json/include
STB_INC = -I ./lib/stb/

INC = -I ./include $(ASSIMP_INC) $(GLAD_INC) $(GLFW_INC) $(GLM_INC) $(JSON_INC) $(STB_INC)

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