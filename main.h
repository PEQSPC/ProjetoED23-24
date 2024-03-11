#pragma once
#include <stdio.h>
#include <stdbool.h>

#define FILENAME "matriz.txt"

#pragma region Primeira Pergunta do Trabalho
//typedef struct line {
//	int value;
//	struct line* next;
//}Line;
//
///// <summary>
///// Aloca espaço
///// </summary>
///// <param name="x"></param>
//Line* CreateValue(int value);
//
///// <summary> Cria valor na lista</summary>/// <param name="f"></param>/// <param name=""></param>/// <returns></returns>
//Line* Insertintolist(Line* inicio, Line* novo);
//
//
//
//bool ShowLine(Line* p);
//
///// <summary>Mostra todas as linhas na lista ligada</summary>/// <param name="inicio"></param>/// <returns></returns>
//bool ShowallLines(Line* inicio);

#pragma endregion

/// <summary>
/// Estrutura para representar uma celula da matriz
/// </summary>
typedef struct MatrixCell {
    int value;  // Valor da célula
    int row;    // Indice da linha
    int col;    // Indice da coluna
    struct MatrixCell* nextRow;  // Ponteiro para a proxima celula na mesma linha
    struct MatrixCell* nextCol;  // Ponteiro para a próxima celula na mesma coluna
} MatrixCell;


/// <summary>
///  Estrutura para representar a matriz
/// </summary>
typedef struct Matrix {
    int rows;           // Numero de linhas
    int cols;           // Numero de colunas
    MatrixCell* head;   // Ponteiro para a celula na posicao (0, 0)
} Matrix;


/// <summary>
/// Inicializa uma matriz na memoria com uma determina dimensao rows and cols
/// </summary>
/// <param name="rows"></param>
/// <param name="cols"></param>
/// <returns>da return do endereco da matriz</returns>
Matrix* initializeMatrix(int rows, int cols);

/// <summary>
/// Imprime a matriz na consola
/// </summary>
/// <param name="matrix">Entrada da matriz que quer dar display na consola</param>
void printMatrix(Matrix* matrix);


/// <summary>
/// Cria uma celula na matriz
/// </summary>
/// <param name="value">valor a adicionar na matriz</param>
/// <param name="row">escrever as linhas que vai ter a matriz</param>
/// <param name="col">as colunas que vai ter a matriz</param>
/// <returns></returns>
MatrixCell* createMatrixCell(int value, int row, int col);

/// <summary>
/// Adiciona a matriz que entra dum ficheiro txt Matriz.txt
/// </summary>
/// <param name="matrix"> Matriz que quer adicionar no ficheiro</param>
void saveMatrixToFile(Matrix* matrix);




