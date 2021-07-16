#include <stdio.h>

int main(){
	int horaI, minI, horaF, minF;
	//printf("Digite a hora inicial do jogo: \n");
	scanf("%d", &horaI);
	//printf("Digite o minuto inicial do jogo: \n");
	scanf("%d", &minI);
	//printf("Digite a hora final do jogo: \n");
	scanf("%d", &horaF);
	//printf("Digite o minuto final do jogo: \n");
	scanf("%d", &minF);
	
	int h = horaF - horaI;
	int m = minF - minI;
	
	if (m < 0){
		m += 60;	
		h --;
	}
	if (h < 0)
		h += 24;
	if (horaI == horaF && minI == minF)
		printf("O JOGO DUROU 24 HORA(S) E 0 MINUTO(S)\n");
	else	
		printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", h, m);
	
	return 0;
}
