/*****************************************************************//**
 * \file   Function.c
 * \brief
 *
 * \author GG
 * \date   March 2024
 * \contact telesgomes96@gmail.com
 *********************************************************************/
#include "Header.h"
#include <stdio.h>


 /**
  * Funcao para inserir um novo inicio de uma lista ligada da Linha.
  *
  * \param inicio
  * \param valorInserir
  * \return
  */
Linha* inserirDadosInicioLinha(Linha* inicio, int valorInserir) {
    //Alocao de Memoria
    Linha* nova;
    nova = malloc(sizeof(Linha));


    nova->valor = valorInserir;

    nova->proximo = inicio;

    // Retorna o ponteiro para a nova lista
    return nova;
}

/**
 * Funcao para adcicionar uma lista a matriz
 *
 * \param inicio
 * \param linhaInserir
 * \return
 */
Matriz* inserirNovaLinha(Matriz* inicio, Linha* linhaInserir) {
    Matriz* nova;
    nova = malloc(sizeof(Matriz));

    // Define o inicio da linha da nova matriz como a linha a ser inserida.
    nova->inicioLinha = linhaInserir;
    // A prxima lista apos o inicio da lista
    nova->proximo = inicio;

    // Retorna o ponteiro para a nova matriz
    return nova;
}


/**
 * Funcao para remover uma linha de uma lista ligada de Matriz..
 *
 * \param inicio
 * \param linhaParaRemover
 * \return da matriz sem a coluna
 */
Matriz* removerLinhaExistente(Matriz* inicio, int linhaParaRemover) {
    // Verifica se a linha a ser removida e valida 
    if (linhaParaRemover < 1)
    {
        printf("linha invalida");
        return inicio; 
    }

    Matriz* auxMatriz = inicio;
    Matriz* linhaAnterior = NULL;
    int linhaAtual = 1;

    // se a linha a ser removida for a primeira
    if (linhaParaRemover == 1) {
        inicio = inicio->proximo;
        return inicio;   // Retorna o novo inicio da lista
    }

    // Percorre a lista ligada
    while (auxMatriz != NULL)
    {
        //verificamos se a linha a remover e igual a lista ,se for vamos buscar a promixa lista e apontamos para a proxima
        if (linhaAtual == linhaParaRemover)
        {
            
            // Remove a lista  atual, ajustando a lista anterior
            linhaAnterior->proximo = auxMatriz->proximo;
            return inicio;
        }
        linhaAtual++;
        linhaAnterior = auxMatriz;
        auxMatriz = auxMatriz->proximo;
    }

    printf("Linha invalida");
    return inicio; 
}

/**
 * Fun��o para remover uma coluna de uma lista  da Matriz...
 *
 * \param inicio
 * \param colunaParaRemover
 * \return
 */
Matriz* removerColuna(Matriz* inicio, int colunaParaRemover) {

    // Verifica se a coluna a ser removida e valida
    if (colunaParaRemover < 1) {
        printf("Coluna invalida");
        return inicio; // Retorna a matriz original se a coluna for invalida.
    }

    Matriz* auxMatriz = inicio;// Ponteiro auxiliar para percorrer a lista de linhas

    // Percorre a lista de linhas
    while (auxMatriz != NULL) {

        // Chama a funcao para remover a coluna da linha atual
        auxMatriz->inicioLinha = removerColunaExistente(auxMatriz->inicioLinha, colunaParaRemover);
        auxMatriz = auxMatriz->proximo;// Avanca para a proxima linha
    }

    return inicio; // Retorna a matriz original apos a remover a coluna
}

/**
 * Fuction to assist removerColuna.
 *
 * \param inicio
 * \param colunaParaRemover
 * \return
 */
Linha* removerColunaExistente(Linha* inicio, int colunaParaRemover) {

    // Verifica se a coluna a ser removida � v�lida
    if (colunaParaRemover < 1) {
        printf("Coluna invalida");
        return inicio; // Retorna a lista original se a linha for inv�lida.
    }

    Linha* auxColuna = inicio; // Ponteiro auxiliar para percorrer a lista de colunas
    Linha* colunaAnterio = NULL; // Ponteiro para a coluna anterior

    int colunaAtual = 1;// Contador de colunas

    //remo��o da primeira coluna
    if (colunaParaRemover == 1) {

        inicio = inicio->proximo; // Atualiza o in�cio para apontar para a proxima coluna
        return inicio; // Retorna a lista atualizada

    }

    // Percorre a lista de colunas
    while (auxColuna != NULL)
    {
        // Se encontrarmos a coluna a ser removida
        if (colunaAtual == colunaParaRemover)
        {
            // Ajusta o ponteiro da coluna anterior para apontar para a proxima coluna
            colunaAnterio->proximo = auxColuna->proximo;
            return inicio;
        }

        // Atualiza os ponteiros e o contador para a pr�xima itera��o
        colunaAtual++;
        colunaAnterio = auxColuna;
        auxColuna = auxColuna->proximo;
    }

    // Se chegou aqui, a linha n�o foi encontrada
    printf("Coluna invalida");
    return inicio; // Retorna a lista original se a linha nao for encontrada.
}

/**
 * Funcao para imprimir os valores de uma linha de uma matriz..
 *
 * \param linha
 * \return
 */
