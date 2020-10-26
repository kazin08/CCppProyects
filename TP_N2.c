//TP 2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int es_clave(char clav[]) //verifica si la clave es correcta
{
    int i, j, k, val=0;

    if(contar_str(clav)!=5) //para verificar que sean 5 letras
    {
        return 0;
    }
    else
    {
        for (i=0;i<5;i++)
        {
            k=i;
            if (clav[i]>= 'A' && clav[i]<= 'Y' && clav[i]!= 'Ñ') //clave de caracteres validos
            {
                for(j=0;j<5;j++) //se fija en todo el vector si las letras son iguales
                {
                    if (clav[i]!=clav[++k]) //ver si ingresan dos letras iguales
                    {
                        val++; //cuenta los datos correctos
                    }
                    else;
                }
            }
        }
        if(val==25)	//si no tiene valores iguales y las letras son correctas devuelve 1
        {
            return 1;
        }
        else return 0;
    }
}

void armar_matriz(char clav[5], char matriz[][5]) //funcion para armar la matriz 5x5
{
    int i, j, k; //i columna, j fila
    char letra='A';
    for(j=0;j<5;j++)
    {
        matriz[0][j]=clav[j]; //copia clave en el primer vector
    }

    for(i=1;i<5;i++) //ciclo para completar con las letras del abcedario
    {
        for(j=0;j<5;j++)
        {
            for(k=0;k<5;k++)
            {
                if(clav[k]==letra)
                {
                    letra++;
                }
                else;
            }
            matriz[i][j]=letra;
            letra++;

        }
    }

}

void cifrado(char texto[], int hacer, char matriz[5][5], char codif[]) //cifrado del texto ingresado
{
    int i, j=0, k, l, p, q=0,r=0, fil[2], col[2]; //i columna j fila
    char m[2], c[2]; //memorias para las letras de a par

    l=contar_str(texto); //para saber cuantas veces lo va a realizar
    if (l%2!=0) //si es impar le agrego una z al final
    {
        texto[l++]='Z';
        l/=2;           //divido por dos porq pasa de a dos letras
    }
    else l/=2;          //divido por dos porq pasa de a dos letras

    while (l>0) //ciclo para pasar de a dos lo cambie (l>=0)
    {
        for(p=0;p<2;p++) //ciclo para pasar de a dos letras
        {
            m[p]=texto[q];
            q++;
        }
        if(hacer == 1) //codifica con hacer =1, decodifica con hacer =0
        {
            codificar(matriz, texto, m, c);//!!codificar

        }
        else  //aca va el decodificado
        {
            decodificar(matriz, texto, m, c);

        }
        l--;
        for(k=0;k<2;k++)
        {
            codif[r]=c[k]; //guarda el texto en codif
            r++;
        }
    }
}

void codificar(char matriz[5][5],char texto[],char m[], char c[])//funcion para codificar
{
    int i, j, k, fil[2], col[2];

    for(i=0;i<5;i++) //busca donde estan las letras iguales
    {
        for(j=0;j<5;j++)
        {
            for(k=0;k<2;k++)
            {
                if(matriz[i][j]==m[k])
                {
                    fil[k]=j;
                    col[k]=i;
                }
            }
        }
    }
    if(m[0]!=m[1] && m[0]<'Z' && m[1]<'Z' && m[0]>='A' && m[1]>='A') //verificacion de los datos ingresados
    {
        if(fil[0]==fil[1])
        {
            if(col[0]==4)
            {
                col[0]=0;
            }
            else if(col[1]==4)
                {
                    col[1]=0;
                }
                else
                {
                    col[0]++;
                    col[1]++;
                }
        }
        else if(col[0]==col[1])
        {
            if(fil[0]==4)
            {
                fil[0]=0;
            }
            else if(fil[1]==4)
                {
                    fil[1]=0;
                }
                else
                {
                    fil[0]++;
                    fil[1]++;
                }
        }
        else
        {
            k=fil[0];//lo q se hace cuando no son iguales
            fil[0]=fil[1];
            fil[1]=k;
        }
        for(k=0;k<2;k++)
        {
            c[k]=matriz[col[k]][fil[k]];
        }
    }
    else
    {
        c[0]=m[0];
        c[1]=m[1];
    }
}

void decodificar(char matriz[5][5],char texto[],char m[], char c[])//funcion para decodificar
{
    int i, j, k, fil[2], col[2];

    for(i=0;i<5;i++) //busca donde estan las letras iguales
    {
        for(j=0;j<5;j++)
        {
            for(k=0;k<2;k++)
            {
                if(matriz[i][j]==m[k])
                {
                    fil[k]=j;
                    col[k]=i;
                }
            }
        }
    }
    if(m[0]!=m[1] && m[0]<'Z' && m[1]<'Z' && m[0]>='A' && m[1]>='A')
    {
        if(fil[0]==fil[1])
        {
            if(col[0]==0)
            {
                col[0]=4;
            }
            else if(col[1]==0)
                {
                    col[1]=4;
                }
                else
                {
                    col[0]--;
                    col[1]--;
                }
        }
        else if(col[0]==col[1])
        {
            if(fil[0]==0)
            {
                fil[0]=4;
            }
            else if(fil[1]==0)
                {
                    fil[1]=4;
                }
                else
                {
                    fil[0]--;
                    fil[1]--;
                }
        }
        else
        {
            k=fil[0];//lo q se hace cuando no son iguales
            fil[0]=fil[1];
            fil[1]=k;
        }
        for(k=0;k<2;k++)
        {
            c[k]=matriz[col[k]][fil[k]];
        }
    }
    else
    {
        c[0]=m[0];
        c[1]=m[1];
    }
}

int contar_str(char texto[]) //funcion para contar caracteres hasta en \0
{
    int i, cont=0;

    for(i=0;texto[i]!='\0';i++)
    {
        cont++;
    }
    return cont;
}

int main()
{
    int i,j, hacer=1;
    char c=1, clav[5], matriz[5][5]={0}, texto[512]={0}, codif[512]={0}; //c verifica la validez de la clave

    while (c==1) //primer ciclo q vuelve a preguntar cuando la clave es incorrecta
    {
        printf("ingrese una clave de 5 letras sin repetir y en mayusculas: ");
        gets(clav); //gets funciona bien
        fflush(stdin);
        printf("%s\n", clav); //ver q hay

        if (!(es_clave(clav)))
        {
            printf("clave invalida.\n");
            c=1;
        }
        else
        {
            printf("clave valida.\n");
            c=0;
            armar_matriz(clav, matriz);
            printf("ingrese texto a cifrar en mayusculas de lo contrario no codificara ninguna letra (maximo 512 caracteres): ");
            gets(texto);
            fflush(stdin);
            cifrado(texto, hacer, matriz, codif);
            printf("el texto cifrado es %s ", codif);
            printf("\ningrese texto a decodificar: ");
            gets(texto);
            hacer = 0; //para decodificar
            cifrado(texto, hacer, matriz, codif);
            printf("el texto decodificado es %s ", codif);
        }
    }

    return 0;
}
