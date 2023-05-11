struct residente{
    int id; //Numero unico de usuario
    char *cadastro; //Cadastro de residente no hospital
    char *nome;
    char *senha;
    int mes;
    int ano;
    int residencia[2];
    struct residente *next;
};

struct preceptor{
    int id; //Numero unico de usuario
    char *cadastro; //Cadastro de residente no hospital
    char *nome;
    char *senha;
    int mes;
    int ano;
    int residencia[2];
    struct preceptor *next;
};

struct gestor{
    int id; //Numero unico de usuario
    char *nome;
    char *senha;
    int residencia;
    struct gestor *next;
};