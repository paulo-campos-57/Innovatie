#include <stdio.h>
#include "arquivos.h"
#include "structs.h"

void login_residente(){
    struct residente user_residente;

    buscar_residente("nome", "2", &user_residente);

    if(user_residente.id != -1){
        printf("Sim\n");
    }
    else{
        printf("Não\n");
    }
}
