/**
 * @file main.c
 * @author Teles Gomes
 * @date 2024-03
 * @author telesgomes96@gmail.com
 *
 */
//#include "C:\\Users\\GG\\Desktop\\temp\\header.h"
#include "Header.h"
#include <stdio.h>
#include <stdbool.h>
//#pragma comment(lib,"C:\\Users\\GG\\Desktop\\temp\\LibProjectED.lib")

int main() {
	Matriz* inicioMatriz = NULL;
	Linha* inicioLinha = NULL;
	int soma = 0;

	inicioMatriz = carregarFicheiroMatriz(FILENAME);
	//printMatriz(inicioMatriz);
	
	alterarvalor(inicioMatriz, 3, 4, 260);
	//printMatriz(inicioMatriz);

	//inicioMatriz = removerLinhaExistente(inicioMatriz, 3);
//	removerColuna(inicioMatriz, 3);
	//como perdemos o valor do inicio da linha atribuimos o valor que se guarda na matriz outra vez a linha
	//se for usar alguma funcao com entrada de linha uso este metodo
	if (inicioMatriz != NULL) {
		inicioLinha = inicioMatriz->inicioLinha;
	}

	//inicioMatriz = removerColuna(inicioMatriz, 1);*/
	//printMatriz(inicioMatriz);
	
	soma = somamatriz(inicioMatriz);
	printf("Soma: %d", soma);
	gravarmatriz(inicioMatriz,FILENAMEALT);
	return 0;
}