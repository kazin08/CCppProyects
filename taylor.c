/* TAYLOR
Design a function that computes the approximation of the sine using the Taylor series:
sin(x)= 1 - (x^3)/3! + (x^5)/5 - (x^7)/7! + ..........
Note: A good approximation is given by the expansion of at least 10 terms. */
#include <stdio.h>
#include <stdlib.h>

double factorial(double a)
{
    double i, b=1;
    for (i=1;i<=a;i++)
    {
        b*=i;
    }
    return b;
}

double potencia(double a, double b)
{
    double i, c=1;
    for (i=1; i<= b; i++)
    {
        c = c*a;
    }
    return c;
}

double sin (int x)
{
    double sine, algo;

    sine = ((potencia(x,2))/factorial(2)) - ((potencia(x,4))/factorial(4)) + ((potencia(x,6))/factorial(6)) - ((potencia(x,8))/factorial(8)) + ((potencia(x,10))/factorial(10));

    return sine;
}

int main()
{
    int x;
    printf("Enter the value of the sine you want to calculate ");
    scanf("%d", &x);
    printf("The value is %g", sin(x));
    return 0;
}
