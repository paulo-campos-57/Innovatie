#ifndef __ARQUIVOS_LIB__
#define __ARQUIVOS_LIB__

#include "structs.h"

//Geral
int quant_usuarios(char* nome_arquivo);
char *nome_por_id(int id, char *nome_arquivo, int tipo);

//Cadastro
void registrar_preceptor(Preceptor novo_precptor);
void registrar_residente(Residente novo_residente);
void registrar_gestor(Gestor novo_gestor);

Residente *residentes_sem_cadastro();
void cadastra_residente_hospital(int id, char cadastro[20]);
Preceptor *preceptores_sem_cadastro();
void cadastra_preceptor_hospital(int id, char cadastro[20]);

//Login
Residente buscar_residente(char nome[200], char senha[200]);
Preceptor buscar_preceptor(char nome[200], char senha[200]);
Gestor buscar_gestor(char nome[200], char senha[200]);

//Frequência
void salvar_frequencia(Presenca marcar_presenca);
Presenca *frequencias_nao_confirmadas();
void confirmar_frequencia(Presenca* prensencas_confirmadas);
int *ids_lista(char* nome_arquivo);
Presenca *frequencias_residente(int id);
void salvar_falta();
Data data_no_arquivo();
void registrar_falta();

//Feedbacks
void feed_residente_precept(char *nome_precept, char *texto, char *nome_arquivo);
void feed_preceptor_resid(char *nome_precept, char *nome_res, char *texto, char *nome_arquivo);
void visualizar_feed_residente(char nome_residente[200]);
#endif