#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "cadastro.h"
#include "arquivos.h"
#include "ui.h"

char *senha(){
    char *senha_ = (char*)malloc(sizeof(char) * 200);
    char *confirmar_senha = (char*)malloc(sizeof(char) * 200);

    printf("\nDigite uma senha: ");
    scanf(" %[^\n]", senha_);

    printf("Confirme sua senha: ");
    scanf(" %[^\n]", confirmar_senha);

    if(strcmp(senha_, confirmar_senha)==0){
        return senha_;
    }
    else{
        pausa();
        printf("As senhas não são iguais, tente novamente!!!");
        free(senha_);
        free(confirmar_senha);
        return senha();
    }

}

int mes_de_entrada(){
    int mes_;

    do {
        printf("\nInforme o mês de sua entrada (em número): ");
        scanf("%d", &mes_);
        if (mes_ > 12 || mes_ < 1) {
            printf("Opção inválida.");
            pausa();
        }
    } while(mes_ > 12 || mes_ < 1);

    return mes_;
}

int residencia(int quant){
    int residencia;
    
    for(int i = 1; i <=quant; i++){
        printf("[%d] - %s\n", i, define_residencia(i));
    }

    do {
        scanf("%d", &residencia);
        if(residencia>quant || residencia < 1){
            printf("Opção inválida.");
            pausa();
        }
    }while(residencia>quant || residencia < 1);

    return residencia;
}

int new_id(){
    int novo_id = 1;

    novo_id += quant_usuarios("bin/residente.txt");
    novo_id += quant_usuarios("bin/preceptor.txt");
    novo_id += quant_usuarios("bin/gestor.txt");

    return novo_id;
}

void cadastro_residente(struct residente* novo_residente){

    printf("Olá novo residente!\n");
    printf("Preencha suas informações para realizar o cadastro!\n\n");
    printf("Informe o seu nome: ");
    scanf(" %[^\n]", novo_residente->nome);
    printf("\nInforme o seu e-mail institucional: ");
    scanf(" %[^\n]", novo_residente->email);
    novo_residente->senha = senha();
    novo_residente->mes = mes_de_entrada();
    printf("\nInforme o ano de sua entrada: ");
    scanf("%d", &novo_residente->ano);
    printf("\nInforme sua residência\n");
    novo_residente->residencia = residencia(2);
}

void cadastro_preceptor(struct preceptor* novo_preceptor){
    printf("Olá novo preceptor!\n");
    printf("Preencha suas informações para realizar o cadastro!\n");
    printf("Informe o seu nome: ");
    scanf(" %[^\n]", novo_preceptor->nome);
    printf("\nInforme o seu e-mail institucional: ");
    scanf(" %[^\n]", novo_preceptor->email);

    novo_preceptor->senha = senha();
    novo_preceptor->mes = mes_de_entrada();
    printf("\nInforme o ano de sua entrada: ");
    scanf("%d", &novo_preceptor->ano);
    printf("\nInforme a residência a qual é responsável\n");
    novo_preceptor->residencia = residencia(2);
}

void cadastro_gestor(struct gestor* novo_gestor){
    printf("Olá novo gestor!\n");
    printf("Preencha suas informações para realizar o cadastro!\n");
    printf("Informe o seu nome: ");
    scanf(" %[^\n]", novo_gestor->nome);
    printf("\nInforme o seu e-mail: ");
    scanf(" %[^\n]", novo_gestor->email);

    novo_gestor->senha = senha();
    printf("\nInforme a residência a qual é responsável\n");
    novo_gestor->residencia = residencia(3);
}