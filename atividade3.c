#include <stdio.h>

int main(){
    double num1, num2, resultado;
    char operacao;
    
    printf(" qual simbolo vai ser a conta (+ - * /):");
    scanf(" %c",&operacao);
    printf("Informe o primeiro numero: ");
    scanf("%lf", &num1);
    printf("Informe o segundo numero: ");
    scanf("%lf", &num2 );
    

    switch (operacao)
    {
    case '+':
        resultado = num1 + num2;
        printf("Resultado: %.0lf\n",resultado);
        break;
    case '-':
    resultado = num1 - num2;
    printf("Resultado: %.0lf\n", resultado );
        break;
        case '*':
    resultado = num1 * num2;
    printf("Resultado: %.0lf\n", resultado );
        break;
        case '/':
        if (num2!=0)
        {
            resultado = num1 / num2;
        printf("Resultado: %.0lf\n", resultado );
        }else{

            printf("Erro: divisão por zero invalida.\n");

        }
        break;
    default:
        printf("Erro...!");
        break;
    }
    return 0;
}