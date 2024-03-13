/**
 * @file functions.c
 * @author Teles Gomes
 * @date 2024-03
 * @author telesgomes96@gmail.com
 *
 */
#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define FILENAME "matriz.txt"


Linha* inserirDadosFimLinha(Linha* inicio, int valorInserir) {
    // Aloca��o de Mem�ria para o novo n�
    Linha* novo = (Linha*)malloc(sizeof(Linha));
    if (novo == NULL) return NULL;

    // Define o valor do novo n� como o valor fornecido.
    novo->valor = valorInserir;
    novo->proximo = NULL; // O pr�ximo do novo n� ser� NULL, pois ele ser� o �ltimo n�.

    // Se a lista estiver vazia, o novo n� ser� o in�cio da lista.
    if (inicio == NULL) {
        inicio = novo;
    }
    else {
        Linha* aux = inicio;

        // Percorre a lista at� encontrar o �ltimo n�.
        while (aux->proximo != NULL) {
            aux = aux->proximo;
        }

        // Agora que estamos no �ltimo n�, definimos o pr�ximo como o novo n�.
        aux->proximo = novo;
    }

    return inicio; // Retorna o ponteiro para o in�cio da lista.
}




 /**
  * @brief Insere uma linha no inicio da Lista.
  *
  * @param inicio
  * @param nova
  * @return
  * @author teles
  *
  */
Linha* inserirDadosInicioLinha(Linha* inicio, int valorInserir) {
    if (valorInserir == NULL) return inicio;

    // Aloca��o de Memoria para o novo n�
    Linha* novo = (Linha*)malloc(sizeof(Linha));
    if (novo == NULL) return NULL;

    // Define o valor do novo n� como o valor fornecido.
    novo->valor = valorInserir;

    // O pr�ximo n� ap�s o novo n� ser� o n� atual do in�cio da lista.
    novo->proximo = inicio;

    // Retorna o ponteiro para o novo n�, que agora se tornou o in�cio da lista.
    return novo;
}

/**
 * Insere uma lista na matriz .
 * 
 * \param inicio
 * \param linhaInserir
 * \return 
 */
Matriz* inserirNovaLinha(Matriz* inicio, Linha* linhaInserir) {
    // Aloca��o de Memoria para a nova matriz
    Matriz* nova = (Matriz*)malloc(sizeof(Matriz));
    if (nova == NULL) return NULL;

    // Define o in�cio da linha da nova matriz como a linha a ser inserida.
    nova->inicioLinha = linhaInserir;

    // O pr�ximo n� ap�s a nova matriz ser� o n� atual do in�cio da lista.
    nova->proximo = inicio;

    // Retorna o ponteiro para a nova matriz, que agora se tornou o in�cio da lista.
    return nova;
}

/**
 * Fun��o para imprimir os valores de uma linha de uma matriz..
 * 
 * \param linha
 * \return true or false 
 */
bool printLinha(Linha* linha) {
    // Inicializa um ponteiro auxiliar para percorrer a linha.
    Linha* aux = linha;

    // Percorre a linha at� o final, imprimindo os valores de cada n�.
    while (aux != NULL) {
        printf("%d ,", aux->valor);

        // Avan�a para o pr�ximo n� na linha.
        aux = aux->proximo;
    }

    // Ap�s imprimir todos os valores da linha, imprime uma nova linha para separar das pr�ximas impress�es.
    printf("\n");

    return true;
}

/**
 * Fun��o para imprimir os valores de uma matriz..
 * 
 * \param matriz dar entrada do inicio da matriz 
 * \return true or false
 */
bool printMatriz(Matriz* matriz) {
    if (matriz == NULL) {
        printf("Matriz vazia.\n");
        return false;
    }

    Matriz* aux = matriz;

    while (aux != NULL) {
        printLinha(aux->inicioLinha);
        aux = aux->proximo;
    }

    return true;
}
/**
 * Fun��o para carregar uma matriz a partir de um arquivo..
 * 
 * \param nomeFicheiro
 * \return 
 */
Matriz* carregarFicheiroMatriz(char* nomeFicheiro)
{
    // Ponteiro para o in�cio da linha e para o in�cio da matriz.
    Linha* inicioLinha = NULL;
    Matriz* inicioMatriz = NULL;

    FILE* file = fopen(nomeFicheiro, "r");
    if (file == NULL) {
        printf("Error opening file");
        return 1;
    }

    // Contador para o n�mero total de elementos na matriz.
    int count = 0;

    int temp;
    char separador;

    // L� o arquivo enquanto n�o chegar ao final.
    while (fscanf_s(file, "%d%c", &temp, &separador) != EOF)
    { // EOF end of file

        // Insere o valor lido no in�cio da linha.
        inicioLinha = inserirDadosInicioLinha(inicioLinha, temp);
        printf("%d\t", temp);
       

        // Verifica se o separador indica o final da linha.
        if (separador == '\n') {

            // Se sim, insere a linha na matriz e reseta o ponteiro para o in�cio da linha.
            inicioMatriz = inserirNovaLinha(inicioMatriz, inicioLinha);
            inicioLinha = NULL;
            printf("\n");
        }
        // Incrementa o contador de elementos.
        count++;
    }

    // Fecha o arquivo ap�s a leitura.
    fclose(file);

    // Insere a �ltima linha na matriz, caso necess�rio.
 //   inicioMatriz = inserirNovaLinha(inicioMatriz, inicioLinha);

    // Atualiza o n�mero total de elementos na matriz.
    matrizTotal = count;

    // Retorna o ponteiro para o in�cio da matriz.
    return inicioMatriz;
}


// Fun��o para alterar o valor de um dado em uma matriz.
bool alterarDado(Matriz* inicio, int linha, int coluna, int novoDado) {
    // Verifica se a linha � v�lida (maior que 0).
    if (linha < 1)
    {
        printf("linha invalida");
    }

    // Verifica se a coluna � v�lida (maior que 0).
    if (coluna < 1)
    {
        printf("coluna invalida");
    }

    // Ponteiro para percorrer a lista de Matriz.
    Matriz* auxMatriz = inicio;

    // Ponteiro para percorrer a lista de Linha.
    Linha* auxLinha = NULL;

    // Vari�veis para armazenar a posi��o atual da linha e da coluna.
    int linhaAtual = 1;
    int colunaAtual = 1;

    // Percorre a lista de Matriz.
    while (auxMatriz != NULL)
    {
        // Se a linha atual for a linha desejada.
        if (linhaAtual == linha)
        {
            // Inicializa o ponteiro para percorrer a lista de Linha.
            auxLinha = auxMatriz->inicioLinha;

            // Percorre a lista de Linha.
            while (auxLinha != NULL)
            {

                // Se a coluna atual for a coluna desejada.
                if (colunaAtual == coluna)
                {
                    // Altera o valor do dado para o novo valor fornecido.
                    auxLinha->valor = novoDado;
                    return auxLinha; // Retorna ap�s a altera��o.
                }
                // Atualiza a coluna atual e avan�a para o pr�ximo n� da lista de Linha.
                colunaAtual++;
                auxLinha = auxLinha->proximo;
            }
            // Se chegou aqui, significa que a coluna desejada n�o foi encontrada.
            printf("coluna invalida");
            return;
        }
        // Atualiza a linha atual e avan�a para o pr�ximo n� da lista de Matriz.
        linhaAtual++;
        auxMatriz = auxMatriz->proximo;
    }
    // Se chegou aqui, significa que a linha desejada n�o foi encontrada.
    printf("Linha invalida");
}
