#include <iostream>

using namespace std;

struct nodo
{
    int numero;
    struct nodo *siguiente;
};

struct nodo *primero,*ultimo;
struct nodo*nuevo;

int main()
{
    primero = new nodo;
    ultimo = new nodo;
    primero =NULL;
    int xnum;
    char resp;

    do
    {
        nuevo = new nodo;
        cout<<" Ingresar un numero ";
        cin>>xnum;
        nuevo->numero=xnum;
        nuevo->siguiente=NULL;

        if (primero ==NULL)
        {
            primero =nuevo;
            ultimo = nuevo;
            cout<<"inicio";
            cout<<endl;
        }
        else
        {
            ultimo->siguiente=nuevo;
            ultimo = nuevo;
        }
        do
        {
            cout<<"Desea Continual...: ";
            cin>>resp;

        }while((resp!='S') and (resp!='N'));

    }while(resp!='N');

    ultimo->siguiente=NULL;
    struct nodo *aux;

    aux= primero;

    cout<<"\nMostrando la lista completa:\n";
    while(aux!=NULL)
    {
        cout<<" Numero "<<aux->numero<<"\n";
        aux = aux->siguiente;
    }

    return 0;

}

