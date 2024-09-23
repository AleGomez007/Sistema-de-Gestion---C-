#ifndef ARCHIVOADMIN_H_INCLUDED
#define ARCHIVOADMIN_H_INCLUDED
#include<iostream>
using namespace std;

class ArchivoAdmin{
    private:
            char Nombre[30];
    public:
            ArchivoAdmin(const char* n = "ARCHIVOS/ADMIN.DAT"){
                strcpy(Nombre, n);
            }

            bool grabarRegistro(Admin reg);
            Admin leerRegistro(int pos);
            Admin buscarNombre(const char *n);
            int buscarRegistro(int Id);
            int contarRegistros();
            bool modificarRegistro(Admin reg, int pos);
            bool listarRegistros();
};


bool ArchivoAdmin::grabarRegistro(Admin reg){
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


Admin ArchivoAdmin::leerRegistro(int pos){
    FILE *pf;
    Admin reg;

    pf = fopen(Nombre, "rb");

    if(pf == NULL){
        cout << "NO PEUDE ABRIRSE EL ARCHIVO EN leerRegistro()" << endl;
        return reg;
    }

    fseek(pf, sizeof(reg)* pos, 0);
    fread(&reg, sizeof(reg), 1, pf);
    fclose(pf);
    return reg;
}


int ArchivoAdmin::buscarRegistro(int Id){
    FILE *pf;
    Admin reg;
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


int ArchivoAdmin::contarRegistros(){
    FILE *pf;
    Admin reg;
    int regContador = -1, tam;

    pf = fopen(Nombre, "rb");

    if(pf == NULL){
        cout << "NO PUEDE ABRIRSE EL ARCHIVO EN contarRegistro()" << endl;
        return 0;
    }

    fseek(pf, 0, 2);

    tam = ftell(pf);

    regContador = tam / sizeof(reg);

    fclose(pf);
    return regContador;
}


bool ArchivoAdmin::modificarRegistro(Admin reg, int pos){
    FILE *pf;

    pf = fopen(Nombre, "rb+");

    if(pf == NULL){
        cout << "NO PEUDE ABRIRSE EL ARCHIVO EN grabarRegistro()" << endl;
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


bool ArchivoAdmin::listarRegistros(){
    FILE *pf;
    Admin reg;

    pf = fopen(Nombre, "rb");

    if(pf == NULL){
        cout << "NO PEUDE ABRIRSE EL ARCHIVO EN leerRegistro()" << endl;
        return -1;
    }

    while(fread(&reg, sizeof(reg), 1, pf) == 1){
        if(reg.getEstado() == true){
            reg.mostrar();
        }
    }

    fclose(pf);
    return 1;
}


Admin ArchivoAdmin::buscarNombre(const char *n){
    FILE *pf;
    Admin reg;
    Admin aux;

    pf = fopen(Nombre, "rb");

    if(pf == NULL){
        cout << "NO PUEDE ABRIRSE EL ARCHIVO: " << Nombre << " EN MODO RB - buscarRegistro()" << endl;
        system("pause");
        return reg;
    }

    while(fread(&reg, sizeof(Admin), 1, pf)){
        if((strcmp(reg.getUsuario(), n) == 0)||(strcmp(reg.getNombreAdmin(), n) == 0)){
            fclose(pf);
            aux.setId(reg.getId());
            aux.setNombreAdmin(reg.getNombreAdmin());
            aux.setPropiedadAdmin(reg.getPropiedadAdmin());
            aux.setUsuario(reg.getUsuario());
            aux.setClave(reg.getClave());
            aux.setDescripcion(reg.getDescripcion());
            aux.setEstado(reg.getEstado());
            return aux;
        }
    }

    fclose(pf);
    return reg;
}


#endif // ARCHIVOADMIN_H_INCLUDED
