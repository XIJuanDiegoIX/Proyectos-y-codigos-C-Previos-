#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    do{
        printf("\n\t\tEres la mas hermosa del mundo :)");
        printf("\n\t\tQuiere volver a imprimir? ");
        scanf("%i", &x);
    }while(x == 1);
    return 0;
}
