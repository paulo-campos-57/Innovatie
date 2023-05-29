#ifndef __STRUCTS_LIB__
#define __STRUCTS_LIB__

struct residente{
    int id; //Numero unico de usuario
    char cadastro[20]; //Cadastro de residente no hospital
    char email[250];
    char nome[200];
    char *senha;
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


//typedef struct residente RESIDENTE;
//typedef struct preceptor PRECEPTOR;
//typedef struct gestor GESTOR;

#endif