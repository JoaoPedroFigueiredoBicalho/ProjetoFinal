CC=g++
CFLAGS=-std=c++11 -Wall
CXXFLAGS = -O0 -g
SRC_DIR=src
INCLUDE_DIR=include
OBJ_DIR=obj

all: projetofinal_execution

$(OBJ_DIR)/boardLogic.o: $(INCLUDE_DIR)/boardLogic.hpp $(SRC_DIR)/boardLogic.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/boardLogic.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/boardLogic.o

$(OBJ_DIR)/jogoVelha.o: $(INCLUDE_DIR)/jogoVelha.hpp $(INCLUDE_DIR)/boardLogic.hpp $(SRC_DIR)/jogoVelha.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/jogoVelha.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/jogoVelha.o

$(OBJ_DIR)/lig4.o: $(INCLUDE_DIR)/lig4.hpp $(INCLUDE_DIR)/boardLogic.hpp $(SRC_DIR)/lig4.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/lig4.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/lig4.o

$(OBJ_DIR)/Players.o: $(INCLUDE_DIR)/Players.hpp $(SRC_DIR)/Players.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Players.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Players.o

$(OBJ_DIR)/reversi.o: $(INCLUDE_DIR)/reversi.hpp $(INCLUDE_DIR)/boardLogic.hpp $(SRC_DIR)/reversi.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/reversi.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/reversi.o

$(OBJ_DIR)/main.o: $(INCLUDE_DIR)/boardLogic.hpp $(INCLUDE_DIR)/jogoVelha.hpp $(INCLUDE_DIR)/lig4.hpp $(INCLUDE_DIR)/Players.hpp $(INCLUDE_DIR)/reversi.hpp $(SRC_DIR)/main.cpp 
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/main.o

projetofinal_execution: $(OBJ_DIR)/main.o $(OBJ_DIR)/boardLogic.o $(OBJ_DIR)/jogoVelha.o $(OBJ_DIR)/reversi.o $(OBJ_DIR)/Players.o $(OBJ_DIR)/lig4.o
	$(CC) $(CFLAGS) $(OBJ_DIR)/main.o $(OBJ_DIR)/boardLogic.o $(OBJ_DIR)/jogoVelha.o $(OBJ_DIR)/reversi.o $(OBJ_DIR)/Players.o $(OBJ_DIR)/lig4.o -o projetofinal_execution