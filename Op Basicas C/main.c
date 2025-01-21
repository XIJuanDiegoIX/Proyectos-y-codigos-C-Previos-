#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

int main()
{
    int r;
    setlocale(LC_ALL, "");
    do {
        r = menu();
        cont();
    } while (r != 5);
    return 0;
}

int menu() {
    titulo();
    int i, Res, val[3];
    char op[100];
    printf("\n\n\t1.- Suma de dos números enteros.");
    printf("\n\t2.- Resta de dos números enteros.");
    printf("\n\t3.- Multiplicación de dos números enteros.");
    printf("\n\t4.- División de dos números enteros.");
    printf("\n\t5.- Salir\n\tElige una opción: ");
    scanf("%i", &i);
    if (i != 5) {
        if (i == 1) {
            Suma(val);
            strcpy(op, "Suma");
        } else if (i == 2) {
            Resta(val);
            strcpy(op, "Resta");
        } else if (i == 3) {
            Mult(val);
            strcpy(op, "Multiplicación");
        } else if (i == 4) {
            Div(val);
            strcpy(op, "División");
        }
        Resultado(val, op);
    }
    return i;
}

int Suma(int val[3]) {
    titulo();
    int n1, n2, res = 0;
    printf("\n\n\t\tIngrese el primer número: ");
    scanf("%i", &n1);
    printf("\n\t\tIngrese el segundo número: ");
    scanf("%i", &n2);
    res = n1 + n2;
    val[0] = res;
    val[1] = n1;
    val[2] = n2;
    return val;
}

int Resta(int val[3]) {
    titulo();
    int n1, n2, res = 0;
    printf("\n\n\t\tIngrese el primer número: ");
    scanf("%i", &n1);
    printf("\n\t\tIngrese el segundo número: ");
    scanf("%i", &n2);
    res = n1 - n2;
    val[0] = res;
    val[1] = n1;
    val[2] = n2;
    return val;
}

int Mult(int val[3]) {
    titulo();
    int n1, n2, res = 0;
    printf("\n\n\t\tIngrese el primer número: ");
    scanf("%i", &n1);
    printf("\n\t\tIngrese el segundo número: ");
    scanf("%i", &n2);
    res = n1 * n2;
    val[0] = res;
    val[1] = n1;
    val[2] = n2;
    return val;
}

int Div(int val[3]) {
    titulo();
    int n1, n2, res = 0;
    printf("\n\n\t\tIngrese el primer número: ");
    scanf("%i", &n1);
    printf("\n\t\tIngrese el segundo número: ");
    scanf("%i", &n2);
    res = n1 / n2;
    val[0] = res;
    val[1] = n1;
    val[2] = n2;
    return val;
}

int Resultado(int Res[3], char op[100]) {
    titulo();
    printf("\n\n\t\tEl resultado de la operación es: %i", Res[0]);
    Sleep(400);
    printf("\n\n\t\tEl primer número es: %i", Res[1]);
    Sleep(400);
    printf("\n\n\t\tEl segundo número es: %i", Res[2]);
    Sleep(400);
    printf("\n\n\t\tLa operación realizada es: %s", op);
    cont();
    getch();
}

void titulo() {
    system("cls");
    printf("O===================================================================O");
    printf("\n|                                                                   |");
    printf("\n|                 Programa de Operaciones Básicas                   |");
    printf("\n|                                                                   |");
    printf("\nO===================================================================O");
}

void cont() {
    printf("\n\nO===================================================================O");
    printf("\n|                                                                   |");
    printf("\n|                 Pulse <ENTER> para continuar...                   |");
    printf("\n|                                                                   |");
    printf("\nO===================================================================O");
}

/*
#include <stdio.h>

void obtenerValores(int *resultados) {
    resultados[0] = 10;
    resultados[1] = 20;
    resultados[2] = 30;
}

int main() {
    int valores[3];
    obtenerValores(valores);

    printf("Valor 1: %d\n", valores[0]);
    printf("Valor 2: %d\n", valores[1]);
    printf("Valor 3: %d\n", valores[2]);

    return 0;
}
*/
