# Nome do Programa
NAME = vpl_execution

# Diretórios
OBJ_DIR = obj
INCLUDE_DIR = include
SRC_DIR = src

# Flags para o compilador
CPPFLAGS = -Wall -g -O3 -std=c++11

# Arquivos de Origem
SRCS = $(SRC_DIR)/main.cpp \
       $(SRC_DIR)/Players.cpp \
       $(SRC_DIR)/BoardLogic.cpp \
       $(SRC_DIR)/Lig4.cpp \
       $(SRC_DIR)/Reversi.cpp \
       $(SRC_DIR)/JogoVelha.cpp

# Arquivos Objeto
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Regra Padrão
all: $(NAME)

# Criação do diretório de objetos, se não existir
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Regra para construir o programa
$(NAME): $(OBJ_DIR) $(OBJS)
	g++ $(CPPFLAGS) -I$(INCLUDE_DIR) -o $@ $^

# Regra para os arquivos objeto
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(INCLUDE_DIR)/%.hpp
	g++ $(CPPFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Regra para rodar o programa com o make
run: all
	./$(NAME)

# Regra de limpeza
clean:
	rm -f $(OBJ_DIR)/*.o
	rm -f $(NAME)
	rmdir $(OBJ_DIR)
