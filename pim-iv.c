#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>
#include <ctype.h>

#define TAMANHO_MAX 81

/* ====== STRUCTS ======*/
struct colabs {
    char nome[51];
    char matricula[21];
    char usuario[31];
    char senha[31];
};

struct empresas {
    char id[6];
    char responsavel[TAMANHO_MAX];
    char cpf[16];
    char razao[TAMANHO_MAX];
    char fantasia[TAMANHO_MAX];
    char cnpj[21];
    char abertura[15];
    char fone[21];
    char email[TAMANHO_MAX];
    char logradouro[TAMANHO_MAX];
    char numero[6];
    char cep[11];
    char bairro[TAMANHO_MAX];
    char cidade[51];
    char estado[21];
};


/* ====== CORES ======*/
char vermelho[8] = "\033[31m";
char verde[8] = "\033[32m";
char amarelo[8] = "\033[33m";
char azul[8] = "\033[34m";
char limparCor[6] = "\033[m";


/* ====== FERRAMENTAS ======*/
void limparTerm() { 
    /*
    Limpa o terminal com base no Sistema Operacional.
    */
    #ifdef _WIN32
        system("cls"); //Limpa terminal Windows
    #else
        system("clear"); //Limpa terminal Unix
    #endif
}


void limparBuffer() {
    /*
    Limpa o buffer de entrada para evitar loop infinito
    */

    while (getchar() != '\n');
}


void linhaVazia(char cor[8]){
    printf("   %s|                                           |%s\n", cor, limparCor);
}


char *comparaSenhas() {
    /*
    Solicita duas senhas ao usuário e valida. Se as senhas fornecidas estiverem diferentes ele emite a informação e solicita novas senhas. Se os dados inseridos são iguais ele retorna a senha e segue o fluxo do programa.
    */

    struct colabs *colaborador;
    char senha1[31];
    char senha2[31];
    int i = 0;

    while (1) {
        limparTerm();
        printf("\n   > Defina uma senha: ");

        while (1){
            char letra = getch();
            if (letra == '\r' || letra == '\n') {   //Se o usuario apertar ENTER.
                senha1[i] = '\0';
                i = 0;
                break;
            } else if (letra == '\b') {    //Se o campo estiver vazio e o usuario apertar BACKSPACE.
                if (i > 0) {
                    i--;
                    printf("\b \b");
                } else {
                        //Se o campo de senha estiver vazio não faça nada.
                }
            } else if (i < 30) {    //Armazena a letra em "senha".
                senha1[i] = letra;
                i++;
                printf("*");
            }
        }

        printf("\n   > Confirme a senha: ");
        while (1){
            char letra = getch();
            if (letra == '\r' || letra == '\n') {   //Se o usuario apertar ENTER.
                senha2[i] = '\0';
                i = 0;
                break;
            } else if (letra == '\b') {    //Se o campo estiver vazio e o usuario apertar BACKSPACE.
                if (i > 0) {
                    i--;
                    printf("\b \b");
                } else {
                        //Se o campo de senha estiver vazio não faça nada.
                }
            } else if (i < 30) {    //Armazena a letra em "senha".
                senha2[i] = letra;
                i++;
                printf("*");
            }
        }

        if (strcmp(senha1, senha2) == 0){
            limparTerm();
            printf("\n\n   %s>>> Senha armazenada com sucesso! <<<%s", verde, limparCor);
            sleep(1.5);
            limparTerm();
            break;
        } else {
            limparTerm();
            printf("\n\n   %s>>> As senhas digitadas sao diferentes! <<<%s", amarelo, limparCor);
            sleep(2);
            senha1[0] = '\0';
            senha2[0] = '\0';
        }
    }
    char *senha = strdup(senha1);
    return senha;
}


int dadoExiste(char *formato, char *dadoProcurado, char *Arquivo) {
    /*
    Verifica se determinada informação existe dentro de determinado aquivo. 
    Usa três parametros:

    - formato: O formato em que aquela informação está no arquivo, exemplo: "Matricula: ;";
    - dadoProcurado: o que será buscado no aqruivo, exemplo: m123;
    - Arquivo: nome do arquivo em que a busca será realizada.

    Exemplo: dadoExiste(formato, colaborador.matricula, arquivo);
    Obs: necessario declarar o formato antes.
    */
    char linhaArquivo[TAMANHO_MAX];

    while (fgets(linhaArquivo, sizeof(linhaArquivo), Arquivo) != NULL) {
        linhaArquivo[strcspn(linhaArquivo, "\n")] = '\0';

        // Comparar o dado procurado com o dado na linha do arquivo
        if (strstr(linhaArquivo, formato) != NULL && strstr(linhaArquivo, dadoProcurado) != NULL) {
            rewind(Arquivo); //coloca o cursor no inicio do arquivo
            return 1;  // Se o dado foi encontrato
        }
    }
    rewind(Arquivo); //coloca o cursor no inicio do arquivo
    return 0; // Se o dado não foi encontrato
}


