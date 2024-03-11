#include "main.h"
#include <stdio.h>
#include <stdbool.h>

int main() {
#pragma region Primeira Pergunta do Trabalho
	//int x;
	//int* p1;			//p é apontador para inteiro!!
	//p1 = &x;			//p fica com o endereço de x

	//x = 1;

	//printf("P: %p\n", p1);
	//printf("&P: %p\n", &p1);
	//printf("*P: %d\n", *p1);


		//Line* inicio = NULL;
		//Line* p10 = CreateValue(10);
		//
		//inicio = Insertintolist(inicio, p10);

		//Line* p30 = CreateValue(30);

		//inicio = Insertintolist(inicio, p30);

		////Apontador inicio da Lista
		//bool aux = ShowallLines(inicio);
#pragma endregion 

	
	Matrix* matrix = initializeMatrix(3, 3); /// Inicializa a matriz 3x3

	createMatrixCell(10, 1, 1);

	/// Imprime a matriz
	printf("Matriz:\n");
	printMatrix(matrix);

	/// Salva a matriz em um arquivo txt
	saveMatrixToFile(matrix);



	return 0;
}