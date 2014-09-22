#include <iostream>

using namespace std;

int const lin=4;
int const col=4;
int  linsuma,sumal;
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
            cout<<bidi[l][c]<<" ";
        }
        cout<<"\n";
    }
}
int sumarfila(int bidi[][col],int col,int linsuma)
{
    int c,xsuma=0;
       for(c=0;c<col;c++)
       {
           xsuma+=bidi[linsuma][c];
       }
       return xsuma;
}
int main()
{
    ingreso(bidi,lin,col);
    presentar(bidi,lin,col);
    cout<<"ingresar la linia a sumar : ";
    cin>>linsuma;
    sumal=sumarfila(bidi,col,linsuma-1);
    cout<<"suma es ... : "<<sumal<<"\n";

}
