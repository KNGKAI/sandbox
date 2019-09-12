NAME = Tests
# FLAGS = -Wall -Wextra -Werror

INC_DIR = ../include

HEADERS = $(INC_DIR)/ientity.h \
		$(INC_DIR)/transform.h \
		$(INC_DIR)/rigidbody.h \
		$(INC_DIR)/mesh.h \
		$(INC_DIR)/vector3.h \
		$(INC_DIR)/Character.class.hpp \
		$(INC_DIR)/CharacterFactory.class.hpp

SRC_DIR = ../src

SRC = $(SRC_DIR)/vector3.cpp \
 	$(SRC_DIR)/Character.class.cpp \
	$(SRC_DIR)/CharacterFactory.class.cpp 

$(NAME) :
	g++ Character.tests.cpp $(SRC) -I ../include/$(HEADERS)

all : $(NAME)

clean:
	@echo "suppose to clean .o"

fclean:
	@echo "suppose to clean everything"
re:
	@echo "Suppose to clean and recompile"