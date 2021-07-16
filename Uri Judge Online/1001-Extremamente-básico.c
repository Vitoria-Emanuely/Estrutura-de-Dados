#include <stdio.h>

int main() {
	int A, B, X; //Declaração de variáveis
	printf("Digite o valor de A: \n");
	scanf("%d", &A); //Guarda o valor digitado no endereço de A
	printf("Digite o valor de B: \n");
	scanf("%d", &B); //Guarda o valor digitado no endereço de B
	X = A + B; //X recebe a soma de A com B 
	printf("X = %d \n", X);
	
	return 0;
}
