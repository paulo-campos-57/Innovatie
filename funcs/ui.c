#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivos.h"

//funcao para limpar tela
void limpa_tela() {
#ifdef __linux__
    system("clear");
#elif _WIN32
    system("CLS");
#else
    system("clear");
#endif
}

//funcao para pausar o programa.
void pausa() {
    printf("\n\nPressione ENTER para continuar...\n\n");
    getchar();
}

void menu_inicial() {
    printf("=================BOAS-VINDAS AO=================\n");
    printf(" _       ______  _____  __  __  ______  _____    \n");
    printf("| |     |  ____||_   _||  \\/  ||  ____||  __ \\   \n");
    printf("| |     | |__     | |  | \\  / || |__   | |__) |  \n");
    printf("| |     |  __|    | |  | |\\/| ||  __|  |  _  /   \n");
    printf("| |____ | |____  _| |_ | |  | || |____ | | \\ \\   \n");
    printf("|______||______||_____||_|  |_||______||_|  \\_\\  \n");

    printf("\n[1] - Fazer login\n");
    printf("[2] - Novo usuario\n");
    printf("[0] - Sair\n");
    printf("Selecione uma das opcoes e tecle ENTER: ");
}

void menu_login(){
    printf("=============== LOGIN ===============\n");
    printf("[1] - Residente\n");
    printf("[2] - Preceptor\n");
    printf("[3] - Gestor\n");
    printf("[0] - Voltar para menu\n");
    printf("Selecione uma das opcoes de login e tecle ENTER: ");
}

void menu_residente() {
    printf("Bem-Vindo, Residente!\n\n");
    printf("[1] - Marcar Presenca\n");    
    printf("[2] - Consultar Feedbacks\n");
    printf("[3] - Dar Feedbacks\n");
    printf("[4] - Quadro de Avisos\n"); //apenas visualizar
    printf("[5] - Minhas Faltas\n");
    printf("[0] - Sair\n");
    
}

void menu_preceptor() {
    printf("Bem-Vindo, Preceptor!\n\n");
    printf("[1] - Validar Presencas\n");    
    printf("[2] - Consultar Feedbacks\n");
    printf("[3] - Dar Feedbacks\n");
    printf("[4] - Quadro de Avisos\n"); //opcao de visualizar e inserir avisos
    printf("[0] - Sair\n");
}

void menu_gestor() {
    printf("Bem-Vindo, Gestor!\n\n");
    printf("[1] - Gerar Codigo de Cadastro\n");    
    printf("[2] - Remover Usuario\n");
    printf("[3] - Consultar Feedbacks\n");
    printf("[4] - Quadro de Avisos\n"); //opcao de visualizar e inserir avisos
    printf("[0] - Sair\n");
}

void menu_cadastro() {
    printf("Seja bem vindo ao Leimer!\n");
    printf("Selecione uma das opcoes para realizar o seu cadastro!\n");
    printf("[1] - RESIDENTE\n");
    printf("[2] - PRECEPTOR\n");
    printf("[3] - GESTOR\n");
    printf("[0] - SAIR\n");
}

char *define_mes(int num) {
    switch (num) {
    case 1:
        return "Janeiro";
        break;
    case 2:
        return "Fevereiro";
        break;
    case 3:
        return "Marco";
        break;
    case 4:
        return "Abril";
        break;
    case 5:
        return "Maio";
        break;
    case 6:
        return "Junho";
        break;
    case 7:
        return "Julho";
        break;
    case 8:
        return "Agosto";
        break;
    case 9:
        return "Setembro";
        break;
    case 10:
        return "Outubro";
        break;
    case 11:
        return "Novembro";
        break;
    case 12:
        return "Dezembro";
        break;
    default:
        return "Erro ao encontar o mes!!!";
        break;
    }
}

char *define_residencia(int num){
    switch(num){
        case 1:
            return "Medicina";
            break;
        case 2:
            return "Multi";
            break;
        case 3:
            return "Medicina e Multi";
            break;
        default:
            return "!!Erro ao buscar residencia!!";
            break;
    }
}

void menu_frequencia_residente(){
    printf("\nVoce pode seguir as seguintes acoes:\n");
    printf("[1] - Registrar frequencia\n");
    printf("[2] - Vizualizar historico mais detalhado\n");
    printf("[3] - Voltar para menu\n");
    printf("Selecione uma opcao: ");
}

void menu_frequencia_preceptor(){
    printf("=============== FREQUENCIA ===============\n");

    printf("\nVoce pode seguir as seguintes acoes:\n");
    printf("[1] - Confirmar frequencias\n");
    printf("[2] - Buscar historico de residente\n");
    printf("[0] - Voltar para menu\n");
    printf("Selecione uma opcao: ");
}

void lista_residentes(char *nome_arquivo){
    int quant_residentes = quant_usuarios("bin/residente.txt");
    int *lista_ids = ids_lista("bin/residente.txt");

    for(int i=0; i<quant_residentes; i++){
        char *nome = nome_por_id(lista_ids[i], "bin/residente.txt", 1);
        printf("ID: %d    NOME: %s\n", lista_ids[i], nome);
    }
}