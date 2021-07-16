#include "arvbin.h"

int main(void){
	/*Arv *a = cria('a', cria('b',
							inicializa(),
							cria('d', inicializa(), inicializa())),
						cria('c',
							cria('e', inicializa(), inicializa()),
							cria('f', inicializa(), inicializa())
							)
				);	
	a->esq->esq = cria('x',
						cria('y', inicializa(), inicializa()),
						cria('z', inicializa(), inicializa())
						);
	a->dir->esq = libera(a->dir->esq);*/
	Arv *a = cria('A', cria('B',
							inicializa(),
							cria('C', inicializa(), inicializa())),
						cria('D',
							cria('E', 
								cria('F', inicializa(), inicializa()),
								cria('G', inicializa(), inicializa())),
							cria('H', 
								cria('I', inicializa(), inicializa()),
								inicializa())
							)
				);
	
	Arv *b = cria('a', cria('b',
							inicializa(),
							cria('d', inicializa(), inicializa())),
						cria('c',
							cria('e', inicializa(), inicializa()),
							cria('f', inicializa(), inicializa())
							)
				);
	
	Arv *c = cria('+', cria('*',
							cria('+', 
								cria('3', inicializa(), inicializa()),
								cria('6', inicializa(), inicializa())),
							cria('-', 
								cria('4', inicializa(), inicializa()),
								cria('1', inicializa(), inicializa()))
							),	
						cria('5', inicializa(), inicializa())
				);
	
	Arv *d = cria('2',  cria('7',
							cria('3', inicializa(), inicializa()),
							cria('6', 
								cria('5', inicializa(), inicializa()),
								cria('1', inicializa(), inicializa()))
							),	
						cria('8',
							inicializa(),
							cria('9', 
								cria('4', inicializa(), inicializa()),
								inicializa())
							)
				);				
				
					
	printf("1. ");	
	printf("Pre-ordem: ");						
	imprimePreOrdem(a);
	printf("\n");
	printf("   In-ordem: ");	
	imprimeInOrdem(a);
	printf("\n");
	printf("   Pos-ordem: ");	
	imprimePosOrdem(a);
	printf("\n");
	printf("\n");
	
	printf("2. ");
	printf("Pre-ordem: ");
	imprimePreOrdem(b);
	printf("\n");
	printf("\n");
	
	printf("3. ");
	printf("Ordem simetrica: ");
	imprimeInOrdem(c);
	printf("\n");
	printf("   Pos-ordem: ");
	imprimePosOrdem(c);
	printf("\n");
	printf("\n");
	
	printf("4. ");
	printf("Ordem simetrica: ");
	imprimeInOrdem(d);
	printf("\n");
	printf("   Pre-ordem: ");						
	imprimePreOrdem(d);
	printf("\n");
	printf("   Pos-ordem: ");
	imprimePosOrdem(d);
	printf("\n");
	
	libera(a);	
	libera(b);		
	libera(c);	
	libera(d);
	return 0;					
}
