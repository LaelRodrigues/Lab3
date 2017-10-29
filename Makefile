RM = rm -rf 

# Compilador
CC=g++ 

LIB_DIR=./lib
INC_DIR=./include
SRC_DIR=./src
OBJ_DIR=./build
BIN_DIR=./bin
DOC_DIR=./doc
TEST_DIR=./test
 
CFLAGS=-Wall -pedantic -ansi -std=c++11 -I. -I$(INC_DIR)

.PHONY: all clean doxy debug doc 


all: init questao1 questao2 questao3

debug: CFLAGS += -g -O0
debug: all

init:
	@mkdir -p $(OBJ_DIR)/questao1
	@mkdir -p $(OBJ_DIR)/questao2
	@mkdir -p $(OBJ_DIR)/questao3
	@mkdir -p $(BIN_DIR)

questao1: CFLAGS+= -I$(INC_DIR)/questao1
questao1: $(OBJ_DIR)/questao1/produto.o $(OBJ_DIR)/questao1/fruta.o $(OBJ_DIR)/questao1/roupa.o $(OBJ_DIR)/questao1/bebida.o $(OBJ_DIR)/questao1/arquivo.o   $(OBJ_DIR)/questao1/main.o 
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel 'questao1' criado em $(BIN_DIR)] +++"
	@echo "============="
$(OBJ_DIR)/questao1/produto.o: $(SRC_DIR)/questao1/produto.cpp $(INC_DIR)/questao1/produto.h
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJ_DIR)/questao1/fruta.o: $(SRC_DIR)/questao1/fruta.cpp $(INC_DIR)/questao1/fruta.h
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJ_DIR)/questao1/roupa.o: $(SRC_DIR)/questao1/roupa.cpp $(INC_DIR)/questao1/roupa.h
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJ_DIR)/questao1/bebida.o: $(SRC_DIR)/questao1/bebida.cpp $(INC_DIR)/questao1/bebida.h
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJ_DIR)/questao1/arquivo.o: $(SRC_DIR)/questao1/arquivo.cpp $(INC_DIR)/questao1/arquivo.h
	$(CC) -c $(CFLAGS) -o $@ $<
	
$(OBJ_DIR)/questao1/main.o: $(SRC_DIR)/questao1/main.cpp
	$(CC) -c $(CFLAGS) -o $@ $<

questao2: CFLAGS+= -I$(INC_DIR)/questao2
questao2: $(OBJ_DIR)/questao2/conta.o $(OBJ_DIR)/questao2/movimentacao.o $(OBJ_DIR)/questao2/agencia.o $(OBJ_DIR)/questao2/menu.o $(OBJ_DIR)/questao2/main.o 
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel 'questao2' criado em $(BIN_DIR)] +++"
	@echo "============="

$(OBJ_DIR)/questao2/movimentacao.o: $(SRC_DIR)/questao2/movimentacao.cpp $(INC_DIR)/questao2/movimentacao.h
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJ_DIR)/questao2/conta.o: $(SRC_DIR)/questao2/conta.cpp $(INC_DIR)/questao2/conta.h
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJ_DIR)/questao2/agencia.o: $(SRC_DIR)/questao2/agencia.cpp $(INC_DIR)/questao2/agencia.h
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJ_DIR)/questao2/menu.o: $(SRC_DIR)/questao2/menu.cpp $(INC_DIR)/questao2/menu.h
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJ_DIR)/questao2/main.o: $(SRC_DIR)/questao2/main.cpp
	$(CC) -c $(CFLAGS) -o $@ $<

questao3: CFLAGS+= -I$(INC_DIR)/questao3
questao3: $(OBJ_DIR)/questao3/movimentacao.o $(OBJ_DIR)/questao3/conta.o $(OBJ_DIR)/questao3/contacorrente.o $(OBJ_DIR)/questao3/poupanca.o $(OBJ_DIR)/questao3/agencia.o $(OBJ_DIR)/questao3/menu.o $(OBJ_DIR)/questao3/main.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel 'questao3' criado em $(BIN_DIR)] +++"
	@echo "============="

$(OBJ_DIR)/questao3/movimentacao.o: $(SRC_DIR)/questao3/movimentacao.cpp  $(INC_DIR)/questao3/movimentacao.h
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJ_DIR)/questao3/conta.o: $(SRC_DIR)/questao3/conta.cpp $(INC_DIR)/questao3/conta.h
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJ_DIR)/questao3/contacorrente.o: $(SRC_DIR)/questao3/contacorrente.cpp $(INC_DIR)/questao3/contacorrente.h
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJ_DIR)/questao3/poupanca.o: $(SRC_DIR)/questao3/poupanca.cpp $(INC_DIR)/questao3/poupanca.h
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJ_DIR)/questao3/agencia.o: $(SRC_DIR)/questao3/agencia.cpp $(INC_DIR)/questao3/agencia.h
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJ_DIR)/questao3/menu.o:  $(SRC_DIR)/questao3/menu.cpp $(INC_DIR)/questao3/menu.h
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJ_DIR)/questao3/main.o: $(SRC_DIR)/questao3/main.cpp
	$(CC) -c $(CFLAGS) -o $@ $<


doxy:
	$(RM) $(DOC_DIR)/*
	doxygen -g

doc:
	doxygen

clean:
	$(RM) $(BIN_DIR)/* 
	$(RM) $(OBJ_DIR)/*