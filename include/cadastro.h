#ifndef __CADASTRO_LIB__
#define __CADASTRO_LIB__

#include "structs.h"

void ler(struct preceptor novo_precptor);
void ler2(struct residente novo_precptor);
void ler3(struct gestor novo_precptor);
char *define_mes(int num);
int new_id();
char *senha();

#endif