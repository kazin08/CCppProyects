/*
1) Se dispone de los siguientes datos de los empleados de una empresa: numero
de legajo, sueldo y antigüedad. Las ternas de datos se ingresaran en cualquier
orden. Luego del último juego de datos se ingresara un 0 como numero de legajo.
Se sabe que la cantidad de empleados no es más de 100. Se pide un programa
que:
o Imprima un listado ordenado en forma creciente por número de legajo,
de todos aquellos empleados que superen o igualen el sueldo promedio,
informando sus tres atributos.
o Datos completos del o los empleados de mayor antigüedad.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int legajo;
    int sueldo;
    int antig;
}Tempresa;

int main()
{
    int i,j=0,cant=0,cantmost=0,sum=0,mostrar[100], ordenado=0, aux;
    float prom;
    Tempresa empleados[100];

    for (i=0;i<100 && empleados[i-1].legajo;i++) //legajo != 0
    {
        printf("ingrese legajo (0 para terminar) ");
        scanf("%d", &empleados[i].legajo);
        printf("ingrese sueldo ");
        scanf("%d", &empleados[i].sueldo);
        printf("ingrese antiguedad ");
        scanf("%d", &empleados[i].antig);

        cant++;
    }

    cant-=1;//resta uno porq cuenta el 0

    for (i=0; i<cant;i++)//calcula prom
    {
        sum+=empleados[i].sueldo;
    }

    prom=(float)sum/cant;

    for(i=0;i<cant;i++)//los q cumplen con lo pedido
    {
        if(empleados[i].sueldo >= prom)
        {
            mostrar[j++]=i;//guardar la dir de mem de empleados o la posicion?
            cantmost++;
        }
    }

    for(i=0;i<cantmost-1 && !ordenado;i++) //ordena por burbujeo
    {
        ordenado=1;
        for(j=0;j<cantmost-1-i;j++)
        {
            if(empleados[mostrar[j]].legajo>empleados[mostrar[j+1]].legajo)
            {
                aux=mostrar[j];
                mostrar[j]=mostrar[j+1];
                mostrar[j+1]=aux;
                ordenado=0;
            }
        }
    }

    for (i=0; i<cantmost; i++) //muestra en pantalla
    {

        printf("legajo %d sueldo %d antiguedad %d\n", empleados[mostrar[i]].legajo, empleados[mostrar[i]].sueldo, empleados[mostrar[i]].antig);
    }

    return 0;
}
