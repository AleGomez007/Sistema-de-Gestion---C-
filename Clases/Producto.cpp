#include<cstdio>
#include<cstring>
#include <iostream>
#include "Producto.h"
using namespace std;

void Producto::setPrecio(long long _Precio){
    Precio = _Precio;
}

void Producto::setEstado(bool _Estado){
    Estado = _Estado;
}

void Producto::setNombre(const char *_Nombre){
    strcpy(Nombre, _Nombre);
}

void Producto::setDescripcion(const char *_Descripcion){
    strcpy(Descripcion, _Descripcion);
}

void Producto::setId(int _Id){
    Id = _Id;
}

void Producto::setPaisOrigen(const char* _PaisOrigen){
    strcpy(PaisOrigen, _PaisOrigen);
}

void Producto::setStock(int _Stock){
    Stock = _Stock;
}

void Producto::setFecha(Fecha _Fecha){
    FechaAlta = _Fecha;
}

long long Producto::getPrecio(){
    return Precio;
}

bool Producto::getEstado(){
    return Estado;
}

char* Producto::getNombre(){
    return Nombre;
}

char* Producto::getDescripcion(){
    return Descripcion;
}

int Producto::getId(){
    return Id;
}

char* Producto::getPaisOrigen(){
    return PaisOrigen;
}

int Producto::getStock(){
    return Stock;
}

Fecha Producto::getFechaAlta(){
    return FechaAlta;
}

void Producto::cargar(){
    system("cls");
    cout<<"Codigo: ";
    cin>>Id;
    cin.ignore();
    cout<<"Nombre: ";
    cin.getline(Nombre, sizeof(Nombre));
    cout<<"Precio: u$d ";
    cin>>Precio;
    cout<<"Stock: ";
    cin>>Stock;
    cin.ignore();
    cout<<"Pais de Origen: ";
    cin.getline(PaisOrigen, sizeof(PaisOrigen));
    cout<<"Descripcion: ";
    cin.getline(Descripcion, sizeof(Descripcion));
    Estado = true;
    system("cls");
}

void Producto::mostrar(){
    cout<<"Codigo: " << Id << endl;
    cout<<"Nombre: " << Nombre << endl;
    cout<<"Precio: u$d " << Precio << endl;
    cout<<"Estado: " << (Estado ? "ACTIVO" : "DESACTIVADO") << endl;
    cout<<"Stock: " << Stock << endl;
    cout<<"Pais de Origen: " << PaisOrigen << endl;
    cout<<"Descripcion: " << Descripcion << endl;
}





