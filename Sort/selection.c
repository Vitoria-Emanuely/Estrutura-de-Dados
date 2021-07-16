//Exemplo Selection Sort

#include <stdio.h>
void selection_sort(int vetor[], int n){ 
	int i, j, min, aux;
	for (i = 0; i < (n-1); i++){
		min = i;
    	for (j = (i+1); j < n; j++) {
    		if(vetor[j] < vetor[min]) 
        	min = j;
    	}
    	if (i != min) {
    		aux = vetor[i];
       		vetor[i] = vetor[min];
        	vetor[min] = aux;
    	}
	}
}

int main(){
    int v[] = {5, 4, 2, 3};
    selection_sort(v, 4); 
    return 0;
}
