#include <iostream>
#include <cstring>
#include "Misil.h"
#include <conio.h>
using namespace std;

void Misil::setTipoPropulsion(const char* _TipoPropulsion) {
    strncpy(TipoPropulsion, _TipoPropulsion, sizeof(TipoPropulsion) - 1);
    TipoPropulsion[sizeof(TipoPropulsion) - 1] = '\0';
}

void Misil::setTipoGuia(const char* _TipoGuia) {
    strncpy(TipoGuia, _TipoGuia, sizeof(TipoGuia) - 1);
    TipoGuia[sizeof(TipoGuia) - 1] = '\0';
}

void Misil::setCantCabezasExplosivas(int _CantCabezasExplosivas) {
    CantCabezasExplosivas = _CantCabezasExplosivas;
}

void Misil::setVelocidadMax(int _VelocidadMax) {
    VelocidadMax = _VelocidadMax;
}

void Misil::setPeso(int _Peso) {
    Peso = _Peso;
}

void Misil::setTipoCombustible(const char* _TipoCombustible) {
    strncpy(TipoCombustible, _TipoCombustible, sizeof(TipoCombustible) - 1);
    TipoCombustible[sizeof(TipoCombustible) - 1] = '\0';
}

void Misil::setTipoCarga(const char* _TipoCarga) {
    strncpy(TipoCarga, _TipoCarga, sizeof(TipoCarga) - 1);
    TipoCarga[sizeof(TipoCarga) - 1] = '\0';
}

void Misil::setHipersonico(bool _Hipersonico) {
    Hipersonico = _Hipersonico;
}

void Misil::setTipo(const char* _Tipo) {
    strncpy(Tipo, _Tipo, sizeof(Tipo) - 1);
    Tipo[sizeof(Tipo) - 1] = '\0';
}

char* Misil::getTipoPropulsion() {
    return TipoPropulsion;
}

char* Misil::getTipoGuia() {
    return TipoGuia;
}

int Misil::getCantCabezasExplosivas() {
    return CantCabezasExplosivas;
}

int Misil::getVelocidadMax() {
    return VelocidadMax;
}

int Misil::getPeso() {
    return Peso;
}

char* Misil::getTipoCombustible() {
    return TipoCombustible;
}

char* Misil::getTipoCarga() {
    return TipoCarga;
}

bool Misil::gethipersonico() {
    return Hipersonico;
}

