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
    void agregarSaldo(float saldo){
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
    string imprimir;
    
    
    for(int i = 0; i<3; i++){
        
        //Manejo de Excepciones
        try{
            cout<<"Escribe el nombre"<<endl;
            cin>>nombre;
            cout<<"Escribe el apellido"<<endl;
            cin>>apellido;
            cout<<endl;
            
            b[i] = Cliente(nombre, apellido);
        }catch(int e){
            cout << e << endl;
        }
        
    }
    
    cout<<"¿Deseas imprimir la información de los clientes? (Escriba sí)"<<endl;
    cin>>imprimir;
    
    if(imprimir=="Sí" || imprimir=="sí" || imprimir=="si" || imprimir=="Si"){
        cout<<endl<<"Clientes del banco"<<endl<<"=============="<<endl;
        for(int i=0; i<3; i++){
            b[i].imprimirDatos();
        }
    }
    return 0;
}
