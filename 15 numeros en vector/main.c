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
    int v1[15], i;

    for(i=1;i<16;i++){
        printf("%i: ",i);
        scanf("%i", &v1[i]);
    }

    return 0;
}
