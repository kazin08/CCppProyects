#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo
{
    int dato;
    struct nodo * sig;
}Tnodo;

typedef Tnodo * Tlista;


void copiar_dato(int *d, int d2)
{
    *d=d2;
}

void lista_agregar (int dato, Tlista *l)
{
    Tnodo *aux;
    aux=(Tnodo*)malloc(sizeof(Tnodo));
    copiar_dato(&(aux->dato),dato);
    aux->sig=*l;
    *l=aux;
    //return 0;
}

int main()
{
    int otro, a, b;
    char c='s';
    Tlista lista, aux, aux2, q;

    lista=(Tlista*)malloc(sizeof(Tlista));
    aux2=(Tnodo*)malloc(sizeof(Tnodo));

    printf("ingrese un numero: ");
    scanf("%d", &a);
    fflush(stdin);

    lista->dato=a;
    lista->sig=NULL;

    while (c=='s')
    {

        printf("ingrese un numero: ");
        scanf("%d", &a);
        fflush(stdin);

        lista_agregar(aux, lista);


        printf("desea ingresar otro dato? s/n\n");
        scanf("%c", &c);
        fflush(stdin);

    }

    q=lista;
    while (q)
    {
        printf("esto es lo q hay %d", q->dato);
        q=q->sig;
    }

    return 0;


}
