#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "frequencia.h"
#include "structs.h"
#include "geral.h"
#include "arquivos.h"

void testes_sofia(){
    Presenca presenca_test;

    presenca_test = registrar_presenca(1);

    printf("\nID RESIDENTE: %d\n", presenca_test.id_residente);
    printf("DATA: %d/%d/%d\n", presenca_test.nova_data.dia, presenca_test.nova_data.mes, presenca_test.nova_data.ano);
    printf("FREQUENCIA: %d  CONFIRMAÇÃO %d\n", presenca_test.frequencia, presenca_test.confirmacao);

    int *lista_ids = ids_lista("bin/residente.txt");

    printf("Lista Ids %d\n", lista_ids[0]);
}

Presenca registrar_presenca(int id_residente){
    Presenca regs_presenca;

    regs_presenca.id_residente = id_residente;
    regs_presenca.nova_data = data_atual();
    regs_presenca.frequencia = 1;
    regs_presenca.confirmacao = 0;

    salvar_frequencia(regs_presenca);

    return regs_presenca;
}