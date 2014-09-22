#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
 int const npar[3];
struct alumnos
{
   char nombre[30];
   int parcial[npar];
   double promedio;
   char obs[15];
};

int const n=5;
alumnos alumno[n];

void ingresar(alumnos alumno[],int n)
{
    int i,k;
    for (i=0;i<n;i++)
    {
        cout<<" ingresar el nombre del alumno.... : ";
        cin>>getline(alumno[i].nombre,30);
        for (k=0;k<npar;k++)
        {
            cout<<"ingresar el parcial "<<k<<"...: " ;
            cin>>alumno[i].parcial[k];
        }
    }
}

double calpromedio(int parcial[],int npar)
{
    double suma=0;
    for (k=0;k<npar;k++)
    {
        suma+=parcial[k];
    }
    return suma/npar;

}


void calculo (alumnos alumno[],int n,int npar)
{
    int i,k;
    for (i=0;i<n;i++)
    {
        alumno[i].promedio=calpromedio(alumno[i].parcial,npar);
        if (alumno[i].promedio>60)
        {
            strcpy(alumno[i].obs,"Aprobado");
            else
            {
                strcpy(alumno[i].obs,"Reprobado");
            }
        }
    }
}

void presentar (alumnos alumno[],int n)
{
    int i;
    for (i=0;i<n;i++)
    {
        cout<<alumno[i].nombre<<"promedio "<<alumno[i].promedio<<"Obs "<<alumno[i].obs<<"\n";

    }

}

int main()
{
     ingresar(alumno,n);
     calcular(alumno,n);
     presentar(alumno,n);



}
