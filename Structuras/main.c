#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

int main()
{
    struct datos
    {
        char cNombre[40], cEdad[40], cCiudad[25], cTelefono[20], cCorreo[40];
    }Datos;

    printf("\n");
    printf("**** ESTRUCTURA SIMPLE ****");
    printf("\n");
    printf("\n");
    printf(" Digite sus datos:");
    printf("\n");
    printf(" Nombre: ");
    gets(Datos.cNombre);
    printf(" Edad: ");
    gets(Datos.cEdad);
    printf(" Ciudad: ");
    gets(Datos.cCiudad);
    printf(" Telefono: ");
    gets(Datos.cTelefono);    printf(" Correo: ");
    gets(Datos.cCorreo);


    printf("\n");
    printf("**** REPORTE DE DATOS ****");
    printf("\n");
    Sleep(600);
    printf("\n");
    printf(" Nombre: %s", Datos.cNombre);
    Sleep(600);
    printf("\n");
    printf(" Edad: %s", Datos.cEdad);
    Sleep(600);
    printf("\n");
    printf(" Ciudad: %s", Datos.cCiudad);
    Sleep(600);
    printf("\n");
    printf(" Telefono: %s", Datos.cTelefono);
    Sleep(600);
    printf("\n");
    printf(" Correo: %s", Datos.cCorreo);
    Sleep(600);
    printf("\n");    printf("\n");
    printf(" Presione Cualquier tecla para continuar...");
    getch();
    return 0;
}
