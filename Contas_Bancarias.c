#include "Contas_Bancarias.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void inserir(Conta *contas, int *totalContas){

    if (*totalContas >= MAXIMO_CONTAS) {// Verifica se o numero total de contas já cadastradas
        printf("Nao eh possivel cadastrar mais contas.\n");
        return;
    }

    Conta novaConta; // Cria uma nova estrutura do tipo Conta para armazenar as informações da nova conta a ser cadastrada

    char entrada[20]; // Declara um vetor de caracteres para armazenar as entradas do usuário

    do{

        printf("Numero da conta (DIGITE 9999 PARA VOLTAR AO MENU): ");  // Solicita ao usuário que digite o numero

        scanf(" %s", entrada); // Lê a entrada do usuario

        if (strcmp(entrada, "9999") == 0) { // Verifica se foi digitado o código de retorno para o menu
            return; // Retorna ao menu
        }

        sscanf(entrada, "%d", &novaConta.numero);   //converte a string entrada em um inteiro e armazena no vetor novaConta

        int entradaValida = 1;

        for (int i = 0; i < strlen(entrada); i++) { // percorre cada valor da entrada do usuario
            if (entrada[i] < '0' || entrada[i] > '9') { //verifica se nao e numero
                entradaValida = 0;  //sinal para entradaa invalida
                break;
            }
        }

        if (!entradaValida) {   //verifica se a entrada e iniválida
            printf("ERRO. Digite apenas numeros.\n");
            entrada[0] = '\0';//limpa o vetor para repetir a solicitação
            continue; // Retorna ao começo do loop
        }

        // Verifica se o número de conta já existe
        int numeroExistente = 0;
        for (int i = 0; i < *totalContas; i++) {
            if (contas[i].numero == novaConta.numero) { //caso encontrar um numero igual da indica que o valor ja esta cadastrado
                numeroExistente = 1;
                break;
            }
        }

        if (numeroExistente) {// verificaa se o numero foi encontrado
            printf("ERRO. Numero de conta ja existente. Digite outro numero.\n");
            entrada[0] = '\0';  // String vazia para repetir a entrada
        }

    }while (entrada[0] == '\0');    //continua no loop te uma entrada valida

    do{
        printf("Nome do cliente (DIGITE 9999 PARA VOLTAR AO MENU): ");

        scanf(" %[^\n]", novaConta.cliente);//le a entrada

        if (strcmp(novaConta.cliente, "9999") == 0) {   // Verifica se foi digitado o código de retorno o menu
            return; // Retorna ao menu
        }

        int nomeValido = 1;
        for (int i = 0; novaConta.cliente[i] != '\0'; i++) {
            if ( ! ((novaConta.cliente[i] >= 'a' && novaConta.cliente[i] <= 'z') ||// verifica se e letra minuscula
                    (novaConta.cliente[i] >= 'A' && novaConta.cliente[i] <= 'Z') ||// verifica se e letra maiuscula
                    novaConta.cliente[i] == ' ') ) {//verifica se e espaço
                printf("ERRO. Digite apenas letras.\n");
                nomeValido = 0;//sinal nome invalido
                break;
            }
        }

        if (nomeValido) {//verifica se o nome e valido
            break;
        }

    }while (1);//loop ate que tenha uma entrada valida

    do{
        printf("Conta especial [1 - Sim, 0 - Nao] (DIGITE 9999 PARA VOLTAR AO MENU): ");
        scanf("%s", entrada);//le a enntrada do usuario

        if (strcmp(entrada, "9999") == 0) {//verifica se o e o codigo para retornar ao menu
            return; // Retorna ao menu
        }

        if (strcmp(entrada, "0") != 0 && strcmp(entrada, "1") != 0) {//compara se a entrada e diferente de 1 e 0
            printf("ERRO. Digite apenas 1 ou 0.\n");
        }else {
            novaConta.especial = entrada[0] - '0'; // Converte o primeiro caractere para um valor inteiro
            break;
        }

    }while (1);

    do{
        printf("Digite o Saldo (DIGITE 9999 PARA VOLTAR AO MENU): ");

        if (scanf("%f", &novaConta.saldo) != 1) {// verifica se a entrada e um numero valido
            char ch;
            scanf("%c", &ch); // Lê o caractere inválido
            printf("ERRO. Digite um valor de saldo valido.\n");
        }

        else if (novaConta.saldo == 9999) { //verifica se e o codigo para voltar ao menun
            return; // Retorna ao menu

        }

        else if (novaConta.saldo < 0) { //verifica se o valor e negativo
            printf("ERRO. Digite um valor de saldo valido.\n");

        }

        else {  //se for válido sai do loop
            break;
        }

    }while (1); //loop ate um entradaa valida

    contas[*totalContas] = novaConta;   //adiciona uma nova conta ao vetor de contas e incrementando o total de contas cadastradas

    (*totalContas)++;

    printf("\nConta cadastrada com sucesso!\n");
}

/*-------------------------------------------------------------------------------------------------------------*/

