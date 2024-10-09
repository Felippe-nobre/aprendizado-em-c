#include <stdio.h>

int main(){
    int num, i;
    long long int fatorial = 1.0;
    printf("Digite um numero para fatorial: \n");
    scanf("%d", &num);

    if (num < 0)
    {
        printf("Coloque numero para fatorial", num);
    }
    else
    {
        for ( i = 1; i <= num; i++)
        {
            fatorial *=i;
            printf("O fatorial de %d: %lld \n", num, fatorial);
        }
        
    }
return 0;
}