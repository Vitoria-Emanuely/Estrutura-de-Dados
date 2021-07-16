/* Programa que lê 1 valor inteiro N(2 < N < 1000) e mostra a tabuada de N: 1 x N = N até 10 x N = 10N recursivamente */

#include <stdio.h>

/* Função tabuada que monta a tabuada recursivamente */
int tabuada (int i, int n){
    if (i > 10){ //Se i for maior que 10  
        return 0; //Termina a tabuada
    }
    printf ("%d x %d = %d\n", i, n, i * n); //Imprime na tela 
    return tabuada(i + 1, n); //Retorna recursivamente a função para fazer a próxima linha da tabuada, passando i + 1 para fazer o "andamento" da tabuada, onde será chamada até i == 10
}

/* Função principal */
int main (void){
    int n; //Declara variável n do tipo inteiro
    scanf ("%d", &n); //Guarda o valor digitado no endereço de n
    if (n < 2 || n > 1000){ //Se n for menor que 2 ou maior que 1000 -> respeitando N (2 < N < 1000)
        scanf ("%d", &n); //Guarda o valor digitado no endereço de n
    }
    tabuada(1, n); //Faz a primeira chamada para a função tabuada
    return 0; //Encerra o programa
}
