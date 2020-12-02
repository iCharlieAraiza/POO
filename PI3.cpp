#include <iostream>
#include <list>

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
    
    Materia(string nombre, int credito, Profesor profesor){
        this->nombre = nombre;
        this->credito = credito;
        setProfesor(profesor);
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
    Materia materias[2];
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
    void setMaterias(Materia materias[2]){
        for(int i = 0; i<2; i++){
            this->materias[i] = materias[i];
        }
    }
    
    Materia* getMaterias(){
        return materias;
    }
};
 
/**
 *  Clase GestorControlEscolar
*/


class GestorControlEscolar{
    Profesor profesores[4];
    Materia materia[2];
    Alumno alumno[4];
    list<Profesor> profesores_l;
    list<Materia> materia_l;
    list<Alumno> alumno_l;

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
            
            profesores_l.push_back( Profesor(nombre, apellido, edad, sexo, titulo, cedula) );

        }
    }
    
    void agregarMateria(){
        string nombre;
        int creditos;
        int id = 0;
        Profesor profesor_asignado;
        
        cout<<endl;
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
            
            materia_l.push_back(Materia(nombre, creditos,profesor_asignado));
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
            Materia materiaArray[2];
            
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
            
            int id=0;
            
            cout<<endl<<"**********************"<<"Elige la materia a asignar por ID"<<"**********************"<<endl;
            imprimirMaterias();
            for(int i=0; i<2; i++){
                do{
                    cout<<endl<<"Materia "<<i+1<<": ";
                    cin >>id;
                        
                    if(id<0 || id>2){
                        cout<<endl<<"Ups! Has agregado una opción no válida. Vuélvelo a intentar"<<endl;
                    }else{
                        materiaArray[i] = getMateria(id);
                        //cout<<"===========**"<<materiaArray[i].getNombre()<<endl;
                    }
                }while(id<0 || id>2);
            }
            
            cout<<endl;
            Alumno alumno = Alumno(nombre, apellido, edad, sexo, matricula, semestre);
            alumno.setCarrera(carrera);
            alumno.setMaterias(materiaArray);
            alumno_l.push_back(alumno);
            
            cout<<endl;
        }
    }
    
    
    Profesor getProfesor(int id){
        
        Profesor profesor_elegido;
        list <Profesor> :: iterator it;
        for(it = profesores_l.begin(); it != profesores_l.end(); ++it){
            if(id==it->getID()){
                Profesor &pe = *it;
                return pe;
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
        Materia materia;
        list <Materia> :: iterator it;
        for(it = materia_l.begin(); it != materia_l.end(); ++it){
            if(id==it->getID()){
                Materia &pe = *it;
                return pe;
            }
        }
        return materia;
    }
    
    void imprimirMaterias(){
        list <Materia> :: iterator it;
        bool encontrado = false;
        for(it = materia_l.begin(); it != materia_l.end(); ++it){
            cout <<endl<<"ID: "<<it->getID()<<" Nombre: "<< it->getNombre()<<" Profesor: asignado"<<it->getProfesor().getNombre()<<endl;
            encontrado = true;
        }
    }
    
    void imprimirProfesores(){
        list <Profesor> :: iterator it;
        bool encontrado = false;
        cout<<endl<<"************************"<<endl;
        
        for(it = profesores_l.begin(); it != profesores_l.end(); ++it){
            cout <<"ID: "<<it->getID()<<" Nombre: "<< it->getNombre()<<" "<<it->getApellido()<< " Edad: "<<it->getEdad()<<endl;
            encontrado = true;
        }
    }
    
    void imprimirAlumnos(){
        
        list <Alumno> :: iterator it;
        bool encontrado = false;
        for(it = alumno_l.begin(); it != alumno_l.end(); ++it){
            cout<<endl<<"************************";
            cout <<endl<<"ID: "<<it->getID()<<" Nombre: "<< it->getNombre()<<" "<<it->getApellido()<< " Edad: "<<it->getEdad()<< " Carrera: "<< it->getCarrera() <<endl;
            encontrado = true;
        }
        
    }
    
    
    void imprimirProfesor(int id){
        
        list <Profesor> :: iterator it;
        for(it = profesores_l.begin(); it != profesores_l.end(); ++it){
            if(id==it->getID()){
                cout <<endl<<"ID: "<<it->getID()<<" Nombre: "<< it->getNombre()<<" "<<it->getApellido()<< " Edad: "<<it->getEdad()<<" Profesión: "<<it->getProfesion() <<endl;
            }
        }
        
    }
    
    void imprimirAlumno(int id){
        list <Alumno> :: iterator it;
        for(it = alumno_l.begin(); it != alumno_l.end(); ++it){
            if(id==it->getID()){
                cout<<endl<<"*******************"<<"Registro del Alumno"<<"*******************"<<endl;
                cout <<endl<<"ID: "<<it->getID()<<" Nombre: "<< it->getNombre()<<" "<<it->getApellido()<< " Edad: "<<it->getEdad()<< " Carrera: "<< it->getCarrera() <<endl;
                
                cout<<endl<<"Materias asignadas: "<<endl;
                for(int j = 0; j < 2; j++){
                    cout<< "ID: "<< it->getMaterias()[j].getID() <<"  Nombre de la materia"<<it->getMaterias()[j].getNombre()<<"   Profesor titular: "<<it->getMaterias()[j].getProfesor().getNombre() << " " << it->getMaterias()[j].getProfesor().getApellido() <<endl;
                }
                break;
            }
        }
    }
        
    
    void imprimirMateria(int id){
        bool encontrado = false;
        list <Materia> :: iterator it;
        for(it = materia_l.begin(); it != materia_l.end(); ++it){
            if(id==it->getID()){
                cout<<endl<<"************************";
                cout <<endl<<"ID: "<<it->getID()<<" Nombre de la materia:  "<<it->getNombre()<< " Profesor asignado: "<<it->getProfesor().getNombre() <<" "<< it->getProfesor().getApellido()<<endl;
                encontrado = true;
            }
        }
        /*
        bool encontrado = false;
        for(int i = 0; i<2; i++){
            if(materia[i].getID() == id){
                cout<<endl<<"************************";
                cout <<endl<<"ID: "<<materia[i].getID()<<" Nombre de la materia: "<< materia[i].getNombre()<<" Créditos: : "<<materia[i].getCreditos()<< " Profesor asignado: "<<materia[i].getProfesor().getNombre() <<" "<< materia[i].getProfesor().getApellido()<<endl;
                encontrado = true;
                break;
            }
        }
        */
        if(!encontrado)
            cout<<"No se ha encontrado el registro con ese ID"<<endl;
    }
    
};


void showlist(list <int> g)
{
    list <int> :: iterator it;
    for(it = g.begin(); it != g.end(); ++it)
        cout << '\t' << *it;
    cout << '\n';
};

void showlist(list <Profesor> g)
{
    list <Profesor> :: iterator it;
    bool encontrado = false;
    for(it = g.begin(); it != g.end(); ++it){
        cout<<endl<<"************************";
        cout <<endl<<"ID: "<<it->getID()<<" Nombre: "<< it->getNombre()<<" "<<it->getApellido()<< " Edad: "<<it->getEdad()<<endl;
        encontrado = true;
    }
};
  


int main()
{
    
    GestorControlEscolar gestorControlEscolar = GestorControlEscolar();
    int id;
    
    gestorControlEscolar.agregarProfesores();
    
    
    
    cout <<"Escribe el ID del profesor que deseas buscar (núnmero entero)"<<endl;
    cin>>id;
    
    gestorControlEscolar.imprimirProfesor(id);
    
    gestorControlEscolar.agregarMateria();
    
    cout <<"Escribe el ID de la materia que deseas buscar (núnmero entero)"<<endl;
    cin>>id;
    
    gestorControlEscolar.imprimirMateria(id);
    
    gestorControlEscolar.agregarAlumno();
    gestorControlEscolar.imprimirAlumno(1);
    

    return 0;
}
