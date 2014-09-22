#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
struct empleado
{
    char nombre[30];
    char zona;
    double pc,ventas,comis;
};

const int n=5;
empleado emple[n];
empleado maxemple;
empleado temp;

void ingresoReg(empleado emple)
{
    cout<<"ingresar el nombre del empleado....: ";
    cin>>emple.nombre;
    cout<<"ventas de la semanana.. : ";
    cin>>emple.ventas;

    do
    {
        cout<<"ingresar el turno... : ";
        cin>>emple.zona;
    }while(!((emple.zona=='A') or (emple.zona=='B') or (emple.zona=='C')));
}

void ingresar(empleado emple[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        ingresoReg(emple[i]);
    }
}

double comision(empleado emple)
{
    switch(emple.zona)
    {
        case 'A':
        return emple.ventas*0.05;
        break;
              case 'B':
              return emple.ventas*0.06;
              break;
                     default:
                     return emple.ventas*0.08;
    }
}

void calcular(empleado emple[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        emple[i].comis=comision(emple[i]);
    }
}

void presentarReg(empleado emple)
{

    cout<<"nombre del empleado..:  "<<emple.nombre<<"\n";
    cout<<"ventas del mes.......:  "<<emple.ventas<<"\n";
    cout<<"Zona.................:  "<<emple.zona<<"\n";
    cout<<"comision.............:  "<<emple.comis<<"\n\n\n";

}

void presentar(empleado emple[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        presentarReg(emple[i]);
    }
}

 empleado maxEmpleado(empleado emple[],int n)
 {
     int i;
     empleado mayor;
     mayor.comis=0;
     for(i=0;i<n;i++)
     {
         if(emple[i].comis>mayor.comis)
         {
             mayor=emple[i];
         }
     }
     return mayor;
 }

 void ordenalfabetico(){
int i,j;
    for(i=65;i<90;i++){
           for(j=0;j<n;j++){
            if(((int)emple[j].nombre[1])==i){
               presentar(emple[j]);
               }
           }
    }
}
void presentarPorComision(){
int i;
int j;
    for(i=0;i<n;i++){
        for(j=0;j<n-1;j++){
            if(emple[i].comision<emple[j].comision){
                temp = emple[j];
                emple[j]=emple[i];
                emple[i]=temp;
            }
        }
    }
    presentaempleado ( emple, n);
}


int main()
{
    ingresar(emple,n);
    calcular(emple,n);
    presentar(emple,n);
    maxemple=maxEmpleado(emple,n);
    cout<<"empleado mayor.." ;
    presentarReg(maxemple);
    ordenalfabetico();
}
