//
//  main.cpp
//  Controlescolar
//
//  Created by Carlos Araiza on 16/11/20.
//  Copyright © 2020 Carlos Araiza. All rights reserved.
//

#include <iostream>
using namespace std;

/**
 *  Clase usuario
 *
 */


class Usuario{
    string nombre;
    string apellido;
    int edad;
    string sexo;
    
    public:
    Usuario(string nombre, string apellido, string sexo, int edad) : nombre(nombre), apellido(apellido), edad(edad), sexo(sexo){
    };
    
    void agregarNombre(string nombre){
        this->nombre = nombre;
    };
    
    void agregarApellido(string apellido){
        this->nombre = apellido;
    };
    
    string regresarNombre(){
        return this->nombre;
    }
    
    string regresarApellido(){
        return this->apellido;
    }
};


class Profesor : public Usuario{
    string profesion;
    string cProfesional;
    public:
    Profesor(string nombre, string apellido, string sexo, int edad, string profesion, string cProfesional): Usuario(nombre,apellido, sexo, edad), profesion(profesion), cProfesional(cProfesional) {
    }
    
    string regresarProfesion(){
        return this->profesion;
    }
    
    string regresarCProfesional(){
        return this->cProfesional;
    }
    
    void agregarProfesion(string profesion){
        this->profesion = profesion;
    }
    
    void agregarcProfesion(string cProfesional){
        this->cProfesional = cProfesional;
    }
    
};


class Materia{
    string nombre;
    int creditos;
    
    public:
    Materia(string nombre, int creditos) : nombre(nombre), creditos(creditos){
    };
    
    string regresarNombre(){
        return this->nombre;
    }
};

class Alumno : public Usuario{
    string n_control;
    int semestre;
    string materias[6];
    public:
    Alumno(string nombre, string apellido, string sexo, int edad, string n_control, int semestre): Usuario(nombre,apellido, sexo, edad), n_control(n_control), semestre(semestre) {
    }
    
    string regresarControl(){
        return n_control;
    }
    
    int regresarSemestre(){
        return this->semestre;
    }
    
};



class Grupo{
    int id;
    Materia materia;
    Profesor profesor;
    public:
    Grupo(Materia materia, Profesor profesor): materia(materia), profesor(profesor){
        this->id = 1;
    };
};




int main(int argc, const char * argv[]) {
    
    /*
     Prueba de registro de Alumno, Maestro y Materia
     */
    
    string materias[6] = {"Matemáticas", "Física", "Programación", "Cálculo", "Estructuras", "Sistemas"};
    
    
    Profesor profesorA = Profesor("Luis","Gonzalez","Masculino",40,"Ingeniero","1234459");
    
    cout<<"El nombre del maestro A es "<< profesorA.regresarNombre() << " " << profesorA.regresarApellido()<<endl;
    
    Alumno alumnoA = Alumno("Carlos","Álvares","Masculino",20,"234234234",4);
    cout<<"El nombre del alumno A es "<< alumnoA.regresarNombre() << " " << alumnoA.regresarApellido()<<endl;
    
    Materia materiaA = Materia("Matemáticas", 34);
    cout<<"El nombre de la materia es " << materiaA.regresarNombre()<<endl;
    
    Grupo grupoA = Grupo(materiaA, profesorA);
    
    return 0;
}
