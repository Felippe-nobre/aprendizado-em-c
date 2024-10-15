#include <stdio.h>

int main(){
    char letra[27]  = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    int numero;
    printf("Digite um numero de 1 a 26:", numero);
    scanf("%d", &numero);

    if (numero < 1 || numero > 26)
    {
        printf("Erro... porfavor digite um numero de 1 a 26");
        return 0;
    }
    
    
    for (int i = 0; i < numero ; i++)
        {
            printf("%c ", letra[i]);
        }




    return 0;
}