void inserirDadosColab() {
    /*
    Usados para inserir dados no arquivo de colaboradores
    */

    limparTerm();
    
    while(1) {
        char continuar;
        struct colabs colaborador;

        FILE *arquivo;
        arquivo = fopen("arqUsuarios.txt", "a+");

        printf("\n\n");
        if (arquivo == NULL) {
            printf("\n\n   %s>>> Houve um erro na abertura do arquivo! <<<%s\n", vermelho, limparCor);
            sleep(2);
            break;
        }
        limparBuffer();

        //solicita matricula
        while(1){
            printf("   > Matricula: ");
            fgets(colaborador.matricula, sizeof(colaborador.matricula), stdin);
            colaborador.matricula[strcspn(colaborador.matricula, "\n")] = '\0';

            char formato[TAMANHO_MAX];
            snprintf(formato, sizeof(formato), "Matricula: %s;", colaborador.matricula);

            if (dadoExiste(formato, colaborador.matricula, arquivo)) {
                printf("   %s>>> Essa matricula ja foi registrada antes! <<<.%s\n", amarelo, limparCor);
                sleep(2);
                colaborador.matricula[0] = '\0';
                limparTerm();
                printf("\n\n");
            } else {
                break;
            }
        }

        //solicita nome
        printf("\n   > Nome completo: ");
        fgets(colaborador.nome, sizeof(colaborador.nome), stdin);
        colaborador.nome[strcspn(colaborador.nome, "\n")] = '\0';

        //solicita usuario
        while(1){
            printf("   > Defina um usuario: ");
            fgets(colaborador.usuario, sizeof(colaborador.usuario), stdin);
            colaborador.usuario[strcspn(colaborador.usuario, "\n")] = '\0';

            char formato2[TAMANHO_MAX];
            snprintf(formato2, sizeof(formato2), "Usuario: %s;", colaborador.usuario);

            if (dadoExiste(formato2, colaborador.usuario, arquivo)) {
                printf("   %s>>> Esse usuario ja foi registrado antes! <<<.%s\n", amarelo, limparCor);
                sleep(2);
                colaborador.usuario[0] = '\0';
                limparTerm();
                printf("\n\n");
            } else {
                break;
            }
        }

        //solicita senha
        char *senha = comparaSenhas();
        strncpy(colaborador.senha, senha, sizeof(colaborador.senha));

        //Armazena os dados da struct no arquivo
        fprintf(arquivo, "Matricula: %s;\n", colaborador.matricula);
        fprintf(arquivo, "Nome: %s;\n", colaborador.nome);
        fprintf(arquivo, "Usuario: %s;\n", colaborador.usuario);
        fprintf(arquivo, "Senha: %s\n", colaborador.senha);
        fprintf(arquivo, "\n");
        fprintf(arquivo, "----------------------------------------------");
        fprintf(arquivo, "\n");
        
        fclose(arquivo);
        printf("\n\n   %s>>> Dados armazenados! <<<%s", verde, limparCor);
        free(senha);
        sleep(2);
        
        //Deseja continuar?
        while (1){
            limparTerm();
            printf("   Deseja cadastrar outro usuario? \n   [S] - Sim \n   [N] - Nao\n   Sua opcao: ");
            scanf("%c", &continuar);
            
            if (toupper(continuar) == 'S' || toupper(continuar) == 'N'){
                limparTerm();
                break;          
            } else {
                limparTerm();
                printf("   %s>>> Opcao invalida <<<%s", vermelho, limparCor);
                sleep(2);
                limparBuffer();
            }
        }
        if (toupper(continuar) == 'N'){
            break;
        }
    }
}


