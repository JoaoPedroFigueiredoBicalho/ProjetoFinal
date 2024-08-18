# Nome do Programa
NAME = vpl_execution

# Diretórios
OBJ_DIR = obj
INCLUDE_DIR = include
SRC_DIR = src

# Flags para o compilador
CPPFLAGS = -Wall -g -O3 -std=c++11

# Arquivos de Origem e Objeto
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
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
