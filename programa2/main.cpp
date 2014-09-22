#include <iostream>

using namespace std;
/*
ingresar 5numeros a un arreglo y calcular el factorial de cada
uno delos numeros y copiarlo en otro arreglo =.
usar una funcion para generar el factorial del numero.
usar un procedimiento para ingresar,otro para calcular y para presntar
*/

int const n=5;
int num[n];
long facto[n];

void ingreso (int num[],int n)
{
    int i;
    for (i=0;i<n;i++)
    {
        cout<<"Ingrsar arreglo... [ "<<i<<"]..:";
        cin>>num[i];
    }
}

long factorial (int numero)
{
     int i,fact;
     fact=1;
    for (i=1;i<=numero;i++)
    {
       fact =fact*i;
    }
    return fact;
}

void calcular (int num[],long facto[],int n)
{
    int i;
    for (i=0;i<n;i++)
    {
       facto[i] =factorial(num[i]);
    }

}

void presentar (int num[],long facto[],int n)
{
     int i;
    for (i=0;i<n;i++)
    {
        cout<<"factorial de "<<num[i]<<" es "<<facto[i]<<"\n";
    }
}

int main()
{
    ingreso(num,n);
    calcular(num,facto,n);
    presentar(num,facto,n);

}
