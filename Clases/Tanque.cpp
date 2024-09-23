#include<cstdio>
#include<cstring>
#include <iostream>
#include <string>
#include "Tanque.h"
#include "Producto.h"
using namespace std;


///     SETER´S
void Tanque::setTipoBlindaje(const char *_tipoBlindaje){
    strcpy(TipoBlindaje,_tipoBlindaje);
}

void Tanque::setMovilidad(const char *_movilidad){
    strcpy(Movilidad,_movilidad);
}

void Tanque::setOcultamiento(bool _ocultamiento){
    Ocultamiento = _ocultamiento;
}

void Tanque::setRangoVision(const char* _rangoVision){
    strcpy(RangoVision,_rangoVision);
}

void Tanque::setLargoAlcance(bool _largoAlcance){
    LargoAlcance = _largoAlcance;
}

void Tanque::setPrecision(const char* _precision){
    strcpy(Precision,_precision);
}

void Tanque::setAntiTanque(bool _antiTanque){
    AntiTanque = _antiTanque;
}
void Tanque::setVelocidad(int _velocidad){
    Velocidad = _velocidad;
}

void Tanque::setTorretaBlindada(bool _torretaBlindada){
    TorretaBlindada = _torretaBlindada;
}

void Tanque::setTorretaCalibre(int _torretaCalibre){
    TorretaCalibre = _torretaCalibre;
}

void Tanque::setPeso(int _peso){
    Peso = _peso;
}

void Tanque::setAlcanceOperativo(int _alcanceOperativo){
    AlcanceOperativo = _alcanceOperativo;
}

void Tanque::setAmetralladora(bool _ametralladora){
    Ametralladora = _ametralladora;
}

///     GETER'S
char* Tanque::getTipoBlindaje(){
    return TipoBlindaje;
}

char* Tanque::getMovilidad(){
    return Movilidad;
}

bool Tanque::getOcultamiento(){
    return Ocultamiento;
}

char* Tanque::getRangoVision(){
    return RangoVision;
}

bool Tanque::getLargoAlcance(){
    return LargoAlcance;
}

char* Tanque::getPrecision(){
    return Precision;
}

bool Tanque::getAntiTanque(){
    return AntiTanque;
}

int Tanque::getVelocidad(){
    return Velocidad;
}

bool Tanque::getTorretaBlindada(){
    return TorretaBlindada;
}

int Tanque::getTorretaCalibre(){
    return TorretaCalibre;
}

int Tanque::getPeso(){
    return Peso;
}

int Tanque::getAlcanceOperativo(){
    return AlcanceOperativo;
}

bool Tanque::getAmetralladora(){
    return Ametralladora;
}