bool printLinha(Linha* linha) {

    // Inicializa um ponteiro auxiliar para percorrer a linha.
    Linha* aux = linha;

    // Percorre a linha ate o final, imprimindo os valores de cada lista.
    while (aux != NULL) {
        if (aux->proximo == NULL) {
            printf("%d", aux->valor);
        }
        else
        {
            printf("%d;", aux->valor);
        }


        //avan�a com o aux assumindo o valor de proximo
        aux = aux->proximo;
    }

    // Ap�s imprimir todos os valores da linha, imprime uma nova linha para separar das proximas impressoes.
    printf("\n");

    return true;
}

/**
 * Funcao para imprimir os valores de uma linha de uma matriz..
 *
 * \param matriz
 * \return
 */
bool printMatriz(Matriz* matriz) {
    Matriz* aux = matriz;
    printf("Matriz:\n");
    while (aux != NULL) {
        printf("Linhas:\n");
        printLinha(aux->inicioLinha);
        aux = aux->proximo;
    }
}




/**
 * Funcao para alterar o valor de um dado em uma matriz..
 *
 * \param inicio
 * \param linha
 * \param coluna
 * \param novoDado
 * \return
 */
bool alterarDado(Matriz* inicio, int linha, int coluna, int novoDado) {
    // Verifica se a linha e valida
    if (linha < 1)
    {
        printf("linha invalida");
    }

    // Verifica se a coluna e valida
    if (coluna < 1)
    {
        printf("coluna invalida");
    }


    Matriz* auxMatriz = inicio;

    Linha* auxLinha = NULL;

    // Armazena as posicoes 
    int linha_Atual = 1;
    int coluna_Atual = 1;

    // Percorre a lista de Matriz.
    while (auxMatriz != NULL)
    {
        // Se a linha atual for a linha desejada.
        if (linha_Atual == linha)
        {
            // Inicializa o ponteiro para percorrer a lista de Linha.
            auxLinha = auxMatriz->inicioLinha;

            // Percorre a lista de Linha.
            while (auxLinha != NULL)
            {

                // Se a coluna atual for a coluna desejada.
                if (coluna_Atual == coluna)
                {
                    // Altera o valor do dado para o novo valor fornecido.
                    auxLinha->valor = novoDado;
                    return auxLinha; // Retorna apos a alteracao.
                }
                // Atualiza a coluna atual e avanca para a proxima lista
                coluna_Atual++;
                auxLinha = auxLinha->proximo;
            }
            printf("coluna invalida");
            return false;
        }
        // conta as listas que foram percorridas
        linha_Atual++;
        auxMatriz = auxMatriz->proximo;
    }
    printf("Linha invalida");
    return false;

}

/**
 * Inserir dados no fim da lista.Export feito de github luferipca
 *
 * \param inicio
 * \param valorInserir
 * \return
 */
Linha* inserirDadosFimLinha(Linha* inicio, int valor) {
    Linha* novo = (Linha*)malloc(sizeof(Linha));
    if (novo == NULL) return NULL;

    // Define o valor do novo no como o valor fornecido.
    novo->valor = valor;
    novo->proximo = NULL; 

    //Se a lista estiver vazia o novo valor vai ser o inicio
    if (inicio == NULL) {
        inicio = novo;
    }
    else {
        Linha* aux = inicio;
        while (aux->proximo != NULL) {
            aux = aux->proximo;
        }
        aux->proximo = novo;
    }

    return inicio; // Retorna o ponteiro para o inicio da lista.
}

/**
 * Funcao para carregar uma matriz a partir de um arquivo.
 *
 * \param nomeFicheiro matriz.txt
 * \return do inicio da matriz
 */
Matriz* carregarFicheiroMatriz(char* nomeFicheiro)
{
    // ponteiro para o inicio da lista
    Linha* inicioLinha = NULL;
    //guarda a primeira lista
    Matriz* inicioMatriz = NULL;
    //guarda sempre a matriz atual
    Matriz* matriz_atual = NULL;

    // Contador para o numero total de elementos na matriz.
    int count = 0;
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
        printf("%d;", temp);

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
                // Sen�o, insere a linha no final da matriz existente.
                matriz_atual->proximo = (Matriz*)malloc(sizeof(Matriz));
                matriz_atual = matriz_atual->proximo;
                matriz_atual->inicioLinha = inicioLinha;
                matriz_atual->proximo = NULL;
            }

            // Reinicia o ponteiro para o inicio da linha.
            inicioLinha = NULL;
            printf("\n");
        }

        // Incrementa o contador de elementos.
        count++;
    }

    // Fecha o arquivo apos a leitura.
    fclose(file);

    // Retorna o ponteiro para o inicio da matriz.
    return inicioMatriz;
}


/**
 * Gravar a matriz depois de tudo o processo no main ,gravar o resultado.
 *
 * \param iniciomatriz entrada do incio da matriz
 * \param filename matriz.txt
 * \return inicio da matriz
 */
Matriz* gravarmatrix(Matriz* iniciomatriz, char* filename) {
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
            fprintf(arquivo, "%d ", linha_atual->valor);
            linha_atual = linha_atual->proximo;
        }

        fprintf(arquivo, "\n");
        matriz_atual = matriz_atual->proximo;
    }

    fclose(arquivo);
    printf("Matriz gravada com sucesso no arquivo: %s\n", filename);
    return iniciomatriz;
}