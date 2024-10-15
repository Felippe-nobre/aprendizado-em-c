#include <stdio.h>

int main(){
    float idade;
    printf("Digite sua idade:" ,idade);
    scanf("\n%f", &idade);

    if (idade < 18)
    {
        printf("menor de idade");
    } else if (idade >= 18 && idade <= 64)
    {
        printf("Adulto");
    } else{
        printf("idoso");
    }
    
    return 0;
}