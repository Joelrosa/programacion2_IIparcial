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

int contar(char nombre[])
{
     int c=1;
     for(int k=0;k<=strlen(nombre);k++)
     {
         switch(nombre[k])
         {
               case ' ':
                         c++;
                         break;
              default:
                         break;
         }
     }

     return c;
}

void contarpalabras(char nombre[t][30])
{
    int conta=0;
    for(int i=0;i<=t;i++)
    {
        conta = contar(nombre[i]);
        cout<<nombre[i]<<"tiene "<<conta<<"palabras "<<"\n";
    }
}


int main()
{
    ingresodecadenas(nombre);
    contarpalabras(nombre);

}
