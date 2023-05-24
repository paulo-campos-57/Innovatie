#ifndef __FUNC_LIB__
#define __FUNC_LIB__

struct residente{
    int id; //Numero unico de usuario
    char cadastro[20]; //Cadastro de residente no hospital
    char email[250];
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
    char email[250];
    char nome[200];
    char senha[200];
    int mes;
    int ano;
    int residencia[2];
    struct preceptor *next;
};

struct gestor{
    int id; //Numero unico de usuario
    char email[250];
    char nome[200];
    char senha[200];
    int residencia;
    struct gestor *next;
};

void limpa_tela();
void pausa();
void menu_residente();
void menu_preceptor();
void menu_gestor();
void ler(struct preceptor novo_precptor);
void ler2(struct residente novo_precptor);
void ler3(struct gestor novo_precptor);
char *define_mes(int num);
int id();

#endif /* __FUNC_LIB__ */