#include <stdio.h>
#include <string.h>

typedef struct
{
    char nombre[30];
    int id;
    float peso;
    float estatura;
    float imc;
} datospersonales;

void burbuja(datospersonales personas[], int tamano);

int main()
{
    int npersonas;
    scanf("%d", &npersonas);
    datospersonales personas[npersonas];
    for (int i = 0; i < npersonas; i++)
    {
        scanf("%d", &personas[i].id);
        scanf(" %[^\n]", personas[i].nombre);
        scanf("%f %f", &personas[i].peso, &personas[i].estatura);
        personas[i].imc = (personas[i].peso / (personas[i].estatura * personas[i].estatura));
    }

    burbuja(personas, npersonas);

    for (int i = 0; i < npersonas; i++)
    {
        printf("%d ", personas[i].id);
        printf("%s ", personas[i].nombre);
        printf("%0.1f\n", personas[i].imc);
    }
}

void burbuja(datospersonales personas[], int tamano)
{
    for (int i = 0; i < tamano - 1; i++)
    {
        for (int j = 0; j < tamano - 1 - i; j++)
        {
            if (personas[j].imc < personas[j + 1].imc)
            {
                datospersonales temp = personas[j];
                personas[j] = personas[j + 1];
                personas[j + 1] = temp;
            }
        }
    }
}