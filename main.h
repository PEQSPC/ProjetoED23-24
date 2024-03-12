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


 /// <summary>
 /// Carrega o ficheiro e guardas informaçoes nas structs
 /// </summary>
 /// <param name="nomeFicheiro">matriz.txt</param>
 /// <returns>da return do inicio da matriz</returns>
 Matriz* carregarFicheiroMatriz(char* nomeFicheiro);

 bool printLinha(Linha* linha);
 Linha* inserirDadosInicioLinha(Linha* inicio, int valorInserir);
 Matriz* inserirNovaLinha(Matriz* inicio, Linha* LinhaInserir);
 bool alterarDado(Matriz* inicio, int linha, int coluna, int novoDado);

 bool printMatriz(Matriz* matriz);
