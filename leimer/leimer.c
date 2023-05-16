#include<stdio.h>
#include<stdlib.h>
#include "func_lib.h"

struct residente{
    int id; //Numero unico de usuario
    char *cadastro; //Cadastro de residente no hospital
    char *nome;
    char *senha;
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
        printf("3 - GESTOR");
        scanf("%d", &opcoes);
        limpa_tela();

        switch (opcoes) {
            case 1:
                // Criação de novo usuário residente
                struct residente novo_residente;
                printf("Olá novo residente!\n");
                printf("Preencha suas informações para realizar o cadastro!\n\n");
                break;
            case 2:
                struct preceptor novo_preceptor;
                printf("Olá novo preceptor!\n");
                printf("Preencha suas informações para realizar o cadastro!\n");
                break;
            case 3:
                struct gestor novo_gestor;
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
