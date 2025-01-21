#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    int num=1, lim;
    printf("\nIngrese el numero limite: ");
    scanf("%i", &lim);

    while(num <= lim){
        //res = num % 5
        //res2 = num % 3
        if(num % 3 == 0){
            if(num % 5 == 0){
                printf("\nFizzBuzz (%i)", num);
                num++;
            }
            else{
                printf("\nFizz (%i)", num);
                num++;
            }
        }
        else if(num % 5 == 0){
            printf("\nBuzz (%i)",num);
            num++;
        }
        else{
            printf("\n%i", num);
            num++;
        }
        //("Numero: %i", num);
        //num++;
    }
    return 0;
}
