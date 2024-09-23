#include "Pais.h"
#include <string>
#include <cstring>
#include <iostream>
using namespace std;


void Pais::setNombrePais(const char* _NombrePais){
    strcpy(NombrePais, _NombrePais);
}

void Pais::setDineroCaja(long long _DineroCaja){
    DineroCaja = _DineroCaja;
}

void Pais::cargar(int _Id){
    char aux[30];

    Entidad::setId(_Id);
    cout << "CARGANDO ID: " << Entidad::getId() << endl;

    cout << "ING NOMBRE CLIENTE PAIS: ";
    cin >> aux;
    Entidad::setUsuario(aux);
    strcpy(NombrePais, aux);

    cout << "ING CLAVE: ";
    cin >> aux;
    Entidad::setClave(aux);

    cout << "ING DESCRIPCION: ";
    cin >> aux;
    Entidad::setDescripcion(aux);

    Entidad::setPropiedadAdmin(false);
    Entidad::setEstado(true);
    DineroCaja = 0;
}

void Pais::mostrar(){
    cout << "CLIENTE PAIS: " << NombrePais << endl;
    cout << "USUARIO: " << Entidad::getUsuario() << endl;
    cout << "CLAVE: " << Entidad::getClave() << endl;
    cout << "DESCRIPCION: " << Entidad::getDescripcion() << endl;
    cout << "ESTADO: " << Entidad::getEstado() << endl;
    cout << "ID: " << Entidad::getId() << endl;
}
