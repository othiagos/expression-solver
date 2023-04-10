NAME = expression_solver
TEST_NAME = test
CC = g++
SRC_DIR = ./src
INC_DIR = ./include
LIB_DIR = ./lib
BIN_DIR = ./bin
OBJ_DIR = ./obj
CFLAGS = -Wall -g
TEST_DIR = ./test
TEST_BIN_DIR = ./test/bin
TEST_SRC_DIR = ./test/src
EXE = $(BIN_DIR)/$(NAME)
EXE_TEST = $(BIN_DIR)/$(TEST_NAME)

OBJS = \
	$(OBJ_DIR)/Parser.o

TEST_OBJS = \
	$(OBJ_DIR)/TestArrayStack.o

all: mkdir $(EXE)

run: all
	$(EXE)

mkdir:
	mkdir -p $(BIN_DIR)
	mkdir -p $(OBJ_DIR)

$(EXE): $(OBJ_DIR)/$(NAME).o $(OBJS) 
	$(CC) $< $(OBJS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(INC_DIR)/%.hpp
	$(CC) -c $(CFLAGS) $< -I $(INC_DIR) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) -c $(CFLAGS) $< -I $(INC_DIR) -o $@ 

$(EXE_TEST): $(OBJ_DIR)/$(TEST_NAME).o $(OBJS) $(TEST_OBJS)
	$(CC) $(CFLAGS) $< $(OBJS) $(TEST_OBJS) -o $(EXE_TEST)

test: mkdir $(EXE_TEST)

run_test: test
	$(EXE_TEST)

$(OBJ_DIR)/%.o: $(TEST_SRC_DIR)/%.cpp
	$(CC) -c $(CFLAGS) $< -I $(INC_DIR) -I $(LIB_DIR) -o $@

$(OBJ_DIR)/%.o: $(TEST_DIR)/%.cpp
	$(CC) -c $(CFLAGS) $< -I $(INC_DIR) -I $(LIB_DIR) -o $@

clean:
	rm -f $(OBJ_DIR)/*
	rm -f $(EXE)
	rm -f $(EXE_TEST)