void inserirDadosEmpr() {
    /*
    Usados para inserir dados no arquivo de empresas
    */
    limparTerm();
    
    while (1){
        char continuar;
        struct empresas empresa;

        FILE *arquivo;
        arquivo = fopen("arqEmpresas.txt", "a+");

        if (arquivo == NULL) {
            printf("\n\n   %s>>> Houve um erro na abertura do arquivo! <<<%s\n", vermelho, limparCor);
            sleep(2);
            break;
        }
        limparBuffer();

        //solicita ID
        while(1){
            printf("\n\n   > ID: ");
            fgets(empresa.id, sizeof(empresa.id), stdin);
            empresa.id[strcspn(empresa.id, "\n")] = '\0';

            char formato[TAMANHO_MAX];
            snprintf(formato, sizeof(formato), "ID: %s", empresa.id);

            if (dadoExiste(formato, empresa.id, arquivo)) {
                printf("   %s>>> Esse ID ja foi registrado antes! <<<.%s\n", amarelo, limparCor);
                sleep(2);
                empresa.id[0] = '\0';
                limparTerm();
            } else {
                break;
            }
        }
            
        //solicita dados do responsavel
        printf("   > Nome completo do responsavel: ");
        fgets(empresa.responsavel, sizeof(empresa.responsavel), stdin);
        empresa.responsavel[strcspn(empresa.responsavel, "\n")] = '\0';

        printf("   > CPF do responsavel: ");
        fgets(empresa.cpf, sizeof(empresa.cpf), stdin);
        empresa.cpf[strcspn(empresa.cpf, "\n")] = '\0';

        //solicita dados da empresa;
        printf("   > Razao social: ");
        fgets(empresa.razao, sizeof(empresa.razao), stdin);
        empresa.razao[strcspn(empresa.razao, "\n")] = '\0';

        printf("   > Nome fantasia: ");
        fgets(empresa.fantasia, sizeof(empresa.fantasia), stdin);
        empresa.fantasia[strcspn(empresa.fantasia, "\n")] = '\0';
        
        //solicita o CNPJ;
        while(1){
            printf("   > CNPJ: ");

            fgets(empresa.cnpj, sizeof(empresa.cnpj), stdin);
            empresa.cnpj[strcspn(empresa.cnpj, "\n")] = '\0';

            char formato2[TAMANHO_MAX];
            snprintf(formato2, sizeof(formato2), "CNPJ: %s", empresa.cnpj);

            if (dadoExiste(formato2, empresa.cnpj, arquivo)) {
                printf("   %s>>> Esse CNPJ ja foi registrado antes! <<<.%s\n", amarelo, limparCor);
                sleep(2);
                empresa.cnpj[0] = '\0';
                limparTerm();
            } else {
                break;
            }
        }

        printf("   > Data de abertura (dd/mm/aaa): ");
        fgets(empresa.abertura, sizeof(empresa.abertura), stdin);
        empresa.abertura[strcspn(empresa.abertura, "\n")] = '\0';

        //solicita o dados de contato;
        printf("   > Fone: ");
        fgets(empresa.fone, sizeof(empresa.fone), stdin);
        empresa.fone[strcspn(empresa.fone, "\n")] = '\0';

        printf("   > E-mail: ");
        fgets(empresa.email, sizeof(empresa.email), stdin);
        empresa.email[strcspn(empresa.email, "\n")] = '\0';

        //solicita o endereço;
        printf("   > Logradouro: ");
        fgets(empresa.logradouro, sizeof(empresa.logradouro), stdin);
        empresa.logradouro[strcspn(empresa.logradouro, "\n")] = '\0';

        printf("   > Numero: ");
        fgets(empresa.numero, sizeof(empresa.numero), stdin);
        empresa.numero[strcspn(empresa.numero, "\n")] = '\0';

        printf("   > CEP: ");
        fgets(empresa.cep, sizeof(empresa.cep), stdin);
        empresa.cep[strcspn(empresa.cep, "\n")] = '\0';

        printf("   > Bairro: ");
        fgets(empresa.bairro, sizeof(empresa.bairro), stdin);
        empresa.bairro[strcspn(empresa.bairro, "\n")] = '\0';

        printf("   > Cidade: ");
        fgets(empresa.cidade, sizeof(empresa.cidade), stdin);
        empresa.cidade[strcspn(empresa.cidade, "\n")] = '\0';

        printf("   > Estado: ");
        fgets(empresa.estado, sizeof(empresa.estado), stdin);
        empresa.estado[strcspn(empresa.estado, "\n")] = '\0';

        //Armazena os dados da struct no arquivo
        fprintf(arquivo, "ID: %s;\n", empresa.id);
        fprintf(arquivo, "Resposavel: %s;\n", empresa.responsavel);
        fprintf(arquivo, "CPF: %s;\n", empresa.cpf);
        fprintf(arquivo, "Razao social: %s;\n", empresa.razao);
        fprintf(arquivo, "Nome fantasia: %s;\n", empresa.fantasia);
        fprintf(arquivo, "CNPJ: %s;\n", empresa.cnpj);
        fprintf(arquivo, "Data de abertura: %s;\n", empresa.abertura);
        fprintf(arquivo, "Fone: %s;\n", empresa.fone);
        fprintf(arquivo, "E-mail: %s;\n", empresa.email);
        fprintf(arquivo, "Logradouro: %s;\n", empresa.logradouro);
        fprintf(arquivo, "Numero: %s;\n", empresa.numero);
        fprintf(arquivo, "CEP: %s;\n", empresa.cep);
        fprintf(arquivo, "Bairro: %s;\n", empresa.bairro);
        fprintf(arquivo, "Cidade: %s;\n", empresa.cidade);
        fprintf(arquivo, "Estado: %s;\n", empresa.estado);
        fprintf(arquivo, "\n");
        fprintf(arquivo, "----------------------------------------------");
        fprintf(arquivo, "\n");
        
        fclose(arquivo);
        limparTerm();
        printf("\n\n   %s>>> Dados armazenados! <<<%s", verde, limparCor);
        sleep(2);
        
        //Deseja continuar?
        while (1){
            limparTerm();
            printf("   Deseja cadastrar outro usuario? \n   [S] - Sim \n   [N] - Nao\n   Sua opcao: ");
            scanf("%c", &continuar);
            
            if (toupper(continuar) == 'S' || toupper(continuar) == 'N'){
                limparTerm();
                break;          
            } else {
                limparTerm();
                printf("   %s>>> Opcao invalida <<<%s", vermelho, limparCor);
                sleep(2);
                limparBuffer();
            }
        }
        if (toupper(continuar) == 'N'){
            break;
        }
    }
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
            //limparBuffer();
        }
    }
}


