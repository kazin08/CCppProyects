/* Tp N1 Algoritmos y programacion I, catedra Kuhn, alumno: Emanuel Lupia. padrón: 92934 */

#include <stdio.h>

int main()
{   int A=0, monto, montot=0, montov1=0, montov2=0, montov3=0, montov4=0, totalvent=0, vendedor=0, vend1=0, vend2=0, vend3=0, vend4=0;
    char letra;
    float comic;

    do{
    puts("Ingrese una opción para resolver el problema:\na) Utilizando ciclo for\nb) Utilizando ciclo while\nc) Utilizando ciclo do-while\nd) Salir "); //menu inicial
    scanf("%c", &letra);
    fflush(stdin);                                  //sin el fflush pasaba dos veces por el menu

    switch (letra)
    {
        case 'a':                                   //caso FOR

        totalvent=0, vendedor=0, monto=0, montot=0, montov1=0, montov2=0, montov3=0, montov4=0, vend1=0, vend2=0, vend3=0, vend4=0; //vuelvo a inicializar
        for (letra = 's'; letra == 's'; totalvent++)//inicio del bucle con FOR
        {
            puts("Ingrese el número del vendedor: (1 al 4)");
            scanf("%d", &vendedor);
            fflush(stdin);

            if (vendedor>=1 && vendedor<=4)               //para ver si ingresaron bien el numero
            {
                puts("Ingrese el valor de la venta:");
            scanf("%d", &monto);
            fflush(stdin);
            montot += monto;                        //monto total de todos los vendedores
            if (vendedor == 1)
            {
                vend1 ++;                           //cantidad de ventas del vendedor 1
                montov1 += monto;                   //monto paracial del vendedor 1
            }
            else if (vendedor == 2)
            {
                vend2 ++;
                montov2 += monto;
            }
            else if (vendedor == 3)
            {
                vend3 ++;
                montov3 += monto;
            }
            else if (vendedor == 4)
            {
                vend4 ++;
                montov4 += monto;
            }
            do {                                                            //verificar letra ingresada
                puts("Quiere volver a cargar otro valor? (ingrese s o n)");
                scanf("%c", &letra);
                fflush(stdin);
                if (!(letra == 's' || letra == 'n'))                        //si la letra no es s o n salta el error y vuelve a preguntar
                    {
                        puts("El valor ingresado no es correcto.\n");
                        A=0;
                    }
                else A=1;
                } while (A == 0);
            }

            else puts("el numero ingreso no es correcto");
        }
        comic = ( montot/100.0)*20.0;                                                   //calculo de la comicion y la muestra en pantalla
        printf("El monto total es de $%d\nDe comición es $%.2f\nSe vendieron %d vehiculos\n", montot, comic, totalvent); //utilize printf porque el puts me daba error
        if (vend1>vend2 && vend1>vend3 && vend1>vend4)                                  //el if es para ver cual vendio mas
        {
            printf("El vendedor 1 es el que mas vendio con un monto de $%d", montov1);
        }
        else if(vend2>vend3 && vend2>vend4)
        {
            printf("El vendedor 2 es el que mas vendio con un monto de $%d", montov2);
        }
        else if(vend3>vend4)
            {
                printf("El vendedor 3 es el que mas vendio con un monto de $%d", montov3);
            }
            else printf("El vendedor 4 es el que mas vendio con un monto de $%d", montov4);
        getchar();                                                                      //agrego getchar para que no vuelva el menu muy rapido
        break;



        case 'b': //caso WHILE

        letra='s', totalvent=0, vendedor=0, monto=0, montot=0, montov1=0, montov2=0, montov3=0, montov4=0, vend1=0, vend2=0, vend3=0, vend4=0; //vuelvo a inicializar
        while (letra == 's') //incio del bucle con WHILE
        {
            totalvent ++;

            puts("Ingrese el número del vendedor: (1 al 4)");
            scanf("%d", &vendedor);
            fflush(stdin);

            if (vendedor>=1 && vendedor<=4)               //para ver si ingresaron bien el numero
            {
                puts("Ingrese el valor de la venta:");
            scanf("%d", &monto);
            fflush(stdin);
            montot += monto;                        //monto total de todos los vendedores
            if (vendedor == 1)
            {
                vend1 ++;                           //cantidad de ventas del vendedor 1
                montov1 += monto;                   //monto paracial del vendedor 1
            }
            else if (vendedor == 2)
            {
                vend2 ++;
                montov2 += monto;
            }
            else if (vendedor == 3)
            {
                vend3 ++;
                montov3 += monto;
            }
            else if (vendedor == 4)
            {
                vend4 ++;
                montov4 += monto;
            }
            do {                                                            //verificar letra ingresada
                puts("Quiere volver a cargar otro valor? (ingrese s o n)");
                scanf("%c", &letra);
                fflush(stdin);
                if (!(letra == 's' || letra == 'n'))                        //si la letra no es s o n salta el error y vuelve a preguntar
                    {
                        puts("El valor ingresado no es correcto.\n");
                        A=0;
                    }
                else A=1;
                } while (A == 0);
            }

            else puts("el numero ingreso no es correcto");
        }
        comic = ( montot/100.0)*20.0;
        printf("El monto total es de $%d\nDe comición es $%.2f\nSe vendieron %d vehiculos\n", montot, comic, totalvent);
        if (vend1>vend2 && vend1>vend3 && vend1>vend4)                                  //el if es para ver cual vendio mas
        {
            printf("El vendedor 1 es el que mas vendio con un monto de $%d", montov1);
        }
        else if(vend2>vend3 && vend2>vend4)
        {
            printf("El vendedor 2 es el que mas vendio con un monto de $%d", montov2);
        }
        else if(vend3>vend4)
            {
                printf("El vendedor 3 es el que mas vendio con un monto de $%d", montov3);
            }
            else printf("El vendedor 4 es el que mas vendio con un monto de $%d", montov4);
        getchar();
        break;




        case 'c': //caso DO-WHILE

        letra='s', totalvent=0, vendedor=0, monto=0, montot=0, montov1=0, montov2=0, montov3=0, montov4=0, vend1=0, vend2=0, vend3=0, vend4=0; //vuelvo a inicializar
        do                                                  //inicio del bucle con DO-WHILE
        {
            totalvent ++;

            puts("Ingrese el número del vendedor: (1 al 4)");
            scanf("%d", &vendedor);
            fflush(stdin);

            if (vendedor>=1 && vendedor<=4)               //para ver si ingresaron bien el numero
            {
                puts("Ingrese el valor de la venta:");
            scanf("%d", &monto);
            fflush(stdin);
            montot += monto;                        //monto total de todos los vendedores
            if (vendedor == 1)
            {
                vend1 ++;                           //cantidad de ventas del vendedor 1
                montov1 += monto;                   //monto paracial del vendedor 1
            }
            else if (vendedor == 2)
            {
                vend2 ++;
                montov2 += monto;
            }
            else if (vendedor == 3)
            {
                vend3 ++;
                montov3 += monto;
            }
            else if (vendedor == 4)
            {
                vend4 ++;
                montov4 += monto;
            }
            do {                                                            //verificar letra ingresada
                puts("Quiere volver a cargar otro valor? (ingrese s o n)");
                scanf("%c", &letra);
                fflush(stdin);
                if (!(letra == 's' || letra == 'n'))                        //si la letra no es s o n salta el error y vuelve a preguntar
                    {
                        puts("El valor ingresado no es correcto.\n");
                        A=0;
                    }
                else A=1;
                } while (A == 0);
            }

            else puts("el numero ingreso no es correcto");

        } while (letra == 's');

        comic = ( montot/100.0)*20.0;
        printf("El monto total es de $%d\nDe comición es $%.2f\nSe vendieron %d vehiculos\n", montot, comic, totalvent);
        if (vend1>vend2 && vend1>vend3 && vend1>vend4)                                  //el if es para ver cual vendio mas
        {
            printf("El vendedor 1 es el que mas vendio con un monto de $%d", montov1);
        }
        else if(vend2>vend3 && vend2>vend4)
        {
            printf("El vendedor 2 es el que mas vendio con un monto de $%d", montov2);
        }
        else if(vend3>vend4)
            {
                printf("El vendedor 3 es el que mas vendio con un monto de $%d", montov3);
            }
            else printf("El vendedor 4 es el que mas vendio con un monto de $%d", montov4);
        getchar();

        break;
    }

    } while (letra != 'd');
    puts("Usted salio del programa.");
    getchar();

    return 0;
}
