#include <stdio.h>
#include <math.h>

int main(){
	double raio, area;
	//printf("Digite o valor do raio: \n");
	scanf("%lf", &raio);
	raio = pow(raio, 2);
	area = 3.14159 * raio;
	printf("A=%.4f \n", area);
	
	return 0;
}
