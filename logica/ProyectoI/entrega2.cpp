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
void pantallaResultadosBusqueda();
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
                cout<<"Estudiante "<<alumnos[0].nombre<<endl;
                break;
            case 2:
                pantallaBusqueda();
                scanf("%d", &matricula);
                posResultado = getAlumnoPorMatricula(alumnos, matricula, pos);
                
                if(posResultado == -1){
                    cout<<"No se ha encontrado :("<<endl;
                }else{
                    cout<<"Se ha encontrado! "<<endl;
                }
                break;
            case 3: 
                pantallaModificar();
                break;
            case 4:
                pantallaEliminar();
                scanf("%d", &matricula);
                eliminarAlumno(alumnos, matricula);
                
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

void pantallaResultadosBusqueda(){
    printf("Resultados de la consulta: \n\nNombre: \nApellido paterno: \nApellido materno: \nCarrera: \nSemestre: \n\n");
}

void pantallaModificar(){
        printf("Ingresa los datos a modificar: \n\nMatricula: \nNombre: \nApellido paterno: \nApellido materno: \nCarrera: \nSemestre: \n\n");
}

void pantallaEliminar(){
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
    if(r_pos!=-1){
        for(int i=r_pos; i<n; i++){
            if(i+1<n){
                alumnos[i] = alumnos[i+1];
            }
        }
        pos--;
    }else{
        printf("No se ha encontrado :( ");
    }
}
