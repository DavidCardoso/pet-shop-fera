# Programa Pet Fera
# Created by David Cardoso
# IMD0030 LP1 - Prof. Silvio Sampaio - BTI UFRN
# @date 10/12/2016
# @copyright (c) 2016 - All rights reserveds
#
# $@ nome do alvo (target)
# $^ nome de todos os pré-requisitos sem duplicatas
# $< nome do primeiro pré-requisito
#

# variáveis genéricas
INC_DIR = include
SRC_DIR = src
OBJ_DIR = build
LIB_DIR = lib
CC      = g++
CFLAGS  = -Wall -pedantic -std=c++11 -g -O0 -I. -I$(INC_DIR)/$(PROG_DIR)

# variáveis do programa 1
PROG 		= petfera.exe
PROG_DIR	= petfera
PROG_ARG	= ""
PROG_OBJ	=  $(OBJ_DIR)/$(PROG_DIR)/main.o $(LIB_DIR)/$(PROG_DIR)/auxiliar.so

# biblioteca dinamica
LIB_OBJ		= $(OBJ_DIR)/$(PROG_DIR)/pessoa.o $(OBJ_DIR)/$(PROG_DIR)/pessoa_funcionario.o $(OBJ_DIR)/$(PROG_DIR)/pessoa_tratador.o $(OBJ_DIR)/$(PROG_DIR)/pessoa_veterinario.o $(OBJ_DIR)/$(PROG_DIR)/animal_silvestre.o $(OBJ_DIR)/$(PROG_DIR)/animal_exotico.o $(OBJ_DIR)/$(PROG_DIR)/animal_nativo.o $(OBJ_DIR)/$(PROG_DIR)/animal.o $(OBJ_DIR)/$(PROG_DIR)/classe_ave.o $(OBJ_DIR)/$(PROG_DIR)/classe_ave_exotico.o $(OBJ_DIR)/$(PROG_DIR)/classe_ave_nativo.o $(OBJ_DIR)/$(PROG_DIR)/classe_anfibio.o $(OBJ_DIR)/$(PROG_DIR)/classe_anfibio_exotico.o $(OBJ_DIR)/$(PROG_DIR)/classe_anfibio_nativo.o $(OBJ_DIR)/$(PROG_DIR)/classe_mamifero.o $(OBJ_DIR)/$(PROG_DIR)/classe_mamifero_exotico.o $(OBJ_DIR)/$(PROG_DIR)/classe_mamifero_nativo.o $(OBJ_DIR)/$(PROG_DIR)/classe_reptil.o $(OBJ_DIR)/$(PROG_DIR)/classe_reptil_exotico.o $(OBJ_DIR)/$(PROG_DIR)/classe_reptil_nativo.o


