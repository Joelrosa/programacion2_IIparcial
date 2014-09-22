#include <iostream>

using namespace std;
/*
Elaborar un programa donde ingresemos datos en un arreglo bidimensional
de 4 lineas y 5 columnas y dejemos la ultima linea reservada para
sumar los números pares.
si no hay pares deberá de aparecer 0.
*/

int const lin=3;
int const col=5;

int sumal,sumacol;
int bidi[lin][col];

void ingreso(int bidi[][col],int lin,int col)
{
    int l,c;
    for(l=0;l<lin;l++)
    {
        for(c=0;c<col;c++)
        {
            cout<<"ingresar numero[ "<<l<<","<<c<<" ]...";
            cin>>bidi[l][c];
        }
    }
}


void presentar(int bidi[][col],int lin,int col)
{
    int l,c;
    for(l=0;l<lin;l++)
    {
        for(c=0;c<col;c++)
        {
            cout<<bidi[l][c]<<" ";;
        }
        cout<<"\n";
    }
}
int sumardepares(int bidi[][col],int lin,int sumacol)
{
    int l,xsuma=0;
       for(l=0;l<lin;l++)
       {


      if ( (bidi[ l ][sumacol] % 2) == 0)

          {xsuma+=bidi[l][sumacol];}


       }
       return sumal;
}

 int presentar_suma(int bidi[][col],int col,int lin)
 {
     int l;
     for(l=0;l<col;l++)

        {
            cout<<bidi[l][sumal]<<" ";
        }
        cout<<"\n";

 }

int main()
{
    ingreso(bidi,lin,col);
    presentar(bidi,lin,col);
    sumardepares(bidi,col,sumacol-1);
    presentar_suma(bidi,col,lin);


}
