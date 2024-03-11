#include "main.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h> // para a fun��o malloc

#define FILENAME "matriz.txt"

#pragma region Primeira Pergunta Trabalho
//// Estrutura do n� da lista ligada
//typedef struct Line {
//    int value;
//    struct Line* next;
//} Line;
//
//// Fun��o para criar um novo n�
//Line* CreateValue(int value) {
//    Line* aux = (Line*)malloc(sizeof(Line));
//    if (aux == NULL) return NULL;
//    aux->value = value;
//    aux->next = NULL;
//    return aux;
//}
//
//// Fun��o para inserir um novo n� no final da lista
//Line* Insertintolist(Line* inicio, Line* novo) {
//    if (novo == NULL) return inicio;
//    if (inicio == NULL) {
//        return novo;
//    }
//
//    Line* aux = inicio;
//    while (aux->next != NULL) aux = aux->next;
//    aux->next = novo;
//    return inicio;
//}
//
//// Fun��o para mostrar um �nico n�
//bool ShowLine(Line* p) {
//    if (p == NULL) return false;
//    printf("Value: %d\n", p->value);
//    return true;
//}
//
//// Fun��o para mostrar todos os n�s da lista
//bool ShowallLines(Line* inicio) {
//    if (inicio == NULL) return false;
//    Line* aux = inicio;
//    while (aux != NULL) {
//        ShowLine(aux);
//        aux = aux->next;
//    }
//    return true;
//}
#pragma endregion

/// Funcao para criar uma nova celula da matriz
MatrixCell* createMatrixCell(int value, int row, int col) {
    MatrixCell* cell = (MatrixCell*)malloc(sizeof(MatrixCell));
    ///Verifica se a celula foi mal criada
    if (cell == NULL) {
        printf("Erro: Falha ao alocar mem�ria para a c�lula.\n");
        exit(1);
    }
    
    cell->value = value; /// Apontador que aponta para o valor value na struct
    cell->row = row; /// adiciona o valor row na struct MatrizCell
    cell->col = col;
    cell->nextRow = NULL;
    cell->nextCol = NULL;
    return cell;
}

/// Fun��o para inicializar a matriz com um n�mero espec�fico de linhas e colunas
Matrix* initializeMatrix(int rows, int cols) {
    Matrix* matrix = (Matrix*)malloc(sizeof(Matrix));
    if (matrix == NULL) {
        printf("Erro: Falha ao alocar mem�ria para a matriz.\n");
        exit(1);
    }
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->head = NULL;
    // Criar c�lulas para cada elemento da matriz
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            MatrixCell* cell = createMatrixCell(0, i, j); // Valor inicial � 0
            // Conectar c�lulas na linha
            if (matrix->head == NULL || i == 0) {
                cell->nextRow = matrix->head;
                matrix->head = cell;
            }
            else {
                MatrixCell* temp = matrix->head;
                while (temp->nextRow != NULL && temp->nextRow->col < j)
                    temp = temp->nextRow;
                cell->nextRow = temp->nextRow;
                temp->nextRow = cell;
            }
            // Conectar c�lulas na coluna
            if (i > 0) {
                MatrixCell* temp = matrix->head;
                while (temp->nextCol != NULL && temp->nextCol->row < i)
                    temp = temp->nextCol;
                cell->nextCol = temp->nextCol;
                temp->nextCol = cell;
            }
        }
    }
    return matrix;
}

/// Fun��o para imprimir a matriz
void printMatrix(Matrix* matrix) {
    if (matrix == NULL || matrix->head == NULL) {
        printf("Matriz vazia.\n");
        return;
    }
    MatrixCell* temp = matrix->head;
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            if (temp != NULL && temp->row == i && temp->col == j) {
                printf("%d\t", temp->value);
                temp = temp->nextRow;
            }
            else {
                printf("0\t"); // Se a c�lula n�o existir, o valor � 0
            }
        }
        printf("\n");
    }
}


/// Fun��o para salvar a matriz em um arquivo
void saveMatrixToFile(Matrix* matrix) {
    FILE* fp;
    fp = fopen_s(&fp,FILENAME, "w");
    if (fp == NULL) {
        printf("Erro: N�o foi poss�vel criar o arquivo %s.\n", FILENAME);
        exit(1);
    }

    MatrixCell* temp = matrix->head;
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            if (temp != NULL && temp->row == i && temp->col == j) {
                fprintf(fp, "%d\t", temp->value);
                temp = temp->nextRow;
            }
            else {
                fprintf(fp, "0\t"); // Se a c�lula n�o existir, o valor � 0
            }
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
    printf("Matriz salva com sucesso em %s\n", FILENAME);
}