//Arreglos de Estructuras en C, base de datos solo se pide nombre y edad

#include<stdio.h>


int main(){
	int i, x;

	/*El for es para trabajar 5 registros,
	si desean más pueden agregar en lugar de 5, pueden ser
	10 o los que ustedes necesiten,
	lo único que deben hacer es agregar el número de registros que necesitan.
    */

    // Aqui se CAPTURA la base de datos

    printf("\n ***********Captura: Base de datos****************\n\n\n ");
    printf("\nIngrese la cantidad de personas a registrar: ");
    scanf("%i", &x);

    struct persona{
        char nombre[20];
        int edad;
    }personas[x];


	for(i=0;i<x;i++)
        {
		fflush(stdin);
		 printf("\n ************************************** \n");
		printf("%i. Digite su nombre: ",i+1);
		gets(personas[i].nombre);
		printf("\n");
		printf("%i. Digite su edad: ",i+1);
		scanf("%i",&personas[i].edad);
        printf("\n ************************************** \n");
		printf("\n");
        printf("\n DIGITE NUEVO REGISTRO: \n");
		}


		system("cls");

		// Aqui se IMPRIME la base de datos
printf("\n ***********Reporte de la Base de datos**************** \n ");
	for(i=0;i<x;i++)
        {
        printf("\n ************************************** \n");
		printf("\n%i. Su nombre es: %s",i+1,personas[i].nombre);
		printf("\n%i. Su edad es: %i",i+1,personas[i].edad);

	}
printf("\n ************************************** \n");

	printf("\n PRESIONE ENTER PARA SALIR...\n\n\n"); //mensaje de salida
    printf("\n");


	return 0;
}

