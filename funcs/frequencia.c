#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "frequencia.h"
#include "structs.h"
#include "geral.h"
#include "arquivos.h"
#include "ui.h"

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

    //registrar_falta();
    salvar_frequencia(regs_presenca);

    return regs_presenca;
}

void confirmar_presenca(){
    Presenca *lista_nao_confirmadas = frequencias_nao_confirmadas();

    limpa_tela();
    printf("Lista de frequencias: \n");
    exibir_frequencias_nao_confirmadas(lista_nao_confirmadas);

    int id_rest;
    printf("\nDigite o id do residente que voce deseja ver a frequencia: ");
    scanf("%d", &id_rest);

    limpa_tela();
    Presenca *presencas_confirmadas = exibir_frequencias_nao_confirmadas_do_residente(lista_nao_confirmadas, id_rest);

    confirmar_frequencia(presencas_confirmadas);
}

void exibir_frequencias_nao_confirmadas(Presenca *lista_nao_confirmadas){
    Presenca *n = lista_nao_confirmadas;

    while(n != NULL){
        char *nome_residente = nome_por_id(n->id_residente, "bin/residente.txt", 1);
        printf("ID do Residente: %d Residente: %s   Data: %d/%d/%d\n", n->id_residente, nome_residente, n->nova_data.dia, n->nova_data.mes, n->nova_data.ano);
        n = n->next;
    }
    
}

Presenca *exibir_frequencias_nao_confirmadas_do_residente(Presenca *lista_nao_confirmadas, int id){
    Presenca *n = lista_nao_confirmadas;
    Presenca *confirmadas_head = NULL;
    int count = 0;

    char *nome_residente = nome_por_id(n->id_residente, "bin/residente.txt", 1);
    printf("Residente: %s\n", nome_residente);

    while(n != NULL){
        if(n->id_residente == id){
            Presenca *nova_confirmada = malloc(sizeof(Presenca));
            int opcao_conf_pres;
            printf("Data: %d/%d/%d\n", n->nova_data.dia, n->nova_data.mes, n->nova_data.ano);
            printf("[1] - Confirmar presenca\n");
            printf("[2] - Nao estava presente\n");
            printf("Escolha uma opcao: ");   
            scanf("%d", &opcao_conf_pres);
            printf("\n");

            nova_confirmada->id_residente = n->id_residente;
            nova_confirmada->nova_data = n->nova_data;

            if(opcao_conf_pres==1){
                nova_confirmada->frequencia=1;
                nova_confirmada->confirmacao=1;
            }
            else if (opcao_conf_pres==2){
                nova_confirmada->frequencia=0;
                nova_confirmada->confirmacao=1;     
            } 
            else{
                printf("Opcao invalida, confirmacao dessa frequencia sera resetada!!!\n");
                nova_confirmada->frequencia=1;
                nova_confirmada->confirmacao=0;     
            }

            if(confirmadas_head == NULL){
                confirmadas_head = nova_confirmada;
                confirmadas_head->next = NULL;
            }   
            else{
                nova_confirmada->next = confirmadas_head;
                confirmadas_head = nova_confirmada;
            }
            break;
        }

        n = n->next;
    }

    return confirmadas_head;
}

Presenca *presencas_residente(int id){
    Presenca *residente = frequencias_residente(id);

    int presenca = 0;
    int falta = 0;
    int nao_confirmada = 0;

    Presenca *n = residente;

    while(n!=NULL){
        if(n->frequencia == 0){
            falta++;
        }
        else{
            if(n->confirmacao == 1){
                presenca++;
            }
            else{
                nao_confirmada++;
            }
        }

        n = n->next;
    }

    printf("Presencas: %d\n", presenca);
    printf("Faltas: %d\n", falta);
    printf("Nao confimadas: %d\n", nao_confirmada);

    return residente;
}

void imprimir_freuencias(Presenca *presencas_residente){
    Presenca *n = presencas_residente;

    
    char *nome_residente = nome_por_id(n->id_residente, "bin/residente.txt", 1);
    printf("Residente: %s\n", nome_residente);

    while(n!=NULL){
        printf("Data: %2d/%2d/%4d", n->nova_data.dia, n->nova_data.mes, n->nova_data.ano);

        char status[50];
        if(n->frequencia == 1 && n->confirmacao ==1){
            strcpy(status, "Presente");
        }
        else if(n->frequencia == 0){
            strcpy(status, "Falta");
        }
        else if(n->confirmacao ==0){
            strcpy(status, "Nao confirmada");
        }

        printf("  |  %s\n", status);

        n = n->next;
    }
}