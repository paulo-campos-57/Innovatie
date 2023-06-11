#ifndef __UI_LIB__
#define __UI_LIB__

void limpa_tela();
void pausa();
void menu_inicial();
void menu_login();
void menu_residente();
void menu_preceptor();
void menu_gestor();
void menu_cadastro();
char *define_mes(int num);
char *define_residencia(int num);
void menu_frequencia_residente(int presenca, int falta, int nao_confirmada);
void menu_frequencia_preceptor(int acoes);

#endif