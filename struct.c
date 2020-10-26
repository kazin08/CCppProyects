/*
The following information is available on the employees of a company: 
file number, salary and seniority. 
The triples of data will be entered in any order. 
After the last data set, a 0 will be entered as the file number.
It is known that the number of employees is not more than 100.
A program is requested that:
* Print a list, ordered in increasing order by file number, 
of all those employees who exceed or equal the average salary, 
reporting their three attributes.
* Complete data of the oldest employee (s).
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
