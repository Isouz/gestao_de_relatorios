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


void linhaVazia(char cor[8]){
    printf("   %s|                                           |%s\n", cor, limparCor);
}


void telaLogin() {
    char usrAdm[31] = "adm";
    char senAdm[31] = "adm123";
    char usuario[31];
    char senha[31];
    int i = 0;

    while (1){
        limparTerm();
        printf("\n");
        printf("   %s+=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+\n", amarelo);
        printf("   |                   LOGIN                   |\n");
        printf("   +=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+%s\n", limparCor);
        printf("\n");
        printf("   Usuario: ");
        fgets(usuario, sizeof(usuario), stdin);
        usuario[strcspn(usuario, "\n")] = '\0'; //Remover a quebra de linha (\n) do final do nome de usuário.
        printf("   Senha: ");

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
            printf("   %s====================================\n", verde);
            printf("   |    >>> Seja bem vindo(a)! <<<    |\n");
            printf("   ====================================%s\n", limparCor);
            sleep(2);
            break;
        } else {
            limparTerm();
            i = 0;
            usuario[0] = '\0';
            senha[0] = '\0';
            printf("\n");
            printf("   %sUsuario e/ou senha incorreto(s). Por favor, tente novamente!%s", vermelho, limparCor);
            sleep(2);
        }
    }
}


void desenhaMenuPrinc() {
    limparTerm();
    printf("\n");
    printf("   %s+=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+\n", verde);
    printf("   |               MENU PRINCIPAL              |\n");
    printf("   +=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+%s\n", limparCor);
    linhaVazia(verde);
    printf("   %s|%s [1] Relatorios                            %s|%s\n", verde, limparCor, verde, limparCor);
    linhaVazia(verde);
    printf("   %s|%s [2] Empresas                              %s|%s\n", verde, limparCor, verde, limparCor);
    linhaVazia(verde);
    printf("   %s|%s [3] Colaboradores                         %s|%s\n", verde, limparCor, verde, limparCor);
    linhaVazia(verde);
    printf("   %s|%s [0] Encerrar sessao                       %s|%s\n",verde, vermelho, verde, limparCor);
    linhaVazia(verde);
    printf("   %s-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%s\n", verde, limparCor);
    printf("\n");
}


void desenhaMenuEmpr() {
    limparTerm();
    printf("\n");
    printf("   %s+=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+\n", amarelo);
    printf("   |              MENU DE EMPRESAS             |\n");
    printf("   +=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+%s\n", limparCor);
    linhaVazia(amarelo);
    printf("   %s|%s [1] Cadastrar empresa                     %s|%s\n", amarelo, limparCor, amarelo, limparCor);
    linhaVazia(amarelo);
    printf("   %s|%s [2] Lista de empresas                     %s|%s\n", amarelo, limparCor, amarelo, limparCor);
    linhaVazia(amarelo);
    printf("   %s|%s [3] Remover empresa                       %s|%s\n", amarelo, limparCor, amarelo, limparCor);
    linhaVazia(amarelo);
    printf("   %s|%s [0] Voltar                                %s|%s\n",amarelo, amarelo, amarelo, limparCor);
    linhaVazia(amarelo);
    printf("   %s-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%s\n", amarelo, limparCor);
    printf("\n");
}


void desenhaMenuColab() {
    limparTerm();
    printf("\n");
    printf("   %s+=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+\n", amarelo);
    printf("   |           MENU DE COLABORADORES           |\n");
    printf("   +=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+%s\n", limparCor);
    linhaVazia(amarelo);
    printf("   %s|%s [1] Cadastrar usuario                     %s|%s\n", amarelo, limparCor, amarelo, limparCor);
    linhaVazia(amarelo);
    printf("   %s|%s [2] Lista de usuarios                     %s|%s\n", amarelo, limparCor, amarelo, limparCor);
    linhaVazia(amarelo);
    printf("   %s|%s [3] Remover usuario                       %s|%s\n", amarelo, limparCor, amarelo, limparCor);
    linhaVazia(amarelo);
    printf("   %s|%s [0] Voltar                                %s|%s\n",amarelo, amarelo, amarelo, limparCor);
    linhaVazia(amarelo);
    printf("   %s-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%s\n", amarelo, limparCor);
    printf("\n");
}