void lerArquivo(char *Arquivo, char *textoIgnorado) {
    /*
    Lê o arquivo. 
    Usa dois paramentros: 
    
    - Arquivo: nome do arquivo que será lido;
    - TextoIgnorado: Se houver algum texto dentro do arquivo que não deve ser lido inserimos neste parametro. Caso não seja necessario ignorar algum texto, basta usar aspas vazias, exemplo: lerArquivo("arqEmpresas.txt","");
    */
    limparTerm();

    FILE *arquivo;
    arquivo = fopen(Arquivo, "r");

    if (arquivo == NULL) {
        printf("\n\n   %s>>> Houve um erro na abertura do arquivo! <<<%s\n", vermelho, limparCor);
        sleep(2);
    } else {
        char linha[TAMANHO_MAX];

        while (fgets(linha, sizeof(linha), arquivo) != NULL) {
            if(strncmp(linha, textoIgnorado, 7) == 0) {
                continue;
            } else {
                printf("%s", linha);
            }
        }

        fclose(arquivo);

        printf("\n\n   %s> ", verde);
        system("pause");
        printf("%s", limparCor);
        limparTerm();
    }
}


void excluirDados(char *Arquivo, int *quantidadeLinhas, char *referencia) {
	/*
    Exclui dados do arquivo, utiliza três parâmetros:

    - nome do arquivo; 
    - a quantidade de linhas que será excluida; 
    - referência ("Matricula: ", "ID: ").

    Exemplo: excluirDados("arqUsuarios.txt", 5, "Matricula");
    */

    limparTerm();

    FILE *arquivo;
    arquivo = fopen(Arquivo, "r");
    FILE *temp;
    temp = fopen("temp.txt", "w");

    if (arquivo == NULL || temp == NULL) {
        printf("\n\n   %s>>> Houve um erro na abertura do arquivo! <<<%s\n", vermelho, limparCor);
        sleep(2);
    } else {
        char dadoInformado[21];
        char linha[TAMANHO_MAX];

        printf("\n\n   > Digite a %s para REMOVER: ", referencia);
        scanf("%s", &dadoInformado);

        char formato[34];
        snprintf(formato, sizeof(formato), "%s: %s;", referencia, dadoInformado); //Moodifica o formato que será buscado

        if(dadoExiste(formato, dadoInformado, arquivo)) {
            while (fgets(linha, sizeof(linha), arquivo) != NULL) {
                if (strstr(linha, formato) == NULL) {  // Verifica se a linha contém o dado a ser removida
                    fprintf(temp, "%s", linha); // Se não contém, escreve a linha no arquivo temporário
                } else {   
                    for (int i = 0; i < quantidadeLinhas; ++i) { 
                        if (fgets(linha, sizeof(linha), arquivo) == NULL) { 
                            break;  // Se contém, pula as linhas para não escrever no arquivo temporario
                        }
                    }
                }
            }

            fclose(arquivo);
            fclose(temp);
                             
            remove(Arquivo);   // Remove o arquivo original
            rename("temp.txt", Arquivo); // renomeia o temporário

            limparTerm();
            printf("\n\n   %s>>> Dados removidos com sucesso! <<<.%s\n", verde, limparCor);
            sleep(2);
        } else {
            printf("\n\n   %s>>> %s nao encontrada! <<<.%s\n", amarelo, referencia, limparCor);
            sleep(2);
            dadoInformado[0] = '\0';
            fclose(arquivo);
            fclose(temp);
            remove(temp);
            limparBuffer();
            limparTerm();
        }
    }
}

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


