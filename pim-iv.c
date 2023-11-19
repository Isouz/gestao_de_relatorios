#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>

//Cores
char vermelho[8] = "\033[31m";
char verde[8] = "\033[32m";
char amarelo[8] = "\033[33m";
char azul[8] = "\033[34m";
char limparCor[6] = "\033[m";

void limparTerm() {  //Limpa o terminal com base no SO
    #ifdef _WIN32
        system("cls"); //Limpa terminal Windows
    #else
        system("clear"); //Limpa terminal Unix
    #endif
}

void linhaVazia(){
    printf("%s|                                           |%s\n", verde, limparCor);
}

void telaLogin() {
    char usrAdm[30] = "adm";
    char senAdm[30] = "adm123";
    char usuario[30];
    char senha[30];
    int i = 0;

    while (1){
        limparTerm();
        printf("\n");
        printf("%s+=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+\n", amarelo);
        printf("|                   LOGIN                   |\n");
        printf("+=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+%s\n", limparCor);
        printf("\n");
        printf("Usuario: ");
        fgets(usuario, sizeof(usuario), stdin);
        usuario[strcspn(usuario, "\n")] = '\0'; //Remover a quebra de linha (\n) do final do nome de usuário.
        printf("Senha: ");

        while (1){
            char letra = getch();
            if (letra == '\r' || letra == '\n') {   //Se o usuario apertar ENTER.
                senha[i] = '\0';
                break;
            } else if (letra == '\b') {    //Se o campo estiver vazio e o usuario apertar BACKSPACE.
                if (i > 0) {
                    i--;
                    printf("\b \b");
                } else {
                        //Se o campo de senha estiver vazio não faça nada.
                }
            } else if (i < 30) {    //Armazena a letra em "senha".
                senha[i] = letra;
                i++;
                printf("*");
            }
        }
        printf("\n");
        if (strcmp(usuario, usrAdm) == 0 && strcmp(senha, senAdm) == 0) {
            limparTerm();
            printf("\n");
            printf("%s====================================\n", verde);
            printf("|    >>> Seja bem vindo(a)! <<<    |\n");
            printf("====================================%s\n", limparCor);
            sleep(2);
            break;
        } else {
            limparTerm();
            i = 0;
            usuario[0] = '\0';
            senha[0] = '\0';
            printf("\n");
            printf("%sUsuario e/ou senha incorreto(s). Por favor, tente novamente!%s", vermelho, limparCor);
            sleep(2);
        }
    }
}

void menuPrincipal() {
    limparTerm();
    printf("\n");
    printf("%s+=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+\n", verde);
    printf("|               MENU PRINCIPAL              |\n");
    printf("+=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+%s\n", limparCor);
    linhaVazia();
    printf("%s|%s [1] Consulta                              %s|%s\n", verde, limparCor, verde, limparCor);
    linhaVazia();
    printf("%s|%s [2] Gerar relatorio                       %s|%s\n", verde, limparCor, verde, limparCor);
    linhaVazia();
    printf("%s|%s [3] Cadastrar empresa                     %s|%s\n", verde, limparCor, verde, limparCor);
    linhaVazia();
    printf("%s|%s [4] Cadastrar colaborador                 %s|%s\n", verde, limparCor, verde, limparCor);
    linhaVazia();
    printf("%s|%s [0] Encerrar sessao                       %s|%s\n",verde, vermelho, verde, limparCor);
    linhaVazia();
    printf("%s-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%s\n", verde, limparCor);
    printf("\n");
}

void main() {
    int opcao;

    //telaLogin();

    while (1) {
        menuPrincipal();
        printf("Sua opcao: ");
        scanf("%d", &opcao);

        if (opcao == 0) {
            limparTerm();
            printf("\n\n\n");
            printf("%s >>>  Encerrando...  <<<%s", vermelho, limparCor);
            sleep(1.5);
            limparTerm();
            break;
        } else if (opcao == 1){
            /* code */
        }else if (opcao == 2){
            /* code */
        }else if (opcao == 3){
            /* code */
        }else if (opcao == 4){
            /* code */
        } else {
            limparTerm();
            printf("\n\n\n");
            printf("%s >>>  Opcao invalida, tente novamente!  <<<%s", amarelo, limparCor);
            sleep(1.5);
        }
    }
}