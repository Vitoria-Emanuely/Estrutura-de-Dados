#include <stdio.h>
int imprimir(int n);
int main(){
    imprimir(2);
    return 0;
}

int imprimir(int n){
    if (n >= 2 && n <= 100){
        printf("%d\n", n);
        int x;
        x = imprimir(n + 2);
        return x;
    }    
}
