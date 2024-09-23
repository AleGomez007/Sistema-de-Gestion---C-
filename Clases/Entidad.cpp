#include "Entidad.h"
#include<cstring>

void Entidad::setClave(char* _Clave){
    strcpy(Clave, _Clave);
}

void Entidad::setUsuario(char* _Usuario){
    strcpy(Usuario, _Usuario);
}

void Entidad::setDescripcion(char* _Descripcion){
    strcpy(Descripcion, _Descripcion);
}

void Entidad::setPropiedadAdmin(bool _PropiedadAdmin){
    PropiedadAdmin = _PropiedadAdmin;
}

void Entidad::setId(int _Id){
    Id = _Id;
}

void Entidad::setEstado(bool _Estado){
    Estado = _Estado;
}

char* Entidad::getUsuario(){
    return Usuario;
}

char* Entidad::getClave(){
    return Clave;
}

char* Entidad::getDescripcion(){
    return Descripcion;
}

int Entidad::getId(){
    return Id;
}

bool Entidad::getPropiedadAdmin(){
    return PropiedadAdmin;
}

bool Entidad::getEstado(){
    return Estado;
}
