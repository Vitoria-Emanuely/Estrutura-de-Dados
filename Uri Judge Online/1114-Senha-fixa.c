/* Programa que repete a leitura de uma senha at� que ela seja v�lida */

#include <stdio.h>

/* Fun��o senha que verifica se a senha digitada � v�lida */
int senha(int s){
    if (s == 2002){ //Se s for igual a 2002 (senha v�lida)
        printf("Acesso Permitido\n"); //Imprime na tela
        return 0; //Encerra o algoritmo
    }
    printf("Senha Invalida\n"); //Imprime na tela
    scanf("%d", &s); //Guarda o valor digitado no endere�o de s
    return senha(s); //Retorna recursivamente a fun��o para repetir a leitura da senha at� que seja v�lida (s == 2002)
}

/* Fun��o principal */
int main(void){
    int s; //Declara vari�vel s do tipo inteiro
    scanf("%d", &s); //Guarda o valor digitado no endere�o de s
    senha(s); //Faz a primeira chamada para a fun��o senha
    return 0; //Encerra o programa
}
