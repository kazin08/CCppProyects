//punto 16) Sub programas
//16) Diseñar una función que calcule la aproximación del seno utilizando la serie de
//Taylor:
//sen(x)= 1 - (x^3)/3! + (x^5)/5 - (x^7)/7! + ..........
//Nota: Una buena aproximación está dada por el desarrollo de 10 términos como
//mínimo.
#include <stdio.h>
#include <stdlib.h>

double factorial(double a)
{
    double i, b=1;
    for (i=1;i<=a;i++)
    {
        b*=i;
    }
    printf("esto tiene el factorial de %g = %g\n", a, b);
    return b;
}

double potencia(double a, double b)
{
    double i, c=1;
    for (i=1; i<= b; i++)
    {
        c = c*a;
    }
    printf("esto tiene potencia de %g a la %g = %g\n", a, b, c);
    return c;
}

double sen (int x)
{
    double seno, algo;

    seno = ((potencia(x,2))/factorial(2)) - ((potencia(x,4))/factorial(4)) + ((potencia(x,6))/factorial(6)) - ((potencia(x,8))/factorial(8)) + ((potencia(x,10))/factorial(10));

    return seno;
}

int main()
{
    int x;
    printf("ingrese el valor del seno que desee calcular ");
    scanf("%d", &x);
    printf("el valor es %g", sen(x));
    return 0;
}
