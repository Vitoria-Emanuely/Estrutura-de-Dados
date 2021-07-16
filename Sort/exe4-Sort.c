#include <stdio.h>
#include <stdlib.h>

int compara(int v1, int v2, int mod){
    if (v1 % mod < v2 % mod)
        return 1;
    if (v1 % mod > v2 % mod)
        return 0;
    //abs() pega o valor absoluto    
    //se ambos forem ímpares (arruma embate)
    if (abs(v1 % 2) == 1 && abs(v2 % 2) == 1){    
        if (v1 > v2)
            return 1;
        else
            return 0;
    }        
    //se ambos forem pares (arruma embate)   
    if (abs(v1 % 2) == 0 && abs(v2 % 2) == 0){    
        if (v1 < v2)
            return 1;
        else
            return 0;
    }  
    //se for entre par e ímpar (arruma embate)  
    if (abs(v1 % 2) == 1) 
        return 1;
    else
        return 0;
}

void merge(int vetor[], int comeco, int meio, int fim, int mod){
    int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;
    int *vetAux;
    vetAux = (int*)malloc(tam * sizeof(int));

    while(com1 <= meio && com2 <= fim){
        if(compara(vetor[com1], vetor[com2], mod)) {
            vetAux[comAux] = vetor[com1];
            com1++;
        } else {
            vetAux[comAux] = vetor[com2];
            com2++;
        }
        comAux++;
    }

    while(com1 <= meio){  //Caso ainda haja elementos na primeira metade
        vetAux[comAux] = vetor[com1];
        comAux++;
        com1++;
    }

    while(com2 <= fim){   //Caso ainda haja elementos na segunda metade
        vetAux[comAux] = vetor[com2];
        comAux++;
        com2++;
    }

    for(comAux = comeco; comAux <= fim; comAux++){    //Move os elementos de volta para o vetor original
        vetor[comAux] = vetAux[comAux-comeco];
    }
    
    free(vetAux);
}

void mergeSort(int vetor[], int comeco, int fim, int mod){
    if (comeco < fim) {
        int meio = (fim+comeco)/2;

        mergeSort(vetor, comeco, meio, mod);
        mergeSort(vetor, meio+1, fim, mod);
        merge(vetor, comeco, meio, fim, mod);
    }
}

int main(){
    int n, m, i;    
	// cria o vetor com o tamanho máximo para as entradas.
    int vetor[10001];

	//leitura do n e m
    scanf("%d %d", &n, &m);
    
    while (n>0){
        for (i = 0; i < n; ++i)
			scanf("%d", &vetor[i]);
		
		mergeSort(vetor, 0, n - 1, m);
		
		
		//Imprime a resposta no formato esperado.
		printf("%d %d\n", n, m);
		for (i = 0; i < n; ++i)
			printf("%d\n", vetor[i]);
	    
		
		//leitura do n e m
	    scanf("%d %d", &n, &m);
    }
    
	//Imprime o último par de n e m, mesmo quando for zero.
    printf("%d %d\n", n, m);
    
    return 0;
}
