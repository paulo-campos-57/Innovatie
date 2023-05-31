#ifndef __STRUCTS_LIB__
#define __STRUCTS_LIB__

struct residente{
    int id; //Numero unico de usuario
    char cadastro[20]; //Cadastro de residente no hospital
    char nome[200];
    char email[250];
    char *senha;
    int mes;
    int ano;
    int residencia;
    struct residente *next;
};

struct preceptor{
    int id; //Numero unico de usuario
    char cadastro[20]; //Cadastro de residente no hospital
    char nome[200];
    char email[250];
    char *senha;
    int mes;
    int ano;
    int residencia;
    struct preceptor *next;
};

struct gestor{
    int id; //Numero unico de usuario
    char nome[200];
    char email[250];
    char *senha;
    int residencia;
    struct gestor *next;
};


#endif