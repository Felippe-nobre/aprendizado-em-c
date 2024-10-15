#include <stdio.h>

int main() {
    int num, i;
    float fatorial = 1;
    printf("Digite um número de 0 a 10: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Fatorial não definido para números negativos.\n");
    }else if (num > 10)
    {
        printf("Fatorial não definido por ser maior que o numero aceito.\n");
    } else
    {
        for (i = 1; i <= num; i++) {
            fatorial *= i;
        }
        printf("Fatorial de %d é %.f\n", num, fatorial);
    
    }
    return 0;
}
