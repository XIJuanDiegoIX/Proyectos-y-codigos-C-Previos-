/*Digite un número,
Si el número supera a 10,
Multiplique los 10 primeros números,
Sino
Súmelos

IMPRIMIR:
a) El número que se digito.
b) La operación realizada (multiplicación o suma, de los primeros 10
números).
c) Los números multiplicados o sumados.*/

#include<stdio.h>
#include <stdlib.h>

int main(){
    int num, n=1, res=1;
    char op[20];
    printf("Ingrese un numero: ");scanf("%i",&num);

    if(num > 10){
        do{
           res = n * res;
           n++;
        }while(n <= 10);
        strcpy(op, "multiplicacion");
    }
    else{
        res--;
        do{
            res += n;
            n++;
        }while(n <= 10);
        strcpy(op, "suma");
    }
    fflush(stdin);
    printf("\n El numero digitado es: %i", num);
    printf("\n La operacion realizada es: %s", op);
    n=1;
    printf("\n Se aplico %s a los numeros: ", op);
    do{
        printf("%i, ", n);
        n++;
    }while(n <= 9);
    printf("%i\n Que es igual a: %i",n, res);

    return 0;
}

