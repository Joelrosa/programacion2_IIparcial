#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
/* si tiene un arreglo de registros con la siguiente estructura
nombre
zona
ventas
comision

elaborar un procedimiento para ingresar el registro nombre,ventas y validar zona

debera de calcular la comision ganada usando una funcion
zona       comis
A             5%
B             6%
C             8%

elaborar un procedimiento para calcular todas las camisiones
elaborar una funcion para devolver el mejor empleado usando la comision
ganada

usar prosedimiento para presentar un empleado y otro para presentar todos los empleados
presentar el mejor empleado y otro para presentar todos los empleados
presentar mejor empleado
*/
struct empleado
{
    char nombre[30];
    int zona,ventas;
    double comis;
};
int const n=5;
empleado emple[n];

void ingreso(empleado emple[], int n)
{   int i;
    for(i=0;i<n;i++)
    {
        cout<<"Ingresar Nombre del empleado:...";
        cin.getline(emple[i].nombre,30);
        cout<<"Zona..:";
        cin>>emple[i].zona;
        do
        {
            cout<<"Turno de trabajo...:";
            cin>>emple[i].zona;

        }while((emple[i].zona!='A') and (emple[i].zona!='B') and (emple[i].zona!='C'));
        _flushall();
    }
}

double comision(int zona)
{   int i;
    switch(zona)
    {
    case 'A':
        return 0.05;
        break;
     case 'B':
        return 0.06;
        break;
    default:
        return 0.08;
        break;
    }
    return emple[i].comis;
}

double calcular(empleado emple[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        emple[i].zona= comision (emple[i].zona);
        emple[i].comis= emple[i].ventas * emple[i].zona;
    }
}
void presentar_reg(empleado emple)
{
    cout<<"nombre del empleado... " <<emple.nombre<<endl;
    cout<<" comision por zona .... : "<<emple.zona<<endl;
    cout<<" comision ganada ....: "<<emple.comis<<endl;
}
void presentar_todos(empleado emple[], int n)
{
    int i;
    for (i=0; i<n; i++)
    {
        presentar_reg(emple[i]);
    }
}

  empleado Mejoraempleado(empleado emple[], int n)
{
    int i;
    empleado xmax;
    xmax= emple[0];
    for(i=0;i<n;i++)
    {
        if(emple[i].comis> xmax.comis)
            xmax= emple[i];
    }
    return xmax;





int main()
{

}
































