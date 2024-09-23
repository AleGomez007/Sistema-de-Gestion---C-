#include "Admin.h"
#include <iostream>
using namespace std;

void Admin::setNombreAdmin(const char* _NombreAdmin){
    strcpy(NombreAdmin, _NombreAdmin);
}

char* Admin::getNombreAdmin(){
    return NombreAdmin;
}

void Admin::cargar(int _Id){
    char aux[30];
    Entidad::setId(_Id);

    cout << "CARGANDO ID: " << Entidad::getId() << endl;

    cout << "ING NOMBRE USUARIO: ";
    cin >> aux;
    Entidad::setUsuario(aux);
    strcpy(NombreAdmin, aux);

    cout << "ING CLAVE: ";
    cin >> aux;
    Entidad::setClave(aux);

    cout << "ING DESCRPCION: ";
    cin >> aux;
    Entidad::setDescripcion(aux);

    Entidad::setPropiedadAdmin(true);
    Entidad::setEstado(true);
}

void Admin::mostrar(){
    cout << "NOMBRE USUARIO: " << NombreAdmin << endl;
    cout << "USUARIO: " << Entidad::getUsuario() << endl;
    cout << "CLAVE: " << Entidad::getClave() << endl;
    cout << "DESCRIPCION: " << Entidad::getDescripcion() << endl;
    cout << "PROPIEDAD ADMIN: " << Entidad::getPropiedadAdmin() << endl;
    cout << "ESTADO: " << Entidad::getEstado() << endl;
    cout << "ID: " << Entidad::getId() << endl;
}
