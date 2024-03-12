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


 /**
  * @brief Insere uma linha no inicio da Lista.
  *
  * @param inicio
  * @param nova
  * @return
  * @author teles
  *
  */
// Função para inserir um novo nó no início de uma lista ligada da Linha.
Linha* inserirDadosInicioLinha(Linha* inicio, int valorInserir) {
    if (valorInserir == NULL) return inicio;
    if (inicio == NULL)
        inicio = valorInserir;
    //Alocação de Memoria
    Linha* aux = (Linha*)malloc(sizeof(Linha));
    if (aux == NULL) return NULL;

    // Define o valor do novo nó como o valor fornecido.
    aux->valor = valorInserir;

    // O próximo nó após o novo nó será o nó atual do início da lista.
    aux->proximo = inicio;

    // Retorna o ponteiro para o novo nó, que agora se tornou o início da lista.
    return aux;
}

// Função para inserir uma nova linha no início de uma lista ligada de Matriz.
Matriz* inserirNovaLinha(Matriz* inicio, Linha* linhaInserir) {
    Matriz* nova;
    nova = malloc(sizeof(Matriz));

    // Define o início da linha da nova matriz como a linha a ser inserida.
    nova->inicioLinha = linhaInserir;
    // O próximo nó após a nova matriz será o nó atual do início da lista.
    nova->proximo = inicio;

    // Retorna o ponteiro para a nova matriz, que agora se tornou o início da lista.
    return nova;
}

// Função para imprimir os valores de uma linha de uma matriz.
bool printLinha(Linha* linha) {

    // Inicializa um ponteiro auxiliar para percorrer a linha.
    Linha* aux = linha;

    // Percorre a linha até o final, imprimindo os valores de cada nó.
    while (aux != NULL) {
        printf("%d ,", aux->valor);

        //avança com o aux assumindo o valor de proximo
        aux = aux->proximo;
    }

    // Após imprimir todos os valores da linha, imprime uma nova linha para separar das próximas impressões.
    printf("\n");

    return true;
}

// Função para imprimir os valores de uma linha de uma matriz.
bool printMatriz(Matriz* matriz) {
    Matriz* aux = matriz;

    while (aux != NULL) {
        printLinha(aux->inicioLinha);
        aux = aux->proximo;
    }
}

/// Função para carregar uma matriz a partir de um arquivo.
Matriz* carregarFicheiroMatriz(char* nomeFicheiro)
{
    // Ponteiro para o início da linha e para o início da matriz.
    Linha* inicioLinha = NULL;
    Matriz* inicioMatriz = NULL;

    FILE* file = fopen(nomeFicheiro, "r");
    if (file == NULL) {
        printf("Error opening file");
        return 1;
    }

    // Contador para o número total de elementos na matriz.
    int count = 0;

    int temp;
    char separador;

    // Lê o arquivo enquanto não chegar ao final.
    while (fscanf_s(file, "%d%c", &temp, &separador) != EOF)
    { // EOF end of file

        // Insere o valor lido no início da linha.
        inicioLinha = inserirDadosInicioLinha(inicioLinha, temp);

       

        // Verifica se o separador indica o final da linha.
        if (separador == '\n') {

            // Se sim, insere a linha na matriz e reseta o ponteiro para o início da linha.
            inicioMatriz = inserirNovaLinha(inicioMatriz, inicioLinha);
            inicioLinha = NULL;
        }
        // Incrementa o contador de elementos.
        count++;
    }

    // Fecha o arquivo após a leitura.
    fclose(file);

    // Insere a última linha na matriz, caso necessário.
    inicioMatriz = inserirNovaLinha(inicioMatriz, inicioLinha);

    // Atualiza o número total de elementos na matriz.
    matrizTotal = count;

    // Retorna o ponteiro para o início da matriz.
    return inicioMatriz;
}


// Função para alterar o valor de um dado em uma matriz.
bool alterarDado(Matriz* inicio, int linha, int coluna, int novoDado) {
    // Verifica se a linha é válida (maior que 0).
    if (linha < 1)
    {
        printf("linha invalida");
    }

    // Verifica se a coluna é válida (maior que 0).
    if (coluna < 1)
    {
        printf("coluna invalida");
    }

    // Ponteiro para percorrer a lista de Matriz.
    Matriz* auxMatriz = inicio;

    // Ponteiro para percorrer a lista de Linha.
    Linha* auxLinha = NULL;

    // Variáveis para armazenar a posição atual da linha e da coluna.
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
                    return auxLinha; // Retorna após a alteração.
                }
                // Atualiza a coluna atual e avança para o próximo nó da lista de Linha.
                colunaAtual++;
                auxLinha = auxLinha->proximo;
            }
            // Se chegou aqui, significa que a coluna desejada não foi encontrada.
            printf("coluna invalida");
            return;
        }
        // Atualiza a linha atual e avança para o próximo nó da lista de Matriz.
        linhaAtual++;
        auxMatriz = auxMatriz->proximo;
    }
    // Se chegou aqui, significa que a linha desejada não foi encontrada.
    printf("Linha invalida");
}
