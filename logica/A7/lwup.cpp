#include <iostream>

using namespace std;

void mayusculas(char cadena[]);
void minusculas(char cadena[]);

int main()
{
    int op;
    char cadena[50];
    
    printf("Escribe algo (máximo 50 caracteres): \n");
    scanf(" %[^\n]s",cadena);

    printf("Elige la opción:\n1) Convertir a mayuscula  2) Convertir a minusculas\n");
    scanf("%d", &op);
    
    if(op == 1){
        mayusculas(cadena);
    }else if(op == 2){
        minusculas(cadena);
    }else{
        printf("Ups! Has elegido un valor no válido.");
    }

    return 0;
}


void mayusculas(char cadena[]){
    char final[50];
    int cont= 0;
    
    for(int i = 0; cadena[i]!='\0'; i++ ){
        final[i] = cadena[i] >= 97 ? cadena[i]-32 : cadena[i];
    }
    printf("%s", final);
}


void minusculas(char cadena[]){
    char final[50];
    int cont= 0;
    
    for(int i = 0; cadena[i]!='\0'; i++ ){
        final[i] = cadena[i] <= 90 && cadena[i]>32 ? cadena[i]+32 : cadena[i];
    }
    printf("%s", final);
}
