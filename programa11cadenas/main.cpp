#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

 string cadena,insertado;

int main()
{
    cout<<"ingresar cadena... : ";
    cin>>cadena;
    insertado=cadena.insert(1," juan ");
    cout<<"valor de insertado.. : "<<insertado<<"\n";
    string ree;
    ree="BBBBB";
    ree=ree.replace(3,3," joel1 ");
    cout<<"valor ree "<<ree<<"\n";
    return 0;
}
