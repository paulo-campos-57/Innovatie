#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include "structs.h"
#include "cadastro.h"
#include "arquivos.h"
#include "ui.h"


int main() {

    setlocale(LC_ALL, "Portuguese_Brazil");

    limpa_tela();
    int exec = true;
    int opcoes;

    //menu_inicial();

    while (exec) {
        menu_cadastro();

        scanf("%d", &opcoes);
        limpa_tela();
        
        struct residente novo_residente;
        struct preceptor novo_preceptor;
        struct gestor novo_gestor;

        int aux;
        switch (opcoes) {
            case 1:
                // Cria��o de novo usu�rio residente
                /*printf("Ol� novo residente!\n");
                printf("Preencha suas informa��es para realizar o cadastro!\n\n");
                printf("Informe o seu nome: ");
                scanf(" %[^\n]", novo_residente.nome);
                printf("\nInforme o seu e-mail institucional: ");
                scanf(" %[^\n]", novo_residente.email);
                novo_residente.senha = senha();
                novo_residente.mes = mes_de_entrada();
                printf("\nInforme o ano de sua entrada: ");
                scanf("%d", &novo_residente.ano);
                *//*do {
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
                } while(aux > 2 || aux < 1);*//*

                
                novo_residente.residencia = residencia(2, "\nInforme sua resid�ncia\n[1 - Medicina]\n[2 - Multi]\n");*/
                cadastro_residente(&novo_residente);
                printf("\nCadastro Finalizado!");
                pausa();
                limpa_tela();
                printf("Nome: %s\n", novo_residente.nome);
                printf("E-mail: %s\n", novo_residente.email);
                printf("Senha: %s\n", novo_residente.senha);
                printf("Entrou em %s de %d\n", define_mes(novo_residente.mes), novo_residente.ano);
                /*if (novo_residente.residencia[0] == 1) {
                    printf("Residente de Medicina");
                } else if (novo_residente.residencia[1] == 1) {
                    printf("Residente de Multi");
                }*/
                printf("Residente de %s", define_residencia(novo_residente.residencia));
                registrar_residente(novo_residente);
                exec = false;
                break;
            case 2:
                /*printf("Ol� novo preceptor!\n");
                printf("Preencha suas informa��es para realizar o cadastro!\n");
                printf("Informe o seu nome: ");
                scanf(" %[^\n]", novo_preceptor.nome);
                printf("\nInforme o seu e-mail institucional: ");
                scanf(" %[^\n]", novo_preceptor.email);

                novo_preceptor.senha = senha();
                // PREVEN��O DE ERROS (inser��o de dados inv�lidos no campo m�s)
                novo_preceptor.mes = mes_de_entrada();
                printf("\nInforme o ano de sua entrada: ");
                scanf("%d", &novo_preceptor.ano);*/
                /*do {
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
                } while(aux > 2 || aux < 1);*/
                /*printf("\nInforme a resid�ncia a qual � respons�vel\n");
                novo_preceptor.residencia = residencia(2);*/
                cadastro_preceptor(&novo_preceptor);
                printf("\nCadastro Finalizado!");
                pausa();
                limpa_tela();
                printf("Nome: %s\n", novo_preceptor.nome);
                printf("E-mail: %s\n", novo_preceptor.email);
                printf("Senha: %s\n", novo_preceptor.senha);
                printf("Entrou em %s de %d\n", define_mes(novo_preceptor.mes), novo_preceptor.ano);
                /*if (novo_preceptor.residencia[0] == 1) {
                    printf("Preceptor de Medicina");
                } else if (novo_preceptor.residencia[1] == 1) {
                    printf("Preceptor de Multi");
                }*/
                printf("Preceptor de %s", define_residencia(novo_preceptor.residencia));
                registrar_preceptor(novo_preceptor);
                exec = false;
                break;
            case 3:
                /*printf("Ol� novo gestor!\n");
                printf("Preencha suas informa��es para realizar o cadastro!\n");
                printf("Informe o seu nome: ");
                scanf(" %[^\n]", novo_gestor.nome);
                printf("\nInforme o seu e-mail: ");
                scanf(" %[^\n]", novo_gestor.email);

                novo_gestor.senha = senha();*/
                /*do {
                    printf("\nInforme a resid�ncia a qual � respons�vel\n[1 - Medicina]\n[2 - Multi]\n[3 - Ambas]\n");
                    scanf("%d", &aux);
                    if (aux > 3 || aux < 1) {
                        printf("Op��o inv�lida");
                        pausa();
                    }
                } while(aux > 3 || aux < 1);*/
                /*printf("\nInforme a resid�ncia a qual � respons�vel\n");
                novo_gestor.residencia = residencia(3);*/
                cadastro_gestor(&novo_gestor);
                printf("\nCadastro Finalizado!");
                pausa();
                limpa_tela();
                printf("Nome: %s\n", novo_gestor.nome);
                printf("E-mail: %s\n", novo_gestor.email);
                printf("Senha: %s\n", novo_gestor.senha);
                /*if (aux == 1) {
                    printf("Respons�vel pelas resid�ncias de Medicina");
                    novo_gestor.residencia = 1;
                } else if (aux == 2) {
                    printf("Respons�vel pelas resid�ncias de Multi");
                    novo_gestor.residencia = 2;
                } else if (aux == 3) {
                    printf("Respons�vel pelas resid�ncias de Medicina e Multi");
                    novo_gestor.residencia = 3;
                }*/
                printf("Respons�vel pelas resid�ncias de de %s", define_residencia(novo_gestor.residencia));
                registrar_gestor(novo_gestor);
                exec = false;
                break;
            case 0:
                printf("Execu��o encerrada.");
                exec = false;
                break;
            default:
                printf("Op��o inv�lida\n");
        }
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
