#include<stdio.h>
#include<stdlib.h>

#define String_Max 100

int main() {
    
    char cadastro[String_Max], senha[String_Max];
    int opcoes;
    
    printf("\tMenu\n");
    printf("1 - Login\n");
    printf("2 - Cadastro\n");
    scanf("%d", &opcoes);

    switch (opcoes) {
    	
        case 1:
            printf("\tLogin\n");
            printf("Username: ");
            scanf("%s", cadastro);
            printf("\n");
            printf("Senha: ");
            scanf("%s", senha);
            break;
        
		case 2:
            printf("\tCadastro\n");
            printf("Username: ");
            scanf("%s", cadastro);
            printf("\n");
            printf("Senha: ");
            scanf("%s", senha);
            break;
        
		default:
            printf("Opcao invalida\n");
            return 1;
    }
    
    return 0;
}
