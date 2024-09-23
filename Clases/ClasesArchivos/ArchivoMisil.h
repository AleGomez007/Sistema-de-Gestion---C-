#ifndef ARCHIVOMISIL_H
#define ARCHIVOMISIL_H
#include<iostream>
#include<string.h>
#include "../Misil.h"

using namespace std;


class ArchivoMisil
{
    private:
            char Nombre[30];
    public:
            ArchivoMisil(const char* n = "ARCHIVOS/MISIL.DAT"){
                strcpy(Nombre, n);
            }
            bool escribirEnDisco(Misil reg);
            bool ModificarEnDisco(Misil reg, int pos);
            void ModificarDatos();
            bool listarRegistros();
            int contarRegistros();
            void borrarRegistroMisil();
            Misil leerRegistro(int pos);
            int buscarRegistro(int Id);
            bool modificarStock(Misil reg, int pos);
};

bool ArchivoMisil::escribirEnDisco(Misil reg){
    FILE *pf;

    pf = fopen(Nombre, "ab");

    if(pf == NULL){
        cout << "NO PUEDE ABRIRSE EL ARCHIVO EN grabarRegistro()" << endl;
        return true;
    }

    if(fwrite(&reg, sizeof(reg), 1, pf)){
    }
    else{
        cout << "PROBLEMAS AL GRABAR EL REGISTRO" << endl;
        fclose(pf);
        return true;
    }

    fclose(pf);
    return true;
}


bool ArchivoMisil::ModificarEnDisco(Misil reg, int pos) {
    FILE *p;
    p = fopen(Nombre, "rb+");
    if(p == NULL){
        cout << "NO PUEDE ABRIRSE EL ARCHIVO EN ModificarEnDisco()" << endl;
        return false;
    }
    fseek(p, pos * sizeof(Misil), 0);
    if(fwrite(&reg, sizeof(Misil), 1, p)){
        fclose(p);
        return true;
    } else {
        fclose(p);
        return false;
    }
}


void ArchivoMisil::ModificarDatos() {
    Misil reg;
    int pos = 0;
    int num = 0;
    bool encontrado = false;

    cout << "Ingrese el Numero de misil: ";
    cin >> num;

    FILE* p = fopen(Nombre, "rb+");
    if (p == NULL) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }

    while (fread(&reg, sizeof(Misil), 1, p)) {
        if (num == reg.getCodigoUnico()) {
            cout << "Actualice los nuevos datos del misil" << endl;

            char buffer[30];

            cout << "Ingrese el tipo de propulsion: ";
            cin.ignore();
            cin.getline(buffer, sizeof(buffer));
            reg.setTipoPropulsion(buffer);

            cout << "Ingrese el tipo de guia: ";
            cin.getline(buffer, sizeof(buffer));
            reg.setTipoGuia(buffer);

            int tempInt;
            cout << "Ingrese la cantidad de cabezas explosivas: ";
            cin >> tempInt;
            reg.setCantCabezasExplosivas(tempInt);

            cout << "Ingrese la velocidad maxima: ";
            cin >> tempInt;
            reg.setVelocidadMax(tempInt);

            cout << "Ingrese el peso: ";
            cin >> tempInt;
            reg.setPeso(tempInt);
            cin.ignore();

            cout << "Ingrese el tipo de combustible: ";
            cin.getline(buffer, sizeof(buffer));
            reg.setTipoCombustible(buffer);

            cout << "Ingrese el tipo de carga: ";
            cin.getline(buffer, sizeof(buffer));
            reg.setTipoCarga(buffer);

            cout << "Ingrese el tipo: ";
            cin.getline(buffer, sizeof(buffer));
            reg.setTipo(buffer);

            bool tempBool;
            cout << "Es hipersonico (1: Si, 0: No): ";
            cin >> tempBool;
            reg.setHipersonico(tempBool);

            fseek(p, pos * sizeof(Misil), SEEK_SET);
            if (fwrite(&reg, sizeof(Misil), 1, p)) {
                cout << "Datos del misil actualizados correctamente." << endl;
                encontrado = true;
            } else {
                cout << "Error al intentar modificar el archivo." << endl;
            }
            break;
        }
        pos++;
    }

    if (!encontrado) {
        cout << "No se encontro el misil con el Numero proporcionado." << endl;
    }

    fclose(p);
}


