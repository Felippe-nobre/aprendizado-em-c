#include <stdio.h>
#include <math.h>

int numeroPrimo(int n){

    if (n <= 1)
    {
       return 0;
    }
    for (int i = 2; i < sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
        
    }
    return 1; 
    
}

int main(){

    int num;
    printf("Digite um numero inteiro: ");
    scanf("%d", &num);
    if (numeroPrimo(num))
    {
        printf("%d é um numero primo. \n", num);
    }
    else
    {
        printf("%d nao é numero primo \n", num);
    }
    


    return 0;
}