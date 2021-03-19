#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n = 0, i = 0;
    bool par = true;
    
    
    printf("Escribe un numero: ");
    scanf("%d",&n);
    
    
    while(i!=n){
        par = !par;
        i++;
    }
    
    if(par)
        printf("El numero es par\n");
    else
        printf("El numero es impar\n");

    return 0;
}
