#ifndef DESENHA_MENU_H_INCLUDED
#define DESENHA_MENU_H_INCLUDE


/* ====== CORES ======*/
char vermelho[8] = "\033[31m";
char verde[8] = "\033[32m";
char amarelo[8] = "\033[33m";
char limparCor[6] = "\033[m";


/* ====== DESENHAR MENUS ======*/
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

#endif // DESENHA_MENU_H_INCLUDED
