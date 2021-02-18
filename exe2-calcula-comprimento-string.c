 /* Programa que calcula o comprimento (n�mero de caracteres de uma string */
 
 #include <stdio.h>
void tamanho(char *str, int *strsize);
 
 int main(void){
 	char str[200]; //Define a quantidade m�xima que o vetor armazena
	int size = 0;
 	printf("Digite a palavra que deseja calcular o comprimento: \n");
 	scanf("%s", str);
 	tamanho(str, &size); 
 	return 0;
 }
 
void tamanho(char *str, int *strsize){
	/* Enquanto o caracter na posi��o do conte�do do ponteiro strsize for diferente de \0 (onde termina o caracter) */
    while(str[*strsize] != '\0'){
        (*strsize)++;	//Soma 1 no conte�do do ponteiro de strsize
	}
	printf("A palavra digitada possui %d caracteres", *strsize);	
}


