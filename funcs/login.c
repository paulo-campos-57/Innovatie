#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivos.h"
#include "structs.h"
#include "ui.h"

Residente login_residente(int nun){
    char nome[200];
    char senha[200];

    limpa_tela();
    getchar();
    printf("Digite seu nome de usuario: ");
    scanf("%[^\n]", nome);

    printf("\nDigite sua senha: ");
    scanf("%s", senha);

    Residente user_residente=buscar_residente(nome, senha);

    if(user_residente.id != -1){
        if(strcmp(user_residente.cadastro, "0")==0){
            printf("Voce nao esta cadastrado no sistema do hospital, fale com a gestao em caso de erro!!\n");
            exit(1);
        }
        return user_residente;
    }
    else{
        if(nun<3){
            printf("Nome de usuario ou senha não correspondem, tente novamente....\n");
            pausa();
            nun++;
            return login_residente(nun);
        }
        printf("\n\nMultiplas tentativas falhas, fale com um gestor para recuperar sua conta......\n");
        printf("\nPrograma encerrado...\n\n");
        exit(1);
    }
}

Preceptor login_preceptor(int nun){
    char nome[200];
    char senha[200];

    limpa_tela();
    getchar();
    printf("Digite seu nome de usuario: ");
    scanf("%[^\n]", nome);

    printf("\nDigite sua senha: ");
    scanf("%s", senha);

    Preceptor user_preceptor=buscar_preceptor(nome, senha);

    if(user_preceptor.id != -1){
        if(strcmp(user_preceptor.cadastro, "0")==0){
            printf("Voce nao esta cadastrado no sistema do hospital, fale com a gestao em caso de erro!!\n");
            exit(1);
        }
        return user_preceptor;
    }
    else{
        if(nun<3){
            printf("Nome de usuario ou senha não correspondem, tente novamente....\n");
            pausa();
            nun++;
            return login_preceptor(nun);
        }
        printf("\n\nMultiplas tentativas falhas, fale com um gestor para recuperar sua conta......\n");
        printf("\nPrograma encerrado...\n\n");
        exit(1);
    }
}

Gestor login_gestor(int nun){
    char nome[200];
    char senha[200];

    limpa_tela();
    getchar();
    printf("Digite seu nome de usuario: ");
    scanf("%[^\n]", nome);

    printf("\nDigite sua senha: ");
    scanf("%s", senha);

    Gestor user_gestor=buscar_gestor(nome, senha);

    if(user_gestor.id != -1){
        return user_gestor;
    }
    else{
        if(nun<3){
            printf("Nome de usuario ou senha não correspondem, tente novamente....\n");
            pausa();
            nun++;
            return login_gestor(nun);
        }
        printf("\n\nMultiplas tentativas falhas, fale com outro gestor para recuperar sua conta......\n");
        printf("\nPrograma encerrado...\n\n");
        exit(1);
    }
}