///     FUNCIONES.
void Tanque::cargar(){
    int opcion = 0;
    Producto::cargar();

    cout<<"Tipo de Blindaje: " << endl;
    //cin>>TipoBlindaje;
    cout << "1. BAJO" << endl;
    cout << "2. MEDIO" << endl;
    cout << "3. ALTO" << endl;
    cout << "Opcion: ";
    cin >> opcion;
    while(opcion < 0 || opcion > 3){
        cout << "Opcion incorrecta, re ingrese..." << endl;
        cout << "Opcion: ";
        cin >> opcion;
    }
    switch(opcion){
        case 1:
            strcpy(TipoBlindaje, "BAJO");
            break;
        case 2:
            strcpy(TipoBlindaje, "MEDIO");
            break;
        case 3:
            strcpy(TipoBlindaje, "ALTO");
            break;
    }

    cout<<"Movilidad: " << endl;
    //cin>>Movilidad;
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
            strcpy(Movilidad, "ALTA");
            break;
        case 2:
            strcpy(Movilidad, "BAJA");
            break;
    }

    cout<<"Ocultamiento: " << endl;
    //cin>>Ocultamiento;
    cout << "1. SI" << endl;
    cout << "2. NO" << endl;
    cout << "Opcion: ";
    cin >> opcion;
    while(opcion < 0 || opcion > 2){
        cout << "Opcion incorrecta, re ingrese..." << endl;
        cout << "Opcion: ";
        cin >> opcion;
    }
    switch(opcion){
        case 1:
            Ocultamiento = true;
            break;
        case 2:
            Ocultamiento = false;
            break;
    }

    cout<<"Rango de Vision: " << endl;
    //cin>>RangoVision;
    cout << "1. BAJO" << endl;
    cout << "2. MEDIO" << endl;
    cout << "3. ALTO" << endl;
    cout << "Opcion: ";
    cin >> opcion;
    while(opcion < 0 || opcion > 3){
        cout << "Opcion incorrecta, re ingrese..." << endl;
        cout << "Opcion: ";
        cin >> opcion;
    }
    switch(opcion){
        case 1:
            strcpy(RangoVision, "BAJO");
            break;
        case 2:
            strcpy(RangoVision, "MEDIO");
            break;
        case 3:
            strcpy(RangoVision, "ALTO");
            break;
    }

    system("cls");
    cout<<"Largo Alcance: " << endl;
    //cin>>LargoAlcance;
    cout << "1. SI" << endl;
    cout << "2. NO" << endl;
    cout << "Opcion: ";
    cin >> opcion;
    while(opcion < 0 || opcion > 2){
        cout << "Opcion incorrecta, re ingrese..." << endl;
        cout << "Opcion: ";
        cin >> opcion;
    }
    switch(opcion){
        case 1:
            LargoAlcance = true;
            break;
        case 2:
            LargoAlcance = false;
            break;
    }

    cout<<"Precision: " << endl;
    //cin>>Precision;
    cout << "1. BAJO" << endl;
    cout << "2. MEDIO" << endl;
    cout << "3. ALTO" << endl;
    cout << "Opcion: ";
    cin >> opcion;
    while(opcion < 0 || opcion > 3){
        cout << "Opcion incorrecta, re ingrese..." << endl;
        cout << "Opcion: ";
        cin >> opcion;
    }
    switch(opcion){
        case 1:
            strcpy(Precision, "BAJO");
            break;
        case 2:
            strcpy(Precision, "MEDIO");
            break;
        case 3:
            strcpy(Precision, "ALTO");
            break;
    }

    cout<<"AntiTanque: " << endl;
    //cin>>AntiTanque;
    cout << "1. SI" << endl;
    cout << "2. NO" << endl;
    cout << "Opcion: ";
    cin >> opcion;
    while(opcion < 0 || opcion > 2){
        cout << "Opcion incorrecta, re ingrese..." << endl;
        cout << "Opcion: ";
        cin >> opcion;
    }
    switch(opcion){
        case 1:
            AntiTanque = true;
            break;
        case 2:
            AntiTanque = false;
            break;
    }

    cout<<"Velocidad Max (80 - 140): ";
    cin>>Velocidad;
    while(Velocidad < 80 || Velocidad > 140){
        cout << "Opcion incorrecta, re ingrese..." << endl;
        cout<<"Velocidad Max (80 - 140): ";
        cin>>Velocidad;
    }

    cout<<"Torreta Blindada: " << endl;
    //cin>>TorretaBlindada;
    cout << "1. SI" << endl;
    cout << "2. NO" << endl;
    cout << "Opcion: ";
    cin >> opcion;
    while(opcion < 0 || opcion > 2){
        cout << "Opcion incorrecta, re ingrese..." << endl;
        cout << "Opcion: ";
        cin >> opcion;
    }
    switch(opcion){
        case 1:
            TorretaBlindada = true;
            break;
        case 2:
            TorretaBlindada = false;
            break;
    }

    cout<<"Calibre de Torrera (105 mm - 135 mm): ";
    cin>>TorretaCalibre;
    while(TorretaCalibre < 105 || TorretaCalibre > 135){
        cout << "Opcion incorrecta, re ingrese..." << endl;
        cout<<"Calibre de Torrera (105 mm - 135 mm): ";
        cin>>TorretaCalibre;
    }

    cout<<"Peso Tn (40 - 80): ";
    cin>>Peso;
    while(Peso < 40 || Peso > 80){
        cout << "Opcion incorrecta, re ingrese..." << endl;
        cout<<"Peso Tn (40 - 80): ";
        cin>>Peso;
    }


    cout<<"Alcance operativo kms (50 - 150): ";
    cin >>AlcanceOperativo;
    while(AlcanceOperativo < 50 || AlcanceOperativo > 150){
        cout << "Opcion incorrecta, re ingrese..." << endl;
        cout<<"Alcance operativo kms (50 - 150): ";
        cin >>AlcanceOperativo;
    }

    cout<<"Ametralladora: " << endl;
    //cin>>Ametralladora;
    cout << "1. SI" << endl;
    cout << "2. NO" << endl;
    cout << "Opcion: ";
    cin >> opcion;
    while(opcion < 0 || opcion > 2){
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

void Tanque::mostrar(){
    Producto::mostrar();
    cout << "Tipo de Blindaje: " << TipoBlindaje << endl;
    cout << "Movilidad: " << Movilidad << endl;
    cout << "Ocultamiento: " << (Ocultamiento ? "Si" : "No") << endl;
    cout << "Rango de Vision: " << RangoVision << endl;
    cout << "Largo Alcance: " << (LargoAlcance ? "Si" : "No") << endl;
    cout << "Precision: " << Precision << endl;
    cout << "AntiTanque: " << (AntiTanque ? "Si" : "No") << endl;
    cout << "Velocidad: " << Velocidad << endl;
    cout << "Torreta Blindada: " << (TorretaBlindada ? "Si" : "No") << endl;
    cout << "Calibre de Torrera: " << TorretaCalibre << endl;
    cout << "Peso: " << Peso << endl;
    cout << "Alcance operativo: " << AlcanceOperativo << endl;
    cout << "Ametralladora: " << Ametralladora << endl;
}
