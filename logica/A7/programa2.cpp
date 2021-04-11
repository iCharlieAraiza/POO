/**
    *************
    * Aclaración*
    * ***********
    Los programas corren correctamente desde www.onlinegdb.com/online_c++_compiler o en compiladores estándares de C/C++. 
    En compiladores propietarios como los de Borland o Dev C++, puede que no funcionen correctamente.
**/

#include <stdio.h>
#include <ctype.h>

int main()
{
    int op;
    char cadena[50];
    
    printf("Escribe algo (máximo 50 caracteres): \n");
    scanf(" %[^\n]s",cadena);
    printf("\n");

    do{
        printf("Elige la opción:\n1) Convertir a mayuscula  2) Convertir a minusculas  3) Salir\n");
        scanf("%d", &op);
        
        if(op == 1){
            for(int i = 0; cadena[i] != '\0'; i++){
                printf("%c", toupper(cadena[i]));
            }
        }else if(op == 2){
            for(int i = 0; cadena[i] != '\0'; i++){
                printf("%c", tolower(cadena[i]));
            }   
        }else if(op==3){
            printf("Adios.");
        }else{
            printf("Ups! Has elegido un valor no válido.");
        }
        printf("\n\n");
    }while(op!=3);
    return 0;
}
