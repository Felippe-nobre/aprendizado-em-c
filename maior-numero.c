#include <stdio.h>

int main(){

    int num1,num2;

    printf("Digite primeiro numero:");
    scanf("%d", &num1);
    printf("Digite segundo numero:");
    scanf("%d", &num2);

    if (num1 > num2)
    {
        printf("O primeiro numero (%d)  maior\n", num1);
    }
    else
    {
        printf("O segundo numero (%d)  maior\n", num2);
    }
    



    return 0;
}