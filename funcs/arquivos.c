#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivos.h"
#include "cadastro.h"
#include "structs.h"
#include "geral.h"


int quant_usuarios(char* nome_arquivo){
    FILE* f;

    f = fopen(nome_arquivo, "r");

    int quant;
    fscanf(f, "%d", &quant);
    fclose(f);

    return quant;
}

int *ids_lista(char* nome_arquivo){
    FILE *f = NULL;

    f = fopen(nome_arquivo, "r");
    
    if(f == 0){
        printf("Erro ao abrir banco!!!\n");
        exit(1);
    }    

    int quant;
    fscanf(f, "%d", &quant);

    int *lista_id = malloc(sizeof(int)*quant);
    char texto[50000];

    for(int i = 0; i<quant; i++){
        fscanf(f, "\n%d, %s", &lista_id[i], texto);
        printf("ID: %d\n", lista_id[i]);
    }

    fclose(f);
    return lista_id;
}

// cadastro
void registrar_preceptor(Preceptor novo_preceptor){
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
    fprintf(f, "\n%d, %s, %s, %s, %s, %d, %d, %d", id_, "0", novo_preceptor.nome, novo_preceptor.email, novo_preceptor.senha, novo_preceptor.mes, novo_preceptor.ano, novo_preceptor.residencia);
    fclose(f);
}

void registrar_residente(Residente novo_residente){
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
    fprintf(f, "\n%d, %s, %s, %s, %s, %d, %d, %d", id_, "0", novo_residente.nome, novo_residente.email, novo_residente.senha, novo_residente.mes, novo_residente.ano, novo_residente.residencia);
    fclose(f);
}

void registrar_gestor(Gestor novo_gestor){
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

Residente buscar_residente(char nome[200], char senha[200]){
    FILE *f;

    f = fopen("bin/residente.txt", "r");

    if(f == 0){
        printf("Erro ao abrir banco!!!\n");
        exit(1);
    }

    int quant;
    fscanf(f, "%d", &quant);

    for(int i = 0; i<quant; i++){
        Residente user_residente;
        fscanf(f, "\n%d, %[^,], %[^,], %[^,], %[^,], %d, %d, %d", &user_residente.id, user_residente.cadastro, user_residente.nome, user_residente.email, user_residente.senha, &user_residente.mes, &user_residente.ano, &user_residente.residencia);

        if(strcmp(user_residente.nome, nome)==0 && strcmp(user_residente.senha, senha)==0){
            fclose(f);
            return user_residente;
        }
    }  

    Residente user_residente;

    user_residente.id = -1;
    return user_residente;
    fclose(f);
}

Preceptor buscar_preceptor(char nome[200], char senha[200]){
    FILE *f;

    f = fopen("bin/preceptor.txt", "r");

    if(f == 0){
        printf("Erro ao abrir banco!!!\n");
        exit(1);
    }

    int quant;
    fscanf(f, "%d", &quant);

    for(int i = 0; i<quant; i++){
        Preceptor user_preceptor;
        fscanf(f, "\n%d, %[^,], %[^,], %[^,], %[^,], %d, %d, %d", &user_preceptor.id, user_preceptor.cadastro, user_preceptor.nome, user_preceptor.email, user_preceptor.senha, &user_preceptor.mes, &user_preceptor.ano, &user_preceptor.residencia);

        if(strcmp(user_preceptor.nome, nome)==0 && strcmp(user_preceptor.senha, senha)==0){
            fclose(f);
            return user_preceptor;
        }
    }  

    Preceptor user_preceptor;

    user_preceptor.id = -1;
    return user_preceptor;
    fclose(f);
}

Gestor buscar_gestor(char nome[200], char senha[200]){
    FILE *f;

    f = fopen("bin/gestor.txt", "r");

    if(f == 0){
        printf("Erro ao abrir banco!!!\n");
        exit(1);
    }

    int quant;
    fscanf(f, "%d", &quant);

    for(int i = 0; i<quant; i++){
        Gestor user_gestor;
        fscanf(f, "\n%d, %[^,], %[^,], %[^,], %d", &user_gestor.id, user_gestor.nome, user_gestor.email, user_gestor.senha, &user_gestor.residencia);

        if(strcmp(user_gestor.nome, nome)==0 && strcmp(user_gestor.senha, senha)==0){
            fclose(f);
            return user_gestor;
        }
    }  

    Gestor user_gestor;

    user_gestor.id = -1;
    return user_gestor;
    fclose(f);
}
// frequencia

void salvar_frequencia(Presenca marcar_presenca){
    FILE *f = NULL;

    f = fopen("bin/frequencia.txt", "r+");

    if(f == NULL){
        printf("Erro ao abrir banco!!!\n");
        exit(1);
    }

    int count;
    fscanf(f, "%d", &count);
    count++;
    fseek(f, 0, SEEK_SET);
    fprintf(f, "%d", count);

    fseek(f, 0, SEEK_END);
    fprintf(f, "\n%d, %d, %d, %d, %d, %d", marcar_presenca.id_residente, marcar_presenca.nova_data.dia, marcar_presenca.nova_data.mes, marcar_presenca.nova_data.ano, marcar_presenca.frequencia, marcar_presenca.confirmacao);
    fclose(f);
}

void salvar_falta(){
    Data dia_atual = data_atual();

}

//Feedbacks

void feed_residente_precept(char *nome_precept, char *texto, char *nome_arquivo) {
    FILE *f = NULL;

    f = fopen(nome_arquivo, "r+");

    if(f == NULL){
        printf("Erro ao abrir banco!!!\n");
        exit(1);
    }

    int count;
    fscanf(f, "%d", &count);
    count++;
    fseek(f, 0, SEEK_SET);
    fprintf(f, "%d", count);

    fseek(f, 0, SEEK_END);
    fprintf(f, "\n%s, %s", nome_precept, texto);
    fclose(f);
}

void feed_preceptor_resid(char *nome_precept, char *nome_res, char *texto, char *nome_arquivo) {
    FILE *f = NULL;

    f = fopen(nome_arquivo, "r+");

    if (f == NULL) {
        printf("Erro ao abrir banco!!!\n");
        exit(1);
    }

    int count;
    fscanf(f, "%d", &count);
    count++;
    fseek(f, 0, SEEK_SET);
    fprintf(f, "%d", count);

    fseek(f, 0, SEEK_END);
    fprintf(f, "\n%s, %s, %s", nome_precept, nome_res, texto);
    fclose(f);
}