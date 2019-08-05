NAME = sandbox

TARGET_DIR = ./bin/
TARGET = $(TARGET_DIR)$(NAME)


COMPILER = clang++
FLAGS = -w -Werror -Wextra -Wall -I include

SRC = src/*.cpp
OBJ = obj/*.o

all: $(NAME)

$(NAME): $(OBJ)
	@echo "COMPILING MAIN"
	@mkdir -p bin
	@$(COMPILER) -w main.cpp -o $(TARGET) $(OBJ) $(FLAGS)
	@echo "DONE"

$(OBJ):
	@echo "COMPILING OBJECTS"
	@$(COMPILER) -w -c $(SRC) $(FLAGS)
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