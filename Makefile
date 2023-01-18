NAME:=libqueue
ENTRY:=queue
MODE:=prod

LD_LIBRARY_PATH:=/usr/local/lib
INCLUDE:=/usr/local/include

SRC_DIR:=src
OBJ_DIR:=obj
DEP_DIR:=$(OBJ_DIR)
HEAD_DIR:=include
TEST_DIR:=test
EXAMPLE_DIR:=examples
DOCS_DIR:=docs

INC_DIR:=.

TEST:=test
EXAMPLE:=example

SRCFILES:=$(shell find $(SRC_DIR) -type f -name "*.c")
OBJFILES := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCFILES))
DEPFILES := $(patsubst $(SRC_DIR)/%.c,$(DEP_DIR)/%.d,$(SRCFILES))

CC:=gcc

ifeq ($(MODE), dev)
CFLAGS:=-std=gnu18 -Og $(addprefix -I,$(INC_DIR))
else
CFLAGS:=-std=gnu18 -Ofast $(addprefix -I,$(INC_DIR))
endif
INSTALL:=install

all: $(NAME).so

.PHONY: all run

$(NAME).so: $(OBJFILES)
	@echo "Building Final Shared Object"
	@$(CC) $(CFLAGS) $(OBJ_DIR)/*.o -shared -o $@
	@echo "Done"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile $(OBJ_DIR)
	@$(CC) $(CFLAGS) -MMD -MP -fPIC -c $< -o $@
	@echo "Compiling $< file"

$(OBJ_DIR):
	@mkdir $(OBJ_DIR) 2> /dev/null

test: install
	@$(CC) $(CFLAGS) -o ./$(TEST_DIR)/$(TEST).o ./$(TEST_DIR)/$(TEST).c -lqueue
	@echo "------------"
	@./$(TEST_DIR)/$(TEST).o

run: install
	@$(CC) $(CFLAGS) -o ./$(EXAMPLE_DIR)/$(TEST).o ./$(EXAMPLE_DIR)/$(EXAMPLE).c -lqueue
	@echo "------------"
	@./$(EXAMPLE_DIR)/$(TEST).o

install: $(NAME).so $(HEAD_DIR)/$(ENTRY).h
	@echo "Installing..."
	@sudo mkdir -p $(INCLUDE)/$(NAME)
	@sudo ldconfig $(LD_LIBRARY_PATH)
	@sudo cp -a $(HEAD_DIR)/. $(INCLUDE)/$(NAME)/
	@sudo cp $(NAME).so $(LD_LIBRARY_PATH)
	@echo "Done!"

docs: $(SRCFILES) $(HEADERFILES)
	@doxygen 1> /dev/null
	@echo "Documentation created!"
	@echo ""
	@echo "Copy the following link and open in a browser:"
	@echo file://$(shell pwd)/$(DOCS_DIR)/html/index.html

clean:
	@rm -rf $(NAME).so $(TEST).o $(OBJ_DIR) $(DEP_DIR) ./examples/$(TEST).o

-include $(DEPFILES)