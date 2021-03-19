#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n = 0;
    
    printf("Escribe un numero: ");
    scanf("%d",&n);
    
    if(n%2==0)
        printf("El numero es par\n");
    else
        printf("El numero es impar\n");

    return 0;
}
