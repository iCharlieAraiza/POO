/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n, sum = 0;
    
    printf("Escribe el numero de productos: ");
    scanf("%d",&n);
    
    for(int i = 0; i<n; i++){
        int cantidad, precio;
        
        printf("Articulo %d cantidad: ", i+1);
        scanf("%d",&cantidad);
        printf("Articulo %d precio: ", i+1);
        scanf("%d",&precio);
        sum += cantidad*precio;
    }
    
    printf("\nTotal a pagar es: %d", sum);
    
    return 0;
}