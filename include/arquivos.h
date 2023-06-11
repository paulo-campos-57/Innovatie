#ifndef __ARQUIVOS_LIB__
#define __ARQUIVOS_LIB__

#include "structs.h"

//Geral
int quant_usuarios(char* nome_arquivo);

//Cadastro
void registrar_preceptor(Preceptor novo_precptor);
void registrar_residente(Residente novo_residente);
void registrar_gestor(Gestor novo_gestor);

//Login
Residente buscar_residente(char nome[200], char senha[200]);
Preceptor buscar_preceptor(char nome[200], char senha[200]);
Gestor buscar_gestor(char nome[200], char senha[200]);

//Frequência
void salvar_frequencia(Presenca marcar_presenca);
int *ids_lista(char* nome_arquivo);

//Feedbacks
void feed_residente_precept(char *nome_precept, char *texto, char *nome_arquivo);
void feed_preceptor_resid(char *nome_precept, char *nome_res, char *texto, char *nome_arquivo);
#endif