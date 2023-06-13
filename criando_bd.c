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

void adicionar_informacoes1(char filename[200], int id, char cadastro[20], char nome[200], char email[250], char senha[200], int mes, int ano, int residencia) {
    FILE *f = fopen(filename, "r+");

    if (f == NULL) {
        printf("Erro ao abrir o arquivo %s\n", filename);
        return;
    }

    int count;
    fscanf(f, "%d", &count);
    count++;
    fseek(f, 0, SEEK_SET);
    fprintf(f, "%d", count);

    fprintf(f, "\n%d, %s, %s, %s, %s, %d, %d, %d", id, cadastro, nome, email, senha, mes, ano, residencia);
    fclose(f);
}

void adicionar_informacoes2(char filename[200], int id, char nome[200], char email[250], char senha[200], int residencia) {
    FILE *f = fopen(filename, "r+");

    if (f == NULL) {
        printf("Erro ao abrir o arquivo %s\n", filename);
        return;
    }

    int count;
    fscanf(f, "%d", &count);
    count++;
    fseek(f, 0, SEEK_SET);
    fprintf(f, "%d", count);

    fprintf(f, "\n%d, %s, %s, %s, %d", id, nome, email, senha, residencia);
    fclose(f);
}


int main(void){
    criar_arquivo("bin/residente.txt");
    criar_arquivo("bin/preceptor.txt");
    criar_arquivo("bin/gestor.txt");
    criar_arquivo("bin/frequencia.txt");
    criar_arquivo("bin/avisos.txt");
    criar_arquivo("bin/feedback_residente.txt");
    criar_arquivo("bin/feedback_preceptor.txt");
    criar_arquivo("bin/feedback_gestao.txt");

    adicionar_informacoes1("bin/residente.txt", 1, "testecadastro", "Lucia Oliveira", "lucia.oli@email.com", "Lucia123", 6, 2023, 1);
    adicionar_informacoes1("bin/preceptor.txt", 2, "testecadastro", "Carlos Lacerda", "carlos.lacerda@email.com", "Carlos123", 6, 2023, 1);
    adicionar_informacoes2("bin/gestor.txt", 3, "Marcela Guerra", "marcela.guerra@email.com", "Marcela123", 3);
}