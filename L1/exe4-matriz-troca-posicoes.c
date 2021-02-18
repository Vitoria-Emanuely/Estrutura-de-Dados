/* Programa que lê os elementos de uma matriz 3x4 e troca de posição os valores da primeira com os 
da última coluna e imprime a matriz.*/

#include <stdio.h>

/* Função que cria a matriz 3x4 e uma matriz temporária 3x1 e faz as trocas de posições */
void criaMatriz(void){
	int matriz[3][4], i, j, temp[3][1];;
	for (i = 0; i < 3; i++){
		for (j = 0; j < 4; j++){
			printf("Digite o valor da posicao [%d, %d]: \n", i, j); //Cadastra os valores na 3x4
			scanf("%d", &matriz[i][j]);
		}
	}
	/* Guarda os valores na matriz temporária para fazer a troca de posições */
	for (i = 0; i < 3; i++){
		temp[i][0] = matriz[i][0]; 
	}
	
	for (i = 0; i < 3; i++){
		matriz[i][0] = matriz[i][3]; 
	}
	
	for (i = 0; i < 3; i++){
		matriz[i][3] = temp[i][0]; 
	}
	
	/* Imprime a matriz com as posições trocadas */
	for ( i = 0; i < 3; i++){
    	for ( j = 0; j < 4; j++ ){
      	printf ("Elemento[%d, %d] = %d\n", i, j, matriz[i][j]);
		}
    }
}

int main(void){
	criaMatriz();
	return 0;
}
