#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;
/*
elaborar un programa donde ingrese una cadena de texto y luego
usando un porcesimiento se sustituyan vocales  por x
*/
char cadena[30];

void cambiarvocales(char cadena[])
{
    int i,k;
    for(i=0;i<strlen(cadena);i++)
    {
        switch(cadena[i])
        {
            case 'a':
            case 'A':
            case 'e':
            case 'E':
            case 'i':
            case 'I':
            case 'o':
            case 'O':
            case 'u':
            case 'U':
            cadena[i]='X';
            break;
            default:
                break;
        }
    }
}

 int main()
{
    cout<<"ingresar cadena de exto....: ";
    cin.getline(cadena,30);
    cambiarvocales(cadena);
    cout<<"\n"<<cadena<<"\n";

}
