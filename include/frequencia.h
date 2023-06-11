#ifndef __FREQUENCIA_LIB__
#define __FREQUENCIA_LIB__

#include "structs.h"

void testes_sofia();
Presenca registrar_presenca(int id_residente);
void confirmar_presenca();

void exibir_frequencias_nao_confirmadas(Presenca *lista_nao_confirmadas);
Presenca *exibir_frequencias_nao_confirmadas_do_residente(Presenca *lista_nao_confirmadas, int id);

#endif