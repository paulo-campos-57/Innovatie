#include <stdio.h>
#include <stdlib.h>
#include "func_lib.h"

//funcao para limpar tela
void limpa_tela() {
#ifdef __linux__
    // system("CLS");
#elif _WIN32
    system("CLS");
#else
    system("clear");
#endif
}

//funcao para pausar o programa.
void pausa() {
#ifdef __linux__
    // printf("------------------")
#elif _WIN32
    system("PAUSE");
#else
    printf("-----------");
#endif
}

void menu_residente() {
    printf("Bem-Vindo, Residente!\n\n");
    printf("[1] Marcar Presença\n");    
    printf("[2] Consultar Feedbacks\n");
    printf("[3] Dar Feedbacks\n");
    printf("[4] Quadro de Avisos\n"); //apenas visualizar
    printf("[5] Minhas Faltas\n");
    printf("[0] Sair\n");
    
}

void menu_preceptor() {
    printf("Bem-Vindo, Preceptor!\n\n");
    printf("[1] Validar Presenças\n");    
    printf("[2] Consultar Feedbacks\n");
    printf("[3] Dar Feedbacks\n");
    printf("[4] Quadro de Avisos\n"); //opcao de visualizar e inserir avisos
    printf("[0] Sair\n");
}

void menu_gestor() {
    printf("Bem-Vindo, Gestor!\n\n");
    printf("[1] Gerar Código de Cadastro\n");    
    printf("[2] Remover Usuário\n");
    printf("[3] Consultar Feedbacks\n");
    printf("[4] Quadro de Avisos\n"); //opcao de visualizar e inserir avisos
    printf("[0] Sair\n");
}

char *define_mes(int num) {
    switch (num) {
    case 1:
        return "Janeiro";
        break;
    case 2:
        return "Fevereiro";
        break;
    case 3:
        return "Março";
        break;
    case 4:
        return "Abril";
        break;
    case 5:
        return "Maio";
        break;
    case 6:
        return "Junho";
        break;
    case 7:
        return "Julho";
        break;
    case 8:
        return "Agosto";
        break;
    case 9:
        return "Setembro";
        break;
    case 10:
        return "Outubro";
        break;
    case 11:
        return "Novembro";
        break;
    case 12:
        return "Dezembro";
        break;
    }
}

void ler(struct preceptor novo_precptor){
    int id_ = id();
    FILE* f;

    f = fopen("preceptor.txt", "r+");

    if(f == 0){
        printf("Erro ao abrir banco!!!\n");
        exit(1);
    }    

    int count;
    fscanf(f, "%d", &count);
    count++;
    fseek(f, 0, SEEK_SET);
    fprintf(f, "%d", count);

    fseek(f, 0, SEEK_END);
    fprintf(f, "\n%d, %d, %s, %s, %s, %d, %d, %d, %d", id_, 000000, novo_precptor.nome, novo_precptor.email, novo_precptor.senha, novo_precptor.mes, novo_precptor.ano, novo_precptor.residencia[0], 000000);
    fclose(f);
}

void ler2(struct residente novo_precptor){
    int id_ = id();
    FILE* f;

    f = fopen("residente.txt", "r+");

    if(f == 0){
        printf("Erro ao abrir banco!!!\n");
        exit(1);
    }    

    int count;
    fscanf(f, "%d", &count);
    count++;
    fseek(f, 0, SEEK_SET);
    fprintf(f, "%d", count);

    fseek(f, 0, SEEK_END);
    fprintf(f, "\n%d, %d, %s, %s, %s, %d, %d, %d, %d", id_, 000000, novo_precptor.nome, novo_precptor.email, novo_precptor.senha, novo_precptor.mes, novo_precptor.ano, novo_precptor.residencia[0], 000000);
    fclose(f);
}

void ler3(struct gestor novo_precptor){
    int id_ = id();
    FILE* f;

    f = fopen("gestor.txt", "r+");

    if(f == 0){
        printf("Erro ao abrir banco!!!\n");
        exit(1);
    }    

    int count;
    fscanf(f, "%d", &count);
    count++;
    fseek(f, 0, SEEK_SET);
    fprintf(f, "%d", count);

    fseek(f, 0, SEEK_END);
    fprintf(f, "\n%d, %s, %s, %s, %d", id_, novo_precptor.nome, novo_precptor.email, novo_precptor.senha, novo_precptor.residencia);
    int id; //Numero unico de usuario
    char email[250];
    char nome[200];
    char senha[200];
    int residencia;
    fclose(f);
}


int id(){
    FILE* f_res;
    f_res = fopen("residente.txt", "r");
    int res;
    fscanf(f_res, "%d", &res);
    fclose(f_res);

    FILE* f_pre;
    f_pre = fopen("preceptor.txt", "r");
    int pre;
    fscanf(f_pre, "%d", &pre);
    fclose(f_pre);

    FILE* f_ges;
    f_ges = fopen("gestor.txt", "r");
    int ges;
    fscanf(f_ges, "%d", &ges);
    fclose(f_ges);

    return res + pre + ges;
}
