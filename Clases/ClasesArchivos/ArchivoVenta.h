#ifndef ARCHIVOVENTA_H
#define ARCHIVOVENTA_H
#include<iostream>
#include<string.h>
#include "../Venta.h"
using namespace std;

class ArchivoVenta
{
     private:
            char Nombre[30];
    public:
            ArchivoVenta(const char* n = "ARCHIVOS/VENTAS.DAT"){
                strcpy(Nombre, n);
            }
            bool grabarRegistro(Venta reg);
            bool listarRegistros();
            int contarRegistros();
            int contarRegistros(const char *nombre);
            Venta leerRegistro(int pos);
            Venta buscarNombre(const char *nom);
};

bool ArchivoVenta::grabarRegistro(Venta reg) {
    FILE *pf;

    pf = fopen(Nombre, "ab");

    if (pf == NULL) {
        cout << "NO PUEDE ABRIRSE EL ARCHIVO: " << Nombre << " EN MODO AB - grabarRegistro()" << endl;
        system("pause");
        return false;
    }

    if (fwrite(&reg, sizeof(reg), 1, pf)) {
        fclose(pf);
        return true;
    }
    cout << "PROBLEMAS AL GRABAR EL REGISTRO" << endl;
    fclose(pf);
    return false;
}

bool ArchivoVenta::listarRegistros(){
    FILE *pf;
    Venta reg;

    pf = fopen(Nombre, "rb");

    if(pf == NULL){
        cout << "NO PUEDE ABRIRSE EL ARCHIVO: " << Nombre << " EN MODO RB - listarRegistros()" << endl;
        system("pause");
        return -1;
    }

    while(fread(&reg, sizeof(reg), 1, pf) == 1){
            reg.mostrar();
            system("pause");
    }

    fclose(pf);
    return 1;
}

int ArchivoVenta::contarRegistros(){
        FILE *p;
        p=fopen(Nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Venta);
}


int ArchivoVenta::contarRegistros(const char *nombre){
    Venta reg;
    int contadorRegistros = 0;

    FILE *p = fopen(Nombre, "rb");
    if (p == NULL) return -1;

    while (fread(&reg, sizeof(Venta), 1, p)) {
        if (strcmp(reg.getCliente(), nombre)) {
            contadorRegistros++;
        }
    }
    fclose(p);
    return contadorRegistros;
}


Venta ArchivoVenta::leerRegistro(int pos){
    FILE *pf;
    Venta reg;

    pf = fopen(Nombre, "rb");

    if(pf == NULL){
        cout << "NO PUEDE ABRIRSE EL ARCHIVO EN leerRegistro()" << endl;
        return reg;
    }

    fseek(pf, sizeof(reg)* pos, 0);
    fread(&reg, sizeof(reg), 1, pf);
    fclose(pf);
    return reg;
}


Venta ArchivoVenta::buscarNombre(const char *n){
    FILE *pf;
    Venta reg;
    Venta aux;

    pf = fopen(Nombre, "rb");

    if(pf == NULL){
        cout << "NO PUEDE ABRIRSE EL ARCHIVO: " << Nombre << " EN MODO RB - buscarRegistro()" << endl;
        system("pause");
        return reg;
    }

    while(fread(&reg, sizeof(Venta), 1, pf)){
        if(strcmp(reg.getCliente(), n) == 0){
            fclose(pf);
            aux.setId(reg.getId());
            aux.setCliente(reg.getCliente());
            aux.setFecha(reg.getFecha());
            aux.setCantidadItems(reg.getCantidadItems());
            aux.setMontoTotal(reg.getMontoTotal());
            return aux;
        }
    }

    fclose(pf);
    return reg;
}


#endif // ARCHIVOVENTA_H
