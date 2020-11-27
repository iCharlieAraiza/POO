#include <iostream>
#include <string>


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
    
    void setDireccion(string direccion){
        this->direccion = direccion;
    }
    
    
    int getCuenta(){
        return cuenta;
    }
    
    string getTipoCliente(){
        return tipo_cliente;
    }

    
    void getDatosCliente(){
        cout<<endl<<"Impresion de datos del clienta"<<endl<<endl;
        cout<<"Nombre: " <<getNombre() <<endl<< "Apellido: "<< getApellido() 
        <<endl<<"Edad: "<< getEdad() <<" Cuenta: "<< getTipoCliente() <<endl
        << "Cuenta: "<< getCuenta() <<endl << "Tipo de cliente: "<< getTipoCliente()<<endl;
    }
    
};

class Empleado : public Persona{
    string identificador;
    string puesto;
    string area;
    
    public:
    
    void setIdentidficador(string identificador){
        this->identificador = identificador;
    }
    
    void setPuesto(string puesto){
        this->puesto = puesto;
    }
    
    void setArea(string area){
        this->area = area;
    }
    
    string getIdentificador(){
        return identificador;
    }
    
    string getPuesto(){
        return puesto;
    }
    
    string getArea(){
        return area;
    }
    
    void getDatos(){
        cout<<endl<<"Impresion de datos del Empleado"<<endl<<endl;
        cout<<"Nombre: " <<getNombre() <<endl<< "Apellido: "<< getApellido() 
        <<endl<<"Edad: "<< getEdad() <<" Número de Empleado: "<< getIdentificador() <<endl
        << "puesto: "<< getPuesto() <<endl << "Area: "<< getArea()<<endl;
    }
    
};


int main()
{

    string direccion;
    string nombre;
    string apellido;
    int edad;
    int cuenta;
    string tipo_cliente;
    string n_empleado;
    string puesto;
    string area;
    
    
    cout <<"Registro del cliente"<<endl<<"**********************"<<endl<<endl;
    
    cout<<"Escribe el nombre: "<<endl;
    getline(cin, nombre);
    cout<<"Escribe los apellidos: "<<endl;
    getline(cin, apellido);
    cout<<"Escribe la edad: "<<endl;
    cin>>edad;
    cout<<"Escribe la cuenta: "<<endl;
    cin>>cuenta;
    cout<<"Escribe la dirección: "<<endl;
    cin>>direccion;
    cout<<"Escribe el tipo de cuenta: "<<endl;
    cin>>tipo_cliente;
 
 
    
    Cliente cliente = Cliente();
    
    cliente.setNombre(nombre);
    cliente.setApellido(apellido);
    cliente.setEdad(edad);
    cliente.setTipoCliente(tipo_cliente);
    cliente.setCuenta(cuenta);
    
    
    
    cout <<endl<<"Registro del Personal"<<endl<<"**********************"<<endl<<endl;
    
    cout<<"Escribe el nombre: "<<endl;
    cin>> nombre;
    cout<<"Escribe el apellido: "<<endl;
    cin>>apellido;
    cout<<"Escribe la edad: "<<endl;
    cin>>edad;
    cout<<"Escribe númeor de Empleado: "<<endl;
    cin>>n_empleado;
    cout<<"Escribe el puesto: "<<endl;
    cin>>puesto;
    cout<<"Escribe el área: "<<endl;
    cin>>area;
    
    Empleado empleado = Empleado();
    
    empleado.setNombre(nombre);
    empleado.setApellido(apellido);
    empleado.setEdad(edad);
    empleado.setIdentidficador(n_empleado);
    empleado.setArea(area);
    empleado.setPuesto(puesto);
    
    
    cliente.getDatosCliente();
    empleado.getDatos();
    
    return 0;
}

