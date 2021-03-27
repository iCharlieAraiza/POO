#include <iostream>
#include <stdio.h>

using namespace std;


void comprobarParImpar(int);

int main()
{
    int n;
    printf("Escribe un numero: \n");
    scanf("%d",&n);
    comprobarParImpar(n);
    return 0;
}

void comprobarParImpar(int n){
    if(n%2==0)
        printf("El numero %d es par", n);
    else
        printf("El numero %d es impar", n);
        
}
