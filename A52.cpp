#include <iostream>

using namespace std;

class Persona{
    string nombre;
    int edad;
    string sexo;
    
    public:
    
    Persona(string nombre, int edad, string sexo) : nombre(nombre), edad(edad), 
    sexo(sexo){} 
    
    string getNombre(){
        return nombre;
    }
    
    int getEdad(){
        return edad;
    }
    
    string getSexo(){
        return sexo;
    }
    
};

void imprimir(Persona persona_impr);

int main()
{
    string nombre, sexo;
    int edad;
    
    try{
        cout<<"-Escribe el nombre: "<<endl;
        cin>>nombre;
        
        cout<<"-Escribe la edad"<<endl;
        cin>>edad;
        
        cout<<"-Escribe el sexo"<<endl;
        cin>>sexo;
        
        Persona persona = Persona(nombre, edad, sexo);
        
                    
        //Función para imprimir los valores
        imprimir(persona);
        
    }catch(int e){
        cout<<e<<"Has agregado un valor inválido"<<endl;
    }
    
    return 0;
}

void imprimir(Persona persona_impr){
    cout<<endl<<"======================="<<endl;
    cout << "Nombre: "<<persona_impr.getNombre()<<endl;
    cout << "Edad: "<<persona_impr.getEdad()<<endl;
    cout << "Sexo: "<<persona_impr.getSexo()<<endl;
}
