#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct usuario{
  int id;
  char *nombre;
  int q_amigos; //cantidad de amigos
  int *amigos; //vector de usuarios
 }tUsuario;

typedef struct red{
  int q_usuarios;
  tUsuario * usuarios;
}tRed;

int nom_son_iguales(tRed facebook, int n)//nom pasa el nombre, n pasa cuantos usuarios hay
{
    int i;

    //printf("entro al nom iguales y esto tiene n %d ",n);

    if (n==0)//si hay un solo usuario devuelve q no son iguales
    {
        return 0;
    }
    else
    {
        for(i=0;i<n;i++)
        {
            //printf("entro al ciclo. ");
            //printf("\nstrcmp tiene %d\n",strcmp(facebook.usuarios[n].nombre,facebook.usuarios[i].nombre));
            //printf("esto tiene usn %s y esto us i %s.\n",facebook.usuarios[n].nombre, facebook.usuarios[i].nombre);

            /*if(strlen(nom)!=strlen(us[i].nombre))//se fija la cantidad de letras
            {
                return 0;
            }
            else*/ //if((strcmp(nom,us[i].nombre))==0)//compara el nombre con los nmobres del struct

                if((strcmp(facebook.usuarios[n].nombre,facebook.usuarios[i].nombre))==0)
                {
                    //printf("\ndio q son iguales\n");
                    return 1;
                }
                else;
        }
        return 0;
    }
    return 0;
}


int Crear_usuario(tRed facebook, int n)// siempre devuelve el valor de n para saber cuantos hay
{
    char aux[50]={0};
    int f=1;

    facebook.usuarios[n].id=n; //guarda el id del usuario
    while (f!=0)
    {
        printf("\ningrese su nombre: ");
        scanf("%s", aux);
        fflush(stdin);

        //printf("\nesto tiene f %d esto n %d y esto aux %s\n", f, n, aux);

        facebook.usuarios[n].nombre=(char*)malloc(sizeof(char)*(strlen(aux)+1)); //redimenciona la variable nombre para q no ocupe espacio de mas
        strcpy(facebook.usuarios[n].nombre,aux);

        //printf("esto quedo en us[n].nombre %s\n",us[n].nombre);

        f=nom_son_iguales(facebook,n);

        if(f==1)
        {
            printf("el nombre ya existe.\n");
        }
        else;
    }

    facebook.usuarios[n].q_amigos=0;
    facebook.usuarios[n].amigos=NULL;
    n++;
    return n;
}

int main()
{
    int n=0, i;
    char j='s';
    tRed facebook;
    //tUsuario *us=NULL;

    facebook.usuarios=(tUsuario*)malloc(sizeof(tUsuario));//!! usar en el main principal!!agranda con la cantidad de usuarios

    while(j=='s')
    {

        n=Crear_usuario(facebook, n);
        facebook.usuarios=(tUsuario*)realloc(facebook.usuarios,sizeof(tUsuario)*(n+1));

        fflush(stdin);
        printf("desea cargar otro nombre? (pulse s)\n");
        scanf("%c", &j);
        fflush(stdin);

    }

    /*for(i=0;i<n;i++)//para probar q anda
    {
        printf("esto tiene nombre %s esto tiene de amigos %d %d y esto id %d\n", facebook.usuarios[i].nombre, facebook.usuarios[i].amigos, facebook.usuarios[i].q_amigos, facebook.usuarios[i].id);
    }*/
    return 0;
}

