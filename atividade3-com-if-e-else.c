#include <stdio.h>

int main(){
    double num1, num2, resultado;
    char operacao;
    printf("\n qual simbolo vai ser a conta (+ - * /):");
    scanf("%c",&operacao);

    printf("Informe o primeiro numero: ");
    scanf("%lf", &num1);

    printf("Informe o segundo nÃºmero: ");
    scanf("%lf", &num2);

   if (operacao == '+')
   {
    resultado = num1 + num2;
        printf("Resultado: %.0lf\n",resultado);
   }else if (operacao == '-')
   {
   resultado = num1 - num2;
    printf("Resultado: %.0lf\n", resultado );
   }else if (operacao == '*')
   {
   resultado = num1 * num2;
    printf("Resultado: %.0lf\n", resultado );
   }else if (operacao == '/')
   {if (num2!=0)
   {
     resultado = num1 / num2;
    printf("Resultado: %.0lf\n", resultado );
   }else
   {
    printf("Erro... a divisao por zero invalida");
   }
   }else{
    printf("Erro...!");
   }
   
   
   
    
    return 0;
}