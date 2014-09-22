#include <stdio.h>
#include <stdlib.h>
int main (void)
{

int jugador = 0;
	int ganador = 0;
	int opcion = 0;
	int fila = 0;
	int columna = 0;
	int linea = 0;

	int array [3][3] = {
				 {'1','2','3'},
				 {'4','5','6'},
				 {'7','8','9'}
						};


	for (int i = 0; i<9 && ganador==0; i++)
	{
		printf("\n\n");
		printf(" %c | %c | %c\n", array[0][0], array[0][1], array[0][2]);
		printf("---|---|----\n");
		printf(" %c | %c | %c\n", array[1][0], array[1][1], array[1][2]);
		printf("---|---|----\n");
		printf(" %c | %c | %c\n", array[2][0], array[2][1], array[2][2]);

		jugador = i%2 + 1;

		do
		{
			printf("\nJugador %d, Elige un numero de uno de cuadro del X O %c: ",
				jugador,(jugador==1)?'X':'O');
			scanf("%d", &opcion);


			fila = --opcion/3;
			columna = opcion%3;
		}
while(opcion<0 || opcion>9 || array [fila][columna]>'9');

		array[fila][columna] = (jugador == 1) ? 'X' : 'O';


		if((array[0][0]==array[1][1] && array[0][0]==array[2][2]) ||
		   (array[0][2]==array[1][1] && array[0][2]==array[2][0]))
		   ganador = jugador;
		else
			for(linea = 0; linea <=2; linea++)
				if((array[linea][0]==array[linea][1] && array[linea][0]==array[linea][2])||
					(array[0][linea]==array[1][linea] && array[0][linea]==array[2][linea]))
					ganador = jugador;


	}

		printf("\n\n");
		printf(" %c | %c | %c\n", array[0][0], array[0][1], array[0][2]);
		printf("---|---|----\n");
		printf(" %c | %c | %c\n", array[1][0], array[1][1], array[1][2]);
		printf("---|---|----\n");
		printf(" %c | %c | %c\n", array[2][0], array[2][1], array[2][2]);


		if(ganador==0)
			printf("empate\n");
		else
			printf("jugador %d ha ganado\n", ganador);

	return 0;
}
