#include <iostream>

using namespace std;

const int n=5;

int num[n],mayor,suma,cpar;

void ingreso(int num[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
       cout<<"ingresar Num["<<i<<"]...:";
       cin>>num[i];
    }
}

void presentar(int num[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
       cout<<"Num["<<i<<"]...:"<<num[i]<<"\n";
    }

}

int sumararreglo(int num[],int n)
{
    int i;
    int xsuma=0;
    for(i=0;i<n;i++)
    {
        xsuma+=num[i];
    }
    return xsuma;
}

int maximo(int num[],int n)
{
    int i;
    int xmax=0;
    for(i=0;i<n;i++)
    {
        if(xmax<num[i])
        {
            xmax=num[i];
        }
    }
    return xmax;

}

int pares (int num[],int n)
{
     int i;
    int xpar=0;
    for(i=0;i<n;i++)
    {
        if(num[i]%2==0)
        {
            xpar++;
        }
    }
    return xpar;
}

int main()
{
    mayor=0;
    suma=0;

    ingreso(num,n);
    presentar(num,n);
    suma=sumararreglo(num,n);
    mayor=maximo(num,n);
    cpar=pares(num,n);
    cout<<"Suma del arreglo....: "<<suma<<"\n";
    cout<<"numero mayor....: "<<mayor<<"\n";
    cout<<"contador de pares....: "<<cpar<<"\n";
}
