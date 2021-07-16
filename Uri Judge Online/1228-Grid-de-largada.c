/*  Programa que exibe o n�mero m�nimo de ultrapassagens necess�rias para se chegar do grid de largada ao grid de chegada. Foi utilizado o m�todo de ordena��o Insertion */

#include <stdio.h>

/* Fun��o ordenacao que ordena o vetor v1 em ordem crescente e o v2 o acompanha simultaneamente, guardando o n�mero de ordena��es */
void ordenacao(int v1[], int v2[], int n){
    int i, j, chave, chave2; //Declara as vari�veis i, j, chave, chave2 do tipo inteiro
    int count = 0; //Declara vari�vel count do tipo inteiro (contador)
    for (i = 1; i < n; i++){ //Percorre os vetores
        chave = v1[i]; //Vari�vel chave recebe o valor de v1 na posi��o i
        chave2 = v2[i]; //Vari�vel chave2 recebe o valor de v2 na posi��o i
        j = i - 1; //Vari�vel j recebe o valor de i - 1
        while (j >= 0 && v1[j] > chave){ //Enquanto j for maior ou igual a 0 e v1 na pois��o j for maior que chave
            v1[j + 1] = v1[j]; //Vari�vel v1 na posi��o j + 1 recebe o valor de v1 na posi��o j
            v2[j + 1] = v2[j]; //Vari�vel v2 na posi��o j + 1 recebe o valor de v2 na posi��o j
            j = j - 1; //Vari�vel j recebe o valor de j - 1
            count ++; //Vari�vel count soma 1
        }
        v1[j + 1] = chave; //Vari�vel v1 na posi��o j + 1 recebe o valor de chave
        v2[j + 1] = chave2; //Vari�vel v2 na posi��o j + 1 recebe o valor de chave2
    }
	printf("%d\n", count); //Imprime na tela
}

/* Fun��o principal */
int main(void){	
	int largada[24]; //Declara vetor largada de tamanho 24 do tipo inteiro
	int chegada[24]; //Declara vetor chegada de tamanho 24 do tipo inteiro
	int n, i, j; //Declara as vari�veis n, i, j do tipo inteiro
	while (scanf("%d", &n) != EOF){ //Enquanto o valor digitado no endere�o de n for diferente de EOF (End Of File)
		for (i = 0; i < n; i++){ //Percorre o vetor
			scanf("%d", &largada[i]); //Guarda o valor digitado no endere�o do vetor largada na posi��o i
		}
		for (i = 0; i < n; i++){ //Percorre o vetor
			scanf("%d", &chegada[i]); //Guarda o valor digitado no endere�o do vetor chegada na posi��o i
		}
		int v3[n]; //Declara vari�vel do vetor v3 do tipo inteiro
		for (i = 0; i < n; i++){ //Percorre o vetor 
			for (j = 0; j < n; j++){ //Percorre o vetor
				if (chegada[i] == largada[j]){ //Se o valor chegada na posi��o i for igual ao valor de largada na posi��o j
   					v3[i] = j; //Vetor v3 na posi��o i recebe o valor de j
				}
			}
		}
		ordenacao(v3, chegada, n); //Chama a fun��o ordenacao passando o vetor v3, vetor chegada e n
	}
    return 0; //Encerra o programa
}
