#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;

char cadena[30];

void presenar1(char cadena[])
{
    int i,k;
    for(i=0;i<strlen(cadena);i++)
    {
        for(k=0;k<=i;k++)
        {
            cout<<cadena[k];
        }
        cout<<"\n";
    }
}

void presentar2(char cadena[])
{
    int i,k;
    for(i=strlen(cadena);i>=0;i--)
    {
        for(k=0;k<=i;k++)
        {
            cout<<cadena[k];
        }
        cout<<"\n";
    }

}
int main()
{
    cout<<"ingresar cadena de exto....: ";
    cin.getline(cadena,30);
    presenar1(cadena);
    presentar2(cadena);

    cadena[2]='X';
    cadena[0]='X';
    cout<<"\n";
    presenar1(cadena);

}
