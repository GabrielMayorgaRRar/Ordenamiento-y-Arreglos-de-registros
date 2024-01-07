#include <stdio.h>
#include <stdbool.h>

struct Cliente
{
    char nombre_del_cliente[30];
    int numero_del_cliente;
    float saldo_actual;
    bool estatus;
};

void menu();

int main(){
    do
    {
        menu();
    }while (/* condition */)
    {
        /* code */
    }
    return 0;       
}
