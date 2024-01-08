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
                float aux = personas[j].imc;
                personas[j].imc = personas[j + 1].imc;
                personas[j + 1].imc = aux;

                char nombre_aux[30];
                strcpy(nombre_aux, personas[j].nombre);
                strcpy(personas[j].nombre, personas[j + 1].nombre);
                strcpy(personas[j + 1].nombre, nombre_aux);

                int id_aux = personas[j].id;
                personas[j].id = personas[j + 1].id;
                personas[j + 1].id = id_aux;

                float peso_aux = personas[j].peso;
                personas[j].peso = personas[j + 1].peso;
                personas[j + 1].peso = peso_aux;

                float estatura_aux = personas[j].estatura;
                personas[j].estatura = personas[j + 1].estatura;
                personas[j + 1].estatura = estatura_aux;
            }
        }
    }
}