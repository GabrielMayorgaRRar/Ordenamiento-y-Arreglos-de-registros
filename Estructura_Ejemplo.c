#include <stdio.h>

#define MAX 2

struct owner
{
    char nombredu[30];
    char domiciliodu[50];
};

struct perro
{
    char nombre[30];
    int edadenmeses;
    float peso;
    struct owner ownerper;
};

int main()
{

    struct perro STPerro[MAX];

    for (int i = 0; i < MAX; i++)
    {
        printf("Ingresa el nombre del perro: ");
        scanf(" %[^\n]", STPerro[i].nombre);
        printf("Ingresa la edad en meses del perro: ");
        scanf("%d", &STPerro[i].edadenmeses);
        printf("Ingresa el peso del perro: ");
        scanf("%f", &STPerro[i].peso);
        printf("Ingresa el nombre del dueño: ");
        scanf(" %[^\n]", STPerro[i].ownerper.nombredu);
        printf("Ingresa la direccion del dueño: ");
        scanf(" %[^\n]", STPerro[i].ownerper.domiciliodu);
        printf("\n");
    }

    for (int i = 0; i < MAX; i++)
    {
        printf("\nEl nombre del perro %d es: %s", i + 1, STPerro[i].nombre);
        printf("\nLa edad en meses del perro %d es: %d", i + 1, STPerro[i].edadenmeses);
        printf("\nEl peso del perro %d es: %0.2f", i + 1, STPerro[i].peso);
        printf("\nEl dueño de %s se llama %s", STPerro[i].nombre, STPerro[i].ownerper.nombredu);
        printf("\n%s vive en %s", STPerro[i].ownerper.nombredu, STPerro[i].ownerper.domiciliodu);
        printf("\n");
    }
    return 0;
}