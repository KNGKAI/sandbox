NAME = sandbox

TARGET_DIR = ./bin/
TARGET = $(TARGET_DIR)$(NAME)


COMPILER = clang++
FLAGS = -w -Werror -Wextra -Wall -framework Opengl

DEP_DIR = ~/.brew/Cellar

OPENGL_DEP = -framework OpenGL
GLEW_DEP = $(DEP_DIR)/glew/2.1.0/lib/libGLEW.2.1.0.dylib
GLFW_DEP = $(DEP_DIR)/glfw/3.3/lib/libglfw.3.3.dylib
IMGUI_DEP = ./lib/gui/imgui*.cpp #.dynlib
JSON_DEP = ./lib/json/jsoncpp.cpp

DEP = $(OPENGL_DEP) $(GLEW_DEP) $(GLFW_DEP) $(JSON_DEP)

GLEW_INC = -I $(DEP_DIR)/glew/2.1.0/include
GLFW_INC = -I $(DEP_DIR)/glfw/3.3/include/
IMGUI_INC = -I ./lib/gui/
JSON_INC = -I ./lib/json/include
GLM_INC = -I ./lib/glm

INC = -I include $(GLEW_INC) $(GLFW_INC) $(JSON_INC) $(GLM_INC)

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