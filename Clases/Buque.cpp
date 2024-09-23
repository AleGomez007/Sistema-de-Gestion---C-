#include<cstdio>
#include<cstring>
#include <iostream>
#include <string>
#include "Buque.h"
#include "Producto.h"
using namespace std;


///         SETER'S
void Buque::setTipo(const char* _Tipo){
    strcpy(Tipo, _Tipo);
}
void Buque::setCantTorretas(int _CantTorretas){
    CantTorretas = _CantTorretas;
}
void Buque::setVelocidadMax(int _VelocidadMax){
    VelocidadMax = _VelocidadMax;
}
void Buque::setPeso(int _Peso){
    Peso = _Peso;
}
void Buque::setBlindaje(const char* _Blindaje){
    strcpy(Blindaje, _Blindaje);
}
void Buque::setTipoPropulsion(const char* _TipoPropulsion){
    strcpy(TipoPropulsion, _TipoPropulsion);
}
void Buque::setManiobrabilidad(const char* _Maniobrabilidad){
    strcpy(Maniobrabilidad, _Maniobrabilidad);
}
void Buque::setAmetralladora(bool _Ametralladora){
    Ametralladora = _Ametralladora;
}

///         GETER'S
char*Buque::getTipo(){
    return Tipo;
}
int Buque::getCantTorretas(){
    return CantTorretas;
}
int Buque::getVelocidadMax(){
    return VelocidadMax;
}
int Buque::getPeso(){
    return Peso;
}
char*Buque::getBlindaje(){
    return Blindaje;
}
char*Buque::getTipoPropulsion(){
    return TipoPropulsion;
}
char*Buque::getManiobrabilidad(){
    return Maniobrabilidad;
}
bool Buque::getAmetralladora(){
    return Ametralladora;
}

///         FUNCIONES
void Buque::cargar(){
    int opcion = 0;
    Producto::cargar();

    cout<<"Tipo: " << endl;
    //cin>> Tipo;
    cout << "1. MONITOR" << endl;
    cout << "2. CRUZERO - LANZAMISILES" << endl;
    cout << "3. CRUZERO - PORTAAVIONES" << endl;
    cout << "4. CRUZERO - ACORAZADO" << endl;
    cout << "5. CRUZERO - LIGERO" << endl;
    cout << "6. DESTRUCTOR" << endl;
    cout << "7. CAZA TORPEDOS" << endl;
    cout << "Opcion: ";
    cin >> opcion;
    while(opcion < 0 || opcion > 7){
        cout << "Opcion incorrecta, re ingrese..." << endl;
        cout << "Opcion: ";
        cin >> opcion;
    }
    switch(opcion){
        case 1:
            strcpy(Tipo, "MONITOR");
            break;
        case 2:
            strcpy(Tipo, "CRUZERO - LANZAMISILES");
            break;
        case 3:
            strcpy(Tipo, "CRUZERO - PORTAAVIONES");
            break;
        case 4:
            strcpy(Tipo, "CRUZERO - ACORAZADO");
            break;
        case 5:
            strcpy(Tipo, "CRUZERO - LIGERO");
            break;
        case 6:
            strcpy(Tipo, "DESTRUCTOR");
            break;
        case 7:
            strcpy(Tipo, "CAZA TORPEDOS");
            break;
    }

    cout<<"Cantidad de Torretas (1 - 40): ";
    cin>> CantTorretas;
    while(CantTorretas < 1 || CantTorretas > 40){
        cout << "Opcion incorrecta, re ingrese..." << endl;
        cout<<"Cantidad de Torretas (1 - 40): ";
        cin>> CantTorretas;
    }


    cout<<"Velocidad Maxima km/h (70 - 150): ";
    cin>> VelocidadMax;
    while(VelocidadMax < 70 || VelocidadMax > 150){
        cout << "Opcion incorrecta, re ingrese..." << endl;
        cout<<"Velocidad Maxima km/h (70 - 150): ";
        cin>> VelocidadMax;
    }

    cout<<"Peso Tn (50000 - 80000): ";
    cin>> Peso;
    while(Peso < 50000 || Peso > 80000){
         cout << "Opcion incorrecta, re ingrese..." << endl;
        cout<<"Peso Tn (50000 - 80000): ";
        cin>> Peso;
    }

    cout<<"Blindaje: " << endl;
    //cin>> Blindaje;
    cout << "1. ALTO" << endl;
    cout << "2. MEDIO" << endl;
    cout << "3. BAJO" << endl;
    cout << "Opcion: ";
    cin >> opcion;
    while(opcion < 0 || opcion > 3){
        cout << "Opcion incorrecta, re ingrese..." << endl;
        cout << "Opcion: ";
        cin >> opcion;
    }
    switch(opcion){
        case 1:
            strcpy(Blindaje, "ALTO");
            break;
        case 2:
            strcpy(Blindaje, "MEDIO");
            break;
        case 3:
            strcpy(Blindaje, "BAJO");
            break;
    }

    system("cls");

    cout<<"Tipo de Propulsion: " << endl;
    //cin>> TipoPropulsion;
    cout << "1. CALDERAS" << endl;
    cout << "2. TURBINAS" << endl;
    cout << "Opcion: ";
    cin >> opcion;
    while(opcion < 0 || opcion > 2){
        cout << "Opcion incorrecta, re ingrese..." << endl;
        cout << "Opcion: ";
        cin >> opcion;
    }
    switch(opcion){
        case 1:
            strcpy(TipoPropulsion, "CALDERAS");
            break;
        case 2:
            strcpy(TipoPropulsion, "TURBINAS");
            break;
    }

    cout<<"Maniobrabilidad: " << endl;
    //cin>> Maniobrabilidad;
    cout << "1. ALTA" << endl;
    cout << "2. MEDIA" << endl;
    cout << "3. BAJA" << endl;
    cout << "Opcion: ";
    cin >> opcion;
    while(opcion < 0 || opcion > 3){
        cout << "Opcion incorrecta, re ingrese..." << endl;
        cout << "Opcion: ";
        cin >> opcion;
    }
    switch(opcion){
        case 1:
            strcpy(Maniobrabilidad, "ALTA");
            break;
        case 2:
            strcpy(Maniobrabilidad, "MEDIA");
            break;
        case 3:
            strcpy(Maniobrabilidad, "BAJA");
            break;
    }

    cout<<"Ametralladora: " << endl;
    //cin>> Ametralladora;
    cout << "1. SI" << endl;
    cout << "2. NO" << endl;
    cout << "Opcion: ";
    cin >> opcion;
    while(opcion < 1 || opcion > 2){
        cout << "Opcion incorrecta, re ingrese..." << endl;
        cout << "Opcion: ";
        cin >> opcion;
    }
    switch(opcion){
        case 1:
            Ametralladora = true;
            break;
        case 2:
            Ametralladora = false;
            break;
    }
}

void Buque::mostrar(){
    Producto::mostrar();
    cout << "Cantidad de Torretas: " << CantTorretas << endl;
    cout << "Velocidad Maxima: " << VelocidadMax << endl;
    cout << "Peso: " << Peso << endl;
    cout << "Tipo: " << Tipo << endl;
    cout << "Blindaje: " << Blindaje << endl;
    cout << "Tipo de Propulsion: " << TipoPropulsion << endl;
    cout << "Maniobrabilidad: " << Maniobrabilidad << endl;
    cout << "Ametralladora: " << (Ametralladora ? "SI" : "NO") << endl;
}
