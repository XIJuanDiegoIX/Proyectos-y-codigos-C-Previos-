#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    float matriz[2][3];
    int i,j;

    for(i=0;i<2;i++){
        for(j=0;j<3;j++){
            printf("Digite un numero matriz[%i][%i]", i+1, j+1);
            scanf("%f", &matriz[i][j]);
        }
    }

    for(i=0;i<2;i++){
        for(j=0;j<3;j++){
            printf("%.2f ", matriz[i][j]);
        }
        printf("\n");
    }
    return 0;
}
