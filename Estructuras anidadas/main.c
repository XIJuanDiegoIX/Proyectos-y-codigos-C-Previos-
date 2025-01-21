#include <stdio.h>
#include <stdlib.h>


int main()
{

    struct estuche{
        struct colores{
        int ncol;
        float pcol;
        }col;

        struct plumas{
        int nplu;
        float pplu;
        }plu;
    }est;

    printf("Ingrese la cantidad de colores del estuche: ");
    scanf("%i", &est.col.ncol);
    printf("Ingrese el precio de cada color del estuche: ");
    scanf("%f", &est.col.pcol);
    printf("Ingrese la cantidad de plumas del estuche: ");
    scanf("%i", &est.plu.nplu);
    printf("Ingrese el precio de cada plumas del estuche: ");
    scanf("%f", &est.plu.pplu);

    printf("\n");
    printf("Hay %i colores.", est.col.ncol);
    printf("\n");
    printf("Cuestan %.2f c/u.", est.col.pcol);
    printf("\n");    printf("Hay %i plumas.", est.plu.nplu);
    printf("\n");
    printf("Cuestan %.2f c/u.", est.plu.pplu);
    printf("\n");
    return 0;
}
