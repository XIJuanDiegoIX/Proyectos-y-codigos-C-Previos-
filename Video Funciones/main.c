#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, suma=0;

    printf("Digite dos numeros: ");
    scanf("%i %i", &a, &b);

    suma = sumar(a, b);

    printf("\n La suma es: %i", suma);
    return 0;
}

int sumar(int n1, int n2){
    int suma=0;

    suma = n1 + n2;

    return suma;
}