void Misil::cargar() {
    int opcion = 0;

    Producto::cargar();

    cout << "Ingrese el tipo de propulsion: " << endl;
    cout << "1. Cohete" << endl;
    cout << "2. Reaccion" << endl;
    cout << "OPCION: ";
    cin >> opcion;

    while(opcion != 1 && opcion != 2){
        cout << "Opcion incorrecta, seleccione nuevamente..." << endl;
        cout << "OPCION: ";
        cin >> opcion;
    }

    switch(opcion){
        case 1:
            strcpy(TipoPropulsion, "COHETE");
            break;
        case 2:
            strcpy(TipoPropulsion, "REACCION");
            break;
    }

    //cin.ignore();
    //cin.getline(TipoPropulsion, sizeof(TipoPropulsion));

    cout << "Ingrese el tipo de guia: " << endl;
    cout << "1. Total" << endl;
    cout << "2. Parcial" << endl;
    cout << "OPCION: ";
    cin >> opcion;

    while(opcion != 1 && opcion != 2){
        cout << "Opcion incorrecta, seleccione nuevamente..." << endl;
        cout << "OPCION: ";
        cin >> opcion;
    }

    switch(opcion){
        case 1:
            strcpy(TipoGuia, "TOTAL");
            break;
        case 2:
            strcpy(TipoGuia, "PARCIAL");
            break;
    }

    //cin.getline(TipoGuia, sizeof(TipoGuia));

    cout << "Ingrese la cantidad de cabezas explosivas (Max. 10): ";
    cin >> CantCabezasExplosivas;

    while(CantCabezasExplosivas > 10 || CantCabezasExplosivas < 0){
        cout << "Cantidad ingresada incorrecta, re ingrese..." << endl;
        cout << "Ingrese la cantidad de cabezas explosivas (Max. 10): ";
        cin >> CantCabezasExplosivas;
    }

    cout << "Ingrese la velocidad maxima km/h (101 - 99999): ";
    cin >> VelocidadMax;

    while(VelocidadMax < 100 || VelocidadMax > 10000){
        cout << "Velocidad ingresada incorrecta, re ingrese..." << endl;
        cout << "Ingrese la velocidad maxima km/h (101 - 99999): ";
        cin >> VelocidadMax;
    }

    cout << "Ingrese el peso Tn (1 - 4): ";
    cin >> Peso;

    while(Peso < 0 || Peso > 5){
        cout << "Peso ingresado incorrecto, re ingrese..." << endl;
        cout << "Ingrese el peso Tn (1 - 4): ";
        cin >> Peso;
    }

    cin.ignore();
    system("cls");

    cout << "Ingrese el tipo de combustible: " << endl;
    cout << "1. Solido" << endl;
    cout << "2. Liquido" << endl;
    cout << "OPCION: ";
    cin >> opcion;

    while(opcion != 1 && opcion != 2){
        cout << "Opcion incorrecta, seleccione nuevamente..." << endl;
        cout << "OPCION: ";
        cin >> opcion;
    }

    switch(opcion){
        case 1:
            strcpy(TipoCombustible, "SOLIDO");
            break;
        case 2:
            strcpy(TipoCombustible, "LIQUIDO");
            break;
    }

    //cin.getline(TipoCombustible, sizeof(TipoCombustible));

    cout << "Ingrese el tipo de carga: " << endl;
    cout << "1. Explisiva" << endl;
    cout << "2. Nuclear" << endl;
    cout << "3. Quimica" << endl;
    cout << "4. Biologica" << endl;
    cout << "OPCION: ";
    cin >> opcion;

    while(opcion < 1 || opcion > 4){
        cout << "Opcion incorrecta, seleccione nuevamente..." << endl;
        cout << "OPCION: ";
        cin >> opcion;
    }

    switch(opcion){
        case 1:
            strcpy(TipoCarga, "EXPLOSIVA");
            break;
        case 2:
            strcpy(TipoCarga, "NUCLEAR");
            break;
        case 3:
            strcpy(TipoCarga, "QUIMICA");
            break;
        case 4:
            strcpy(TipoCarga, "BIOLOGIA");
            break;

    }
    //cin.getline(TipoCarga, sizeof(TipoCarga));

    cout << "Ingrese el tipo: " << endl;
    cout << "1. Aire-Aire" << endl;
    cout << "2. Aire-Tierra" << endl;
    cout << "3. Tierra-Aire" << endl;
    cout << "4. Tierra-Tierra" << endl;
    cout << "OPCION: ";
    cin >> opcion;

    while(opcion < 1 || opcion > 4){
        cout << "Opcion incorrecta, seleccione nuevamente..." << endl;
        cout << "OPCION: ";
        cin >> opcion;
    }

    switch(opcion){
        case 1:
            strcpy(Tipo, "AIRE-AIRE");
            break;
        case 2:
            strcpy(Tipo, "AIRE-TIERRA");
            break;
        case 3:
            strcpy(Tipo, "TIERRA-AIRE");
            break;
        case 4:
            strcpy(Tipo, "TIERRA-TIERRA");
            break;

    }
    //cin.getline(Tipo, sizeof(Tipo));

    cout << "Es hipersonico: " << endl;
    cout << "1. SI" << endl;
    cout << "2. NO" << endl;
    cout << "OPCION: ";
    cin >> opcion;

    while(opcion != 1 && opcion != 2){
        cout << "Opcion incorrecta, seleccione nuevamente..." << endl;
        cout << "OPCION: ";
        cin >> opcion;
    }

    switch(opcion){
        case 1:
            Hipersonico = true;
            break;
        case 2:
            Hipersonico = false;
            break;
    }

    //cin >> Hipersonico;

    Estado = true;
    }

void Misil::mostrar() {
    Producto::mostrar();
    cout << "Codigo Unico: " << CodigoUnico << endl;
    cout << "Tipo de propulsion: " << TipoPropulsion << endl;
    cout << "Tipo de guia: " << TipoGuia << endl;
    cout << "Cantidad de cabezas explosivas: " << CantCabezasExplosivas << endl;
    cout << "Velocidad maxima: " << VelocidadMax << endl;
    cout << "Peso: " << Peso << endl;
    cout << "Tipo de combustible: " << TipoCombustible << endl;
    cout << "Tipo de carga: " << TipoCarga << endl;
    cout << "Tipo: " << Tipo << endl;
    cout << "Hipersonico: " << (Hipersonico ? "Si" : "No") << endl;

}