# Define o alvo (target) para a compilação completa.
# Define os alvos "executaveis" como dependências.
# Ao final da compilação, remove os arquivos objeto.
linux: $(LIB_DIR)/$(PROG_DIR)/auxiliar.so $(PROG) 
	rm $(OBJ_DIR)/$(PROG_DIR)/*.o


# pessoa
$(OBJ_DIR)/$(PROG_DIR)/pessoa.o: $(SRC_DIR)/$(PROG_DIR)/pessoa.cpp $(INC_DIR)/$(PROG_DIR)/pessoa.h
	$(CC) -fPIC -c $(CFLAGS) -o $@ $<

# pessoa_funcionario
$(OBJ_DIR)/$(PROG_DIR)/pessoa_funcionario.o: $(SRC_DIR)/$(PROG_DIR)/pessoa_funcionario.cpp $(INC_DIR)/$(PROG_DIR)/pessoa_funcionario.h $(INC_DIR)/$(PROG_DIR)/pessoa.h
	$(CC) -fPIC -c $(CFLAGS) -o $@ $<

# pessoa_tratador
$(OBJ_DIR)/$(PROG_DIR)/pessoa_tratador.o: $(SRC_DIR)/$(PROG_DIR)/pessoa_tratador.cpp $(INC_DIR)/$(PROG_DIR)/pessoa_tratador.h $(INC_DIR)/$(PROG_DIR)/pessoa.h
	$(CC) -fPIC -c $(CFLAGS) -o $@ $<

# pessoa_veterinario
$(OBJ_DIR)/$(PROG_DIR)/pessoa_veterinario.o: $(SRC_DIR)/$(PROG_DIR)/pessoa_veterinario.cpp $(INC_DIR)/$(PROG_DIR)/pessoa_veterinario.h $(INC_DIR)/$(PROG_DIR)/pessoa.h
	$(CC) -fPIC -c $(CFLAGS) -o $@ $<


# animal_silvestre
$(OBJ_DIR)/$(PROG_DIR)/animal_silvestre.o: $(SRC_DIR)/$(PROG_DIR)/animal_silvestre.cpp $(INC_DIR)/$(PROG_DIR)/animal_silvestre.h
	$(CC) -fPIC -c $(CFLAGS) -o $@ $<

# animal_exotico
$(OBJ_DIR)/$(PROG_DIR)/animal_exotico.o: $(SRC_DIR)/$(PROG_DIR)/animal_exotico.cpp $(INC_DIR)/$(PROG_DIR)/animal_exotico.h $(INC_DIR)/$(PROG_DIR)/animal_silvestre.h
	$(CC) -fPIC -c $(CFLAGS) -o $@ $<

# animal_nativo
$(OBJ_DIR)/$(PROG_DIR)/animal_nativo.o: $(SRC_DIR)/$(PROG_DIR)/animal_nativo.cpp $(INC_DIR)/$(PROG_DIR)/animal_nativo.h $(INC_DIR)/$(PROG_DIR)/animal_silvestre.h
	$(CC) -fPIC -c $(CFLAGS) -o $@ $<


# animal
$(OBJ_DIR)/$(PROG_DIR)/animal.o: $(SRC_DIR)/$(PROG_DIR)/animal.cpp $(INC_DIR)/$(PROG_DIR)/animal.h
	$(CC) -fPIC -c $(CFLAGS) -o $@ $<


# classe_anfibio
$(OBJ_DIR)/$(PROG_DIR)/classe_anfibio.o: $(SRC_DIR)/$(PROG_DIR)/classe_anfibio.cpp $(INC_DIR)/$(PROG_DIR)/classe_anfibio.h $(INC_DIR)/$(PROG_DIR)/animal.h
	$(CC) -fPIC -c $(CFLAGS) -o $@ $<

# classe_anfibio_exotico
$(OBJ_DIR)/$(PROG_DIR)/classe_anfibio_exotico.o: $(SRC_DIR)/$(PROG_DIR)/classe_anfibio_exotico.cpp $(INC_DIR)/$(PROG_DIR)/classe_anfibio_exotico.h $(INC_DIR)/$(PROG_DIR)/classe_anfibio.h $(INC_DIR)/$(PROG_DIR)/animal_exotico.h 
	$(CC) -fPIC -c $(CFLAGS) -o $@ $<

# classe_anfibio_nativo
$(OBJ_DIR)/$(PROG_DIR)/classe_anfibio_nativo.o: $(SRC_DIR)/$(PROG_DIR)/classe_anfibio_nativo.cpp $(INC_DIR)/$(PROG_DIR)/classe_anfibio_nativo.h $(INC_DIR)/$(PROG_DIR)/classe_anfibio.h $(INC_DIR)/$(PROG_DIR)/animal_nativo.h 
	$(CC) -fPIC -c $(CFLAGS) -o $@ $<


# classe_ave
$(OBJ_DIR)/$(PROG_DIR)/classe_ave.o: $(SRC_DIR)/$(PROG_DIR)/classe_ave.cpp $(INC_DIR)/$(PROG_DIR)/classe_ave.h $(INC_DIR)/$(PROG_DIR)/animal.h
	$(CC) -fPIC -c $(CFLAGS) -o $@ $<

# classe_ave_exotico
$(OBJ_DIR)/$(PROG_DIR)/classe_ave_exotico.o: $(SRC_DIR)/$(PROG_DIR)/classe_ave_exotico.cpp $(INC_DIR)/$(PROG_DIR)/classe_ave_exotico.h $(INC_DIR)/$(PROG_DIR)/classe_ave.h $(INC_DIR)/$(PROG_DIR)/animal_exotico.h 
	$(CC) -fPIC -c $(CFLAGS) -o $@ $<

# classe_ave_nativo
$(OBJ_DIR)/$(PROG_DIR)/classe_ave_nativo.o: $(SRC_DIR)/$(PROG_DIR)/classe_ave_nativo.cpp $(INC_DIR)/$(PROG_DIR)/classe_ave_nativo.h $(INC_DIR)/$(PROG_DIR)/classe_ave.h $(INC_DIR)/$(PROG_DIR)/animal_nativo.h 
	$(CC) -fPIC -c $(CFLAGS) -o $@ $<


# classe_mamifero
$(OBJ_DIR)/$(PROG_DIR)/classe_mamifero.o: $(SRC_DIR)/$(PROG_DIR)/classe_mamifero.cpp $(INC_DIR)/$(PROG_DIR)/classe_mamifero.h $(INC_DIR)/$(PROG_DIR)/animal.h
	$(CC) -fPIC -c $(CFLAGS) -o $@ $<

# classe_mamifero_exotico
$(OBJ_DIR)/$(PROG_DIR)/classe_mamifero_exotico.o: $(SRC_DIR)/$(PROG_DIR)/classe_mamifero_exotico.cpp $(INC_DIR)/$(PROG_DIR)/classe_mamifero_exotico.h $(INC_DIR)/$(PROG_DIR)/classe_mamifero.h $(INC_DIR)/$(PROG_DIR)/animal_exotico.h 
	$(CC) -fPIC -c $(CFLAGS) -o $@ $<

# classe_mamifero_nativo
$(OBJ_DIR)/$(PROG_DIR)/classe_mamifero_nativo.o: $(SRC_DIR)/$(PROG_DIR)/classe_mamifero_nativo.cpp $(INC_DIR)/$(PROG_DIR)/classe_mamifero_nativo.h $(INC_DIR)/$(PROG_DIR)/classe_mamifero.h $(INC_DIR)/$(PROG_DIR)/animal_nativo.h 
	$(CC) -fPIC -c $(CFLAGS) -o $@ $<


# classe_reptil
$(OBJ_DIR)/$(PROG_DIR)/classe_reptil.o: $(SRC_DIR)/$(PROG_DIR)/classe_reptil.cpp $(INC_DIR)/$(PROG_DIR)/classe_reptil.h $(INC_DIR)/$(PROG_DIR)/animal.h
	$(CC) -fPIC -c $(CFLAGS) -o $@ $<

# classe_reptil_exotico
$(OBJ_DIR)/$(PROG_DIR)/classe_reptil_exotico.o: $(SRC_DIR)/$(PROG_DIR)/classe_reptil_exotico.cpp $(INC_DIR)/$(PROG_DIR)/classe_reptil_exotico.h $(INC_DIR)/$(PROG_DIR)/classe_reptil.h $(INC_DIR)/$(PROG_DIR)/animal_exotico.h 
	$(CC) -fPIC -c $(CFLAGS) -o $@ $<

# classe_reptil_nativo
$(OBJ_DIR)/$(PROG_DIR)/classe_reptil_nativo.o: $(SRC_DIR)/$(PROG_DIR)/classe_reptil_nativo.cpp $(INC_DIR)/$(PROG_DIR)/classe_reptil_nativo.h $(INC_DIR)/$(PROG_DIR)/classe_reptil.h $(INC_DIR)/$(PROG_DIR)/animal_nativo.h 
	$(CC) -fPIC -c $(CFLAGS) -o $@ $<


# auxiliar (biblioteca dinamica)
$(LIB_DIR)/$(PROG_DIR)/auxiliar.so: $(LIB_OBJ) $(SRC_DIR)/$(PROG_DIR)/auxiliar.cpp $(INC_DIR)/$(PROG_DIR)/auxiliar.h 
	$(CC) $(CFLAGS) -fPIC -c $(SRC_DIR)/$(PROG_DIR)/auxiliar.cpp -o $(OBJ_DIR)/$(PROG_DIR)/auxiliar.o
	$(CC) -shared 	-fPIC -o $@ $(LIB_OBJ) $(OBJ_DIR)/$(PROG_DIR)/auxiliar.o 
	@echo "+++ [Biblioteca dinamica $@ criada com sucesso em $(LIB_DIR)/$(PROG_DIR)/] +++"


# Alvo (target) para a construcao do executavel
# Define os arquivos objeto como dependências.
$(PROG):
	$(CC) $(CFLAGS) $(SRC_DIR)/$(PROG_DIR)/main.cpp -L$(LIB_DIR)/$(PROG_DIR) $(LIB_DIR)/$(PROG_DIR)/auxiliar.so -o $(OBJ_DIR)/$(PROG_DIR)/$@
	@echo "+++ [Executavel $(PROG) criado com sucesso em $(OBJ_DIR)/$(PROG_DIR)/] +++"


# remove arquivos e recompila tudo
rebuild: clean $(PROG) 

# remove arquivos executaveis e objetos compilados
clean:
	rm -f $(OBJ_DIR)/*/*.exe $(OBJ_DIR)/*/*.o $(LIB_DIR)/*/*.so

# remove arquivos executaveis
clean-executables:
	rm -f $(OBJ_DIR)/*/*.exe

# testa o executavel com o valgrind
valgrind:
	valgrind -v --leak-check=full --show-reachable=yes --track-origins=yes $(OBJ_DIR)/$(PROG_DIR)/$(PROG) $(PROG_ARG)

# up stack - aumenta o tamanho da pilha em sistemas UNIX
upstack:
	sudo ulimit -s unlimited

# down stack - volta o tamanho da pilha para o default em sistemas UNIX
downstack:
	sudo ulimit -s 8192

# remove arquivos de saida .csv
rmcsv:
	rm -f data/$(PROG_DIR)/*.csv

# gera documentação com o Doxygen
docs:
	doxygen

# remove documentação doxygen
rmdocs:
	rm -rf documentation/doc