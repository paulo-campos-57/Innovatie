#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include <time.h>
#include "structs.h"
#include "geral.h"
#include "cadastro.h"
#include "login.h"
#include "arquivos.h"
#include "ui.h"
#include "frequencia.h"

int main() {

    setlocale(LC_ALL, "Portuguese_Brazil");

    limpa_tela();
    int execing = true;
    int selec;
    Residente user_residente;
    Preceptor user_preceptor;
    Gestor user_gestor;
    Aviso quadro_de_avisos;

    do {
        int opcoes;
        int exec = true;
        menu_inicial();
        //testes_sofia();
        scanf("%d", &selec);
        switch (selec) {
            case 1:

                while (exec){
                    limpa_tela();
                    menu_login();
                    scanf("%d", &opcoes);
                    if(opcoes == 1){
                        user_residente = login_residente(0);
                        limpa_tela();
                        exec = false;
                        break;
                    }
                    else if(opcoes == 2){
                        user_preceptor = login_preceptor(0);
                        limpa_tela();
                        exec = false;
                        break;
                    }
                    else if(opcoes == 3){
                        user_gestor = login_gestor(0);
                        limpa_tela();
                        exec = false;
                        break;
                    }
                    else if(opcoes == 0){
                        printf("Execucao encerrada.");
                        exec = false;
                        break;
                    }
                    else{
                        printf("Opcao invalida\n");
                        pausa();
                    }                  
                }

            case 2:

                while (exec) {
                    menu_cadastro();

                    scanf("%d", &opcoes);
                    limpa_tela();
                    
                    Residente novo_residente;
                    Preceptor novo_preceptor;
                    Gestor novo_gestor;

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
                            printf("Responsavel pelas residencias de %s", define_residencia(novo_gestor.residencia));
                            registrar_gestor(novo_gestor);
                            exec = false;
                            break;
                        case 0:
                            printf("Execucao encerrada.");
                            exec = false;
                            break;
                        default:
                            printf("Opcao invalida\n");
                    }
                    pausa();
                    limpa_tela();
                }

                exec = true;

                while (exec) {
                    int op;
                    if (opcoes == 1) {
                        menu_residente();
                        printf("Selecione uma das opcoes e tecle ENTER: ");
                        scanf("%d", &op);
                        limpa_tela();
                        int feed;
                        int av;
                        char texto[10000];
                        char nome_prec[200];
                        switch (op) {
                            case 1:
                                break;
                            case 2:
                                break;
                            case 3:
                                //int feed;
                                //char texto[10000];
                                printf("Residente, todos os seus feedbacks sao anonimos, nao tenha medo de dar sua opiniao!\n");
                                do {
                                    printf("Selecione uma das opcoes de feedback.\n");
                                    printf("[1] - Feedback para preceptor\n");
                                    printf("[2] - Feedback para gestao\n");
                                    printf("[0] - Sair.\n");
                                    scanf("%d", &feed);
                                } while (feed != 1 || feed != 2 || feed != 0);
                                if (feed == 1) {
                                    //char nome_prec[200];
                                    printf("Informe o nome do preceptor que deseja deixar feedback: ");
                                    scanf(" %[^\n]", nome_prec);
                                    printf("Informe seu feedback para o preceptor %s: ", nome_prec);
                                    scanf(" %[^\n]", texto);
                                    feed_residente_precept(nome_prec, texto, "bin/feedback_residente.txt");
                                    printf("\n\nObrigado pelo seu feedback!");
                                } else if (feed == 2) {
                                    printf("Informe seu feedback para a gestao do HC: ");
                                    scanf(" %[^\n]", texto);
                                    printf("\n\nObrigado pelo seu feedback!");
                                } else {
                                    printf("Operacao encerrada.\n");
                                }
                                break; 
                            case 4: //avisos
                                do{
                                    printf("Selecione uma das opcoes do quadro de avisos\n");
                                    printf("[1] - Visualizar Quadro de Avisos\n");
                                    printf("[0] - Voltar Para o Menu Inicial\n");
                                    scanf("%d", &av);
                                }while (av != 1 || av != 0);
                                break;
                            case 5:
                                break;
                            case 0:
                                break;
                            default:
                                printf("Opcao invalida.");
                                break;
                        }
                    } else if (opcoes == 2) {
                        menu_preceptor();
                        printf("Selecione uma das opcoes e tecle ENTER: ");
                        scanf("%d", &op);
                        int av;
                        char texto[10000];
                        char nome_res[200];
                        char titulo[250];
                        char autor[150];
                        char aviso_texto[5000];
                        char data[11];
                        switch (op) {
                            case 1:
                                break;
                            case 2:
                                break;
                            case 3:
                                //char nome_res[200];
                                //char texto[10000];
                                printf("Preceptor, informe o nome do residente o qual deseja dar feedback: ");
                                scanf(" %[^\n]", nome_res);
                                printf("Informe seu feedback sobre o residente %s: ", nome_res);
                                scanf(" %[^\n]", texto);
                                feed_preceptor_resid(user_preceptor.nome, nome_res, texto, "bin/feedback_preceptor.txt");
                                printf("\n\nObrigado pelo seu feedback!");
                                break;
                            case 4: //avisos
                                do{
                                    limpa_tela();
                                    printf("Selecione uma das opcoes e tecle ENTER: ");
                                    printf("\n\n[1] - Visualizar Quadro de Avisos\n");
                                    printf("[2] - Criar Aviso\n");
                                    printf("[0] - Voltar Para o Menu Inicial\n");
                                    scanf("%d", &av);
                                    getchar();
                                }while (av > 2 || av < 0);
                                    if (av == 1){
                                            limpa_tela();
                                            printf("================== Quadro de Avisos ==================\n\n exibir todos os avisos aq");
                                            pausa();
                                            limpa_tela();
                                            break;
                                    }else if (av == 2){
                                            limpa_tela();
                                            printf("=================== Criando Aviso ===================\n");
                                            printf("\nInsira um Titulo Para o Aviso: ");
                                            scanf(" %[^\n]", &quadro_de_avisos.titulo);
                                            printf("Escreva Seu Aviso: ");
                                            scanf(" %[^\n]", &quadro_de_avisos.texto);
                                            printf("Insira a Data de Publicacao\n(Siga o formato exemplo: 01/01/2023): ");
                                            scanf(" %[^\n]", &quadro_de_avisos.data);
                                            getchar();
                                            limpa_tela();
                                            printf("====================== %s ======================\n\n", quadro_de_avisos.titulo); //titulo do aviso
                                            printf("%s\n\n", quadro_de_avisos.texto);
                                            printf("Data de Publicacao: %s\n\n", quadro_de_avisos.data);
                                            printf("================================================="); //titulo do aviso
                                            pausa();
                                            break;
                                            limpa_tela();

                                    }else{
                                        limpa_tela();
                                        break;
                                        }
                                break;
                            case 0:
                                break;
                            default:
                                printf("Opcao invalida.");
                                break;
                        }
                    } else if (opcoes == 3) {
                        menu_gestor();
                        printf("Selecione uma das opcoes e tecle ENTER: ");
                        scanf("%d", &op);
                        switch (op) {
                            case 1:
                                break;
                            case 2:
                                break;
                            case 3:
                                break;
                            case 4: //avisos
                                break;
                            case 0:
                                break;
                            default:
                                printf("Opcao invalida.");
                                break;
                        }
                    }
                }
                break;
            case 0:
                printf("Execucao encerrada.");
                execing = false;
                break;
            default:
                printf("Opcao invalida");
                break;
        }
        pausa();
        limpa_tela();
        //testes_sofia();

    } while(execing);
    
    return 0;
}
