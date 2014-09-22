#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;
/*
se tiene que buscar una cadena dentro de otra cadena y luego sustituir la cadena por X
donde la encuentre
*/

int main()
{
    string cadena1,cadena2,com1;

    cout<<"escrivir una cadena de texto....: ";
    getline(cin,cadena1,'\n');


    cout<<cadena1<<"\n";
    cout<<"cadena a buscar dentro de la cadena de texto...: ";
    cin>>cadena2;

    int largo= cadena1.size();
    int largo2= cadena2.size();
    int i=0;
    int bandera=0;

    for(i=0;i<largo;i++)
    {
        com1=cadena1.substr(i,largo2);
        if(com1==cadena2)
        {
            bandera=1;
            break;
        }
        i++;
    }
    if(bandera==1)
    {
       cout<<"encontrada la cadena "<<com1<<"\n";
    }
    else
    {
        cout<<"No existe cadena  "<<com1;
    }


    return 0;
}

