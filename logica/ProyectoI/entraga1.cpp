#include <iostream>
#include <stdio.h>

using namespace std;

void pantallaInicio();
void pantallaRegistro();
void pantallaBusqueda();
void pantallaResultadosBusqueda();
void pantallaModificar();
void pantallaEliminar();

int main()
{
    int op;
    
    do{
        pantallaInicio();
        scanf("%d",&op);
        
        switch(op){
            case 1:
                pantallaRegistro();
                break;
            case 2:
                pantallaBusqueda();
                pantallaResultadosBusqueda();
                break;
            case 3: 
                pantallaModificar();
                break;
            case 4:
                pantallaEliminar();
                break;
            case 5:
                printf("Adios!");
                break;
            default:
                printf("Has elegido una opción no válida");
        }
        
    }while(op!=5);
    
    return 0;
}


void pantallaInicio(){
    printf("***********************\n");
    printf("* Catalogo de alumnos *\n");
    printf("***********************\n\n");
    
    printf("Elige una opción: \n\n1) Agregar a un nuevo alumno \n2) Buscar alumno \n3) Modificar alumno \n4) Eliminar alumno \n5) Salir\n\n");
    
}

void pantallaRegistro(){
    printf("Ingresa los datos: \n\nNombre: \nApellido paterno: \nApellido materno: \nFecha de nacimiento: \nCarrera: \nSemestre: \n\n");
    
}

void pantallaBusqueda(){
    printf("Busqueda de alumno: \n\nIngresa la matricula del alumno: \n\n");
}

void pantallaResultadosBusqueda(){
    printf("Resultados de la consulta: \n\nNombre: \nApellido paterno: \nApellido materno: \nFecha de nacimiento: \nCarrera: \nSemestre: \n\n");
}

void pantallaModificar(){
        printf("Ingresa los datos a modificar: \n\nMatricula: \nNombre: \nApellido paterno: \nApellido materno: \nFecha de nacimiento: \nCarrera: \nSemestre: \n\n");
}

void pantallaEliminar(){
    printf("Eliminación del alumno: \n\nIngresa la matricula del alumno: \n\n");
}
