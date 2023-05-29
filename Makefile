BIN     = ./bin
INCLUDE = ./include
OBJ     = ./obj
FUNCS   = ./funcs

all:
	gcc -c $(FUNCS)/cadastro.c -I $(INCLUDE) -o $(OBJ)/cadastro.o
	gcc -c $(FUNCS)/ui.c -I $(INCLUDE) -o $(OBJ)/ui.o
	gcc main.c $(OBJ)/*.o -I $(INCLUDE) -o $(BIN)/saida
	gcc $(FUNCS)/criando_arquivos.c -o $(OBJ)/criando_arquivos.o
	$(OBJ)/criando_arquivos.o
	rm $(OBJ)/criando_arquivos.o
	
run:
	$(BIN)/saida

clean:
	rm $(OBJ)/*.o
	rm $(BIN)/*
