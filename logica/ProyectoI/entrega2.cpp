#include <iostream>
#include <stdio.h>
#define n 10

using namespace std;

int pos = 0;


struct Alumno{
    int matricula;
    char nombre[30];
    char apellido_p[30];
    char apellido_m[30];
    char carrera[30];
    char email[60];
    int semestre;
};


void pantallaInicio();
void pantallaRegistro();
void pantallaBusqueda();
void pantallaResultadosBusqueda(struct Alumno alumno);
void pantallaModificar();
void pantallaEliminar();

void agregarAlumno(struct Alumno alumnos[n], int);
int getAlumnoPorMatricula(struct Alumno alumnos[n], int matricula, int pos);
void eliminarAlumno(struct Alumno alumnos[n], int);

int main()
{
    int op;
    int posResultado, matricula;
    struct Alumno alumnos[n];
    
    do{
        pantallaInicio();
        scanf("%d",&op);
        
        switch(op){
            case 1:
                agregarAlumno(alumnos, pos++);
                printf("\n");
                break;
            case 2:
                pantallaBusqueda();
                scanf("%d", &matricula);
                posResultado = getAlumnoPorMatricula(alumnos, matricula, pos);
                
                if(posResultado == -1){
                    printf("No se ha encontrado :( \n");
                    printf("********************\n");
                }else{
                    pantallaResultadosBusqueda(alumnos[posResultado]);
                }
                printf("\n");
                break;
            case 3: 
                pantallaModificar();
                break;
            case 4:
                pantallaEliminar();
                scanf("%d", &matricula);
                eliminarAlumno(alumnos, matricula);
                printf("\n");
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


/**
*   Impresiones de pantalla
**/


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
    printf("******************\n");
    printf("Busqueda de alumno: \n\nIngresa la matricula del alumno: ");
}

void pantallaResultadosBusqueda(struct Alumno alumno){
    //printf("Resultados de la consulta: \n\nNombre: \nApellido paterno: \nApellido materno: \nCarrera: \nSemestre: \n\n");
    printf("******************\n");
    printf("Resultados de la consulta: \n\n");
    printf("Nombre: %s \n", alumno.nombre);
    printf("Apellido paterno: %s \n", alumno.apellido_p);
    printf("Apellido materno: %s \n", alumno.nombre);
    printf("Carrera: %s \n", alumno.carrera);
    printf("Semestre: %d \n", alumno.semestre);
    printf("Email: %s \n", alumno.email);
}

void pantallaModificar(){
        printf("Ingresa los datos a modificar: \n\nMatricula: \nNombre: \nApellido paterno: \nApellido materno: \nCarrera: \nSemestre: \n\n");
}

void pantallaEliminar(){
    printf("******************\n");
    printf("Eliminación del alumno: \n\nIngresa la matricula del alumno: ");
}



/**
*   Operaciones del CRUD
**/

void agregarAlumno(struct Alumno alumnos[n], int pos){
    struct Alumno alumno = alumnos[pos];
    
    printf("\nIngresa los datos \n\nMatricula (número entero): ");
    scanf("%d", &alumno.matricula);
    printf("Alumno: ");
    scanf(" %[^\n]s",alumno.nombre);
    printf("Apellido paterno: ");
    scanf(" %[^\n]s",alumno.apellido_p);
    printf("Apellido materno: ");
    scanf(" %[^\n]s",alumno.apellido_m);
    printf("Carrera: ");
    scanf(" %[^\n]s",alumno.carrera);
    printf("Email: ");
    scanf(" %[^\n]s",alumno.email);
    printf("Semestre: ");
    scanf("%d", &alumno.semestre);
    
    alumnos[pos] = alumno;
    printf("\nSe ha agregado correctamente\n");
}

int getAlumnoPorMatricula(struct Alumno alumnos[n], int matricula, int pos){
    for(int i = 0; i<pos; i++){
        if(alumnos[i].matricula == matricula){
            return i;
        }    
    }
    return -1;
}

void eliminarAlumno(struct Alumno alumnos[n], int matricula){
    int r_pos = getAlumnoPorMatricula(alumnos, matricula, pos);
    if(r_pos==-1){
        printf("No se ha encontrado :( \n");
        return;
    }
    
    int op;
    
    do{
        printf("¿Estás seguro de que deseas eliminar al estudiante? 1. Para si / 2. Para no\n");
        scanf("%d", &op);
        if(op < 1 || op>2 ){
            printf("Ups! Has elegido una opción no válida. Vuelve a intentarlo\n");
        }if(op ==2){
            return;
        }
    }while(op !=1);
    

    
    for(int i=r_pos; i<n; i++){
        if(i+1<n){
            alumnos[i] = alumnos[i+1];
        }
    }
    pos--;
}
