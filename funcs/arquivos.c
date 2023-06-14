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

char *nome_por_id(int id, char *nome_arquivo, int tipo){
    FILE *f = NULL;

    f = fopen(nome_arquivo, "r");
    
    if(f == NULL){
        printf("Erro ao abrir banco!!!\n");
        exit(1);
    }    

    int quant;
    fscanf(f, "%d", &quant);

    if(tipo == 1){
        for(int i=0; i<quant; i++){
            int id_teste;
            char cadastro[20];
            char *nome = malloc(sizeof(char)*200);

            fscanf(f, "%d, %[^,], %[^,], %*[^\n]", &id_teste, cadastro, nome);

            if(id == id_teste){
                fclose(f);
                return nome;
            }
        }        
    }else{
        for(int i=0; i<quant; i++){
            int id_teste;
            char *nome = malloc(sizeof(char)*200);

            fscanf(f, "%d, %[^,], %*[^\n]", &id_teste, nome);

            if(id == id_teste){
                fclose(f);
                return nome;
            }
        } 
    }

    fclose(f);
    return "NOME NÃO ENCONTRADO";    
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

    for(int i = 0; i<quant; i++){
        fscanf(f, "\n%d, %*[^\n]", &lista_id[i]);
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

Residente *residentes_sem_cadastro(){
    Residente *residentes_head = NULL;
    Residente *residentes_tail = NULL;

    FILE* f;

    f = fopen("bin/residente.txt", "r");

    if(f == 0){
        printf("Erro ao abrir banco!!!\n");
        exit(1);
    }   

    int quant;
    fscanf(f, "%d", &quant);

    for(int i=0; i<quant; i++){
        Residente *residente = malloc(sizeof(Residente));

        fscanf(f, "\n%d, %[^,], %[^,], %[^,], %[^,], %d, %d, %d", &residente->id, residente->cadastro, residente->nome, residente->email, residente->senha, &residente->mes, &residente->ano, &residente->residencia);

        if(strcmp(residente->cadastro, "0")==0){
            if(residentes_head == NULL){
                residentes_tail = residente;
                residentes_tail->next = NULL;
                residentes_head = residentes_tail;
            }else{
                residentes_tail->next = residente;
                residentes_tail = residentes_tail->next;
                residentes_tail->next = NULL;
            }
        }
    }

    return residentes_head;
}

Residente *residentes_com_cadastro(){
    Residente *residentes_head = NULL;
    Residente *residentes_tail = NULL;

    FILE* f;

    f = fopen("bin/residente.txt", "r");

    if(f == 0){
        printf("Erro ao abrir banco!!!\n");
        exit(1);
    }   

    int quant;
    fscanf(f, "%d", &quant);

    for(int i=0; i<quant; i++){
        Residente *residente = malloc(sizeof(Residente));

        fscanf(f, "\n%d, %[^,], %[^,], %[^,], %[^,], %d, %d, %d", &residente->id, residente->cadastro, residente->nome, residente->email, residente->senha, &residente->mes, &residente->ano, &residente->residencia);

        if(strcmp(residente->cadastro, "0")!=0){
            if(residentes_head == NULL){
                residentes_tail = residente;
                residentes_tail->next = NULL;
                residentes_head = residentes_tail;
            }else{
                residentes_tail->next = residente;
                residentes_tail = residentes_tail->next;
                residentes_tail->next = NULL;
            }
        }
    }

    return residentes_head;
}

void cadastra_residente_hospital(int id, char cadastro[20]){
    FILE* f = fopen("bin/residente.txt", "r+");

    if (f == NULL) {
        printf("Erro ao abrir banco!!!\n");
        exit(1);
    }

    int quant;
    fscanf(f, "%d", &quant);
    for (int i = 0; i < quant; i++) {
        Residente residente;
        long posicion = ftell(f);

        fscanf(f, "\n%d, %[^,], %[^,], %[^,], %[^,], %d, %d, %d", &residente.id, residente.cadastro, residente.nome, residente.email, residente.senha, &residente.mes, &residente.ano, &residente.residencia);

        if(residente.id == id){
            fseek(f, posicion, SEEK_SET);
            fprintf(f, "\n%d, %s, %s, %s, %s, %d, %d, %d", residente.id, cadastro, residente.nome, residente.email, residente.senha, residente.mes, residente.ano, residente.residencia);
        }
    }

    fclose(f);
}

Preceptor *preceptores_sem_cadastro(){
    Preceptor *preceptores_head = NULL;
    Preceptor *preceptores_tail = NULL;

    FILE* f;

    f = fopen("bin/preceptor.txt", "r");

    if(f == 0){
        printf("Erro ao abrir banco!!!\n");
        exit(1);
    }   

    int quant;
    fscanf(f, "%d", &quant);

    for(int i=0; i<quant; i++){
        Preceptor *preceptor = malloc(sizeof(Residente));

        fscanf(f, "\n%d, %[^,], %[^,], %[^,], %[^,], %d, %d, %d", &preceptor->id, preceptor->cadastro, preceptor->nome, preceptor->email, preceptor->senha, &preceptor->mes, &preceptor->ano, &preceptor->residencia);

        if(strcmp(preceptor->cadastro, "0")==0){
            if(preceptores_head == NULL){
                preceptores_tail = preceptor;
                preceptores_tail->next = NULL;
                preceptores_head = preceptores_tail;
            }else{
                preceptores_tail->next = preceptor;
                preceptores_tail = preceptores_tail->next;
                preceptores_tail->next = NULL;
            }
        }
    }

    return preceptores_head;
}

Preceptor *preceptores_com_cadastro(){
    Preceptor *preceptores_head = NULL;
    Preceptor *preceptores_tail = NULL;

    FILE* f;

    f = fopen("bin/preceptor.txt", "r");

    if(f == 0){
        printf("Erro ao abrir banco!!!\n");
        exit(1);
    }   

    int quant;
    fscanf(f, "%d", &quant);

    for(int i=0; i<quant; i++){
        Preceptor *preceptor = malloc(sizeof(Residente));

        fscanf(f, "\n%d, %[^,], %[^,], %[^,], %[^,], %d, %d, %d", &preceptor->id, preceptor->cadastro, preceptor->nome, preceptor->email, preceptor->senha, &preceptor->mes, &preceptor->ano, &preceptor->residencia);

        if(strcmp(preceptor->cadastro, "0")!=0){
            if(preceptores_head == NULL){
                preceptores_tail = preceptor;
                preceptores_tail->next = NULL;
                preceptores_head = preceptores_tail;
            }else{
                preceptores_tail->next = preceptor;
                preceptores_tail = preceptores_tail->next;
                preceptores_tail->next = NULL;
            }
        }
    }

    return preceptores_head;
}

void cadastra_preceptor_hospital(int id, char cadastro[20]){
    FILE* f = fopen("bin/preceptor.txt", "r+");

    if (f == NULL) {
        printf("Erro ao abrir banco!!!\n");
        exit(1);
    }

    int quant;
    fscanf(f, "%d", &quant);

    for (int i = 0; i < quant; i++) {
        Preceptor preceptor;
        long posicion = ftell(f);

        fscanf(f, "\n%d, %[^,], %[^,], %[^,], %[^,], %d, %d, %d", &preceptor.id, preceptor.cadastro, preceptor.nome, preceptor.email, preceptor.senha, &preceptor.mes, &preceptor.ano, &preceptor.residencia);

        if(preceptor.id == id){
            fseek(f, posicion, SEEK_SET);
            fprintf(f, "\n%d, %s, %s, %s, %s, %d, %d, %d", preceptor.id, cadastro, preceptor.nome, preceptor.email, preceptor.senha, preceptor.mes, preceptor.ano, preceptor.residencia);
        }
    }

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

Presenca *frequencias_nao_confirmadas(){
    Presenca *presenca_head = NULL;

    FILE *f = NULL;

    f = fopen("bin/frequencia.txt", "r+");

    if(f == NULL){
        printf("Erro ao abrir banco!!!\n");
        exit(1);
    }

    int quant;
    fscanf(f, "%d", &quant);

    for(int i=0; i<quant; i++){
        Presenca *nova_presenca = malloc(sizeof(Presenca));

        fscanf(f, "\n%d, %d, %d, %d, %d, %d", &nova_presenca->id_residente, &nova_presenca->nova_data.dia, &nova_presenca->nova_data.mes, &nova_presenca->nova_data.ano, &nova_presenca->frequencia, &nova_presenca->confirmacao);

        if(nova_presenca->confirmacao==0){
            if(presenca_head==NULL){
                presenca_head = nova_presenca;
                presenca_head->next = NULL;
            }else{
                nova_presenca->next = presenca_head;
                presenca_head = nova_presenca;
            }
        }
    }
    
    fclose(f);
    return presenca_head;
}

void confirmar_frequencia(Presenca* presencas_confirmadas) {
    Presenca* presenca_head = presencas_confirmadas;

    FILE* f = fopen("bin/frequencia.txt", "r");
    FILE* tempFile = fopen("bin/temp_frequencia.txt", "w");
    int vefir_linha = 0;

    if (f == NULL || tempFile == NULL) {
        printf("Erro ao abrir banco!!!\n");
        exit(1);
    }

    int quant;
    fscanf(f, "%d", &quant);
    fprintf(tempFile, "%d", quant);

    for (int i = 0; i < quant; i++) {
        Presenca ler_presencas;

        fscanf(f, "%d, %d, %d, %d, %d, %d", &ler_presencas.id_residente, &ler_presencas.nova_data.dia, &ler_presencas.nova_data.mes, &ler_presencas.nova_data.ano, &ler_presencas.frequencia, &ler_presencas.confirmacao);

        Presenca* n = presenca_head;

        while (n != NULL) {
            if (n->id_residente == ler_presencas.id_residente && n->nova_data.dia == ler_presencas.nova_data.dia &&
                n->nova_data.mes == ler_presencas.nova_data.mes && n->nova_data.ano == ler_presencas.nova_data.ano) {
                fprintf(tempFile, "\n%d, %d, %d, %d, %d, %d", n->id_residente, n->nova_data.dia, n->nova_data.mes, n->nova_data.ano, n->frequencia, n->confirmacao);
                vefir_linha = 1;
                break;
            }

            n = n->next;
        }

        if(vefir_linha==0){
            fprintf(tempFile, "\n%d, %d, %d, %d, %d, %d", ler_presencas.id_residente, ler_presencas.nova_data.dia, ler_presencas.nova_data.mes, ler_presencas.nova_data.ano, ler_presencas.frequencia, ler_presencas.confirmacao);
        }else{
            vefir_linha = 0;
        }
    }

    fclose(f);
    fclose(tempFile);

    remove("bin/frequencia.txt");
    rename("bin/temp_frequencia.txt", "bin/frequencia.txt");
}

Presenca *frequencias_residente(int id){
    Presenca *frequencias_head = NULL;

    FILE *f = NULL;

    f = fopen("bin/frequencia.txt", "r+");

    if(f == NULL){
        printf("Erro ao abrir banco!!!\n");
        exit(1);
    }

    int quant;
    fscanf(f, "%d", &quant);

    for(int i = 0; i<quant; i++){
        Presenca *nova_frequencia = malloc(sizeof(Presenca));

        fscanf(f, "\n%d, %d, %d, %d, %d, %d", &nova_frequencia->id_residente, &nova_frequencia->nova_data.dia, &nova_frequencia->nova_data.mes, &nova_frequencia->nova_data.ano, &nova_frequencia->frequencia, &nova_frequencia->confirmacao);

        if(id == nova_frequencia->id_residente){
            if(frequencias_head == NULL){
                frequencias_head = nova_frequencia;
                frequencias_head->next = NULL;
            }
            else{
                nova_frequencia->next = frequencias_head;
                frequencias_head = nova_frequencia;
            }
        }
    }

    fclose(f);
    return frequencias_head;
}

Data data_no_arquivo(){
    Data dia_arquivo;

    FILE *f = NULL;

    f = fopen("bin/frequencia.txt", "r+");

    if(f == NULL){
        printf("Erro ao abrir banco!!!\n");
        exit(1);
    }

    int quant;
    fscanf(f, "%d", &quant);

    for(int i=0; i<quant-1; i++){
        fscanf(f, "%*[^\n]");
    }

    int id;
    fscanf(f, "%d, %d, %d, %d, %*[^\n]", &id, &dia_arquivo.dia, &dia_arquivo.mes, &dia_arquivo.ano);

    fclose(f);
    return dia_arquivo;
}

void registrar_falta() {
    Data dia_atual = data_atual();
    Data dia_arquivo = data_no_arquivo();
    int quant_users = quant_usuarios("bin/residente.txt");
    int *lista_ids_residentes = ids_lista("bin/residente.txt");

    FILE *f = fopen("bin/frequencia.txt", "r+");

    if (f == NULL) {
        printf("Erro ao abrir banco!!!\n");
        exit(1);
    }

    int quant;
    fscanf(f, "%d", &quant);

    if (quant == 0) {
        fclose(f);
        return;
    }

    if (dia_atual.dia == dia_arquivo.dia && dia_atual.mes == dia_arquivo.mes && dia_atual.ano == dia_arquivo.ano) {
        fclose(f);
        return;
    }

    int lista_presentes[quant_users];
    int k = 0;

    for (int i = 0; i < quant; i++) {
        Presenca presenca_existente;
        int test = 0;

        fscanf(f, "\n%d, %d, %d, %d, %d, %d", &presenca_existente.id_residente, &presenca_existente.nova_data.dia,
               &presenca_existente.nova_data.mes, &presenca_existente.nova_data.ano, &presenca_existente.frequencia,
               &presenca_existente.confirmacao);

        for (int j = 0; j < quant_users; j++) {
            if (presenca_existente.id_residente == lista_ids_residentes[j] &&
                dia_arquivo.dia == presenca_existente.nova_data.dia &&
                dia_arquivo.mes == presenca_existente.nova_data.mes &&
                dia_arquivo.ano == presenca_existente.nova_data.ano) {
                lista_presentes[k] = presenca_existente.id_residente;
                k++;
                break;
            }
        }
    }

    int lista_faltas[quant_users];
    int z = 0;

    for (int i = 0; i < quant_users; i++) {
        int vefi2 = 0;
        for (int j = 0; j < k; j++) {
            if (lista_ids_residentes[i] == lista_presentes[j]) {
                vefi2 = 1;
                break;
            }
        }

        if (vefi2 == 0) {
            lista_faltas[z] = lista_ids_residentes[i];
            z++;
        }
    }

    fclose(f);

    FILE *f2 = fopen("bin/frequencia.txt", "r+");

    if (f2 == NULL) {
        printf("Erro ao abrir banco!!!\n");
        exit(1);
    }

    fprintf(f2, "%d", quant + z);

    fseek(f2, 0, SEEK_END);

    for (int i = 0; i < z; i++) {
        fprintf(f2, "\n%d, %d, %d, %d, %d, %d", lista_faltas[i], dia_arquivo.dia, dia_arquivo.mes,
                dia_arquivo.ano, 0, 1);
    }

    fclose(f2);
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

void feed_residente_gestao(char *texto, char *nome_arquivo) {
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
    fprintf(f, "\n%s", texto);
    fclose(f);
}

int visualizar_feed_residente(char nome_residente[200]) {
    int encontro = 0;
    char texto[10000];
    FILE *f = NULL;
    f = fopen("bin/feedback_preceptor.txt", "r");
    int quant;
    fscanf(f, "%d", &quant);
    for (int i = 0; i < quant; i++) {
        char nome_teste[200];
        fscanf(f, "%[^,], %[^\n]", nome_teste, texto);
        if ((strcmp(nome_residente, nome_teste)) == 0) {
            encontro = 1;
            break;
        }
        texto[0] = '\0';
    }  

    if (encontro == 1) {
        printf("%s", texto);
        return 1;
    } else {
        return 0;
    }

    fclose(f);
}

int visualizar_feed_preceptor(char nome_preceptor[200]) {
    int encontro = 0;
    char texto[10000];
    FILE *f = NULL;
    f = fopen("bin/feedback_residente.txt", "r");
    int quant;
    fscanf(f, "%d", &quant);
    for (int i = 0; i < quant; i++) {
        char nome_teste[200];
        fscanf(f, "%[^,], %[^\n]", nome_teste, texto);
        if ((strcmp(nome_preceptor, nome_teste)) == 0) {
            encontro = 1;
            break;
        }
        texto[0] = '\0';
    }  

    if (encontro == 1) {
        printf("%s", texto);
        return 1;
    } else {
        return 0;
    }

    fclose(f);
}

int visualizar_feed_gestor() {
    int status;
    char texto[10000];
    FILE *f = NULL;
    f = fopen("bin/feedback_residente.txt", "r");
    if (f == NULL) {
        status = 0;
    } else {
        fscanf(f, " %[^\n]", texto);
        status = 1;
    }

    if (status == 1) {
        printf("%s", texto);
        return 1;
    } else {
        return 0;
    }

    fclose(f);
} 

// Avisos

void criar_aviso(Aviso *quadro_de_avisos){

    FILE *f = NULL;

    f = fopen("bin/avisos.txt", "r+");

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
    fprintf(f, "\n");
    fprintf(f, "%s,%s,%d %d %d %d", quadro_de_avisos->titulo, quadro_de_avisos->texto, quadro_de_avisos->data_do_aviso.dia, quadro_de_avisos->data_do_aviso.mes, quadro_de_avisos->data_do_aviso.ano, count);
    fclose(f);
}

int visualizar_avisos(char *nome_do_arquivo){
    int num_avisos;
    char titulo[250];
    char texto[5000];
    Data data;
    int id_aviso;
    
    FILE *f = NULL;
    f = fopen("bin/avisos.txt", "r");
    
    if(f == NULL){
        printf("Erro ao abrir banco!!!\n");
        exit(1);
    }

    fseek(f, 0, SEEK_SET);
    fscanf(f, "%d", &num_avisos);
    printf("\n\nQuantidade de Avisos = %d\n\n", num_avisos);

    for(int i=0;i<num_avisos;i++){    
        fscanf(f, "%[^,],", titulo);
        fscanf(f, "%[^,],", texto);
        fscanf(f, "%d", &data.dia);
        fscanf(f, "%d", &data.mes);
        fscanf(f, "%d", &data.ano);
        fscanf(f, "%d", &id_aviso);

        printf("-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n");
        printf("%s\n", titulo);
        printf("\n\t%s\n", texto);
        printf("\nId: %d", id_aviso);
        printf("\nData da Publicacao: %d/%d/%d\n", data.dia, data.mes, data.ano);
        printf("\n-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n\n");
    }

    // frewind(f);

    return 0;

    fclose(f);
}

void editar_aviso(char *filename){
    int id_aviso;
    char *temp;
    char *linha;

    FILE *f = NULL;
    f = fopen("bin/avisos.txt", "r");
    
    if(f == NULL){
        printf("Erro ao abrir banco!!!\n");
        exit(1);
    }

    fseek(f, 0, SEEK_SET);

    fscanf(f, "%[^\n]\n", &linha);
    
    temp = strpbrk(linha, "\n");

    // while(temp != NULL){
    //     temp = strpbrk(temp, );
    // }
    

    printf("id aviso", id_aviso);
}