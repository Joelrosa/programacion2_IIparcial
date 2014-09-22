#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;
const int t=4;
char nombre[t][30];
int num[t];

void ingresodecadenas(char nombre[t][30])
{
    for(int i=0;i<=t;i++)
    {
        cout<<"Ingresar el nombre.... : ";
        cin.getline(nombre[i],30);
    }
}

int comparar2(char nombre[t][30])
{
     char cadcompa[30];

             cout<<"Ingresar el nombre.... : ";
             cin.getline(cadcompa,30);

     for(int i=0;i<=t;i++)
     {
         if (strcmp(nombre[i],cadcompa)==0)
         {
             cout<<"Comparacion correcta con: "<<nombre[i]<<"\n";
         }
     }

}

int main()
{
    ingresodecadenas(nombre);
    comparar2(nombre);
    cout<<"\n"<<"otro tipo de comparacion"<<"\n";

    return 0;

}

