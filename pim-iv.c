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

char telaLogin() {
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
            printf("%s=====================================\n", verde);
            printf("|    >>> Senha bem vindo(a)! <<<    |\n");
            printf("=====================================%s\n", limparCor);
            sleep(2);
            break;
        } else {
            limparTerm();
            i = 0;
            usuario[0] = '\0';
            senha[0] = '\0';
            printf("\n");
            printf("%sUsuario e/ou senha estão incorretos. Por favor, tente novamente%s", vermelho, limparCor);
            sleep(2);
        }
    }
}

char menuPrincipal() {
    limparTerm();
    printf("\n");
    printf("%s+=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+\n", verde);
    printf("|               MENU PRINCIPAL              |\n");
    printf("+=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+%s\n", limparCor);
    printf("[1] Consulta\n");
    printf("[2] Gerar relatório\n");
    printf("[3] Cadastrar empresa\n");
    printf("[4] Cadastrar colaborador\n");
    printf("%s[0] Encerrar sessão\n%s",vermelho, limparCor);
    printf("%s-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%s\n", verde, limparCor);
    printf("\n");
}

void main() {
    telaLogin();
    menuPrincipal();
    sleep(3);
}