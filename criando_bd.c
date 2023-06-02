/*
Compilar sistema:
gcc main.c ./funcs/*.c -I include -o bin/saida.exe

Rodar sistema:
./bin/saida.exe

Criar banco de dados:
gcc criando_bd.c -o ./bin/criando_bd.exe
./bin/criando_bd.exe

Apagar banco de dados:
rm ./bin/*.txt
*/

#include <stdio.h>

void criar_arquivo(char *name){
    FILE *f = NULL;

    f = fopen(name, "r+");

    if(f == NULL){
        f = fopen(name, "w+");
        fprintf(f, "%d", 0);
        fclose(f);
    }
    else{
        printf("Arquivo %s já existe!!!\n", name);
        fclose(f);
    }
}

int main(void){
    criar_arquivo("bin/residente.txt");
    criar_arquivo("bin/preceptor.txt");
    criar_arquivo("bin/gestor.txt");
}