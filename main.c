#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include <time.h>
#include "structs.h"
#include "cadastro.h"
#include "login.h"
#include "arquivos.h"
#include "ui.h"

int main() {

    setlocale(LC_ALL, "Portuguese_Brazil");

    limpa_tela();
    int execing = true;
    int selec;

    do {
        int opcoes;
        int exec = true;
        menu_inicial();
        scanf("%d", &selec);
        switch (selec) {
            case 1:
                break;
            case 2:
                login_residente();

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
                            cadastro_residente(&novo_residente);
                            printf("\nCadastro Finalizado!");
                            pausa();
                            limpa_tela();
                            printf("Nome: %s\n", novo_residente.nome);
                            printf("E-mail: %s\n", novo_residente.email);
                            printf("Senha: %s\n", novo_residente.senha);
                            printf("Entrou em %s de %d\n", define_mes(novo_residente.mes), novo_residente.ano);
                            printf("Residente de %s", define_residencia(novo_residente.residencia));
                            registrar_residente(novo_residente);
                            exec = false;
                            break;
                        case 2:
                            cadastro_preceptor(&novo_preceptor);
                            printf("\nCadastro Finalizado!");
                            pausa();
                            limpa_tela();
                            printf("Nome: %s\n", novo_preceptor.nome);
                            printf("E-mail: %s\n", novo_preceptor.email);
                            printf("Senha: %s\n", novo_preceptor.senha);
                            printf("Entrou em %s de %d\n", define_mes(novo_preceptor.mes), novo_preceptor.ano);
                            printf("Preceptor de %s", define_residencia(novo_preceptor.residencia));
                            registrar_preceptor(novo_preceptor);
                            exec = false;
                            break;
                        case 3:
                            cadastro_gestor(&novo_gestor);
                            printf("\nCadastro Finalizado!");
                            pausa();
                            limpa_tela();
                            printf("Nome: %s\n", novo_gestor.nome);
                            printf("E-mail: %s\n", novo_gestor.email);
                            printf("Senha: %s\n", novo_gestor.senha);
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

                exec = true;

                while (exec) {
                    int op;
                    if (opcoes == 1) {
                        menu_residente();
                        printf("Selecione uma das op��es e tecle ENTER: ");
                        scanf("%d", &op);
                        switch (op) {
                            case 1:
                                break;
                            case 2:
                                break;
                            case 3:
                                break;
                            case 4:
                                break;
                            case 0:
                                break;
                            default:
                                printf("Op��o inv�lida.");
                                break;
                        }
                    } else if (opcoes == 2) {
                        menu_preceptor();
                        printf("Selecione uma das op��es e tecle ENTER: ");
                        scanf("%d", &op);
                        switch (op) {
                            case 1:
                                break;
                            case 2:
                                break;
                            case 3:
                                break;
                            case 4:
                                break;
                            case 0:
                                break;
                            default:
                                printf("Op��o inv�lida.");
                                break;
                        }
                    } else if (opcoes == 3) {
                        menu_gestor();
                        printf("Selecione uma das op��es e tecle ENTER: ");
                        scanf("%d", &op);
                        switch (op) {
                            case 1:
                                break;
                            case 2:
                                break;
                            case 3:
                                break;
                            case 4:
                                break;
                            case 0:
                                break;
                            default:
                                printf("Op��o inv�lida.");
                                break;
                        }
                    }
                }
                break;
            case 0:
                printf("Execu��o encerrada.");
                execing = false;
                break;
            default:
                printf("Op��o inv�lida");
                break;
        }
        pausa();
        limpa_tela();
        //testes_sofia();

    } while(execing);
    
    return 0;
}
