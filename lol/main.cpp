#include <iostream>
#include <stdlib.h>
#include<stdio.h>


using namespace std;
/*
  se tiene un arreglo de registros con la siguiente estructura:
  nombre
  zona
  ventas
  comision

  Elaborar un procedimiento para ingresar nombre , ventas , y validar zona.

  debera calcular la comision ganada  usando una funcion.
  zona comision
  A        5
  B        6
  C        8

  Elaborar un procedimiento para calcular todas las comisiones

  Elaborar una funcion para devolver el mejr epleado usando la comisionganada.

  Usar un procedimiento para presentar un empleado y otro para presentar todos ls empleados

  presentar el mejor empleado

*/
struct empleado
{
    char nombre[30];
    char zona;
    double comision,ventas,;
};

const int n=;
empleado emple[n];
empleado maxemple;
empleado temp;

void ingreso(empleado emple)
{

    cout<<"Ingresar el nombre del empleado :";
    cin>>emple.nombre,30;

    cout<<"Ingresar ventas del empleado:";
    cin>>emple.ventas;

      do
       {
           cout<<"Zona de trabajo del empleado :";
           cin>>emple.zona;


       }while(emple.zona!='a'and emple.zona!='b' and emple.zona!='c');


}

void ingresar(empleado emple[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
     ingreso(emple[i]);
    }

}

double Comision(empleado emple)
{

     switch (emple.zona)
        {
            case 'A':
                  return emple.ventas * 0.05;
                  break;
            case 'B':
                  return emple.ventas * 0.06;
                  break;
            default:
                  return emple.ventas * 0.08;
                  break;
        }
}

void calcular(empleado emple[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        emple[i].comision=Comision(emple[i]);
    }

}

void presentar(empleado emple)
{
   cout<<"Nombre del empleado"<<emple.nombre<<"\n";
   cout<<"Ventas del mes "<<emple.ventas<<"\n";
   cout<<"Zona "<<emple.zona<<"\n";
   cout<<"COmision"<<emple.comision<<"\n";
   _flushall();
}

void presentaempleado (empleado emple[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        presentar(emple[i]);
    }
}
empleado maxEmpleado(empleado emple[],int n)
{
    int i;
    empleado mayor;
    mayor.comision=0;
    for(i=0;i<n;i++)
    {
        if(emple[i].comision>mayor.comision)
        {
            mayor=emple[i];
        }
    }
    return mayor;
}
void presentarOrdenado(){
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
  presentaempleado(emple,n);
  maxemple=maxEmpleado(emple,n);
  cout<<"Empleado mayor";
  presentar(maxemple);
  presentarOrdenado();
