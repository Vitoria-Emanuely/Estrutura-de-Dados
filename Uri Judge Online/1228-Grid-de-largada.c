/*  Programa que exibe o número mínimo de ultrapassagens necessárias para se chegar do grid de largada ao grid de chegada. Foi utilizado o método de ordenação Insertion */

#include <stdio.h>

/* Função ordenacao que ordena o vetor v1 em ordem crescente e o v2 o acompanha simultaneamente, guardando o número de ordenações */
void ordenacao(int v1[], int v2[], int n){
    int i, j, chave, chave2; //Declara as variáveis i, j, chave, chave2 do tipo inteiro
    int count = 0; //Declara variável count do tipo inteiro (contador)
    for (i = 1; i < n; i++){ //Percorre os vetores
        chave = v1[i]; //Variável chave recebe o valor de v1 na posição i
        chave2 = v2[i]; //Variável chave2 recebe o valor de v2 na posição i
        j = i - 1; //Variável j recebe o valor de i - 1
        while (j >= 0 && v1[j] > chave){ //Enquanto j for maior ou igual a 0 e v1 na poisção j for maior que chave
            v1[j + 1] = v1[j]; //Variável v1 na posição j + 1 recebe o valor de v1 na posição j
            v2[j + 1] = v2[j]; //Variável v2 na posição j + 1 recebe o valor de v2 na posição j
            j = j - 1; //Variável j recebe o valor de j - 1
            count ++; //Variável count soma 1
        }
        v1[j + 1] = chave; //Variável v1 na posição j + 1 recebe o valor de chave
        v2[j + 1] = chave2; //Variável v2 na posição j + 1 recebe o valor de chave2
    }
	printf("%d\n", count); //Imprime na tela
}

/* Função principal */
int main(void){	
	int largada[24]; //Declara vetor largada de tamanho 24 do tipo inteiro
	int chegada[24]; //Declara vetor chegada de tamanho 24 do tipo inteiro
	int n, i, j; //Declara as variáveis n, i, j do tipo inteiro
	while (scanf("%d", &n) != EOF){ //Enquanto o valor digitado no endereço de n for diferente de EOF (End Of File)
		for (i = 0; i < n; i++){ //Percorre o vetor
			scanf("%d", &largada[i]); //Guarda o valor digitado no endereço do vetor largada na posição i
		}
		for (i = 0; i < n; i++){ //Percorre o vetor
			scanf("%d", &chegada[i]); //Guarda o valor digitado no endereço do vetor chegada na posição i
		}
		int v3[n]; //Declara variável do vetor v3 do tipo inteiro
		for (i = 0; i < n; i++){ //Percorre o vetor 
			for (j = 0; j < n; j++){ //Percorre o vetor
				if (chegada[i] == largada[j]){ //Se o valor chegada na posição i for igual ao valor de largada na posição j
   					v3[i] = j; //Vetor v3 na posição i recebe o valor de j
				}
			}
		}
		ordenacao(v3, chegada, n); //Chama a função ordenacao passando o vetor v3, vetor chegada e n
	}
    return 0; //Encerra o programa
}
