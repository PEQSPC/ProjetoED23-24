/**
 * @file teste.h
 * @author Teles Gomes
 * @contact : telesgomes96@gmail.com
 * @copyright Copyright (c) 2024
 *
 */

#include "teste.h"
#include <stdio.h>
#include <stdlib.h>

void printMatriz(Matrix* matriz) {
	Matrix* aux = matriz;

	while (aux != NULL) {
		printLinha(aux->sta);
		aux = aux->proximo;
	}
}


int main() {

	Matrix* startmatrix = NULL;
	Node* startline = NULL;

	startmatrix = carregarFicheiroMatriz("matriz.txt");
	//printMatriz(inicioMatriz);

	//alterarDado(startmatrix, 1, 2, 30);
	//printMatriz(inicioMatriz);

	//inicioMatriz = removerLinhaExistente(inicioMatriz, 5);

	if (startmatrix != NULL) {
		startline = startmatrix-;
	}

	//startline = removerColuna(startline, 1);
	printMatriz(startline);

	return 0;

}