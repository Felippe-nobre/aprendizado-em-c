#include <stdio.h>

void trianguloLadinho(int ladinho){
int a = 'f';

for (int i = 1; i <= ladinho; i++)
{
    for (int j = 1; j <= i; j++)
    {
       write(1,&a,1);
    }
    write(1,"\n", 1);
}
}
int main(){

    trianguloLadinho(4);

    return 0;
}
