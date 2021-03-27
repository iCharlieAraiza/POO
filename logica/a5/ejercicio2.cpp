#include <iostream>
#include <stdio.h>

using namespace std;

void pedirCalificaciones(int [], int);
void promedio(int [], int);

int main()
{
    int n;
    
    printf("Cuantas calificaciones deseas agregar?: ");
    scanf("%d", &n);
    int calificaciones[n];
    
    pedirCalificaciones(calificaciones, n);
    promedio(calificaciones, n);
    
    return 0;
}

void pedirCalificaciones(int calificaciones[], int n){
    int calificacion;
    for(int i = 0; i < n; i++){
        do{
            printf("Ingresa la calificacion %d: ", i+1);
            scanf("%d", &calificacion);
            
            if(calificacion<0 || calificacion>10){
                printf("Ups, has agregado un valor no válido");
            }else{
                calificaciones[i] = calificacion; 
            }
        }while(calificacion<0 || calificacion>10);
    }
    printf("\n");
}

void promedio(int calificaciones[], int n){
    int sumaCalificaciones = 0;
    for(int i = 0; i < n; i++){
        sumaCalificaciones += calificaciones[i];
    }
    printf("El promedio es: %f", (float) sumaCalificaciones/n);
}
