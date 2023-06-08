#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "geral.h"
#include "structs.h"


Data data_atual(){
    struct tm *data_;

    time_t segundos;

    time(&segundos);

    data_ = localtime(&segundos);

    Data dia_atual;
    dia_atual.dia = data_->tm_mday;
    dia_atual.mes = data_->tm_mon;
    dia_atual.ano = data_->tm_year;

    return dia_atual;
};