void desenhaMenuRelat() {
    limparTerm();
    printf("\n");
    printf("   %s+=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+\n", amarelo);
    printf("   |             MENU DE RELATORIOS            |\n");
    printf("   +=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=+%s\n", limparCor);
    linhaVazia(amarelo);
    printf("   %s|%s [1] Gerar relatorio                       %s|%s\n", amarelo, limparCor, amarelo, limparCor);
    linhaVazia(amarelo);
    printf("   %s|%s [2] Exibir/Baixar relatorio               %s|%s\n", amarelo, limparCor, amarelo, limparCor);
    linhaVazia(amarelo);
    printf("   %s|%s [3] Excluir relatorio                     %s|%s\n", amarelo, limparCor, amarelo, limparCor);
    linhaVazia(amarelo);
    printf("   %s|%s [0] Voltar                                %s|%s\n",amarelo, amarelo, amarelo, limparCor);
    linhaVazia(amarelo);
    printf("   %s-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%s\n", amarelo, limparCor);
    printf("\n");
}


int menuRelatorios() {
    int opcao;

    while (1) {
        desenhaMenuRelat();
        printf("   Sua opcao: ");
        scanf("%d", &opcao);

        if (opcao == 0) {
            limparTerm();
            break;
        } else if (opcao == 1){
            /*code*/
            sleep(2);
        }else if (opcao == 2){
            /*code*/
            sleep(2);
        }else if (opcao == 3){
            /*code*/
            sleep(2);
        } else {
            limparTerm();
            printf("\n\n\n");
            printf("%s >>>  Opcao invalida, tente novamente!  <<<%s", amarelo, limparCor);
            sleep(1.5);
            while (getchar() != '\n');  // Limpa o buffer de entrada para evitar loop infinito
        }
    }
}


int menuEmpresas() {
    int opcao;

    while (1) {
        desenhaMenuEmpr();
        printf("   Sua opcao: ");
        scanf("%d", &opcao);

        if (opcao == 0) {
            limparTerm();
            break;
        } else if (opcao == 1){
            /*code*/
            sleep(2);
        }else if (opcao == 2){
            /*code*/
            sleep(2);
        }else if (opcao == 3){
            /*code*/
            sleep(2);
        } else {
            limparTerm();
            printf("\n\n\n");
            printf("%s >>>  Opcao invalida, tente novamente!  <<<%s", amarelo, limparCor);
            sleep(1.5);
            while (getchar() != '\n');  // Limpa o buffer de entrada para evitar loop infinito
        }
    }
}


int menuColaboradores() {
    int opcao;

    while (1) {
        desenhaMenuColab();
        printf("   Sua opcao: ");
        scanf("%d", &opcao);

        if (opcao == 0) {
            limparTerm();
            break;
        } else if (opcao == 1){
            /*code*/
            sleep(2);
        }else if (opcao == 2){
            /*code*/
            sleep(2);
        }else if (opcao == 3){
            /*code*/
            sleep(2);
        } else {
            limparTerm();
            printf("\n\n\n");
            printf("%s >>>  Opcao invalida, tente novamente!  <<<%s", amarelo, limparCor);
            sleep(1.5);
            while (getchar() != '\n');  // Limpa o buffer de entrada para evitar loop infinito
        }
    }
}


int menuPrincipal() {
    int opcao;

    while (1) {
        desenhaMenuPrinc();
        printf("   Sua opcao: ");
        scanf("%d", &opcao);

        if (opcao == 0) {
            limparTerm();
            printf("\n\n\n");
            printf("%s >>>  Encerrando...  <<<%s", vermelho, limparCor);
            sleep(1.5);
            limparTerm();
            break;
        } else if (opcao == 1){
            menuRelatorios();
        } else if (opcao == 2){
            menuEmpresas();
        } else if (opcao == 3){
            menuColaboradores();
        } else {
            limparTerm();
            printf("\n\n\n");
            printf("%s >>>  Opcao invalida, tente novamente!  <<<%s", amarelo, limparCor);
            sleep(1.5);
            while (getchar() != '\n');  // Limpa o buffer de entrada para evitar loop infinito
        }
    }
}


void main() {
    //telaLogin();
    menuPrincipal();
}