bool ArchivoMisil::listarRegistros() {
    FILE *pf;
    Misil reg;

    pf = fopen(Nombre, "rb");
    if (pf == NULL) {
        cout << "NO PUEDE ABRIRSE EL ARCHIVO EN listarRegistros()" << endl;
        return false;
    }

    bool hayRegistros = false;
    int contador = 0;
    int limite = contarRegistros();

    while (fread(&reg, sizeof(reg), 1, pf) == 1) {
        if (reg.getEstado()) {
            reg.mostrar();  //
            cout << "-----------------------------------------" << endl;  // Separador entre registros
            hayRegistros = true;
            contador++;

            if (!(contador==limite)) {
                char opcion;
                cout << "Presione 'c' para continuar, 'r' para regresar al menu: ";
                cin >> opcion;
                if (opcion == 'r' || opcion == 'R') {
                    break;
                }
                system("cls");
            } else {
                getch();
                system("cls");
            }
        }
    }

    fclose(pf);

    if (!hayRegistros) {
        cout << "No hay registros activos" << endl;
    }

    return true;
}


void ArchivoMisil::borrarRegistroMisil() {
    Misil reg;
    int num, pos = 0;
    bool encontrado = false;

    cout << "Ingrese el Numero de misil: ";
    cin >> num;

    FILE* p = fopen(Nombre, "rb+");
    if (p == NULL) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }

    while (fread(&reg, sizeof(Misil), 1, p)) {
        if (num == reg.getCodigoUnico() && reg.getEstado() == true) {
            reg.setEstado(false);
            fseek(p, pos * sizeof(Misil), SEEK_SET);
            if (fwrite(&reg, sizeof(Misil), 1, p)) {
                cout << "Registro de misil dado de baja correctamente." << endl;
                encontrado = true;
            } else {
                cout << "Error al intentar modificar el archivo." << endl;
            }
            break;
        }
        pos++;
    }

    if (!encontrado) {
        cout << "No se encontro el misil con el numero proporcionado o ya esta dado de baja." << endl;
    }

    fclose(p);
}


int ArchivoMisil::buscarRegistro(int Id){
    FILE *pf;
    Misil reg;
    int c = 0;

    pf = fopen(Nombre, "rb");

    if(pf == NULL){
        cout << "NO PUEDE ABRIRSE EL ARCHIVO EN leerRegistro()" << endl;
        return -1;
    }

    while(fread(&reg, sizeof(reg), 1, pf)){
        if(reg.getId() == Id){
            return c;
        }
        c++;
    }

    fclose(pf);
    return -1;
}


Misil ArchivoMisil::leerRegistro(int pos){
    FILE *pf;
    Misil reg;

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

int ArchivoMisil::contarRegistros(){
        FILE *p;
        p=fopen(Nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Misil);
}


bool ArchivoMisil::modificarStock(Misil reg, int posicion){
    FILE *pf;

    pf = fopen(Nombre, "rb+");

    if(pf == NULL){
        cout << "NO PEUDE ABRIRSE EL ARCHIVO EN grabarRegistro()" << endl;
        return true;
    }

    fseek(pf, posicion*sizeof(reg), 0);

    if(fwrite(&reg, sizeof(reg), 1, pf)){
    }
    else{
        cout << "PROBLEMAS AL MODIFICADAR EL REGISTRO" << endl;
        fclose(pf);
        return true;
    }

    fclose(pf);
    return true;
}

#endif // ARCHIVOMISIL_H

//
