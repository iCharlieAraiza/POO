#include <iostream>

using namespace std;

int id_profesor = 0;
int id_estudiante = 0;
int id_materia = 0;


/**
 *  Clase Usuario
*/

class Usuario {
    int id;
    string nombre;
    string apellido;
    int edad;
    string sexo;

public:
    void setNombre(string nombre){this->nombre = nombre;}
    string getNombre(){return nombre;}
    string getApellido(){return apellido;}
    int getEdad(){return edad;}
    int getID(){return id;};
    
    void setApellido(string apellido){this->apellido = apellido;}
    void setEdad(int edad){ this->edad = edad;}
    void setSexo(string sexo){this->sexo = sexo;}
    void setId(int id){this->id=id;}
};


/**
 *  Clase Profesor
*/

class Profesor : public Usuario{
    string profesion;
    string cProfesional;
public:
    Profesor(){};
    
    Profesor(string nombre, string apellido, int edad,string sexo, string profesion, string cProfesional){
        setNombre(nombre);
        setApellido(apellido);
        setEdad(edad);
        setSexo(sexo);
        this->profesion = profesion;
        this->cProfesional = cProfesional;
        this->setId(id_profesor++);
    }
    
    string getProfesion(){return profesion;}

};


/**
 *  Clase Materia
*/

class Materia{
    int id;
    string nombre;
    Profesor profesor;
    int credito;
    
public:
    Materia(){};
    
    Materia(string nombre, int credito){
        this->nombre = nombre;
        this->credito = credito;
        id=id_materia++;
    }
    
    int getID(){
        return id;
    }
    
    string getNombre(){
        return nombre;
    }
    
    void setProfesor(Profesor profesor){
        this->profesor = profesor;
    }
    
    Profesor getProfesor(){
        return profesor;
    }
    
    int getCreditos(){
        return credito;
    }
};

/**
 *  Clase Alumno
*/

class Alumno : public Usuario{
    string matricula;
    int semestre;
    Materia materias[3];
    string carrera;
    
    public:
    Alumno(){}
    Alumno(string nombre, string apellido, int edad,string sexo, string matricula, int semestre){
        setNombre(nombre);
        setApellido(apellido);
        setEdad(edad);
        setSexo(sexo);
        this->matricula = matricula;
        this->semestre = semestre;
        setId(id_estudiante++);
    }
    
    string getMatricula(){return matricula;}
    int getSemestre(){return semestre;}
    string getCarrera(){return carrera;}
    void setCarrera(string carrera){this->carrera = carrera;}
};
 
/**
 *  Clase GestorControlEscolar
*/


class GestorControlEscolar{
    Profesor profesores[4];
    Materia materia[4];
    Alumno alumno[4];
    
    public:

    void agregarProfesores(){
        
        string nombre;
        string apellido;
        string sexo;
        int edad;
        string titulo;
        string cedula;
        
        cout<<"**********************"<<endl;
        cout<<"  Registrar profesor"<<endl;
        cout<<"**********************"<<endl;
        
        cout<<"Restricciones:"<<endl<<"1. No se pueden agregar espacios. "<<endl<<"2. Agregar solo números enteros donde se pida"<<endl<<endl;
        
        for(int i = 0; i<2; i++){
            cout<<"Registro número: "<<i+1<<endl;
            cout<<"- Agrega el nombre: "<<endl;
            cin>>nombre;
            cout<<"- Agrega el apellido: "<<endl;
            cin>>apellido;
            cout<<"- Agrega el sexo: "<<endl;
            cin>>sexo;
            cout<<"- Agrega la edad (número entero): "<<endl;
            cin>>edad;
            cout<<"- Agrega el título: "<<endl;
            cin>>titulo;
            cout<<"- Agrega la cédula: "<<endl;
            cin>>cedula;
            cout<<endl;
            
            profesores[i] = Profesor(nombre, apellido, edad, sexo, titulo, cedula);

        }
    }
    
    void agregarMateria(){
        string nombre;
        int creditos;
        int id = 0;
        Profesor profesor_asignado;
        
        cout<<"**********************"<<endl;
        cout<<"  Registrar materia"<<endl;
        cout<<"**********************"<<endl<<endl;
    
        for(int i=0; i<3; i++){
            cout<<"Registro número: "<<i+1<<endl;
            cout<<"-Escribe el nombre de la materia:"<<endl;
            cin>>nombre;
            cout<<"-Escribe los créditos (número entero): "<<endl;
            cin>>creditos;
            do{
                cout<<endl<<"**********************"<<endl;
                cout<<"-Elige el profesor que imparte la materia (por ID)"<<endl<<endl;
                imprimirProfesores();
                try{
                    cin>>id;
                    if(id < 0 || id >1){
                        cout<<"Ups! Has agregado una opción no válida";
                    }else{
                        profesor_asignado = getProfesor(id);
                    }
                    
                }catch(int e){
                    cout<<"Error, valor inválido"<<endl;
                    id = 0;
                }
            }while(id < 0 || id >1);
            cout<<endl;
            
            materia[i] = Materia(nombre, creditos);
            materia[i].setProfesor(profesor_asignado);
        }
    }
    
