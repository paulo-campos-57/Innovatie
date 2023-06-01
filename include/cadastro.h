#ifndef __CADASTRO_LIB__
#define __CADASTRO_LIB__

#include "structs.h"


int new_id();
char *senha();
int mes_de_entrada();
int residencia(int quant);
void cadastro_residente(struct residente* novo_residente);
void cadastro_preceptor(struct preceptor* novo_preceptor);
void cadastro_gestor(struct gestor* novo_gestor);

#endif