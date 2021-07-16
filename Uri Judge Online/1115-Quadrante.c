#include <stdio.h>

int main(){
	int X, Y;
	//printf("Digite a coordenada X: \n");
	scanf("%d", &X);
	//printf("Digite a coordenada Y: \n");
	scanf("%d", &Y);
	
	while(X != NULL || Y != NULL){
		if (X > 0 && Y > 0)
			printf("primeiro\n");
		else if (X < 0 && Y > 0)
			printf("segundo\n");
		else if (X < 0 && Y < 0)
			printf("terceiro\n");	
		else if (X > 0 && Y < 0)
			printf("quarto\n");	
		else
			printf(" \n");	
		//printf("Digite a coordenada X: \n");
		scanf("%d", &X);
		//printf("Digite a coordenada Y: \n");
		scanf("%d", &Y);		
	}
	return 0;
}
