/**
 * @file main.c
 * @author Teles Gomes
 * @date 2024-03
 * @author telesgomes96@gmail.com
 *
 */
#include "Header.h"
#include <stdio.h>
#include <stdbool.h>
#define FILENAME "E:\\C\\ProjetoED_2324\\matriz.txt"

int main() {
	Matriz* inicioMatriz = NULL;
	Linha* inicioLinha = NULL;
	int soma = 0;

	inicioMatriz = carregarFicheiroMatriz(FILENAME);
	//printMatriz(inicioMatriz);

	//alterarvalor(inicioMatriz, 1, 2, 30);
	//printMatriz(inicioMatriz);

	//inicioMatriz = removerLinhaExistente(inicioMatriz, 5);
	//como perdemos o valor do inicio da linha atribuimos o valor que se guarda na matriz outra vez a linha
	if (inicioMatriz != NULL) {
		inicioLinha = inicioMatriz->inicioLinha;
	}

	/*inicioMatriz = removerColuna(inicioMatriz, 1);*/
	printMatriz(inicioMatriz);
	gravarmatrix(inicioMatriz,FILENAME);
	soma = somamatrix(inicioMatriz);
	printf("Soma: %d", soma);
	return 0;
}