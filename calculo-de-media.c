#include <stdio.h>


int main(){
    int quantidade = 0;
    float nota, soma = 0.0 , media;
    char continuar;
    do
    {
        printf("Digite a nota do aluno:");
        scanf("%f", &nota);
         soma += nota ;
        quantidade++;
        printf("Dejesa adicionar outra nota (s/n): ");
        scanf(" %c", &continuar);
    } while (continuar == 's');
    if (quantidade > 0)
    {
        media = soma / quantidade;
        printf("Media do aluno: %.2f\n", media);
    }
    else
    {
        printf("Nenhuma nota inserida\n");
    }
    
    

    printf("Digte o valor da nota");



    return 0;
}