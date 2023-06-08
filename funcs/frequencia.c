#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "frequencia.h"
#include "structs.h"
#include "geral.h"

void testes_sofia(){
    struct tm *data_atual;

    time_t segundos;

    time(&segundos);

    data_atual = localtime(&segundos);

    printf("%d / %d / %d \n", data_atual->tm_mday, data_atual->tm_mon+1, data_atual->tm_year+1900);
}

void registrar_presenca(){
    Presenca regs_presenca;



}