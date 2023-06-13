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
        limpa_tela();
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
                            limpa_tela();
                            printf("\nCadastro Finalizado!\n");
                            printf("O programa vai ser encerrado, entre novamente apos a confirmacao do seu gestor!\n\n");
                            printf("Nome: %s\n", novo_residente.nome);
                            printf("E-mail: %s\n", novo_residente.email);
                            printf("Senha: %s\n", novo_residente.senha);
                            printf("Entrou em %s de %d\n", define_mes(novo_residente.mes), novo_residente.ano);
                            printf("Residente de %s", define_residencia(novo_residente.residencia));
                            registrar_residente(novo_residente);
                            pausa();
                            exit(1);
                            break;
                        case 2:
                            cadastro_preceptor(&novo_preceptor);
                            limpa_tela();
                            printf("\nCadastro Finalizado!\n");
                            printf("O programa vai ser encerrado, entre novamente apos a confirmacao do seu gestor!\n\n");
                            printf("Nome: %s\n", novo_preceptor.nome);
                            printf("E-mail: %s\n", novo_preceptor.email);
                            printf("Senha: %s\n", novo_preceptor.senha);
                            printf("Entrou em %s de %d\n", define_mes(novo_preceptor.mes), novo_preceptor.ano);
                            printf("Preceptor de %s", define_residencia(novo_preceptor.residencia));
                            registrar_preceptor(novo_preceptor);
                            pausa();
                            exit(1);
                            break;
                        case 3:
                            cadastro_gestor(&novo_gestor);
                            limpa_tela();
                            printf("\nCadastro Finalizado!\n");
                            printf("O programa vai ser encerrado, entre novamente apos a confirmacao do seu gestor!\n\n");
                            printf("Nome: %s\n", novo_gestor.nome);
                            printf("E-mail: %s\n", novo_gestor.email);
                            printf("Senha: %s\n", novo_gestor.senha);
                            printf("Responsavel pelas residencias de %s", define_residencia(novo_gestor.residencia));
                            registrar_gestor(novo_gestor);
                            pausa();
                            exit(1);
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
                    break;
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
                                printf("\n=============== FREQUENCIA ===============\n");
                                Presenca *lista_presencas_residente = presencas_residente(user_residente.id);
                                int opcao_frequencia;
                                menu_frequencia_residente();
                                scanf("%d", &opcao_frequencia);
                                if(opcao_frequencia == 1){
                                    limpa_tela();
                                    Presenca presenca_registrada = registrar_presenca(user_residente.id);
                                    printf("== FREQUENCIA REGISTRADA == \n");
                                    printf("\nID RESIDENTE: %d\n", presenca_registrada.id_residente);
                                    printf("DATA: %d/%d/%d\n", presenca_registrada.nova_data.dia, presenca_registrada.nova_data.mes, presenca_registrada.nova_data.ano);
                                    pausa();
                                }
                                else if(opcao_frequencia == 2){
                                    limpa_tela();
                                    imprimir_freuencias(lista_presencas_residente);
                                }
                                else{
                                    limpa_tela();
                                }
                                break;
                            case 2:
                                printf("Olá %s", user_residente.nome);
                                if (visualizar_feed_residente(user_residente.nome) == 0) {
                                    printf("Ainda nao ha feedbacks para voce!");
                                } else {
                                    visualizar_feed_residente(user_residente.nome);
                                }
                                break;
                            case 3:
                                //int feed;
                                //char texto[10000];
                                printf("Residente, todos os seus feedbacks sao anonimos, nao tenha medo de dar sua opiniao!\n");
                                printf("Selecione uma das opcoes de feedback.\n");
                                printf("[1] - Feedback para preceptor\n");
                                printf("[2] - Feedback para gestao\n");
                                printf("[0] - Sair.\n");
                                scanf("%d", &feed);
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
                                exit(1);
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
                        int opcao_freq;
                        limpa_tela();
                        switch (op) {
                            case 1:
                                
                                menu_frequencia_preceptor();
                                scanf("%d", &opcao_freq);
                                if(opcao_freq == 1){
                                    limpa_tela();
                                    confirmar_presenca();
                                    pausa();
                                }
                                else if(opcao_freq == 2){
                                    limpa_tela();
                                    int id_recidente_opc;
                                    printf("== LISTA RESIDENTES ==\n");
                                    lista_residentes("bin/residentes.txt");
                                    printf("Selecione o residente pelo ID: ");
                                    scanf("%d", &id_recidente_opc);
                                    limpa_tela();

                                    Presenca *frequencias_residente = presencas_residente(id_recidente_opc);
                                    imprimir_freuencias(frequencias_residente);
                                    pausa();
                                    limpa_tela();
                                }
                                else{
                                    limpa_tela();
                                }
                                
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
                                    printf("\n\n[1] - Visualizar Quadro de Avisos\n");
                                    printf("[2] - Criar Aviso\n");
                                    printf("[3] - Editar Avisos\n");
                                    printf("[4] - Excluir Avisos\n");
                                    printf("[0] - Voltar Para o Menu Inicial\n\n");
                                    printf("Selecione uma das opcoes e tecle ENTER: ");
                                    scanf("%d", &av);
                                    getchar();
                                }while (av > 4 || av < 0);
                                if (av == 1){
                                        limpa_tela();
                                        printf("================== Quadro de Avisos ==================\n\n");
                                        printf("exibir todos os avisos aqui");
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
                                        quadro_de_avisos.data_do_aviso = data_atual();
                                        criar_aviso(&quadro_de_avisos);
                                        getchar();
                                        limpa_tela();
                                        printf("====================== %s ======================\n\n", quadro_de_avisos.titulo); //titulo do aviso
                                        printf("%s\n\n", quadro_de_avisos.texto);
                                        printf("Data de Publicacao: %d/%d/%d\n\n", quadro_de_avisos.data_do_aviso.dia, quadro_de_avisos.data_do_aviso.mes, quadro_de_avisos.data_do_aviso.ano);
                                        printf("================================================="); //titulo do aviso
                                        pausa();
                                        limpa_tela();
                                        break;
                                }else if (av == 3){
                                    limpa_tela();
                                    break;
                                }else if (av == 4){
                                    limpa_tela();
                                    break;
                                }else{
                                    limpa_tela();
                                    break;
                                }
                                break;
                            case 0:
                                exit(1);
                                break;
                            default:
                                printf("Opcao invalida.");
                                break;
                        }
                    } else if (opcoes == 3) {
                        menu_gestor();
                        printf("Selecione uma das opcoes e tecle ENTER: ");
                        scanf("%d", &op);
                        int opc_gest_cadastro;
                        switch (op) {
                            case 1:
                                limpa_tela();
                                printf("Qual seu tipo de usuario:\n");
                                printf("[1] - Residente\n");
                                printf("[2] - Preceptor\n");
                                printf("[0] - Voltar para menu\n");
                                printf("Selecione uma opcao: ");
                                scanf("%d", &opc_gest_cadastro);
                                limpa_tela();

                                if(opc_gest_cadastro==1){
                                    cadastra_res_hospital();
                                    pausa();
                                    limpa_tela();
                                }else if(opc_gest_cadastro==2){
                                    cadastro_pre_hospital();
                                    pausa();
                                    limpa_tela();
                                    
                                }else{
                                    limpa_tela();
                                }
                                break;
                            case 2:
                                break;
                            case 3:
                                break;
                            case 4: //avisos
                                break;
                            case 0:
                                exit(1);
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
