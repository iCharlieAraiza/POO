#include <stdio.h>
#include <ctype.h>

int main()
{
    int op;
    char cadena[50];
    
    printf("Escribe algo (máximo 50 caracteres): \n");
    scanf(" %[^\n]s",cadena);

    printf("Elige la opción:\n1) Convertir a mayuscula  2) Convertir a minusculas\n");
    scanf("%d", &op);
    
    if(op == 1){
        for(int i = 0; cadena[i] != '\0'; i++){
            printf("%c", toupper(cadena[i]));
        }
    }else if(op == 2){
        for(int i = 0; cadena[i] != '\0'; i++){
            printf("%c", tolower(cadena[i]));
        }   
    }else{
        printf("Ups! Has elegido un valor no válido.");
    }
    return 0;
}
