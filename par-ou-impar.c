#include <stdio.h>

int main(){
    int num1, num2, resultado;

    printf("Digite primeiro numero:");
    scanf("%d", &num1);
    printf("Digite segundo numero:");
    scanf("%d", &num2);
    resultado = (num1 / num2) % 2;
    if (resultado == 0)
    {
        printf("Numero par");
    }
    else
    {
        printf("Numero impar");
    }
    
    return 0;
}