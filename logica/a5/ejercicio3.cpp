#include <iostream>
#include <stdio.h>

using namespace std;


void llenarMatriz(int(*)[3], char);
void sumarMatrices(int(*)[3], int(*)[3], int(*)[3]);
void imprimirMatriz(int(*)[3]);

int main()
{
    int a[3][3], b[3][3], c[3][3];
    llenarMatriz(a, 'A');
    llenarMatriz(b, 'B');
    sumarMatrices(a, b , c);
    imprimirMatriz(c);
}

void llenarMatriz(int(*m)[3], char n_matriz)
{
    printf("Ingresa el valor de la matriz %c\n", n_matriz);
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int valor; 
            printf("Ingresa el valor (%d,%d): ", i, j);
            scanf("%i",&valor);
            m[i][j] = valor;
        }
    }
    printf("\n");
}

void sumarMatrices(int(*a)[3], int(*b)[3], int(*c)[3]){
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++)
            c[i][j] = a[i][j]+b[i][j];
    }
}

void imprimirMatriz(int(*m)[3]){
    printf("La suma de las matrices es:\n");
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}
