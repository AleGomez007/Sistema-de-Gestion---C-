#include<cstdio>
#include<cstring>
#include <iostream>
#include <string>
#include "Avion.h"
#include "Producto.h"
using namespace std;



///         SETER'S
void Avion::setTipo(const char* _Tipo){
    strcpy(Tipo, _Tipo);
}
void Avion::setProposito(const char* _Proposito){
    strcpy(Proposito, _Proposito);
}
void Avion::setTamanio(const char* _Tamanio){
    strcpy(Tamanio, _Tamanio);
}
void Avion::setVelocidadMax(int _VelocidadMax){
    VelocidadMax = _VelocidadMax;
}
void Avion::setManiobrabilidad(const char* _Maniobrabilidad){
    strcpy(Maniobrabilidad, _Maniobrabilidad);
}
void Avion::setCantMisiles(int _CantMisiles){
    CantMisiles = _CantMisiles;
}
void Avion::setAmetralladora(bool _Ametralladora){
    Ametralladora = _Ametralladora;
}
void Avion::setAlcanceOperativo(int _AlcanceOperativo){
    AlcanceOperativo = _AlcanceOperativo;
}


///         GETER'S
char* Avion::getTipo(){
    return Tipo;
}
char* Avion::getProposito(){
    return Proposito;
}
char* Avion::getTamanio(){
    return Tamanio;
}
int Avion::getVelocidadMax(){
    return VelocidadMax;
}
char* Avion::getManiobrabilidad(){
    return Maniobrabilidad;
}
int Avion::getCantMisiles(){
    return CantMisiles;
}
bool Avion::getAmetralladora(){
    return Ametralladora;
}
int Avion::getAlcanceOperativo(){
    return AlcanceOperativo;
}


///         FUNCIONES
void Avion::cargar(){
    int opcion = 0;
    Producto::cargar();

    cout<<"Tipo: " << endl;
    //cin >> Tipo;
    cout << "1. CAZA" << endl;
    cout << "2. BOMBARDERO" << endl;
    cout << "3. CAZA-BOMBARDERO" << endl;
    cout << "Opcion: ";
    cin >> opcion;
    while(opcion < 0 || opcion > 3){
        cout << "Opcion incorrecta, re ingrese..." << endl;
        cout << "Opcion: ";
        cin >> opcion;
    }
    switch(opcion){
        case 1:
            strcpy(Tipo, "CAZA");
            break;
        case 2:
            strcpy(Tipo, "BOMBARDERO");
            break;
        case 3:
            strcpy(Tipo, "CAZA-BOMBARDERO");
            break;
    }

    cout<<"Proposito: " << endl;
    //cin>> Proposito;
    cout << "1. AIRE" << endl;
    cout << "2. TIERRA" << endl;
    cout << "3. AIRE-TIERRA" << endl;
    cout << "Opcion: ";
    cin >> opcion;
    while(opcion < 0 || opcion > 3){
        cout << "Opcion incorrecta, re ingrese..." << endl;
        cout << "Opcion: ";
        cin >> opcion;
    }
    switch(opcion){
        case 1:
            strcpy(Proposito, "AIRE");
            break;
        case 2:
            strcpy(Proposito, "TIERRA");
            break;
        case 3:
            strcpy(Proposito, "AIRE-TIERRA");
            break;
    }

    cout<<"Tamanio: " << endl;
    //cin>> Tamanio;
    cout << "1. CHICO" << endl;
    cout << "2. MEDIANO" << endl;
    cout << "3. GRANDE" << endl;
    cout << "Opcion: ";
    cin >> opcion;
    while(opcion < 0 || opcion > 3){
        cout << "Opcion incorrecta, re ingrese..." << endl;
        cout << "Opcion: ";
        cin >> opcion;
    }
    switch(opcion){
        case 1:
            strcpy(Tamanio, "CHICO");
            break;
        case 2:
            strcpy(Tamanio, "MEDIANO");
            break;
        case 3:
            strcpy(Tamanio, "GRANDE");
            break;
    }

    cout<<"Velocidad Maxima km/h (800 - 2000): ";
    cin>> VelocidadMax;
    while(VelocidadMax < 800 || VelocidadMax > 2000){
        cout << "Opcion incorrecta, re ingrese..." << endl;
        cout<<"Velocidad Maxima km/h (800 - 2000): ";
        cin>> VelocidadMax;
    }

    cout<<"Maniobrabilidad: " << endl;
    //cin>> Maniobrabilidad;
    cout << "1. ALTA" << endl;
    cout << "2. BAJA" << endl;
    cout << "Opcion: ";
    cin >> opcion;
    while(opcion < 0 || opcion > 2){
        cout << "Opcion incorrecta, re ingrese..." << endl;
        cout << "Opcion: ";
        cin >> opcion;
    }
    switch(opcion){
        case 1:
            strcpy(Maniobrabilidad, "ALTA");
            break;
        case 2:
            strcpy(Maniobrabilidad, "BAJA");
            break;
    }

    cout<<"Cantidad de Misiles (1 - 30): ";
    cin>> CantMisiles;
    while(CantMisiles < 1 || CantMisiles > 30){
        cout << "Opcion incorrecta, re ingrese..." << endl;
        cout<<"Cantidad de Misiles (1 - 30): ";
        cin>> CantMisiles;
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

    cout<<"Alcance Operativo kms (100 - 2000): ";
    cin>> AlcanceOperativo;
    while(AlcanceOperativo < 100 || AlcanceOperativo > 2000){
        cout << "Opcion incorrecta, re ingrese..." << endl;
        cout<<"Alcance Operativo kms (100 - 2000): ";
        cin>> AlcanceOperativo;
    }
}

void Avion::mostrar(){
    Producto::mostrar();
    cout << "Velocidad Maxima: " << VelocidadMax << endl;
    cout << "Cantidad de Misiles: " << CantMisiles << endl;
    cout << "Alcance Operativo: " << AlcanceOperativo << endl;
    cout << "Ametralladora: " << (Ametralladora ? "Si" : "No") << endl;
    cout << "Tipo: " << Tipo << endl;
    cout << "Proposito: " << Proposito << endl;
    cout << "Tamanio: " << Tamanio << endl;
    cout << "Maniobrabilidad: " << Maniobrabilidad << endl;
}

