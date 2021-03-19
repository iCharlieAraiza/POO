#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int cal;
    
    printf("Escribe un numero: ");
    scanf("%d",&cal);
    
    if(cal>10 || cal<0){
        printf("Error\n");
    }else if ( cal==10 ){
        printf("Excelente");
    }else if( cal==9 ){
        printf("Muy bien");
    }else if(cal==8){
        printf("Bien");
    }else if(cal==7){
        printf("Regular");
    }else{
        printf("No acreditado");
    }
    
    
    return 0;
}
