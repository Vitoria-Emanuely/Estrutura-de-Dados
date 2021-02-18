/*Programa para conversão de temperatura. */

#include <stdio.h>
float conversao(float c);

int main(void){
	float t;
	printf("Digite uma temperatura em Celsius: ");
	scanf("%f", &t);
	printf("A temperatura convertida em Fahrenheit seria: %f", conversao(t));
	return 0;
}

float conversao(float c){
	float f = c * 1.8 + 32.0;
	return f;
}
