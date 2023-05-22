#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include "func_lib.h"

struct residente{
    int id; //Numero unico de usuario
    char cadastro[20]; //Cadastro de residente no hospital
    char nome[200];
    char senha[200];
    int mes;
    int ano;
    int residencia[2];
    struct residente *next;
};

struct preceptor{
    int id; //Numero unico de usuario
    char cadastro[20]; //Cadastro de residente no hospital
    char nome[200];
    char senha[200];
    int mes;
    int ano;
    int residencia[2];
    struct preceptor *next;
};

struct gestor{
    int id; //Numero unico de usuario
    char nome[200];
    char senha[200];
    int residencia;
    struct gestor *next;
};

int main() {

    setlocale(LC_ALL, " ");

    limpa_tela();
    int exec = true;
    int opcoes;

    while (exec) {
        printf("Seja bem vindo ao Leimer!\n");
        printf("Selecione uma das opções para realizar o seu cadastro!\n");
        printf("1 - RESIDENTE\n");
        printf("2 - PRECEPTOR\n");
        printf("3 - GESTOR\n\n");
        printf("0 - SAIR\n");

        scanf("%d", &opcoes);
        limpa_tela();
        
        struct residente novo_residente;
        struct preceptor novo_preceptor;
        struct gestor novo_gestor;

        int aux;
        switch (opcoes) {
            case 1:
                // Criação de novo usuário residente
                printf("Olá novo residente!\n");
                printf("Preencha suas informações para realizar o cadastro!\n\n");
                printf("Informe o seu nome: ");
                scanf(" %[^\n]", novo_residente.nome);
                printf("\nDefina sua senha: ");
                scanf(" %[^\n]", novo_residente.senha);
                printf("\nInforme o mês de sua entrada (em número): ");
                scanf("%d", &novo_residente.mes);
                printf("\nInforme o ano de sua entrada: ");
                scanf("%d", &novo_residente.ano);
                printf("\nInforme sua residência\n[1 - Medicina]\n[2 - Multi]\n");
                scanf("%d", &aux);
                if (aux == 1) {
                    novo_residente.residencia[0] = 1;
                } else {
                    novo_residente.residencia[1] = 1;
                }
                printf("\nCadastro Finalizado!");
                pausa();
                limpa_tela();
                printf("Nome: %s\n", novo_residente.nome);
                printf("Senha: %s\n", novo_residente.senha);
                printf("Entrou em %d/%d\n", novo_residente.mes, novo_residente.ano);
                if (novo_residente.residencia[0] == 1) {
                    printf("Residente de Medicina");
                } else if (novo_residente.residencia[1] == 1) {
                    printf("Residente de Multi");
                };
                exec = false;
                break;
            case 2:
                printf("Olá novo preceptor!\n");
                printf("Preencha suas informações para realizar o cadastro!\n");
                printf("Informe o seu nome: ");
                scanf(" %[^\n]", novo_preceptor.nome);
                printf("\nDefina sua senha: ");
                scanf(" %[^\n]", novo_preceptor.senha);
                printf("\nInforme o mês de sua entrada (em número): ");
                scanf("%d", &novo_preceptor.mes);
                printf("\nInforme o ano de sua entrada: ");
                scanf("%d", &novo_preceptor.ano);
                printf("\nInforme a residência a qual é responsável\n[1 - Medicina]\n[2 - Multi]\n");
                scanf("%d", &aux);
                if (aux == 1) {
                    novo_preceptor.residencia[0] = 1;
                } else {
                    novo_preceptor.residencia[1] = 1;
                }
                printf("\nCadastro Finalizado!");
                pausa();
                limpa_tela();
                printf("Nome: %s\n", novo_preceptor.nome);
                printf("Senha: %s\n", novo_preceptor.senha);
                printf("Entrou em %d/%d\n", novo_preceptor.mes, novo_preceptor.ano);
                if (novo_preceptor.residencia[0] == 1) {
                    printf("Preceptor de Medicina");
                } else if (novo_preceptor.residencia[1] == 1) {
                    printf("Preceptor de Multi");
                }
                exec = false;
                break;
            case 3:
                printf("Olá novo gestor!\n");
                printf("Preencha suas informações para realizar o cadastro!\n");
                printf("Informe o seu nome: ");
                scanf(" %[^\n]", novo_gestor.nome);
                printf("\nDefina sua senha: ");
                scanf(" %[^\n]", novo_gestor.senha);
                printf("\nInforme a residência a qual é responsável\n[1 - Medicina]\n[2 - Multi]\n[3 - Ambas]\n");
                scanf("%d", &aux);
                printf("\nCadastro Finalizado!");
                pausa();
                limpa_tela();
                printf("Nome: %s", novo_gestor.nome);
                printf("Senha: %s", novo_gestor.senha);
                if (aux == 1) {
                    printf("Responsável pelas residências de Medicina");
                    novo_gestor.residencia = 1;
                } else if (aux == 2) {
                    printf("Responsável pelas residências de Multi");
                    novo_gestor.residencia = 2;
                } else if (aux == 3) {
                    printf("Responsável pelas residências de Medicina e Multi");
                    novo_gestor.residencia = 3;
                }
                exec = false;
                break;
            case 0:
                printf("Execução encerrada.");
                exec = false;
                break;
            default:
                printf("Opção inválida\n");
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
