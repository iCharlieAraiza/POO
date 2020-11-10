#include <iostream>

using namespace std;

int id = 0;

class Cliente 
{ 
    int cuenta; 
    string nombre; 
    string apellido; 
    string tipoCuenta;
    float saldo;

    public: 
    
    //Constructor
    Cliente(){}
  
    Cliente(string nombre, string apellido){
        cuenta = id++;
        this->nombre = nombre;
        this->apellido = apellido;
    }
  
   //Método setter
    void agregarSaldo(float saldo) 
    { 
       this->saldo = saldo;
    } 
    
    //Método getter
    float regresarSaldo(){
        return this->saldo;
    }
    
    void imprimirDatos(){
        cout<<cuenta<<" "<<nombre<<" "<<apellido<<endl;
    }
    
};

int main()
{   
    Cliente* b = new Cliente[3];
    
    string nombre, apellido;
    
    
    for(int i = 0; i<3; i++){
        
        try{
            cout<<"Escribe el nombre"<<endl;
            cin>>nombre;
            cout<<"Escribe el apellido"<<endl;
            cin>>apellido;
            
            cout<<endl;
        }catch(int e){
            cout << e << endl;
        }
        
        b[i] = Cliente(nombre, apellido);
    }
    
    cout<<"Clientes del banco"<<endl<<"=============="<<endl;
    for(int i=0; i<3; i++){
        b[i].imprimirDatos();
    }
    
    //Se borra en memoria
    delete b;
    
    return 0;
}
