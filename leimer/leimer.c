#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    char *cadastro; //Cadastro de residente no hospital
    char *nome;
    char *senha;
    int mes;
    int ano;
    int residencia[2];
    struct preceptor *next;
};

struct gestor{
    int id; //Numero unico de usuario
    char *nome;
    char *senha;
    int residencia;
    struct gestor *next;
};

int main() {
    limpa_tela();
    int opcoes = - 1;

    while (opcoes != 0) {
        printf("Seja bem vindo ao Leimer!\n");
        printf("Selecione uma das opções para realizar o seu cadastro!\n");
        printf("1 - RESIDENTE\n");
        printf("2 - PRECEPTOR\n");
        printf("3 - GESTOR\n\n");
        scanf("%d", &opcoes);
        limpa_tela();
        
        struct residente novo_residente;
        struct preceptor novo_preceptor;
        struct gestor novo_gestor;

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
                pausa();
                limpa_tela();
                printf("Nome: %s\n", novo_residente.nome);
                printf("Senha: %s\n", novo_residente.senha);
                printf("Entrou em %d/%d\n\n", novo_residente.mes, novo_residente.ano);
                pausa();
                limpa_tela();
                break;
            case 2:
                printf("Olá novo preceptor!\n");
                printf("Preencha suas informações para realizar o cadastro!\n");
                break;
            case 3:
                printf("Olá novo gestor!\n");
                printf("Preencha suas informações para realizar o cadastro!\n");
                break;
            case 0:
                printf("Execução encerrada.");
                break;
            default:
                printf("Opção inválida\n");
        }
        pausa();
        limpa_tela();
    }
    
    return 0;
}
