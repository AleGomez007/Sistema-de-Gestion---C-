#include <iostream>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdlib.h>
//#include "rlutil.h"
#include "Stock.h"

using namespace std;
//using namespace rlutil;


void Stock::dibujarCuadro(int x1, int y1, int x2, int y2){
    int i;

    for(i=x1; i<x2; i++){
        gotoxy(i, y1);
        printf("\304"); // LINEA HORIZONTAL SUPERIOR
        gotoxy(i, y2);
        printf("\304"); // LINEA HORIZONTAL INFERIOR
    }

    for(i=y1; i<y2; i++){
        gotoxy(x1, i);
        printf("\263"); // LINEA VERTICAL IZQUIERDA
        gotoxy(x2, i);
        printf("\263"); // LINEA VERTICAL DERECHA
    }

    gotoxy(x1, y1);
    printf("\332");
    gotoxy(x1, y2);
    printf("\300");
    gotoxy(x2, y1);
    printf("\277");
    gotoxy(x2, y2);
    printf("\331");
}


void Stock::gotoxy(int x, int y){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

void Stock::Cargar(){
    cout << "INGRESE LA CANTIDAD:";
    cin>> cantidad;
    if(cantidad<1){
        cout << "TIPIADA MAL, INGRESE NUEVAMENTE.";
        return;
    }
    cout << "INGRESE EL ARMAMENTO A ELEGIR:";

    ///ACA SI DA A ELEGIR EL USUARIO SE TENDRIA QUE LISTAR LAS OTRAS COSAS CLASES, ME CLAVE ACA LPM

}
