#ifndef __CADASTRO_LIB__
#define __CADASTRO_LIB__

#include "structs.h"


int new_id();
char *senha();
int mes_de_entrada();
int residencia(int quant);
void cadastro_residente(Residente* novo_residente);
void cadastro_preceptor(Preceptor* novo_preceptor);
void cadastro_gestor(Gestor* novo_gestor);

void cadastra_res_hospital();

#endif