/**
    *************
    * Aclaración*
    * ***********
    Los programas corren correctamente desde www.onlinegdb.com/online_c++_compiler o en compiladores estándares de C/C++. 
    En compiladores propietarios como los de Borland o Dev C++, puede que no funcionen correctamente.
**/


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
    printf("\n");
    
    do{
        printf("Elige la opción:\n1) Convertir a mayuscula  2) Convertir a minusculas 3) Salir\n");
        scanf("%d", &op);
        
        if(op == 1){
            mayusculas(cadena);
        }else if(op == 2){
            minusculas(cadena);
        }else if(op == 3){
            printf("Adios.");
        }else{
            printf("Ups! Has elegido un valor no válido.");
        }
        printf("\n\n");
    }while(op!=3);

    return 0;
}


void mayusculas(char cadena[]){
   for (int i = 0; cadena[i]!='\0'; i++) {
      if(cadena[i] >= 'a' && cadena[i] <= 'z') {
         cadena[i] = cadena[i] - 32;
      }
   }
    printf("%s", cadena);
}


void minusculas(char cadena[]){
   for (int i = 0; cadena[i]!='\0'; i++) {
      if(cadena[i] >= 'A' && cadena[i] <= 'Z') {
         cadena[i] = cadena[i] + 32;
      }
   }
   printf("%s", cadena);
}