void alterar(Conta *contas, int totalContas) {

    int numeroConta;
    char entrada[20];

    do{

        printf("Digite o numero da conta para alterar (DIGITE 9999 PARA VOLTAR AO MENU): ");
        if (scanf("%s", entrada) != 1)  // Verifica se a entrada é um inteiro válido.
        {
            printf("ERRO. Digite apenas numeros.\n");
            while (getchar() != '\n'); // Limpa o buffer de entrada
            continue;
        }

        if (strcmp(entrada, "9999") == 0) // Verifica se o usuário digitou 9999 para voltar ao menu
        {
            return; // Retorna ao menu
        }

        sscanf(entrada, "%d", &numeroConta);    // Converte a entrada em número inteiro

        int contaEncontrada = 0;
        for (int i = 0; i < totalContas; i++)   // Inicia um loop que percorre todas as contas até encontrar a conta correspondente
        {

            if (contas[i].numero == numeroConta)    // Se a conta for encontrada, solicita ao usuário que informe o novo nome
            {
                char novoNome[50];
                do{
                    // Solicita ao usuário que informe o novo nome ou 9999 para voltar ao menu
                    printf("Informe o novo nome para o cliente (DIGITE 9999 PARA VOLTAR AO MENU): ");
                    scanf(" %[^\n]", novoNome); //le a entrada

                    if (strcmp(novoNome, "9999") == 0)  // Verifica se o usuário digitou 9999 para voltar ao menu.
                    {
                        return; // Retorna ao menu
                    }

                    int nomeValido = 1;
                    // Verifica se o nome é válido
                    for (int j = 0; novoNome[j] != '\0'; j++)
                    {
                        if (!((novoNome[j] >= 'a' && novoNome[j] <= 'z') ||//verifica se e letras minusculas
                              (novoNome[j] >= 'A' && novoNome[j] <= 'Z') ||//verifica se e letra maiusculas
                              novoNome[j] == ' '))//vevrifica se e espaço
                        {
                            printf("ERRO. Digite apenas letras.\n");
                            nomeValido = 0;
                            break;
                        }
                    }

                    // Se o nome for válido, altera o nome da conta
                    if (nomeValido){// Alterar apenas o nome do cliente
                        int k;
                        // Copia cada caractere do novo nome para a conta correspondente
                        for ( k = 0; novoNome[k] != '\0'; k++)
                        {
                            contas[i].cliente[k] = novoNome[k];
                        }
                        contas[i].cliente[k] = '\0'; // Adicionar terminador nulo
                        printf("\nNome atualizado com sucesso!\n");
                        break;
                    }

                }while (1);

                contaEncontrada = 1;
                break;
            }
        }

        if (contaEncontrada)// Se a conta não for encontrada, exibe uma mensagem de erro
            break;
        printf("Conta nao existe.\n");

    } while (1);
}

/*-------------------------------------------------------------------------------------------------------------*/

void procurar(Conta *contas, int totalContas){

    int numeroConta;
    char entrada[20];

    do{
        printf("Digite o numero da conta para procurar (DIGITE 9999 PARA VOLTAR AO MENU): ");

        if (scanf("%s", entrada) != 1)// Verifica se a entrada é um inteiro válido.
        {
            printf("ERRO. Entrada invalida.\n");
            while (getchar() != '\n'); // Limpa o buffer de entrada
            continue;
        }

        if (strcmp(entrada, "9999") == 0) // Verifica se o usuário digitou 9999 para voltar ao menu
        {
            return; // Retorna ao menu
        }

        sscanf(entrada, "%d", &numeroConta);// Converte a entrada em número inteiro.

        int contaEncontrada = 0;
        for (int i = 0; i < totalContas; i++)// Inicia um loop que percorre todas as contas até encontrar a conta correspondente
        {
            if (contas[i].numero == numeroConta){
                //informaçoes da conta encontrada
                printf("Numero da conta: %d\n", contas[i].numero);
                printf("Nome do cliente: %s\n", contas[i].cliente);
                // printf("tipo do cliente: %d\n", contas[i].especial);

                if (contas[i].especial == 1)// verificar o tipo de conta
                {
                    printf("Tipo de cliente: 1 Especial\n");

                }else{
                    printf("Tipo de cliente: 0 Normal\n");
                }

                printf("Saldo: %.2f\n\n", contas[i].saldo);
                contaEncontrada = 1;
                break;
            }
        }

        if (contaEncontrada)//verifica se a cont foi encontrada
        {
            break;
        }

        else{
            printf("Conta nao existe.\n");
        }

    } while (1);// loop ate uma entrada seja valida
}

/*-------------------------------------------------------------------------------------------------------------*/

