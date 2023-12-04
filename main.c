#include <stdio.h>
#include <stdlib.h>
#include "Contas_Bancarias.h"

/**
 * @brief Função principal do programa que gerencia contas bancárias.
 *
 * @return Retorna 0 ao finalizar o programa com sucesso.
 */

int main() {
    Conta contas[MAXIMO_CONTAS];
    int totalContas = 0;
    int opcao = -1; // Inicializa a opção como inválida

    while (opcao != 0) {

        // Exibe o menu de opções
        printf("\n----- MENU -----\n"
               "1 - Inserir nova conta\n"
               "2 - Alterar dados de uma conta\n"
               "3 - Procurar uma conta\n"
               "4 - Listar todas as contas\n"
               "5 - Realizar deposito\n"
               "6 - Realizar saque\n"
               "7 - Imprimir dados de uma conta\n"
               "8 - Mostrar saldo geral\n"
               "0 - Sair\n"
               "Opcao: ");

        // Lê a opção do usuário
        scanf("%d", &opcao);

        // Executa a ação correspondente à opção escolhida
        switch (opcao) {
            case 1:
                inserir(contas, &totalContas); // Faz a chamada da função inserir
                break;

            case 2:
                alterar(contas, totalContas); // Faz a chamada da função alterar
                break;

            case 3:
                procurar(contas, totalContas); // Faz a chamada da função procurar
                break;

            case 4:
                listar(contas, totalContas); // Faz a chamada da função listar
                break;

            case 5:
                depositar(contas, totalContas); // Faz a chamada da função depositar
                break;

            case 6:
                sacar(contas, totalContas); // Faz a chamada da função sacar
                break;

            case 7:
                imprimir(contas, totalContas); // Faz a chamada da função imprimir
                break;

            case 8:
                saldoGeral(contas, totalContas); // Faz a chamada da função saldoGeral
                break;

            case 0:
                printf("Encerrando o programa...\n");
                break;

            default:
                // Caso a opção for inválida é exibido uma mensagem e o buffer de entrada é limpado

                printf("Opcao invalida, por favor digite novamente !\n");

                while (getchar() != '\n') {}; // Limpa o buffer de entrada

                fflush(stdin); // limpa o buffer de saida;

                break;
        }
    }

    printf("Programa encerrado.\n");
    return 0;
}

