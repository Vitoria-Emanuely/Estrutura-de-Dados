/* Programa que ordena os valores informados em ordem crescente */

/* Biblioteca */
#include <stdio.h>
int ordena(int *p1, int *p2, int *p3);

/* Função principal */ 
int main(void){
	int a, b, c; /* Declaração de variáveis */
	/* Atribuição de valores */ 
	printf("Digite o primeiro valor: \n");
	fflush(stdin);
	scanf("%d", &a);
	printf("Digite o segundo valor: \n");
	fflush(stdin);
	scanf("%d", &b);
	printf("Digite o terceiro valor: \n");
	fflush(stdin);
	scanf("%d", &c);
	ordena(&a, &b, &c);
	printf("O menor valor seria %d, o segundo menor valor seria %d e o maior valor seria %d \n", a, b, c);
	return 0;
}

int ordena(int *p1, int *p2, int *p3){
	int temp; /* Declara a variável */
	/* Verifica se os valores de acordo com as condições e organiza nas variáveis */
	if (*p3 < *p2){
		temp = *p3;
		*p3 = *p2;
		*p2 = temp;
	}
	
	if (*p1 > *p2){
		temp = *p2;
		*p2 = *p1;
		*p1 = temp;
	}
	
	if (*p2 > *p3){
		temp = *p3;
		*p3 = *p2;
		*p2 = temp;		
		}
			
	if (*p1 == *p2 && *p1 == *p3){  /* Valores iguais retorna 1 */
		return 1;
	}else{

		return 0; /* Se não 0 */
	}

}
