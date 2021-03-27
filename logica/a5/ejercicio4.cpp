#include <iostream>
#include <stdio.h>

using namespace std;

struct Alumno{
    char matricula[9];
    char nombre[30];
    char carrera[30];
    float promedio;
    char direccion[60];
};

//Funciones prototipo
struct Alumno pedirDatos(struct Alumno alumno);
void imprimirDatosEstudiante(struct Alumno alumno);

int main()
{
    struct Alumno alumno1; 
    alumno1 = pedirDatos(alumno1);
    imprimirDatosEstudiante(alumno1);
    
    return 0;
}

struct Alumno pedirDatos(struct Alumno alumno){
    printf("Ingrese la matricula del estudiante: ");
    scanf("%s", alumno.matricula);
    printf("Ingrese el nombe del estudiante: ");
    scanf(" %[^\n]s",alumno.nombre);
    printf("Ingrese la carrera del estudiante: ");
    scanf(" %[^\n]s", alumno.carrera);
    printf("Ingrese el promedio del estudiante: ");
    scanf("%f", &alumno.promedio);
    printf("Ingrese la direccion del estudiante: ");
    scanf(" %[^\n]s", alumno.direccion);
    printf("\n");
    return alumno;
}

void imprimirDatosEstudiante(struct Alumno alumno){
    printf("Datos del estudiante:\n\n");
    printf("La matricula del estudiante es: %s\n", alumno.matricula);
    printf("El nombre del estudiante es: %s\n", alumno.nombre);
    printf("La carrera del estudiante es: %s\n", alumno.carrera);
    printf("El promedio del estudiante es: %f\n", alumno.promedio);
    printf("La direccion del estudiante es: %s\n", alumno.direccion);
}
