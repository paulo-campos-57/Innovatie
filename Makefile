BIN     = ./bin
INCLUDE = ./include
OBJ     = ./obj
FUNCS   = ./funcs

all:
	gcc -c $(FUNCS)/cadastro.c -I $(INCLUDE) -o $(OBJ)/cadastro.o
	gcc -c $(FUNCS)/ui.c -I $(INCLUDE) -o $(OBJ)/ui.o
	gcc -c $(FUNCS)/arquivos.c -I $(INCLUDE) -o $(OBJ)/arquivos.o
	gcc main.c $(OBJ)/*.o -I $(INCLUDE) -o $(BIN)/saida.exe
	gcc $(FUNCS)/criando_bd.c -o $(OBJ)/criando_bd.o
	$(OBJ)/criando_bd.o
	rm $(OBJ)/criando_bd.o
	
run:
	$(BIN)/saida.exe

clean:
	rm $(OBJ)/*.o
	rm $(BIN)/*.txt
	rm $(BIN)/*.exe
