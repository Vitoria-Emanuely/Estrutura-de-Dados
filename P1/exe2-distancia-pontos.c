/* Programa que l� dois pontos A e B(x, y) e exibe a dist�ncia entre eles */

#include <stdio.h>
#include <math.h> //Lib de fun��es para opera��es matem�ticas

/* TAD: Ponto (x, y) */
typedef struct ponto{ //Guarda as interfaces do ponto
	float x; //Coordenada x
	float y; //Coordenada y
} Ponto; //Tipo exportado

/* Fun��o principal */
int main(void){
	Ponto p1, p2; //Declara duas vari�veis do tipo Ponto
	float d; //Declara vari�vel que guardar� a dist�ncia calculada
	printf("Digite as coordenadas do ponto A (x y): \n"); //Imprime na tela
	scanf("%f %f", &p1.x, &p1.y); //Guarda os valores digitados nos endere�os respectivamente de p1.x e p1.y
	fflush(stdin); //Limpa o buffer do teclado
	printf("Digite as coordenada do ponto B (x y): \n"); //Imprime na tela
	scanf("%f %f", &p2.x, &p2.y); //Guarda os valores digitados nos endere�os respectivamente de p2.x e p2.y
	d = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2)); //F�rmula que calcula a dist�ncia, guardada em d
	/* Imprime na tela os valores de p1.x, p2.x, p1.y e p2.y e o resultado do c�lculo da dist�ncia guardado em d */
	printf("A distancia entre os pontos A(%.2f, %.2f) e B(%.2f, %.2f) seria: %.2f\n", p1.x, p1.y, p2.x, p2.y, d);
	
	return 0; //Encerra o programa
}
