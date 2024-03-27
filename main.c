#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "pila.h"

#define ESC 27
#define DIM 10

void ejercicios();
void menuEjercicios();
void arreglo1();
void arregloPto1();
void muestraArreglo(int a[], int v);
int cargaArregloRandom(int a[], int dim);
int cargaArregloUsuario(int a[], int dim, int v);
int cuentaDigitos(int nro);
int cuentaIngresos(int a[], int v);


int main ()
{
    srand(time(NULL));
    ejercicios();

    return 0;
}
void ejercicios()
{
    char opcion;

    do
    {
        system("cls");
        menuEjercicios();


        printf("\n\n\n");
        opcion = getch();
        printf("ESC para salir o cualquier tecla para continuar.\n");


        switch(opcion)
        {
        case '1':
            arreglo1();
            break;
        case '2':
            arregloPto1();
            break;
        }
        system("pause");
    }
    while(opcion!=27);
}
void menuEjercicios()
{
    printf("Ingrese caso:\n\n\n");
    printf("\n 1 - Ejercicios Arreglo 1");
    printf("\n 2 - Ejercicios Arreglo Pto 1");

}
void arreglo1()
{
    int notas [DIM];
    int validosNotas = 0;
    validosNotas = cargaArregloUsuario(notas, DIM, validosNotas);
    printf("\n Listado de notas\n");
    muestraArreglo(notas, validosNotas);
    validosNotas = cargaArregloUsuario(notas, DIM, validosNotas);
    printf("\n Listado de notas2\n");
    muestraArreglo(notas, validosNotas);
    printf("\n El nro 0 tiene %d", cuentaDigitos(0));
    printf("\n El nro 1999 tiene %d", cuentaDigitos(1999));
    printf("\n El nro 3000000 tiene %d", cuentaDigitos(3000000));
}
void arregloPto1()
{
    int datos [DIM];
    int numeros = 0;
    int cantidad = 0;

    numeros = cargaArregloUsuario(datos, DIM, numeros);
    printf("\n Datos ingresados: \n");
    muestraArreglo(datos, numeros);

    cantidad = cuentaIngresos(datos, numeros);
    printf("\n La cantidad de datos ingresados es: %d .\n", cantidad);

}
void muestraArreglo(int a[], int v)
{
    for(int i = 0; i < v; i++)
    {
        if (i % 10 == 0)
        {
            printf("\n");
        }
        printf("%5d | ", a[i]);
    }
}

int cargaArregloRandom(int a[], int dim)//vacios p/ poder cargar de dif dimension
{
    int i;
    for (i = 0; i < 50; i++)
    {
        a[i] = rand()%10;
    }
    return i;
}
int cargaArregloUsuario(int a[], int dim, int v)
{
    char opcion;

    while( v < dim && opcion != ESC)
    {
        printf("\n Ingrese una nota:");
        scanf("%d", &a[v]);
        v++;

        printf("ESC para salir o cualquier tecla para continuar.");
        opcion = getch();
        system("cls");
    }
    return v;
}
int cuentaDigitos(int nro)
{
    int digitos =0;
    if (nro=0)
    {
        digitos = 1;
    }
    while (nro > 0)
    {
        digitos ++;
        nro = nro/10;
    }
    return digitos;
}
int cuentaIngresos(int a[], int v)
{
    int suma;

    for (int i = 0; i < v; i++){
        suma = suma + a[i];
    }
    return suma;
}

