#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivos.h"
#include "cadastro.h"
#include "structs.h"


int quant_usuarios(char* nome_arquivo){
    FILE* f;

    f = fopen(nome_arquivo, "r");

    int quant;
    fscanf(f, "%d", &quant);
    fclose(f);

    return quant;
}

// cadastro
void registrar_preceptor(struct preceptor novo_preceptor){
    int id_ = new_id();
    FILE* f;

    f = fopen("bin/preceptor.txt", "r+");

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
    fprintf(f, "\n%d, %d, %s, %s, %s, %d, %d, %d", id_, 0, novo_preceptor.nome, novo_preceptor.email, novo_preceptor.senha, novo_preceptor.mes, novo_preceptor.ano, novo_preceptor.residencia);
    fclose(f);
}

void registrar_residente(struct residente novo_residente){
    int id_ = new_id();
    FILE* f;

    f = fopen("bin/residente.txt", "r+");

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
    fprintf(f, "\n%d, %d, %s, %s, %s, %d, %d, %d", id_, 000000, novo_residente.nome, novo_residente.email, novo_residente.senha, novo_residente.mes, novo_residente.ano, novo_residente.residencia);
    fclose(f);
}

void registrar_gestor(struct gestor novo_gestor){
    int id_ = new_id();
    FILE* f;

    f = fopen("bin/gestor.txt", "r+");

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
    fprintf(f, "\n%d, %s, %s, %s, %d", id_, novo_gestor.nome, novo_gestor.email, novo_gestor.senha, novo_gestor.residencia);
    fclose(f);
}

// login

void buscar_residente(char nome[200], char* senha, struct residente* user_residente){
    FILE *f;

    f = fopen("bin/residente.txt", "r");

    if(f == 0){
        printf("Erro ao abrir banco!!!\n");
        exit(1);
    }

    int quant;
    fscanf(f, "%d", &quant);

    for(int i = 0; i<quant; i++){
        fscanf(f, "\n%d, %s, %s, %s, %s, %d, %d, %d", &user_residente->id, user_residente->cadastro, user_residente->nome, user_residente->email, user_residente->senha, &user_residente->mes, &user_residente->ano, &user_residente->residencia);

        printf("\n%s - %s \n", user_residente->nome, user_residente->senha);
        if(strcmp(user_residente->nome, nome)==0 && strcmp(user_residente->senha, senha)==0){
            break;
        }
    }  

    user_residente->id = -1;  
}