#include <stdio.h>

void quadrado(int i, int n);

int main(){
    int n;
    scanf("%d", &n);

    quadrado(2, n);
    
    return 0;
}

void quadrado(int i, int n){
    if (i <= n){
        printf("%d^2 = %d\n", i, i*i);
        quadrado(i + 2, n);
    }   
}
