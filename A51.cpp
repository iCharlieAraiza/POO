#include <iostream>

using namespace std;

class Figura{
    
    float res_area;
    
    public:
    
    void area(float lado){
        this->res_area = lado * lado;
    }
    
    void area(int radio, float pi){
        this->res_area = radio*radio * pi;
    }
    
    void area (float base, float altura){
        this->res_area = base*altura;
    }
    
    void area (float baseMayor,float baseMenor, float altura){
        this->res_area =((baseMayor+baseMenor)*altura)/2;
    }
    
    float getArea(){
        return this->res_area;
    }
};


int main()
{
    int op;
    
    try{
        cout<<"Calcular el área. Elige una opción."<<endl;
        cout<<"1) Cuadrado   2)Círculo     3)Triángulo   4)Trapecio"<<endl;
        cin >> op;
    }catch(int e){
        cout << e << endl;
    }
    
    Figura figura = Figura();
    
    float lado, altura, base, base_menor;
    int radio;
    
    switch(op){
        case 1:
            cout<<"Escribe el valor del lado: "<<endl;
            cin>>lado;
            figura.area(lado);
            break;
        case 2:
            cout<<"Escribe el valor del radio del círculo: "<<endl;
            cin>>radio;
            figura.area(radio,3.14);
            break;
        case 3:
            cout<<"Escribe el valor de la base: "<<endl;
            cin>>base;
            cout<<"Escribe el valor de la altura: "<<endl;
            cin>>altura;
            figura.area(base, altura);
            break;
        case 4:
            cout<<"Escribe el valor de la base mayor: "<<endl;
            cin>>base;
            cout<<"Escribe el valor de la base menor: "<<endl;
            cin>>base_menor;
            cout<<"Escribe el valor de la altura: "<<endl;
            cin>>altura;
            figura.area(base, base_menor, altura);
            break;
        default:
            cout<<"Ups! Has agregado una opción no válida"<<endl;
    }
    
    
    cout<<endl<<"El área total de la figura es: "<<figura.getArea()<<endl; 


    return 0;
}
