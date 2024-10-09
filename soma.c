#include <stdio.h>

int main(){
    float num1,num2, soma,resultado;
    

    printf("Digite o primeiro numero: ");
    scanf("%f", &num1);

    printf("Digite o segundo numero: ");
    scanf("%f", &num2);

     resultado  = num1 + num2;
    
    printf("O resultado da conta: %.f", resultado);

    return 0;
}