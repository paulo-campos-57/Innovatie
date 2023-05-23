#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include "func_lib.h"

int main() {

    setlocale(LC_ALL, "Portuguese_Brazil");

    limpa_tela();
    int exec = true;
    int opcoes;

    while (exec) {
        printf("Seja bem vindo ao Leimer!\n");
        printf("Selecione uma das op��es para realizar o seu cadastro!\n");
        printf("1 - RESIDENTE\n");
        printf("2 - PRECEPTOR\n");
        printf("3 - GESTOR\n");
        printf("0 - SAIR\n");

        scanf("%d", &opcoes);
        limpa_tela();
        
        struct residente novo_residente;
        struct preceptor novo_preceptor;
        struct gestor novo_gestor;

        int aux;
        switch (opcoes) {
            case 1:
                // Cria��o de novo usu�rio residente
                printf("Ol� novo residente!\n");
                printf("Preencha suas informa��es para realizar o cadastro!\n\n");
                printf("Informe o seu nome: ");
                scanf(" %[^\n]", novo_residente.nome);
                printf("\nInforme o seu e-mail institucional: ");
                scanf(" %[^\n]", novo_residente.email);
                printf("\nDefina sua senha: ");
                scanf(" %[^\n]", novo_residente.senha);
                // PREVEN��O DE ERROS (inser��o de dados inv�lidos no campo m�s)
                do {
                    printf("\nInforme o m�s de sua entrada (em n�mero): ");
                    scanf("%d", &novo_residente.mes);
                    if (novo_residente.mes > 12 || novo_residente.mes < 1) {
                        printf("Op��o inv�lida.");
                        pausa();
                    }
                } while (novo_residente.mes > 12 || novo_residente.mes < 1);
                printf("\nInforme o ano de sua entrada: ");
                scanf("%d", &novo_residente.ano);
                do {
                    printf("\nInforme sua resid�ncia\n[1 - Medicina]\n[2 - Multi]\n");
                    scanf("%d", &aux);
                    if (aux == 1) {
                        novo_residente.residencia[0] = 1;
                    } else if (aux == 2) {
                        novo_residente.residencia[1] = 1;
                    } else {
                        printf("Op��o inv�lida");
                        pausa();
                    }
                } while(aux > 2 || aux < 1);
                printf("\nCadastro Finalizado!");
                pausa();
                limpa_tela();
                printf("Nome: %s\n", novo_residente.nome);
                printf("E-mail: %s\n", novo_residente.email);
                printf("Senha: %s\n", novo_residente.senha);
                printf("Entrou em %s de %d\n", define_mes(novo_residente.mes), novo_residente.ano);
                if (novo_residente.residencia[0] == 1) {
                    printf("Residente de Medicina");
                } else if (novo_residente.residencia[1] == 1) {
                    printf("Residente de Multi");
                }
                exec = false;
                break;
            case 2:
                printf("Ol� novo preceptor!\n");
                printf("Preencha suas informa��es para realizar o cadastro!\n");
                printf("Informe o seu nome: ");
                scanf(" %[^\n]", novo_preceptor.nome);
                printf("\nInforme o seu e-mail institucional: ");
                scanf(" %[^\n]", novo_preceptor.email);
                printf("\nDefina sua senha: ");
                scanf(" %[^\n]", novo_preceptor.senha);
                // PREVEN��O DE ERROS (inser��o de dados inv�lidos no campo m�s)
                do {
                    printf("\nInforme o m�s de sua entrada (em n�mero): ");
                    scanf("%d", &novo_preceptor.mes);
                    if (novo_preceptor.mes > 12 || novo_preceptor.mes < 1) {
                        printf("Op��o inv�lida.");
                        pausa();
                    }
                } while (novo_preceptor.mes > 12 || novo_preceptor.mes < 1);
                printf("\nInforme o ano de sua entrada: ");
                scanf("%d", &novo_preceptor.ano);
                do {
                    printf("\nInforme a resid�ncia a qual � respons�vel\n[1 - Medicina]\n[2 - Multi]\n");
                    scanf("%d", &aux);
                    if (aux == 1) {
                        novo_preceptor.residencia[0] = 1;
                    } else if (aux == 2) {
                        novo_preceptor.residencia[1] = 1;
                    } else {
                        printf("Op��o inv�lida");
                        pausa();
                    }
                } while(aux > 2 || aux < 1);
                printf("\nCadastro Finalizado!");
                pausa();
                limpa_tela();
                printf("Nome: %s\n", novo_preceptor.nome);
                printf("E-mail: %s\n", novo_preceptor.email);
                printf("Senha: %s\n", novo_preceptor.senha);
                printf("Entrou em %s de %d\n", define_mes(novo_preceptor.mes), novo_preceptor.ano);
                if (novo_preceptor.residencia[0] == 1) {
                    printf("Preceptor de Medicina");
                } else if (novo_preceptor.residencia[1] == 1) {
                    printf("Preceptor de Multi");
                }
                exec = false;
                break;
            case 3:
                printf("Ol� novo gestor!\n");
                printf("Preencha suas informa��es para realizar o cadastro!\n");
                printf("Informe o seu nome: ");
                scanf(" %[^\n]", novo_gestor.nome);
                printf("\nInforme o seu e-mail: ");
                scanf(" %[^\n]", novo_gestor.email);
                printf("\nDefina sua senha: ");
                scanf(" %[^\n]", novo_gestor.senha);
                // PREVEN��O DE ERROS (inser��o de dados inv�lidos no campo m�s)
                do {
                    printf("\nInforme a resid�ncia a qual � respons�vel\n[1 - Medicina]\n[2 - Multi]\n[3 - Ambas]\n");
                    scanf("%d", &aux);
                    if (aux > 3 || aux < 1) {
                        printf("Op��o inv�lida");
                        pausa();
                    }
                } while(aux > 3 || aux < 1);
                printf("\nCadastro Finalizado!");
                pausa();
                limpa_tela();
                printf("Nome: %s\n", novo_gestor.nome);
                printf("E-mail: %s\n", novo_gestor.email);
                printf("Senha: %s\n", novo_gestor.senha);
                if (aux == 1) {
                    printf("Respons�vel pelas resid�ncias de Medicina");
                    novo_gestor.residencia = 1;
                } else if (aux == 2) {
                    printf("Respons�vel pelas resid�ncias de Multi");
                    novo_gestor.residencia = 2;
                } else if (aux == 3) {
                    printf("Respons�vel pelas resid�ncias de Medicina e Multi");
                    novo_gestor.residencia = 3;
                }
                exec = false;
                break;
            case 0:
                printf("Execu��o encerrada.");
                exec = false;
                break;
            default:
                printf("Op��o inv�lida\n");
        }
        ler(novo_preceptor);
        pausa();
        limpa_tela();
    }

    if (opcoes == 1) {
        menu_residente();
    } else if (opcoes == 2) {
        menu_preceptor();
    } else if (opcoes == 3) {
        menu_gestor();
    }
    
    return 0;
}
