#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//funcao para limpar tela
void limpa_tela() {
    system("CLS");
}

//funcao para pausar o programa.
void pausa() {
    printf("\n\nPressione qualquer tecla para continuar...\n");
    getch();
}

void menu_residente() {
    printf("Bem-Vindo, Residente!\n\n");
    printf("[1] Marcar Presença\n");    
    printf("[2] Consultar Feedbacks\n");
    printf("[3] Dar Feedbacks\n");
    printf("[4] Quadro de Avisos\n"); //apenas visualizar
    printf("[5] Minhas Faltas\n");
    printf("[0] Sair\n");
    
}

void menu_preceptor() {
    printf("Bem-Vindo, Preceptor!\n\n");
    printf("[1] Validar Presenças\n");    
    printf("[2] Consultar Feedbacks\n");
    printf("[3] Dar Feedbacks\n");
    printf("[4] Quadro de Avisos\n"); //opcao de visualizar e inserir avisos
    printf("[0] Sair\n");
}

void menu_gestor() {
    printf("Bem-Vindo, Gestor!\n\n");
    printf("[1] Gerar Código de Cadastro\n");    
    printf("[2] Remover Usuário\n");
    printf("[3] Consultar Feedbacks\n");
    printf("[4] Quadro de Avisos\n"); //opcao de visualizar e inserir avisos
    printf("[0] Sair\n");
}

// char define_mes(int num) {
//     switch (num) {
//     case 1:
//         return "Janeiro";
//         break;
//     case 2:
//         return "Fevereiro";
//         break;
//     case 3:
//         return "Março";
//         break;
//     case 4:
//         return "Abril";
//         break;
//     case 5:
//         return "Maio";
//         break;
//     case 6:
//         return "Junho";
//         break;
//     case 7:
//         return "Julho";
//         break;
//     case 8:
//         return "Agosto";
//         break;
//     case 9:
//         return "Setembro";
//         break;
//     case 10:
//         return "Outubro";
//         break;
//     case 11:
//         return "Novembro";
//         break;
//     case 12:
//         return "Dezembro";
//         break;
//     }
// }