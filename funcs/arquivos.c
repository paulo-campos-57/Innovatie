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
    fprintf(f, "\n%d, %s, %s, %s, %s, %d, %d, %d", id_, "0", novo_preceptor.nome, novo_preceptor.email, novo_preceptor.senha, novo_preceptor.mes, novo_preceptor.ano, novo_preceptor.residencia);
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
    fprintf(f, "\n%d, %s, %s, %s, %s, %d, %d, %d", id_, "0", novo_residente.nome, novo_residente.email, novo_residente.senha, novo_residente.mes, novo_residente.ano, novo_residente.residencia);
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

struct residente buscar_residente(char nome[200], char* senha){
    FILE *f;

    f = fopen("bin/residente.txt", "r");

    if(f == 0){
        printf("Erro ao abrir banco!!!\n");
        exit(1);
    }

    int quant;
    fscanf(f, "%d", &quant);
    printf("%d\n", quant);

    for(int i = 0; i<quant; i++){
        struct residente user_residente;
        printf("Oi\n");
        fscanf(f, "\n%d, %[^,], %[^,], %[^,], %[^,], %d, %d, %d", &user_residente.id, user_residente.cadastro, user_residente.nome, user_residente.email, user_residente.senha, &user_residente.mes, &user_residente.ano, &user_residente.residencia);

        printf("\n%s - %s \n", user_residente.nome, user_residente.senha);
        if(strcmp(user_residente.nome, nome)==0 && strcmp(user_residente.senha, senha)==0){
            fclose(f);
            return user_residente;
        }
    }  

    struct residente user_residente;

    user_residente.id = -1;
    return user_residente;
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