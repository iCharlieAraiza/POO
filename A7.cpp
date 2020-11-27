#include <iostream>

using namespace std;

class Persona{
    string nombre;
    string apellido;
    int edad;
    
    public:
    void setNombre(string nombre){
        this->nombre = nombre;
    }
    
    void setApellido(string apellido){
        this->apellido = apellido;
    }
    
    void setEdad(int edad){
        this->edad = edad;
    }
    
    string getNombre(){
        return nombre;
    }
    
    string getApellido(){
        return apellido;
    }
    
    int getEdad(){
        return edad;
    }
};


class Cliente : public Persona{
    int cuenta;
    string tipo_cliente;
    string direccion;
    
    public:
    
    void setCuenta(int cuenta){
        this->cuenta = cuenta;
    }
    
    void setTipoCliente(string tipo_cliente){
        this->tipo_cliente = tipo_cliente;
    }
    
    
    int getCuenta(){
        return cuenta;
    }
    
    string getTipoCliente(){
        return tipo_cliente;
    }
    
    void getDatosCliente(){
        cout<<"Nombre: " <<getNombre() <<endl<< "Apellido: "<< getApellido() 
        <<endl<<"Edad: "<< getEdad() <<" Cuenta: "<< getTipoCliente() <<endl
        << "Cuenta: "<< getCuenta() <<endl << "Tipo de cliente: "<< getTipoCliente()<<endl;
    }
    
};

class Empleado : public Persona{
    int identificador;
    string puesto;
    string area;
    
    public:
    
    void setIdentidficador(int identificador){
        this->identificador = identificador;
    }
    
    void setPuesto(string puesto){
        this->puesto = puesto;
    }
    
    void setArea(string area){
        this->area = area;
    }
    
    int getIdentificador(){
        return identificador;
    }
    
    string getPuesto(){
        return puesto;
    }
    
    string getArea(){
        return area;
    }
    
};


int main()
{

    Cliente cliente = Cliente();
    
    cliente.setNombre("Juanito");
    cliente.setApellido("Apellido");
    cliente.setEdad(30);
    cliente.setTipoCliente("preferente");
    cliente.setCuenta(122312);
    cliente.getDatosCliente();
    
    

    return 0;
}
