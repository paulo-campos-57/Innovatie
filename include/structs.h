#ifndef __STRUCTS_LIB__
#define __STRUCTS_LIB__

typedef struct data{
    int dia;
    int mes;
    int ano;
}Data;

typedef struct residente{
    int id; //Numero unico de usuario
    char cadastro[20]; //Cadastro de residente no hospital
    char nome[200];
    char email[250];
    char senha[200];
    int mes; // não usa struct de data porque é o de entrada e não precisa de dia
    int ano;
    int residencia;
    struct residente *next;
}Residente;

typedef struct preceptor{
    int id; //Numero unico de usuario
    char cadastro[20]; //Cadastro de residente no hospital
    char nome[200];
    char email[250];
    char senha[200];
    int mes; // não usa struct de data porque é o de entrada e não precisa de dia
    int ano;
    int residencia;
    struct preceptor *next;
}Preceptor;

typedef struct gestor{
    int id; //Numero unico de usuario
    char nome[200];
    char email[250];
    char senha[200];
    int residencia;
    struct gestor *next;
}Gestor;

typedef struct presenca{
    int id_residente;
    Data nova_data;
    int frequencia;
    int confirmacao;
    struct presenca *next;
}Presenca;

#endif