/* Programa que lê dois pontos A e B(x, y) e exibe a distância entre eles */

#include <stdio.h>
#include <math.h> //Lib de funções para operações matemáticas

/* TAD: Ponto (x, y) */
typedef struct ponto{ //Guarda as interfaces do ponto
	float x; //Coordenada x
	float y; //Coordenada y
} Ponto; //Tipo exportado

/* Função principal */
int main(void){
	Ponto p1, p2; //Declara duas variáveis do tipo Ponto
	float d; //Declara variável que guardará a distância calculada
	printf("Digite as coordenadas do ponto A (x y): \n"); //Imprime na tela
	scanf("%f %f", &p1.x, &p1.y); //Guarda os valores digitados nos endereços respectivamente de p1.x e p1.y
	fflush(stdin); //Limpa o buffer do teclado
	printf("Digite as coordenada do ponto B (x y): \n"); //Imprime na tela
	scanf("%f %f", &p2.x, &p2.y); //Guarda os valores digitados nos endereços respectivamente de p2.x e p2.y
	d = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2)); //Fórmula que calcula a distância, guardada em d
	/* Imprime na tela os valores de p1.x, p2.x, p1.y e p2.y e o resultado do cálculo da distância guardado em d */
	printf("A distancia entre os pontos A(%.2f, %.2f) e B(%.2f, %.2f) seria: %.2f\n", p1.x, p1.y, p2.x, p2.y, d);
	
	return 0; //Encerra o programa
}
