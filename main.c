#include <stdio.h>
#include <stdlib.h>

int factorial(int numero);
int ptencia(int base, int potencia);
int cargarArreglo(int arreglo[], int dim);
void mostrarArregloRE(int arreglo[], int i,int validos);
void mostrarArregloREINV(int arreglo[],int i,  int validos);
int sumaRecursiva(int arreglo[], int i, int validos);
int menorElementoRE(int arreglo[], int i, int validos);
void mostrarArchivo();
void cargarArchivo();
int cargarUnArchivo();
int recorrerArchvo(int menor, int i);
int buscaMenorFACU(FILE* archi);
void mostrarArchivoRE(FILE* archi, int i);

int main()
{

    int arreglo[30];

    /* total = factorial(10);
     printf("El factorial es: %d\n", total);

     total = ptencia(6, 10);
     printf("La potencia es: %d", total);

    int validos = cargarArreglo(arreglo, 20);
    mostrarArregloRE(arreglo, 0, validos);
    printf("\n\n");
    mostrarArregloREINV(arreglo, validos-1, 0);

    capicuaRE(arreglo, 0, validos);

    if (capicuaRE(arreglo, validos, 0)){
        printf("es capicua");
    } else {
    printf("no es capicua");
    }

    total = sumaRecursiva(arreglo, 0, validos);

    printf("El total de la suma es: %d", total);

    int menor = menorElementoRE(arreglo, 0, validos);
    printf("El menor es: %d", menor);*/

//   cargarArchivo();
//
    FILE* archi;
//    archi = fopen("miArchivo.bin", "rb");
//    int total = buscaMenorFACU(archi);
//    fclose(archi);
//    printf("EL MENOR ES: %d", total);

    archi = fopen("miArchivo.bin", "rb");
    mostrarArchivoRE(archi, 1);
    fclose(archi);
}


int factorial(int numero)
{

    int rta;

    if(numero == 0)
    {

        rta = 1;

    }
    else
    {

        rta = numero * factorial(numero-1);

    }

    return rta;
}
int ptencia (int base, int potencia)
{

    int rta;

    if(potencia == 0)
    {

        rta = 1;
    }
    else
    {

        rta = base * ptencia(base, potencia-1);
    }

    return rta;
}
int cargarArreglo(int arreglo[], int dim)
{

    int i = 0;
    char letra = 's';

    while(i < dim && letra == 's')
    {

        printf("Ingresa un valor al arreglo: ");
        fflush(stdin);
        scanf("%d", &arreglo[i]);

        printf("Ingresa 's' para contirnuar");
        fflush(stdin);
        scanf("%c", &letra);

        i++;
    }

    return i;
}
void mostrarArregloRE(int arreglo[],int i,  int validos)
{

    if(i == validos-1)
    {

        printf("| %d |", arreglo[i]);
    }
    else
    {

        printf("| %d |", arreglo[i]);
        mostrarArregloRE(arreglo, i+1, validos);
    }
}
void mostrarArregloREINV(int arreglo[],int i,  int validos)
{

    if(i == 0)
    {

        printf("| %d |", arreglo[i]);
    }
    else
    {

        printf("| %d |", arreglo[i]);
        mostrarArregloREINV(arreglo, i-1, validos);
    }
}
int capicuaRE (int arreglo[],int i, int validos)
{
    if (i>=validos)
    {
        return 1;//es capicua
    }

    if(arreglo[i] == arreglo[validos-1-i])
    {

        return capicuaRE(arreglo, i+1, validos);
    }
    else
    {

        return 0;
    }
}
int sumaRecursiva(int arreglo[], int i, int validos)
{

    int suma = 0;

    if(i == validos-1)
    {

        suma = arreglo[i];
    }
    else
    {

        suma = arreglo[i] + sumaRecursiva(arreglo, i+1, validos);
    }
    return suma;
}
int menorElementoRE(int arreglo[], int i, int validos)
{

    int menor;

    if(i == validos-1)
    {

        menor = arreglo[i];

    }
    else
    {

        menor = menorElementoRE(arreglo, i+1, validos);
        if(menor > arreglo[i])
        {

            menor = arreglo[i];

        }
        else
        {

            return menor;

        }

    }

    return menor;
}
int cargarUnArchivo()
{

    FILE* archi;
    archi = fopen("miArchivo.bin", "ab");

    int num;

    if(archi != NULL)
    {

        printf("Ingresa un valor al archivo");
        fflush(stdin);
        scanf("%d", &num);

        fwrite(&num, sizeof(int), 1, archi);

        fclose(archi);
    }

}
void cargarArchivo()
{



    FILE* archi;
    archi = fopen("miArchivo.bin", "ab");

    char letra = 's';

    if(archi != NULL)
    {
        while(letra == 's')

        {

            cargarUnArchivo();

            printf("Ingrese 's' para continuar: ");
            fflush(stdin);
            scanf("%c", &letra);

        }

        fclose(archi);
    }
}
int buscaMenorFACU(FILE* archi)
{
    int aux, menor;

    if(fread(&aux, sizeof(int), 1, archi) == 0)
    {
            fseek(archi, sizeof(int)*-1, SEEK_END);
            fread(&menor, sizeof(int), 1, archi);
    }
    else
    {
        menor = buscaMenorFACU(archi);
        if(aux < menor)
        {
            menor = aux;
        }
    }
    return  menor;
}
void mostrarArchivo(char direc[])
{
    FILE *archi;
    archi = fopen(direc, "rb");
    int num;

    if(archi != NULL)
    {

        while(!feof(archi))
        {

            fread(&num, sizeof(int),1, archi);

            if(!feof(archi))
            {
                printf("\n %d", num);
            }
        }
        fclose(archi);
    }
}

void mostrarArchivoRE(FILE* archi, int i)
{
    int aux;

        if(fread(&aux, sizeof(int), 1, archi) == 0)
        {
            printf("  FINAL ARCHIVO");
        }
        else
        {
            fseek(archi, sizeof(int) * (i-1), SEEK_SET);
            fread(&aux, sizeof(int), 1, archi);
            printf("/ %i ", aux);
            mostrarArchivoRE(archi, i+1);
        }
}
