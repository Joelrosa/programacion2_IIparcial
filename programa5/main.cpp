#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
/*
ingresar 5 alumnos a un registro con los siguentes datos, nombre p1,p2,promedio

usando el prosedimineto ingresar el nombre y las notas usar una funcion para calcular el promedio
de un alumno
usar un procedimiento para calcular los promedios de todos los alumnos
usar una funcion para devolver el mejor alumno de todo el arreglo
elaborar un procedimieto para presentar el alumno
elaborar un procedimiento para presentar todos los alumnos.
*/

struct alumnos
{
    int p1,p2,promedio,promediototal;
    char nombre[30];
};

int const n=5;
alumnos alum[n];
alumnos mejoralumno;

void ingresar_nombrenotas(alumnos alum[], int n)
{
    int i;
    for (i=0;i<n;i++)
    {
        cout<<i+1<<")"<<"Ingresar el nombre del alumno..........: ";
        cin.getline(alum[i].nombre,30);
        cout<<"  Ingresar la nota  del primer parcial...: ";
        cin>>alum[i].p1;
        cout<<"  Ingresar la nota  del segundo parcial..: ";
        cin>>alum[i].p2;
        _flushall();
        cout<<endl;
    }
}
int promedio(int p1, int p2, int promedio)
{
    promedio= (p1+p2)/2;
    return promedio;
}
void promedio_dealumno(alumnos alum[], int n)
{   int i;
    for(i=0;i<n;i++)
    {
        alum[i].promedio= promedio(alum[i].p1, alum[i].p2, alum[i].promedio);
    }
}

void presentar(alumnos alum)
{
    cout<<"El nombre del alumno es.....: "<<alum.nombre<<endl;
    cout<<"Nota del primer parcial.....: "<<alum.p1<<endl;
    cout<<"Nota del segundo parcial....: "<<alum.p2<<endl;
    cout<<"El promedio del alumno es...: "<<alum.promedio<<endl;


}
void presentar_todos(alumnos alum[], int n)
{
    int i;
    for (i=0; i<n; i++)
    {
        presentar(alum[i]);
    }
}
alumnos Mejoralumno(alumnos alum[], int n)
{
    int i;
    alumnos xmax;
    xmax= alum[0];
    for(i=0;i<n;i++)
    {
        if(alum[i].promedio> xmax.promedio)
            xmax= alum[i];
    }
    return xmax;
}

int main()
{
    int promedio;
    ingresar_nombrenotas(alum, n);
    promedio_dealumno(alum, n);
    presentar_todos(alum, n);


    mejoralumno= Mejoralumno(alum,n);
    cout<<endl;
    cout<<"El mejor alumno es:"<<endl;
    presentar(mejoralumno);
}

