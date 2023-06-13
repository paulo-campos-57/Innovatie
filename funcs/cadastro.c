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
        printf("As senhas nao sao iguais, tente novamente!!!");
        free(senha_);
        free(confirmar_senha);
        return senha();
    }

}

int mes_de_entrada(){
    int mes_;

    do {
        printf("\nInforme o mes de sua entrada (em numero): ");
        scanf("%d", &mes_);
        if (mes_ > 12 || mes_ < 1) {
            printf("Opcao invalida.");
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
            printf("Opcao invalida.");
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

void cadastro_residente(Residente* novo_residente){

    printf("Ola novo residente!\n");
    printf("Preencha suas informacoes para realizar o cadastro!\n\n");
    printf("Informe o seu nome: ");
    scanf(" %[^\n]", novo_residente->nome);
    printf("\nInforme o seu e-mail institucional: ");
    scanf(" %[^\n]", novo_residente->email);
    strcpy(novo_residente->senha, senha());
    novo_residente->mes = mes_de_entrada();
    printf("\nInforme o ano de sua entrada: ");
    scanf("%d", &novo_residente->ano);
    printf("\nInforme sua residencia\n");
    novo_residente->residencia = residencia(2);
    getchar();
}

void cadastro_preceptor(Preceptor* novo_preceptor){
    printf("Ola novo preceptor!\n");
    printf("Preencha suas informacoes para realizar o cadastro!\n");
    printf("Informe o seu nome: ");
    scanf(" %[^\n]", novo_preceptor->nome);
    printf("\nInforme o seu e-mail institucional: ");
    scanf(" %[^\n]", novo_preceptor->email);
    strcpy(novo_preceptor->senha, senha());
    novo_preceptor->mes = mes_de_entrada();
    printf("\nInforme o ano de sua entrada: ");
    scanf("%d", &novo_preceptor->ano);
    printf("\nInforme a residencia a qual eh responsavel\n");
    novo_preceptor->residencia = residencia(2);
    getchar();
}

void cadastro_gestor(Gestor* novo_gestor){
    printf("Ola novo gestor!\n");
    printf("Preencha suas informacoes para realizar o cadastro!\n");
    printf("Informe o seu nome: ");
    scanf(" %[^\n]", novo_gestor->nome);
    printf("\nInforme o seu e-mail: ");
    scanf(" %[^\n]", novo_gestor->email);

    strcpy(novo_gestor->senha, senha());
    printf("\nInforme a residencia a qual eh responsavel\n");
    novo_gestor->residencia = residencia(3);
    getchar();
}

void cadastra_res_hospital(){
    Residente *res = residentes_sem_cadastro();
    printf("\n=== LISTA RESITENTES NAO CADASTRADOS ===\n");
    
    while(res != NULL){
        printf("ID: %d   Nome: %s\n", res->id, res->nome);
        res = res->next;
    }
    int id;
    printf("\nSelecione um residente pelo ID: ");
    scanf("%d", &id);

    char cadastro[20];
    printf("\nDigite o cadastro do usuario: ");
    scanf("%s", cadastro);
    getchar();

    cadastra_residente_hospital(id, cadastro);
}