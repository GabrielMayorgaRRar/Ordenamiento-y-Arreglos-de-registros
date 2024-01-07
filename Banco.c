#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

typedef struct
{
    char nombre_del_cliente[50];
    int numero_de_cuenta;
    int saldo_actual;
    bool estatus;
} cliente;

void menu();
void abrir_count_new(cliente Clientes[], int number_count_new,
                     char nombre_count_new[], int saldo_count_new);
void eliminar_count(cliente Clientes[], int number_count_new);
void consultar_saldo_count(cliente Clientes[], int number_count_new);
void depositar_count(cliente Clientes[], int number_count_new, int saldo_count_new);
void retiro_count(cliente Clientes[], int number_count_new, int saldo_count_new);

int main()
{
    int num_operaciones, contador = 0, number_count_new, saldo_count_new;

    char nombre_count_new[50];

    printf("Introduce el numero de operaciones: ");
    scanf("%d", &num_operaciones);

    cliente Clientes[MAX];

    menu();

    char opcion;
    do
    {
        scanf(" %c", &opcion);
        contador++;
        switch (opcion)
        {
        case 'A':
            scanf("%d", &number_count_new);
            scanf(" %[^\n]", nombre_count_new);
            scanf("%d", &saldo_count_new);
            abrir_count_new(Clientes, number_count_new, nombre_count_new, saldo_count_new);
            break;
        case 'B':
            scanf("%d", &number_count_new);
            eliminar_count(Clientes, number_count_new);
            break;
        case 'C':
            scanf("%d", &number_count_new);
            consultar_saldo_count(Clientes, number_count_new);
            break;
        case 'D':
            scanf("%d", &number_count_new);
            scanf("%d", &saldo_count_new);
            depositar_count(Clientes, number_count_new, saldo_count_new);
            break;
        case 'E':
            scanf("%d", &number_count_new);
            scanf("%d", &saldo_count_new);
            retiro_count(Clientes, number_count_new, saldo_count_new);
            break;
        default:
            printf("\n'CASO INVALIDO'\n\n");
            break;
        }
    } while (contador < num_operaciones);
    return 0;
}

void menu()
{
    printf("Elije una opcion entre las siguientes\n");
    printf("Opcion A - Abrir una cuenta\n");
    printf("Opcion B - Dar de Baja una cuenta\n");
    printf("Opcion C - Consultar saldo\n");
    printf("Opcion D - Hacer un deposito\n");
    printf("Opcion E - Retirar dinero\n");
}

void abrir_count_new(cliente Clientes[], int number_count_new,
                     char nombre_count_new[], int saldo_count_new)
{
    if (Clientes[number_count_new].estatus == false)
    {
        Clientes[number_count_new].estatus = true;
        strcpy(Clientes[number_count_new].nombre_del_cliente, nombre_count_new);
        Clientes[number_count_new].numero_de_cuenta = number_count_new;
        Clientes[number_count_new].saldo_actual += saldo_count_new;
        printf("\nOK\n\n");
    }
    else
    {
        printf("\nERROR\n\n");
    }
}

void eliminar_count(cliente Clientes[], int number_count_new)
{
    if (Clientes[number_count_new].estatus == true)
    {
        Clientes[number_count_new].estatus = false;
        strcpy(Clientes[number_count_new].nombre_del_cliente, " ");
        Clientes[number_count_new].numero_de_cuenta = 0;
        Clientes[number_count_new].saldo_actual = 0;
        printf("\nOK\n\n");
    }
    else
    {
        printf("\nERROR\n\n");
    }
}

void consultar_saldo_count(cliente Clientes[], int number_count_new)
{
    if (Clientes[number_count_new].estatus == true)
    {
        printf("%s %d\n\n", Clientes[number_count_new].nombre_del_cliente,
               Clientes[number_count_new].saldo_actual);
    }
    else
    {
        printf("\nERROR\n\n");
    }
}

void depositar_count(cliente Clientes[], int number_count_new, int saldo_count_new)
{
    if (Clientes[number_count_new].estatus == true)
    {
        Clientes[number_count_new].saldo_actual += saldo_count_new;
        printf("\n%s %d\n\n", Clientes[number_count_new].nombre_del_cliente,
               Clientes[number_count_new].saldo_actual);
    }
    else
    {
        printf("\nERROR\n\n");
    }
}

void retiro_count(cliente Clientes[], int number_count_new, int saldo_count_new)
{
    if (Clientes[number_count_new].estatus == true &&
        Clientes[number_count_new].saldo_actual >= saldo_count_new)
    {
        Clientes[number_count_new].saldo_actual -= saldo_count_new;
        printf("\n%s %d\n\n", Clientes[number_count_new].nombre_del_cliente,
               Clientes[number_count_new].saldo_actual);
    }
    else
    {
        printf("\nERROR\n\n");
    }
}