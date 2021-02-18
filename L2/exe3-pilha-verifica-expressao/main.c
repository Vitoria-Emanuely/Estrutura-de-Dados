#include "pilha.h"

int main(void){
	char a[] = "a+(b*c)-2-a"; //Correto
	char b[] = "(a+b*(2-c)-2+a)*2"; //Correto
	char c[] = "(a * b - (2 + c)"; //Incorreto
	char d[] = "2 * (3 - a))"; //Incorreto
	char e[] = ")3 + b * (2 - c)("; //Incorreto
	verifica(a);
	verifica(b);
	verifica(c);
	verifica(d);
	verifica(e);
	return 0;
}
