#include<stdio.h>
#include <stdlib.h>

int main(){
    int num, n, res=1;
    char op[20];
    printf("Ingrese un numero: ");scanf("%i",&num);
    if(num > 10){
        for(n=1;n<=10;n++){
            res = n * res;
        }
        strcpy(op, "multiplicacion");
    }
    else{
        res--;
        for(n=1;n<=10;n++){
            res += n;
        }
        strcpy(op, "suma");
        }
    fflush(stdin);
    printf("\n El numero digitado es: %i", num);
    printf("\n La operacion realizada es: %s", op);
    printf("\n Se aplico %s a los numeros: ", op);
    for(n=1;n <= 9;n++){
        printf("%i, ", n);
    }
        printf("%i\n Que es igual a: %i",n, res);
    return 0;
}
