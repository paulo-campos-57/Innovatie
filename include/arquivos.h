#ifndef __ARQUIVOS_LIB__
#define __ARQUIVOS_LIB__

#include "structs.h"

int quant_usuarios(char* nome_arquivo);
void registrar_preceptor(struct preceptor novo_precptor);
void registrar_residente(struct residente novo_residente);
void registrar_gestor(struct gestor novo_gestor);

void buscar_residente(char nome[200], char* senha, struct residente* user_residente);

#endif