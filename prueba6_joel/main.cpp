#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

/*
Se tiene que buscar una cadena dentro de otra cadena y
luego sustituir la cadena por X donde la encuentre.

*/

int main()
{ string cadena1,cadena2,com1;


    cout<<"Escribir una cadena de texto...: ";
    getline(cin,cadena1,'\n');

    cout<<endl;

    cout<<cadena1<<"\n";

    cout<<endl;

    cout<<"Cadena a buscar dentro de a cadena de texto...: ";
    cin>>cadena2;

    cout<<endl;

    int largo= cadena1.size();
    int largo2= cadena2.size();
    int i=0;
    int bandera=0;

    for (i=0;i<largo;i++)
    { com1 =cadena1.substr(i,largo2);
       if (com1==cadena2)
        {
           bandera=1;
           break;
        }
    }

    if (bandera==1)
    {
        cout<<"Encontrada la cadena ..: "<<com1<<"\n";
    }
    else
    {
        cout<<"No Existe la Cadena (O_O) "<<"\n";
    }

   for (i=0;i<largo;i++)
    {
        com1 =cadena1.substr(i,largo2);

       if (com1==cadena2)
        {
            int k;
           for(k=0;k<largo2;k++)
             {
                cadena1[i]='X';
                i++;
             }

        }

    }

   cout<<endl;

   cout<<"sustitucion de cadena...: "<<cadena1<<"\n";

    return 0;
}
