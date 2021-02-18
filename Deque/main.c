#include "deque.h"

int main(void){
	Deque *d = cria(); //Cria um ponteiro que aponta para o primeiro endereço da lista dupla e inicializa a lista vazia
	d = insereIni(d, 5);
	d = insereIni(d, 3);
	d = insereFim(d, 11);
	d = insereFim(d, 1);
	//imprime(d); 
	printf("Valor removido do inicio: %d \n", eliminaIni(d)); //Elimina o primeiro elemento
	//imprime(d);
	printf("Valor removido do final: %d \n", eliminaFim(d)); //Elimina o último elemento
	//imprime(d);
	libera(d);
	
	return 0;
}
