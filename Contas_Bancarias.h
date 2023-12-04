//
// Created by Thiago on 04/12/2023.
//

#ifndef SISTEMAS_DE_CONTAS_BANCARIAS_CONTAS_BANCARIAS_H
#define SISTEMAS_DE_CONTAS_BANCARIAS_CONTAS_BANCARIAS_H


#define MAXIMO_CONTAS 100 /**< Define o número máximo de contas possiveis */

/**
 * @file contas_Bancarias.h
 * @brief Definição da estrutura de dados para contas bancárias e protótipos de funções relacionadas.
 */

/**
 * @struct Conta
 * @brief Estrutura que representa uma conta bancária.
 *
 * Esta estrutura contém informações sobre o número da conta, nome do cliente,
 * se é uma conta especial e o saldo da conta.
 */
typedef struct {
    int numero;                 /**< Número da conta do cliente. */
    char cliente[51];           /**< Nome do cliente associado à conta. */
    int especial;               /**< Indica se a conta é especial (1) ou não (0). */
    float saldo;                /**< Saldo atual da conta. */
} Conta;

/**
 * @typedef p_conta
 * @brief Ponteiro para uma estrutura Conta.
 */
typedef Conta *p_conta;

/**
 * @brief Vetor que armazena ponteiros para contas bancárias.
 */
extern p_conta totalContas[MAXIMO_CONTAS];

/**
 * @brief Insere uma nova conta no vetor de contas.
 *
 * @param contas Ponteiro para o vetor de contas.
 * @param totalContas Ponteiro para a variável que armazena o total de contas.
 */
void inserir(Conta *contas, int *totalContas);

/**
 * @brief Altera informações de uma conta existente.
 *
 * @param contas Ponteiro para o vetor de contas.
 * @param totalContas Total de contas no vetor.
 */
void alterar(Conta *contas, int totalContas);

/**
 * @brief Procura e exibe informações de uma conta.
 *
 * @param contas Ponteiro para o vetor de contas.
 * @param totalContas Total de contas no vetor.
 */
void procurar(Conta *contas, int totalContas);

/**
 * @brief Lista todas as contas e suas informações.
 *
 * @param contas Ponteiro para o vetor de contas.
 * @param totalContas Total de contas no vetor.
 */
void listar(Conta *contas, int totalContas);

/**
 * @brief Realiza um depósito em uma conta existente.
 *
 * @param contas Ponteiro para o vetor de contas.
 * @param totalContas Total de contas no vetor.
 */
void depositar(Conta *contas, int totalContas);

/**
 * @brief Realiza um saque em uma conta existente.
 *
 * @param contas Ponteiro para o vetor de contas.
 * @param totalContas Total de contas no vetor.
 */
void sacar(Conta *contas, int totalContas);

/**
 * @brief Imprime as informações de uma conta.
 *
 * @param contas Ponteiro para o vetor de contas.
 * @param totalContas Total de contas no vetor.
 */
void imprimir(Conta *contas, int totalContas);

/**
 * @brief Calcula e exibe o saldo geral de todas as contas.
 *
 * @param contas Ponteiro para o vetor de contas.
 * @param totalContas Total de contas no vetor.
 */
void saldoGeral(Conta *contas, int totalContas);



#endif //SISTEMAS_DE_CONTAS_BANCARIAS_CONTAS_BANCARIAS_H
