#pragma once
/**
 * @file main.h
 * @author Teles Gomes
 * @date 2024-03
 * @author telesgomes96@gmail.com
 *
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define FILENAME "E:\\C\\ProjetoED_2324\\matriz.txt"
#define FILENAMEALT "E:\\C\\ProjetoED_2324\\matrizalt.txt"

 /// <summary>
 /// struct para  guardar os valores das celulas  e apontar para o proximo valor
 /// </summary>
typedef struct linha {
	int valor;
	struct linha* proximo;
}Linha;


/// <summary>
/// struct onde fica guardado os inicios das listas e a proxima lista
/// </summary>
typedef struct matriz
{
	Linha* inicioLinha;
	struct matriz* proximo;
}Matriz;


int matrizTotal;

/**
 * GG
 * 2024
 * Carrega o ficheiro e guardas informacoes nas structs linha vai corresponder os valores da matriz,a struct matriz vai guardar o incio da linha e proxima linha
 */
Matriz* carregarFicheiroMatriz(char* nomeFicheiro);
/**
 * GG
 * 2024
 * Imprime na consola uma linha da matriz
 */
bool printLinha(Linha* linha);
/**
 * GG
 * 2024
 * Insere dados numa linha no inicio
 */
Linha* inserirDadosInicioLinha(Linha* inicio, int valorInserir);
/**
 * GG
 * 2024
 * Insere Dados no fim da linha
 */
Linha* inserirDadosFimLinha(Linha* inicio, int valor);
/**
 * GG
 * 2024
 * Insere a linha na matriz
 */
Matriz* inserirNovaLinha(Matriz* inicio, Linha* LinhaInserir);
/**
 * GG
 * 2024
 * Altera Valor na linha onde se escolhe na entrada de dados a linha e coluna do valor para alterar
 */
bool alterarvalor(Matriz* inicio, int linha, int coluna, int novoDado);
/**
 * GG
 * 2024
 * Imprime a matriz toda
 */
bool printMatriz(Matriz* matriz);
/**
 * GG
 * 2024
 * Remove uma linha da matriz
 */
Matriz* removerLinhaExistente(Matriz* inicio, int linhaParaRemover);
/**
 * GG
 * 2024
 * Remove uma coluna da matriz com o uso da struct linha,function usada no removerColuna
 */
Linha* removerColunaExistente(Linha* inicio, int colunaParaRemover);
/**
 * GG
 * 2024
 * Remove coluna da matriz por entrada de valor na function
 */
Matriz* removerColuna(Matriz* inicio, int colunaParaRemover);
/**
 * GG
 * 2024
 * Grava a matriz em memoria num ficheiro txt
 */
Matriz* gravarmatriz(Matriz* iniciomatriz, char* filename);
/**
 * GG
 * 2024
 * Soma os valores mais altos da matriz sem repetir colunas nem linhas
 */
int somamatriz(Matriz* iniciomatriz);
/**
 * GG
 * 2024
 * Funcao secundaria para ser usada na soma matrix,remove um elemento de um array
 */
int removerElemento(int array[], int size, int index);
/**
 * GG
 * 2024
 * Funcao secundaria para ser usada na soma ,verifica se um valor no array existe
 */
bool valorExiste(int array[], int tamanho, int valor);
/**
 * GG
 * 2024
 * Funcao secundaria para ser usada na soma ,cria um array de 0 a int tamanho de valor de entrada
 */
int* criarArray(int tamanho);