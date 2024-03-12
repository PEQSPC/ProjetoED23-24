/**
 * @file main.c
 * @author Teles Gomes
 * @date 2024-03
 * @author telesgomes96@gmail.com
 *
 */
#include "main.h"
#include <stdio.h>
#include <stdbool.h>
#define FILENAME "matriz.txt"

int main() {
	Matriz* inicioMatriz = NULL;
	Linha* inicioLinha = NULL;

	inicioMatriz = carregarFicheiroMatriz(FILENAME);
	//printMatriz(inicioMatriz);

	//alterarDado(inicioMatriz, 1, 2, 30);
	//printMatriz(inicioMatriz);

	//inicioMatriz = removerLinhaExistente(inicioMatriz, 5);

	if (inicioMatriz != NULL) {
		inicioLinha = inicioMatriz->inicioLinha;
	}

	/*inicioMatriz = removerColuna(inicioMatriz, 1);*/
	printMatriz(inicioMatriz);

	return 0;
}