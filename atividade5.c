#include <stdio.h>
int main(){
    int Numero,i;
    printf("Informe o numero:");
    scanf("%d",&Numero);
    printf("Numeros pares entre 1 e %d:\n",Numero);
    for (i = 1; i <= Numero; i++)
    {
        if (i % 2 == 0)
        {
            printf("%d\n",i);
        }
        
    }
    return 0;
}