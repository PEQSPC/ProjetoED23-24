/**
 * @file teste.h
 * @author Teles Gomes
 * @contact : telesgomes96@gmail.com
 * @copyright Copyright (c) 2024
 *
 */

#pragma once
#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int value;
    struct Node* next;
}Node;

typedef struct matrix
{
    Node* startline;
    struct Matrix* next;
}Matrix;

void printMatriz(Matrix* matriz);

