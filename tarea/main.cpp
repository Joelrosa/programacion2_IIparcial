#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void ponerMinas();
int esMina(int& x, int& y, int i=0, int j=0);
void minasRodean(int& x, int& y);
void finJuego();

int table[10][10];
const char g_szClassName[] = "myWindowClass";
const int LADO = 50; //lado del boton
const int NUM_CAS=10; //cantidad de casillas por fila y cantidad de filas
const int ID_CASILLA=100;
static HWND hwndButton[NUM_CAS*NUM_CAS];
HWND hwnd;

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    static HINSTANCE hInstance;
	static int cxClient, cyClient;
	HDC hdc;
	PAINTSTRUCT ps;
    int x=0, y=0, sub=0, i=0;

	switch(msg){
        case WM_CLOSE:
            DestroyWindow(hwnd);
        break;
       	case WM_CREATE:
			ponerMinas();
			for(i=0; i<NUM_CAS; i++) for(int j=0; j<NUM_CAS; j++){
				hwndButton[x++]=CreateWindow("button", TEXT(" ")/*(table[x/NUM_CAS][x%NUM_CAS]==0? TEXT("0"):TEXT("1"))*/,WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_PUSHBUTTON,
									LADO*j,LADO*i,LADO,LADO,hwnd,(HMENU)(ID_CASILLA + x),hInstance,NULL);
                     EnableWindow(hwndButton[x],TRUE);
             }

        break;
        case WM_DESTROY:
            PostQuitMessage(0);
        break;
        case WM_SIZE:
        	cxClient=LOWORD(lParam);
        	cyClient=HIWORD(lParam);
        	break;

		case WM_COMMAND:
			{
				int id = LOWORD(wParam)-ID_CASILLA;
				x=id/NUM_CAS;
				y=id%NUM_CAS;
				if(table[x][y]==1){
					MessageBox(hwnd,"Pisaste una mina!","P E R D I S T E",MB_OK | MB_ICONINFORMATION);
					PostQuitMessage(0);
				}
				else minasRodean(x,y);
				finJuego();
			}
			break;
        case WM_PAINT:
			hdc=BeginPaint(hwnd, &ps);
			EndPaint(hwnd, &ps);
        	break;

        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    WNDCLASSEX wc;
    MSG Msg;


    wc.cbSize        = sizeof(WNDCLASSEX);
    wc.style         = 0;
    wc.lpfnWndProc   = WndProc;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = hInstance;
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc.lpszMenuName  = NULL;
    wc.lpszClassName = g_szClassName;
    wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

    if(!RegisterClassEx(&wc))
    {
        MessageBox(NULL, "Window Registration Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }


    hwnd = CreateWindowEx(
        WS_EX_CLIENTEDGE,
        g_szClassName,
        "Buscaminas",
        WS_OVERLAPPEDWINDOW,
        //CW_USEDEFAULT, CW_USEDEFAULT, 240, 120,
		CW_USEDEFAULT, CW_USEDEFAULT, LADO*(NUM_CAS+1), LADO*(NUM_CAS+1),
        NULL, NULL, hInstance, NULL);

    if(hwnd == NULL)
    {
        MessageBox(NULL, "Window Creation Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    while(GetMessage(&Msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return Msg.wParam;
}

void ponerMinas(){
     int i;
     for(i=0; i<NUM_CAS; i++) for(int j=0; j<NUM_CAS; j++)
             table[i][j]=0;
     srand(time(NULL));
     int x=0,y=0;
     for(i=0; i<NUM_CAS; i++){
             do{
                x=rand()%NUM_CAS;
                y=rand()%NUM_CAS;
             }while(table[x][y]!=0);
             table[x][y]=1;
     }
}

int esMina(int& x, int& y, int i, int j){
    static int cont=0;

    if(i==0 && j==0) cont=0;
    if(i<3){
       if(j<3){
          if((i!=1 || j!=1)/*que no sea [x][y]*/ &&
             (x-1+i>=0 && x-1+i<NUM_CAS  && y-1+j>=0 && y-1+j<NUM_CAS)/*que no salga del tablero*/)
             cont += table[x-1+i][y-1+j]==1? 1:0;
          return esMina(x,y,i,++j);
       }
       else
          return esMina(x,y,++i,0);
    }
    else return cont;
}

void minasRodean(int& x, int& y){
    int sub;
    int minas=esMina(x,y,0,0);
    if(minas==0){
       for(int i=0; i<3; i++) for(int j=0; j<3; j++){
		   if(x-1+i>=0 && x-1+i<NUM_CAS  && y-1+j>=0 && y-1+j<NUM_CAS){//que no salga del tablero*
             sub= NUM_CAS*(x+i-1) + (y+j-1);
			 int a=x-1+i;
			 int b=y-1+j;
			 char chr[]={'0' + esMina(a,b,0,0),''};
			 SetWindowText(hwndButton[sub],chr);
             EnableWindow(hwndButton[sub],FALSE);
			 table[x+i-1][y+j-1]=2;
		  }
	   }
	}
	else{
		sub= NUM_CAS*x + y;
		table[x][y]=2;
		char chr[]={'0' + minas,''};
		SetWindowText(hwndButton[sub],chr);
		EnableWindow(hwndButton[sub],FALSE);
		const char aux[]={minas+'0',''};
	}
}

void finJuego(){
	int sinApretar=0;
	for(int i=0; i<NUM_CAS*NUM_CAS; i++){
		if(table[i/NUM_CAS][i%NUM_CAS]==0) sinApretar++;
	}
	if(sinApretar==0){
		MessageBox(hwnd, "GANASTE!!!","Fin del juego",MB_OK | MB_ICONINFORMATION);
		WndProc(hwnd, WM_CLOSE, NULL, NULL);
	}
 }
