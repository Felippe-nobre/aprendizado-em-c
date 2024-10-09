#include <stdio.h>


int main(){

    int num, i;

     printf("Digete o numero:");
    scanf("%d",&num);

    printf("Tabuada de %d: \n", num);
    for (int i = 1; i <= 10; i++)
    {
       printf("%d x %d = %d\n", num, i, num*i );
    }
    

    return 0;
}