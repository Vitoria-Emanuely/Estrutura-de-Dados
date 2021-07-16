#include <stdio.h>

void imprimir(int i, int n);

int main(){
    int X;
    scanf("%d", &X);
    imprimir(1, X);
    return 0;
}

void imprimir(int i, int n){
    if (i <= n){
        printf("%d\n", i);
        imprimir(i + 2, n);
    }   
}