    void agregarAlumno(){
        string nombre;
        string apellido;
        string sexo;
        int edad;
        int semestre;
        string matricula;
        string carrera;
        
        cout<<"**********************"<<endl;
        cout<<"  Registrar alumno"<<endl;
        cout<<"**********************"<<endl<<endl;
        
        for(int i = 0; i<2; i++){
            cout<<"Registro número: "<<i+1<<endl;
            cout<<"-Agrega el nombre: "<<endl;
            cin>>nombre;
            cout<<"-Agrega el apellido: "<<endl;
            cin>>apellido;
            cout<<"-Agrega el sexo: "<<endl;
            cin>>sexo;
            cout<<"-Agrega la edad (número entero): "<<endl;
            cin>>edad;
            cout<<"-Agrega el semestre (número entero): "<<endl;
            cin>>semestre;
            cout<<"-Agrega la matrícula: "<<endl;
            cin>>matricula;
            cout<<"-Agrega carrera: "<<endl;
            cin>>carrera;
            
            cout<<endl;
            alumno[i] = Alumno(nombre, apellido, edad, sexo, matricula, semestre);
            alumno[i].setCarrera(carrera);
            
        }
    }
    
    
    Profesor getProfesor(int id){
        Profesor profesor_elegido;
        for(int i= 0; i<2; i++){
            if(profesores[i].getID()==id){
                return profesores[i];
            }
        }
        return profesor_elegido;
    }
    
    Alumno getAlumno(int id){
        Alumno alumno_elegido;
        for(int i= 0; i<2; i++){
            if(alumno[i].getID()==id){
                return alumno[i];
            }
        }
        return alumno_elegido;
    }
    
    Materia getMateria(int id){
        Materia materia_elegido;
        for(int i= 0; i<2; i++){
            if(alumno[i].getID()==id){
                return materia[i];
            }
        }
        return materia_elegido;
    }
    
    void imprimirMaterias(){
        for(int i = 0; i<3; i++){
            cout<<"ID: "<<materia[i].getID()<<" Nombre: "<<materia[i].getNombre()<<" Profesor asignado: "<<materia[i].getProfesor().getNombre()<<" "<<materia[i].getProfesor().getNombre()<<endl;
        }
    }
    
    void imprimirProfesores(){
        for(int i = 0; i<2; i++){
            cout <<"ID: "<<profesores[i].getID()<<" Nombre: "<< profesores[i].getNombre()<<" "<<profesores[i].getApellido()<<endl;
        }
    }
    
    void imprimirAlumnos(){
        for(int i = 0; i<2; i++){
            cout <<"ID: "<<alumno[i].getID()<<" Nombre: "<< alumno[i].getNombre()<<" "<<alumno[i].getApellido()<<endl;
        }
    }
    
    void imprimirProfesor(int id){
        bool encontrado = false;
        for(int i = 0; i<2; i++){
            if(profesores[i].getID() == id){
                cout<<endl<<"************************";
                cout <<endl<<"ID: "<<profesores[i].getID()<<" Nombre: "<< profesores[i].getNombre()<<" "<<profesores[i].getApellido()<< " Edad: "<<profesores[i].getEdad()<<endl;
                encontrado = true;
                break;
            }
        }
        
        if(!encontrado)
            cout<<"No se ha encontrado el registro"<<endl;
    }
    
    void imprimirAlumno(int id){
        bool encontrado = false;
        for(int i = 0; i<2; i++){
            if(alumno[i].getID() == id){
                cout<<endl<<"************************";
                cout <<endl<<"ID: "<<alumno[i].getID()<<" Nombre del alumno: "<< alumno[i].getNombre()<<" Semestre: "<<alumno[i].getApellido()<<alumno[i].getSemestre()<<" Carrera: "<< alumno[i].getCarrera() <<endl;
                encontrado = true;
                break;
            }
        }
        
        if(!encontrado)
            cout<<"No se ha encontrado el registro"<<endl;
    }
    
    void imprimirMateria(int id){
        bool encontrado = false;
        for(int i = 0; i<2; i++){
            if(materia[i].getID() == id){
                cout<<endl<<"************************";
                cout <<endl<<"ID: "<<materia[i].getID()<<" Nombre de la materia: "<< materia[i].getNombre()<<" Créditos: : "<<materia[i].getCreditos()<< " Profesor asignado: "<<materia[i].getProfesor().getNombre() <<" "<< materia[i].getProfesor().getApellido()<<endl;
                encontrado = true;
                break;
            }
        }
        
        if(!encontrado)
            cout<<"No se ha encontrado el registro con ese ID"<<endl;
    }
    
};



int main()
{
  
    int op, id;
    bool terminar = false;
    
    GestorControlEscolar gestorControlEscolar = GestorControlEscolar();
    
    gestorControlEscolar.agregarProfesores();
    gestorControlEscolar.agregarMateria();
    gestorControlEscolar.agregarAlumno();
    
    do{
        
        cout<<endl<<endl<<"Elige la opción deseada: "<<endl<<"Visualizar:"<<endl<<"1. Profesor"<<endl<<"2. Materia"<<endl<<"3. Alumno"<<endl<<"4. Salir"<<endl;
        
        do{
            try{
                cin>>op;
            }catch(int e){
                cout<<"Error, valor inválido"<<endl;
                break;
            }
            if(op<1 || op>4){
                cout<<"Ups! Has agregado un valor no válido"<<endl;
            }
        }while(op<1 || op>4);
        
        if(op>0 && op<4){
            cout<<"Escribe el ID: "<<endl;
            cin>>id;
        }


        Profesor profesor;
        Alumno alumno;
        
        switch(op) {
            case 1:
                gestorControlEscolar.imprimirProfesor(id);
                break;
            case 2:
                gestorControlEscolar.imprimirMateria(id);
                break;
            case 3:
                gestorControlEscolar.imprimirAlumno(id);
                break;
            case 4:
                terminar = true;
                cout<<"Adiós"<<endl;
                break;
            default:
                cout<<"Has agregado una opción no válida"<<endl;
                break;
        }
    }while(!terminar);
    


    return 0;
}
