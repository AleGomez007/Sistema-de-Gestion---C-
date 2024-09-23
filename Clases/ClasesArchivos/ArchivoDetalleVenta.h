#ifndef ARCHIVODETALLEVENTA_H
#define ARCHIVODETALLEVENTA_H

#include<iostream>
#include<string.h>
#include "../DetalleVenta.h"

using namespace std;

class ArchivoDetalleVenta
{
    private:
            char Nombre[30];
    public:
            ArchivoDetalleVenta(const char* n = "ARCHIVOS/DETALLEVENTA.DAT"){
                strcpy(Nombre, n);
            }
            int contarRegistros(int id);
            int contarTotalRegistros();
            bool grabarRegistros(DetalleVenta *vecDetalle, int numDetalles);
            DetalleVenta leerRegistro(int pos);
            bool listarRegistros();
};

bool ArchivoDetalleVenta::grabarRegistros(DetalleVenta *vecDetalle, int numDetalles) {
    FILE *pf;

    pf = fopen(Nombre, "ab");

    if (pf == NULL) {
        cout << "NO PUEDE ABRIRSE EL ARCHIVO: " << Nombre << " EN MODO AB - grabarRegistros()" << endl;
        system("pause");
        return false;
    }

    for (int i = 0; i < numDetalles; i++) {
        if (fwrite(&vecDetalle[i], sizeof(DetalleVenta), 1, pf) != 1) {
            cout << "PROBLEMAS AL GRABAR EL REGISTRO" << endl;
            fclose(pf);
            return false;
        }
    }
    fclose(pf);
    return true;
}


DetalleVenta ArchivoDetalleVenta::leerRegistro(int pos){
    FILE *pf;
    DetalleVenta reg;

    pf = fopen(Nombre, "rb");

    if(pf == NULL){
        cout << "NO PUEDE ABRIRSE EL ARCHIVO: " << Nombre << " EN MODO RB - leerRegistro()" << endl;
        system("pause");
        return reg;
    }

    fseek(pf, sizeof(reg)* pos, 0);
    fread(&reg, sizeof(reg), 1, pf);
    fclose(pf);
    return reg;
}


bool ArchivoDetalleVenta::listarRegistros(){
    FILE *pf;
    DetalleVenta reg;

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

int ArchivoDetalleVenta::contarRegistros(int id){
    //FILE *pf;
    DetalleVenta reg;
    int contadorRegistros = 0;

    FILE *p = fopen(Nombre, "rb");
    if (p == NULL) return -1;

    while (fread(&reg, sizeof(DetalleVenta), 1, p)) {
        if (reg.getIdVenta() == id) {
            contadorRegistros++;
        }
    }

    fclose(p);
    return contadorRegistros;
}


int ArchivoDetalleVenta::contarTotalRegistros(){
        FILE *p;
        p=fopen(Nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(DetalleVenta);
}

#endif // ARCHIVODETALLEVENTA_H
