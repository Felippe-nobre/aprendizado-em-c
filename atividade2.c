#include <stdio.h>

int main(){
    
    float nota1,nota2,nota3,media;
    
    printf("\nDigite a primeira nota: ");
    scanf("%f", &nota1);
    
    printf("\nDigite a segunda nota: ");
    scanf("%f", &nota2);

    printf("\nDigite a terceira nota: ");
    scanf("%f", &nota3);
    
    media = (nota1 + nota2 + nota3)/ 3;
    
    if(media >= 7){
        printf("\nmedia%.2fAprovado\n", media);
    }else if (media >=5 && media < 7)
    {
        printf("\n media %.2f Recuperacao\n", media);
    }
     
    else {
        printf("\nmedia %.2fReprovado\n", media);
    }

    return 0;
    
}