#ifndef __ARQUIVOS_LIB__
#define __ARQUIVOS_LIB__

#include "structs.h"

int quant_usuarios(char* nome_arquivo);
void registrar_preceptor(Preceptor novo_precptor);
void registrar_residente(Residente novo_residente);
void registrar_gestor(Gestor novo_gestor);

Residente buscar_residente(char nome[200], char senha[200]);
Preceptor buscar_preceptor(char nome[200], char senha[200]);
Gestor buscar_gestor(char nome[200], char senha[200]);

void salvar_frequencia(Presenca marcar_presenca);

int *ids_lista(char* nome_arquivo);
#endif