void sacar(Conta *contas, int totalContas){

    int numeroConta;
    float valor;

    do{
        printf("Digite o numero da conta para saque (DIGITE 9999 PARA VOLTAR AO MENU): ");
        if (scanf("%d", &numeroConta) != 1)
        {
            printf("ERRO. Digite apenas numeros.\n");
            while (getchar() != '\n'); // Limpa o buffer de entrada
            continue;
        }

        if (numeroConta == 9999) // Se digitar 9999, retorna para o menu
        {
            return; // Retorna ao menu
        }

        // Loop for para percorrer todas as contas cadastradas e encontrar a que tem o número digitado pelo usuário
        for (int i = 0; i < totalContas; i++){
            if (contas[i].numero == numeroConta){
                do{
                    printf("Digite o valor a ser sacado (DIGITE 9999 PARA VOLTAR AO MENU): ");
                    if (scanf("%f", &valor) != 1) // Verifica se o usuário digitou um valor válido
                    {
                        printf("ERRO. Digite apenas numeros positivos.\n");
                        while (getchar() != '\n'); // Limpa o buffer de entrada
                        continue;
                    }

                    if (valor == 9999) // Se digitar 9999, retorna para o menu
                    {
                        return; // Retorna ao menu
                    }

                    if (valor > 0 && valor <= contas[i].saldo)//verifica se o valor e maior que zero e menor ou igual ao saldo
                    {
                        contas[i].saldo -= valor;//subtrai o valor do saldo
                        printf("\nSaque realizado com sucesso.\n");
                        return;
                    }

                    else if (valor == 0)//verifica se e zero
                    {
                        printf("Valor de saque nao pode ser zero.\n");
                    }

                    else{
                        printf("Valor invalido para saque.\n");
                    }

                } while (1);//loop ate o valor de ser sacado seja valido
            }
        }

        printf("Conta nao existente.\n");
    } while (1);// loop ate ter um valor valido
}

/*-------------------------------------------------------------------------------------------------------------*/

void depositar(Conta *contas, int totalContas){

    int numeroConta;
    float valor;

    do{
        printf("Digite o numero da conta para deposito (DIGITE 9999 PARA VOLTAR AO MENU): ");
        if (scanf("%d", &numeroConta) != 1)
        {
            printf("ERRO. Digite apenas numeros.\n");
            while (getchar() != '\n'); // Limpa o buffer de entrada
            continue;
        }

        if (numeroConta == 9999)// Verifica se o usuário digitou 9999 para voltar ao menu
        {
            return; // Retorna ao menu
        }

        // Percorre todas as contas cadastradas para encontrar
        for (int i = 0; i < totalContas; i++)
        {
            if (contas[i].numero == numeroConta)
            {
                do{
                    printf("Digite o valor a ser depositado (DIGITE 9999 PARA VOLTAR AO MENU): ");
                    if (scanf("%f", &valor) != 1)// Verifica se a entrada é um número positivo válido.
                    {
                        printf("ERRO. Digite apenas numeros positivos.\n");
                        while (getchar() != '\n'); // Limpa o buffer de entrada
                        continue;
                    }

                    if (valor == 9999)// Verifica se o usuário digitou 9999 para voltar ao menu
                    {
                        return; // Retorna ao menu
                    }

                    // Deposita o valor na conta e informa ao usuário
                    if (valor > 0)
                    {
                        contas[i].saldo += valor;
                        printf("\nDeposito realizado com sucesso.\n");
                        return;
                    }

                    else if (valor == 0)    //verifica se o valor e zero
                    {
                        printf("Valor de deposito nao pode ser zero.\n");
                    }
                    else{
                        printf("Valor invalido para deposito.\n");
                    }
                }while (1);
            }
        }

        printf("Conta nao existente.\n");
    }while (1);// loop ate a entrada valida
}

/*-------------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------------------------------------------*/

void imprimir(Conta *contas, int totalContas){

    int numeroConta;  // variavel paraa armazenar o numero da conta para impressão
    char entrada[20]; // string para receber a entradaa do usuario

    do{ // inicio do loop
        printf("Digite o numero da conta para imprimir os dados (DIGITE 9999 PARA VOLTAR AO MENU): ");
        scanf(" %s", entrada); // le a entrada do usuario

        if (strcmp(entrada, "9999") == 0) // para verificar foi digitado o codigo para voltar ao menu
        {
            return; // Retorna ao menu
        }

        sscanf(entrada, "%d", &numeroConta); // converte a entrada de string para inteiro

        int contaEncontrada = 0;              // variavel que indica se a conta foi encontrada
        for (int i = 0; i < totalContas; i++) // for para percorrer as contas
        {
            if (contas[i].numero == numeroConta) // se conta atual é igual a conta digitada pelo usuario
            {
                printf("Numero da conta: %d\n", contas[i].numero);  // imprime o numero da conta
                printf("Nome do cliente: %s\n", contas[i].cliente); // imprime o nome do cliente

                if (contas[i].especial == 1)    // se o tipo de cliente é especial
                {
                    printf("Tipo de cliente: 1 Especial\n");
                }

                else{
                    printf("Tipo de cliente: 0 Normal\n");
                }

                printf("Saldo: %.2f\n", contas[i].saldo); // imprime o saldo de cliente
                contaEncontrada = 1;                      // define como verdadeiro para cont encontrada
                break;                                    // sai do loop
            }
        }

        if (contaEncontrada) // pausa o programa se a conta foi encontrada
        {
            printf("Conta encontrada.\n");
            break;
        }

        else{
            printf("Conta nao existe.\n"); // mensagem de alerta
        }

    }while (1);
}