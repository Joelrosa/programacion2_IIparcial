#include <iostream>

using namespace std;

 class jugador{
    public:
    int seccion[2][2];
};

void dos(){
    jugador par[2];
    int jugador,turno,i,j;
    for(jugador=0;jugador<2;jugador++){
        for(i=0;i<3;i++){
            for(j=0;j<3;j++)
                par[jugador].seccion[i][j]=0;
    }
}
    cout<<""<<endl;
    for(turno=0;turno<4;turno++){
        for(jugador=0;jugador<2;jugador++){
            i=0;
            j=0;
            cout<<"Turno Jugador "<<jugador+1<<endl;
            lugar:
            cout<<"Ingrese la fila: ";
            cin>>i;
            cout<<"Ingrese la columna: ";
            cin>>j;
        if(par[0].seccion[i][j]!=0||par[1].seccion[i][j]!=0){
            cout<<"Ese lugar ya esta ocupado. Ingrese un nuevo lugar"<<endl;
            goto lugar;
        }
        else
            par[jugador].seccion[i][j]=jugador+1;
    }
}
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            cout<<" ";
            for(jugador=0;jugador<2;jugador++){
                if(par[jugador].seccion[i][j]!=0)
                cout<<par[jugador].seccion[i][j];
            }
            cout<<" |";
        }
        cout<<'\n';
    }
}
int main(){
    dos();

}
