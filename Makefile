NAME = expression_solver
CC = g++
SRC_DIR = ./src
INC_DIR = ./include
BIN_DIR = ./bin
OBJ_DIR = ./obj
CFLAGS = -Wall -g
EXE = $(BIN_DIR)/$(NAME)

OBJS = \
	$(OBJ_DIR)/Parser.o \
	$(OBJ_DIR)/expression_solver.o

all: mkdir $(EXE)

run: all
	$(EXE)

mkdir:
	mkdir -p $(BIN_DIR)
	mkdir -p $(OBJ_DIR)

$(EXE): $(OBJS)
	$(CC) $(OBJS) -o $(EXE)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(INC_DIR)/%.hpp
	$(CC) -c $(CFLAGS) $< -I $(INC_DIR) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) -c $(CFLAGS) $< -I $(INC_DIR) -o $@

clean:
	rm -f $(OBJS)
	rm -f $(EXE)