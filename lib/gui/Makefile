NAME = imgui.dynlib
SRC = imgui*.cpp
OBJ = imgui*.o
COMPILER = clang++

DEP_DIR = ~/.brew/Cellar
OPENGL_DEP = -framework OpenGL
GLEW_DEP = $(DEP_DIR)/glew/2.1.0/lib/libGLEW.2.1.0.dylib
GLFW_DEP = $(DEP_DIR)/glfw/3.3/lib/libglfw.3.3.dylib

DEP = $(OPENGL_DEP) $(GLEW_DEP) $(GLFW_DEP)

GLEW_INC = -I $(DEP_DIR)/glew/2.1.0/include
GLFW_INC = -I $(DEP_DIR)/glfw/3.3/include/
INC = -I include $(GLEW_INC) $(GLFW_INC) $(IMGUI_INC)

all: $(NAME)

$(NAME): $(OBJ)
	@$(COMPILER) -w -dynamiclib -o $(NAME) $(OBJ) $(INC) $(DEP)

$(OBJ):
	@$(COMPILER) -w -c $(SRC) $(INC) $(DEP)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all