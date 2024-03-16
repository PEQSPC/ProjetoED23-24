/*****************************************************************//**
 * \file   Function.c
 * \brief
 *
 * \author GG
 * \date   March 2024
 * \contact telesgomes96@gmail.com
 *********************************************************************/
#include "Header.h"
//#include "functions.c"
#include <stdio.h>
#include <stdint.h>


 /**
  *Gravar a matriz depois de tudo o processo no main ,gravar o resultado.
  *
  * \param iniciomatriz entrada do incio da matriz
  * \param filename matriz.txt
  * \return inicio da matriz
  */
Matriz* gravarmatriz(Matriz* iniciomatriz, char* filename) {
    if (strlen(filename) == 0) {
        printf("Nome do arquivo invalido.\n");
        return NULL;
    }

    FILE* arquivo = fopen(filename, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return NULL;
    }

    Matriz* matriz_atual = iniciomatriz;

    while (matriz_atual != NULL) {
        Linha* linha_atual = matriz_atual->inicioLinha;

        while (linha_atual != NULL) {
            if (linha_atual->proximo == NULL) {
                fprintf(arquivo, "%d", linha_atual->valor);
            }
            else
            {
                fprintf(arquivo, "%d;", linha_atual->valor);
            }

            linha_atual = linha_atual->proximo;
        }

        fprintf(arquivo, "\n");
        matriz_atual = matriz_atual->proximo;
    }

    fclose(arquivo);

    printf("Matriz salva no arquivo: %s\n", filename);
    return iniciomatriz;
}

/**
 * Funcao para carregar uma matriz a partir de um arquivo.
 *
 * \param nomeFicheiro matriz.txt
 * \return do inicio da matriz
 */
Matriz* carregarFicheiroMatriz(char* nomeFicheiro)
{
    // apontador para o inicio da lista
    Linha* inicioLinha = NULL;
    //guarda a primeira lista
    Matriz* inicioMatriz = NULL;
    //guarda sempre a matriz atual
    Matriz* matriz_atual = NULL;

    
    int temp;
    char icon;

    FILE* file = fopen(nomeFicheiro, "r");

    if (file == NULL) {
        printf("Error opening file");
        return NULL;
    }



    // Le o arquivo ate chegar ao final.
    while (fscanf_s(file, "%d%c", &temp, &icon) != EOF)
    {
        // Insere o valor lido no inicio da linha.
        inicioLinha = inserirDadosFimLinha(inicioLinha, temp);
        //printf("%d\t", temp);

        // Verifica se o separador indica o final da linha.
        if (icon == '\n') {
            // Insere a linha na matriz.
            if (inicioMatriz == NULL) {
                // Se for a primeira linha, cria a primeira matriz.
                inicioMatriz = (Matriz*)malloc(sizeof(Matriz));
                inicioMatriz->inicioLinha = inicioLinha;
                inicioMatriz->proximo = NULL;
                matriz_atual = inicioMatriz;
            }
            else {
                // Senao, insere a linha no final da matriz existente.
                matriz_atual->proximo = (Matriz*)malloc(sizeof(Matriz));
                matriz_atual = matriz_atual->proximo;
                matriz_atual->inicioLinha = inicioLinha;
                matriz_atual->proximo = NULL;
            }

            // Reinicia o apontador para o inicio da linha.
            inicioLinha = NULL;
            matrizTotal++;
            printf("\n");
        }

        
    }

    // Fecha o arquivo apos a leitura.
    fclose(file);

    // Retorna o apontador para o inicio da matriz.
    return inicioMatriz;
}