/* ====== MENUS ======*/
int menuRelatorios() {
    int opcao;

    while (1) {
        desenhaMenuRelat();
        printf("   Sua opcao: ");
        scanf("%d", &opcao);

        if (opcao == 0) {  // Voltar
            limparTerm();
            break;
        } else if (opcao == 1){  // Gerar relatorio
            /*code*/
            sleep(2);
        }else if (opcao == 2){  // Exibir/Baixar relatorio
            limparTerm();
            printf("\n\n");
            /*Code*/
            printf("   > Digite o id do relatorio para EXIBIR: ");
            sleep(2);
        }else if (opcao == 3){  // Excluir relatorio 
            //====A FUNÇAO DE EXCLUSÃO VEM AQUI=====vvvv==============================
            limparTerm();
            printf("\n\n");
            printf("   > Digite o id do relatorio para REMOVER: ");
            sleep(2);
            //====A FUNÇAO DE EXCLUSÃO VEM AQUI===^^^^================================
        } else {
            limparTerm();
            printf("\n\n\n");
            printf("%s   >>>  Opcao invalida, tente novamente!  <<<%s", amarelo, limparCor);
            sleep(1.5);
            limparBuffer();
        }
    }
}


int menuEmpresas() {
    int opcao;

    while (1) {
        desenhaMenuEmpr();
        printf("   Sua opcao: ");
        scanf("%d", &opcao);

        if (opcao == 0) {   // Voltar
            limparTerm();
            break;
        } else if (opcao == 1){  // Cadastrar empresa
            inserirDadosEmpr();
        }else if (opcao == 2){  // Lista de empresas
            lerArquivo("arqEmpresas.txt","");
        }else if (opcao == 3){  // Remover empresa
            excluirDados("arqEmpresas.txt", 16, "ID");
        } else {
            limparTerm();
            printf("\n\n\n");
            printf("%s   >>>  Opcao invalida, tente novamente!  <<<%s", amarelo, limparCor);
            sleep(1.5);
            limparBuffer();
        }
    }
}


int menuColaboradores() {
    int opcao;

    while (1) {
        desenhaMenuColab();
        printf("   Sua opcao: ");
        scanf("%d", &opcao);

        if (opcao == 0) {  // Voltar
            limparTerm();
            break;
        } else if (opcao == 1){  // Cadastrar usuario       
            inserirDadosColab();
        }else if (opcao == 2){  // Lista de usuarios
            lerArquivo("arqUsuarios.txt","Senha: ");
        }else if (opcao == 3){  // Remover usuario
            excluirDados("arqUsuarios.txt", 5, "Matricula");
        } else {
            limparTerm();
            printf("\n\n\n");
            printf("%s   >>>  Opcao invalida, tente novamente!  <<<%s", amarelo, limparCor);
            sleep(1.5);
            limparBuffer();
        }
    }
}


int menuPrincipal() {
    int opcao;

    while (1) {
        desenhaMenuPrinc();
        printf("   Sua opcao: ");
        scanf("%d", &opcao);

        if (opcao == 0) {  // Encerrar
            limparTerm();
            printf("\n\n\n");
            printf("%s   >>>  Encerrando...  <<<%s", vermelho, limparCor);
            sleep(1.5);
            limparTerm();
            break;
        } else if (opcao == 1){   // Relatorios
            menuRelatorios();
        } else if (opcao == 2){  // Empresas
            menuEmpresas();
        } else if (opcao == 3){  // Colaboradores
            menuColaboradores();
        } else {
            limparTerm();
            printf("\n\n\n");
            printf("%s   >>>  Opcao invalida, tente novamente!  <<<%s", amarelo, limparCor);
            sleep(1.5);
            while (getchar() != '\n');  // Limpa o buffer de entrada para evitar loop infinito
        }
    }
}


/* ====== PROGRAMA ======*/
int main() {
    //telaLogin();
    menuPrincipal();

    return 0;
}
