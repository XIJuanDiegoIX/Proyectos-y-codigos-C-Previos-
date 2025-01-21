/*Enunciado: Almacenar 15 números en un vector.

 IMPRIMIR:
A.- cuantos son ceros,
B.- cuantos son negativos,
C.- cuantos positivos.
D.- la suma de los negativos y
E.- la suma de los positivos.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, suma1 = 0, suma2 = 0, v1[15], num1 = 0, num2 = 0, num3 = 0;

    printf("=============================================================");
    printf("\n\n\t\tPrograma de cuadrado de vectores.");
    printf("\n\n=============================================================\n");
    for(i=1;i<16;i++){
        printf("\t\t%i Ingrese un valor: ", i);
        scanf("%i", &v1[i]);
        Sleep(100);
    }
    printf("\n\n=============================================================");
    sleep(3);
    system("cls");

    for(i=1;i<16;i++){              //Compara todos los numeros del vector
        if(v1[i] == 0){             //Von esto creara la longitud de los vectores
            num1 += 1;    //Cero
        }else if(v1[i] < 0){
            num2 += 1;    //negativo
            suma1 += v1[i];
        }else{
            num3 += 1;    //Positivo
            suma2 += v1[i];
        }
    }

    printf("=============================================================");
    printf("\n\n\t\tPrograma de cuadrado de vectores.");
    printf("\n\n=============================================================");
    printf("\n\t\tCeros: %i ",  num1);
    printf("\n\t\tNegativos: %i ", num2);
    printf("\n\t\tPositivos: %i ", num3);
    printf("\n\t\tSuma de los negativos: %i ", suma1);
    printf("\n\t\tSuma de los positivos: %i ", suma2);
    printf("\n\n=============================================================");

    return 0;
}
