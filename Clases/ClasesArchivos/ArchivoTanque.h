#ifndef ARCHIVOTANQUE_H
#define ARCHIVOTANQUE_H
#include<iostream>
#include<string.h>
#include "../Tanque.h"
using namespace std;

class ArchivoTanque{
    private:
            char Nombre[30];
    public:
            ArchivoTanque(const char* n = "ARCHIVOS/TANQUE.DAT"){
                strcpy(Nombre, n);
            }
            bool grabarRegistro(Tanque reg);
            Tanque leerRegistro(int pos);
            int buscarRegistro(int Id);
            int contarRegistros();
            bool modificarRegistro(Tanque reg, int pos);
            bool modificarStock(Tanque reg, int posicion);
            bool listarRegistros();
};

bool ArchivoTanque::grabarRegistro(Tanque reg){
    FILE *pf;

    pf = fopen(Nombre, "ab");

    if(pf == NULL){
        cout << "NO PUEDE ABRIRSE EL ARCHIVO EN grabarRegistro()" << endl;
        return true;
    }

    if(fwrite(&reg, sizeof(reg), 1, pf)){
        cout << "REGRISTRO GRABADO CORRECTAMENTE" << endl;
    }
    else{
        cout << "PROBLEMAS AL GRABAR EL REGISTRO" << endl;
        fclose(pf);
        return true;
    }

    fclose(pf);
    return true;
}

Tanque ArchivoTanque::leerRegistro(int pos){
    FILE *pf;
    Tanque reg;

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

int ArchivoTanque::buscarRegistro(int Id){
    FILE *pf;
    Tanque reg;
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

int ArchivoTanque::contarRegistros(){
        FILE *p;
        p=fopen(Nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Tanque);
}

bool ArchivoTanque::modificarRegistro(Tanque reg, int pos){
    FILE *pf;

    pf = fopen(Nombre, "rb+");

    if(pf == NULL){
        cout << "NO PUEDE ABRIRSE EL ARCHIVO EN grabarRegistro()" << endl;
        return true;
    }

    fseek(pf, pos*sizeof(reg), 0);

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

bool ArchivoTanque::listarRegistros() {
    FILE *pf;
    Tanque reg;

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
                cout << "Fin de registros.";
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


bool ArchivoTanque::modificarStock(Tanque reg, int posicion){
    FILE *pf;

    pf = fopen(Nombre, "rb+");

    if(pf == NULL){
        cout << "NO PUEDE ABRIRSE EL ARCHIVO EN grabarRegistro()" << endl;
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


#endif // ARCHIVOTANQUE_H
