/*  Ordenação de dois vetores ao mesmo tempo */

#include <stdio.h>

void insertion_sort(int v1[], float v2[], int n){
    int i, chave, j;
    float chave2;
    for (i = 1; i < n; i++) {
        chave = v1[i];
        chave2 = v2[i];
        j = i - 1;
        while (j >= 0 && v1[j] > chave){
            v1[j + 1] = v1[j];
            v2[j + 1] = v2[j];
            
            j = j - 1;
        }
        v1[j + 1] = chave;
        v2[j + 1] = chave2;
    }
}

int main(){
    int v1[] = {5, 4, 3, 2};
    float v2[] = {0.65, 0.23, 1.2, 0.75};
    insertion_sort(v1, v2, 4); 
    int i;
    for (i = 0; i < 4; i++){
        printf("%d\n", v1[i]);
        printf("%.2f\n", v2[i]);
	}
    return 0;
}
