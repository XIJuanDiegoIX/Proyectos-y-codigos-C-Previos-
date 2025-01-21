#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    double x, y=1, z=1,r;
    do{
        printf("Numero a factorizar: ");
        scanf("%d", &x);
        for(r=1;r<=x;r++){
            z = z*r;
            printf("%d Resultado: %d\n", y, z);
            y++;
        }
        printf("%d\n",x);
        printf("Repetir? 1.si 2.no");
        scanf("%i", &i);
    }while(i==1);
    return 0;
}
