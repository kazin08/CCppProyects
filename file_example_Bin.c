#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main()
{
    char texto[512], encab[20];
    FILE *fp;

    &encab="EDAD  |";

    if(!fopen("ejemplo.txt","rb"))
    {

        fp=fopen("ejemplo.txt","wb");

        printf("ingrese texto: \n");
        gets(texto);

        fwrite(&texto,sizeof(char),strlen(texto)+1,fp);
        fwrite(&encab,sizeof(char),strlen(encab)+1,fp);

    }
    else
    {

        fp=fopen("ejemplo.txt","rb");

        fread(&texto,sizeof(char),512,fp);
        printf("esto tenia el texto:\n%s\n", texto);

        printf("ingrese texto: \n");
        gets(texto);

        fp=fopen("ejemplo.txt","ab");
        fwrite(&texto,sizeof(char),strlen(texto)+1,fp);

        while (feof(fp)==0)
        {
            printf("%s ", texto);
        }

    }
    fclose(fp);


    return 0;

}
