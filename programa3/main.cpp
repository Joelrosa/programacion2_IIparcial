#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
/*
Generaar en un arreglo que se llama base 5 numeros entre 1 y 10 , gual
en el otro arreglo que se llama expo.
luego determinar la potencia elevada la base al expo y copiarla en otro
arreglo
*/

int const n=5;
int base[n];
int exp[n];
long pot[n];

void generar(int base[],int expo[],int n)
{
    int i;
    srand(time(0));
    for(i=0;i<n;i++)
    {
        base[i]= 1 + rand()%(10+1)
        expo[i]= 1 + rand()%(108+1)
    }
}

long potencia (int base,int expo)
{
    int i;
    int pot=1;
    for(i=0;i<pot;i++)
    {
        pot=base*pot;
    }
    return pot;
}

void calular (int base[],unt expo[],long pot[],int n)
{
    int i;

    for(i=0;i<n;i++)
    {
        pot[i]=potencia(base[i],expo[i]);
    }
}

void presentar(int base[],unt expo[],long pot[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        cout<<base[i]<<"elevado a la "<<expo[i]<<" es "<<pot[i]<<"\n";
    }

}
int main()
{
     generar(base,expo,n);
     calular(base,expo,pot,n);
     presentar(base,expo,n);
}
