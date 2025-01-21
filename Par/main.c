#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    printf("Ingrese un numero: "); scanf("%i",&i);
    if(i%2==0){
        printf("Es par");
    }else{
        printf("Es inpar");
    }
    return 0;
}
