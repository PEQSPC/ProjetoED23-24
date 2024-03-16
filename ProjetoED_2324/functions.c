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
#include <stdint.h>


/**
  * Funcao para inserir um novo inicio de uma lista ligada da Linha.
  *
  * \param inicio
  * \param valorInserir
  * \return
  */
Linha* inserirDadosInicioLinha(Linha* inicio, int valorInserir) {
    if (valorInserir < 1) {
        return inicio;
    }
    //Alocao de Memoria
    Linha* nova;
    nova = malloc(sizeof(Linha));


    nova->valor = valorInserir;

    nova->proximo = inicio;

    // Retorna o apontador para a nova lista
    return nova;
}

/**
 * Funcao para adcicionar uma lista a matriz
 *
 * \param inicio
 * \param linhaInserir
 * \return matriz inicio
 */
Matriz* inserirNovaLinha(Matriz* inicio, Linha* linhaInserir) {
    if (linhaInserir == NULL) {
        return inicio;
    }
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
        // printf("linha invalida");
        return inicio;
    }

    Matriz* auxMatriz = inicio;
    Matriz* temp = NULL;
    Matriz* linhaAnterior = NULL;
    int linhaAtual = 1;

    // se a linha a ser removida for a primeira
    if (linhaParaRemover == 1) {
        auxMatriz = inicio->proximo;
        free(inicio);
        //inicio = inicio->proximo;
        inicio = auxMatriz;
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
            free(auxMatriz);
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
 * Funcao para remover uma coluna de uma lista  da Matriz...
 *
 * \param inicio
 * \param colunaParaRemover
 * \return
 */
Matriz* removerColuna(Matriz* inicio, int colunaParaRemover) {

    // Verifica se a coluna a ser removida e valida
    if (colunaParaRemover < 1) {
        return inicio; // Retorna a matriz original se a coluna for invalida.
    }

    Matriz* auxMatriz = inicio;// apontador auxiliar para percorrer a lista de linhas

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

    // Verifica se a coluna a ser removida  valida
    if (colunaParaRemover < 1) {
        printf("Coluna invalida");
        return inicio; 
    }

    Linha* auxColuna = inicio;
    Linha* colunaAntes = NULL;


    int colunaAtual = 1;// Contador de colunas

    //remover primeira coluna
    if (colunaParaRemover == 1) {
        auxColuna = inicio->proximo;
        free(inicio);
        inicio = auxColuna;
        return inicio;

    }

    // Percorre a lista de colunas
    while (auxColuna != NULL)
    {
        // Se encontrarmos a coluna a ser removida
        if (colunaAtual == colunaParaRemover)
        {
            // Ajusta o apontador da coluna anterior para apontar para a proxima coluna
            colunaAntes->proximo = auxColuna->proximo;
            free(auxColuna);
            //free(c)
            return inicio;
        }

        // Incrementa os apontadores e o contador para a proxima iteracao
        colunaAtual++;
        colunaAntes = auxColuna;
        auxColuna = auxColuna->proximo;
    }

    //a linha nao foi encontrada
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

    // Inicializa o apontador auxiliar para percorrer a linha.
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


        //avanca com o aux assumindo o valor de proximo
        aux = aux->proximo;
    }

    //linha para separar listas.
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
    if (matriz == NULL) {
        return false;
    }
    Matriz* aux = matriz;
    printf("Matriz:\n");
    while (aux != NULL) {
        printf("Linhas:\n");
        printLinha(aux->inicioLinha);
        aux = aux->proximo;
    }
    return true;
}




/**
 * Funcao para alterar o valor de um valor em uma matriz..
 *
 * \param inicio
 * \param linha
 * \param coluna
 * \param novoDado
 * \return
 */
bool alterarvalor(Matriz* inicio, int linha, int coluna, int novoDado) {
    // Verifica se a linha e valida
    if (linha < 1)
    {
        return false;
    }

    // Verifica se a coluna e valida
    if (coluna < 1)
    {
        return false;
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
            // Inicializa o apontador para percorrer a lista da Linha.
            auxLinha = auxMatriz->inicioLinha;

            // Percorre a lista da Linha.
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

            return false;
        }
        // conta as listas que foram percorridas
        linha_Atual++;
        auxMatriz = auxMatriz->proximo;
    }

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

    // Define o valor da nova linha  como o valor fornecido.
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

    return inicio; // Retorna o apontador para o inicio da lista.
}

/**
 * Funcao para fazer a soma total da matriz sem repetir coluna e linha,testado com array de 5x5 .
 *
 * \param iniciomatriz
 * \return da return da soma total da matriz sem repetir coluna e linha
 */
int somamatriz(Matriz* iniciomatriz) {
    //int* array;
    // Chama a função para criar o array
    //int tamanho1 = matrizTotal;
   // int* coluna = criarArray(tamanho1);


    //ter um array com os valores da row e coluna que se podem usar
    int coluna[] = { 1, 2, 3, 4, 5 };
    int tamanho = sizeof(coluna) / sizeof(coluna[0]);




    // Verifica se a coluna e valida
    /*if (cols < 1)
    {
        printf("coluna invalida");
    }*/


    Matriz* auxMatriz = iniciomatriz;

    Linha* auxLinha = NULL;
    int linhaentrar = 1;
    int colunaentrar = 1;
    // Armazena as posicoes 
    int linha_Atual = 1;
    int coluna_Atual = 1;
    int valor_maior = 1;
    int guardar_coluna_do_maior = 0;
    int guardar_linha_do_maior = 0;
    int soma = 0;
    // Percorre a lista de Matriz.
    while (auxMatriz != NULL)
    {
        
        for (int i = 0; i < tamanho; i++) {

            // Inicializa o apontador para percorrer a lista de Linha.
            auxLinha = auxMatriz->inicioLinha;

            // Percorre a lista de Linha.
            while (auxLinha != NULL)
            {

                if (valorExiste(coluna, tamanho, coluna_Atual)) {

                    // Se a coluna atual for a coluna desejada.
                    if (auxLinha->valor > valor_maior) {
                        valor_maior = auxLinha->valor;
                        guardar_coluna_do_maior = coluna_Atual;
                        guardar_linha_do_maior = linha_Atual;
                        // Removendo o elemento de índice 2 (valor 3)
                      //  removerElemento(rows, &tamanho, linha_Atual - 1);
                    }


                }

                // Atualiza a coluna atual e avanca para a proxima lista
                coluna_Atual++;
                auxLinha = auxLinha->proximo;
            }



            i = tamanho;
        }


        // conta as listas que foram percorridas
        linha_Atual++;
        coluna_Atual = 1;
        soma += valor_maior;
        valor_maior = 0;
        //  tamanho = removerElemento(coluna, tamanho, guardar_coluna_do_maior - 1);
        int index = guardar_coluna_do_maior - 1;
        int size = tamanho;

        if (index < 0) {
            printf("Índice inválido\n");
            return;
        }
        if (size == 2) {
            index = 1;
        }
        if (size == 1) {
            index = 0;
        }
        //atualiza o array para eliminar a coluna do valor maior
        for (int i = index; i < size; ++i) {
            coluna[i] = coluna[i + 1];
        }
        tamanho = size - 1;
        /* printf("Array apos a remocao:\n");
         for (int i = 0; i < tamanho; ++i) {
             printf("%d ", coluna[i]);
         }
         printf("\n");*/
        guardar_coluna_do_maior = 0;
        guardar_linha_do_maior = 0;

        //ir para a proxima lista
        auxMatriz = auxMatriz->proximo;


    }

    return soma;
}


int removerElemento(int array[], int size, int index) {
    if (index < 0 || index >= size) {
        printf("Indice invalido\n");
        return;
    }

    for (int i = index; i < size - 1; ++i) {
        array[i] = array[i + 1];
    }

    return size - 1;
}

bool valorExiste(int array[], int tamanho, int valor) {
    for (int i = 0; i < tamanho; i++) {
        if (array[i] == valor) {
            return true; // Valor encontrado no array
        }
    }
    return false; // Valor não encontrado no array
}

int* criarArray(int tamanho) {
    int* array = malloc(tamanho * sizeof(int)); // Aloca memória para o array

    if (array == NULL) { // Verifica se a alocação foi bem-sucedida
        printf("Erro ao alocar memória.\n");
        return NULL;
    }

    // Preenche o array com números de 1 até o tamanho da matriz
    for (int i = 0; i < tamanho; i++) {
        array[i] = i + 1;
    }

    return array;
}