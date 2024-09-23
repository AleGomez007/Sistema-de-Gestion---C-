#include <iostream>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <iomanip>

using namespace std;

#include "rlutil.h"
#include "Menu.h"
#include "Admin.h"
#include "Pais.h"
#include "Misil.h"
#include "Avion.h"
#include "Buque.h"
#include "Tanque.h"
#include "Venta.h"
#include "DetalleVenta.h"

#include "ClasesArchivos/ArchivoAdmin.h"
#include "ClasesArchivos/ArchivoPais.h"
#include "ClasesArchivos/ArchivoAvion.h"
#include "ClasesArchivos/ArchivoMisil.h"
#include "ClasesArchivos/ArchivoBuque.h"
#include "ClasesArchivos/ArchivoTanque.h"
#include "ClasesArchivos/ArchivoVenta.h"
#include "ClasesArchivos/ArchivoDetalleVenta.h"

#include "STRClientes.h"
#include "StockProducto.h"

using namespace std;
using namespace rlutil;


/// DIBUJAR RECUADRO
void Menu::dibujarCuadro(int x1, int y1, int x2, int y2){
    int i;

    for(i=x1; i<x2; i++){
        gotoxy(i, y1);
        printf("\304"); // LINEA HORIZONTAL SUPERIOR
        gotoxy(i, y2);
        printf("\304"); // LINEA HORIZONTAL INFERIOR
    }

    for(i=y1; i<y2; i++){
        gotoxy(x1, i);
        printf("\263"); // LINEA VERTICAL IZQUIERDA
        gotoxy(x2, i);
        printf("\263"); // LINEA VERTICAL DERECHA
    }

    gotoxy(x1, y1);
    printf("\332");
    gotoxy(x1, y2);
    printf("\300");
    gotoxy(x2, y1);
    printf("\277");
    gotoxy(x2, y2);
    printf("\331");
}


/// UBICACION
void Menu::gotoxy(int x, int y){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}


/// CABECERA
void Menu::cabecera(){
    cls();
    system("mode con: cols=80 lines=25"); // DEFINE DIMENSIONES VENTANA PROGRAMA 80 COLUMNAS 25 FILAS
    system("COLOR 70"); // COLOR FONDO y COLOR LETRAS
    dibujarCuadro(0, 0, 78, 24); // DIBUJO CUADRO PRINCIPAL
    dibujarCuadro(1, 1, 77, 3); // DIBUJO CUADRO TITULO
    gotoxy(22, 2);
    cout << "SGA - SISTEMA GESTION ARMAMENTISTICO" << endl;
    gotoxy(29, 3);
    cout << "PROGRAMANDO TU DEFENSA" << endl;
}


/// MENU INGRESO
bool Menu::menuOpcion(){ // MENU INGRESO USERS/ADMINS
    cabecera();

    char user[15];
    char pass[15];

    ArchivoPais archivoPais;
    Pais regPais;
    Admin regAdmin;
    ArchivoAdmin archivoAdmin;

    gotoxy (29,6);
    cout<<"INGRESO AL SISTEMA";
    gotoxy (29,7);
    cout<<"------------------";

    gotoxy (20,10);
    cout<<"INGRESE SU USUARIO: ";
    cin>>user;

    gotoxy (20,12);
    cout<<"INGRESE SU CLAVE: ";
    cin>>pass;

    string nombre = user;
    string clave = pass;
    bool ingresoAdmin = false;

    regAdmin = archivoAdmin.buscarNombre(user);
    if ((strcmp(regAdmin.getNombreAdmin(), user) == 0)&&(strcmp(regAdmin.getClave(), pass)== 0)){
            menuPrincipalAdmin();
            ingresoAdmin = true;
    }
    else if(((nombre == "admin")&&(clave == "admin"))){
        menuPrincipalAdmin();
        ingresoAdmin = true;
    }
    else {
        regPais = archivoPais.buscarNombre(user);
    }

    if ((strcmp(regPais.getNombrePais(), user) == 0)&&(strcmp(regPais.getClave(), pass)== 0)){
        menuPrincipalPais(regPais);
    }
    else if(ingresoAdmin==false) {
        gotoxy(2,14);
        cout << "Credenciales invalidas.";
        getch();
    }

    int respuesta = -1;

    while(respuesta < 0 || respuesta > 1){
        system("cls");
        cabecera();
        gotoxy (29,6);
        cout<<"REINGRESAR AL SISTEMA?: ";
        gotoxy (29,7);
        cout<<"0. NO";
        gotoxy (29,8);
        cout<<"1. SI";
        gotoxy (29,10);
        cout<<"OPCION: ";
        cin>>respuesta;
        if(respuesta < 0 || respuesta > 1){
            cout << "Ingreso incorrecto... re ingrese.." << endl;
            getch();
        }
    }

    if(respuesta == 0){
        return false;
    } else{
        return true;
    }

    gotoxy (2,22);
    anykey();
    return false;
}


/// MENU PRINCIPAL ADMINISTRADOR
void Menu::menuPrincipalAdmin(){
        int opcion = -1;
        while(opcion!=0){

        cabecera();

        gotoxy (2,6);
        cout << "MENU ADMINISTRADOR";
        gotoxy (2,7);
        cout << "------------------";
        gotoxy (2,10);
        cout << "INGRESE UNA OPCION: ";

        gotoxy (2,13);
        cout << "1 - USUARIOS: ";
        gotoxy (2,14);
        cout << "2 - STOCK: ";
        gotoxy (2,15);
        cout << "3 - CLIENTES: ";
        gotoxy (2,16);
        cout << "4 - REPORTES: ";
        gotoxy (2,17);
        cout << "0 - SALIR DEL PROGRAMA: ";
        gotoxy (2,18);
        cout << "->: ";

        cin >> opcion;


            switch(opcion){
                case 1:
                    Usuarios();
                    break;
                case 2:
                    Stock();
                    break;
                case 3:
                    Clientes();
                    break;
                case 4:
                    Reportes();
                    break;
                case 0:
                    break;
                default:
                    break;
            }
        }
}


/// MENU USUARIOS
void Menu::Usuarios(){
    opcion = -1;

    while(opcion!=0){

        cabecera();

        gotoxy (2,6);
        cout<<"MENU ADMINISTRADOR USUARIOS";
        gotoxy (2,7);
        cout<<"------------------";
        gotoxy (2,10);
        cout<<"INGRESE UNA OPCION: ";

        gotoxy (2,13);
        cout<<"1 - ALTA DE USUARIO: ";
        gotoxy (2,14);
        cout<<"2 - LISTAR USUARIOS: ";
        gotoxy (2,15);
        cout<<"3 - MODIFICACION DE USUARIO: ";
        gotoxy (2,16);
        cout<<"4 - BAJA DE USUARIO: ";
        gotoxy (2,17);
        cout<<"0 - VOLVER ATRAS: ";
        gotoxy (2,18);
        cout<<"->: ";
        cin>>opcion;

        system("cls");

            switch(opcion){
                case 1:
                    altaUsuario();
                    break;
                case 2:
                    listarUsuarios();
                    break;
                case 3:
                    modificarUsuario();
                    break;
                case 4:
                    eliminarUsuario();
                    break;
                case 0:
                    opcion = 0;
                    break;
                default:
                    break;
             }
        }
}


/// ALTA USUARIO
void Menu::altaUsuario(){

    int Id;
    Admin reg;
    ArchivoAdmin ArchAdmin;
    Id = ArchAdmin.contarRegistros();
    reg.cargar(Id);
    if(ArchAdmin.grabarRegistro(reg)){
        cout << "ALTA EXITOSA...";
        system("pause");
    } else {
        cout << "NO SE HA PODIDO GRABAR EL REGISTRO.";
        system("pause");
    }
}


/// LISTAR USUARIOS
void Menu::listarUsuarios(){

    Admin reg;
    ArchivoAdmin ArchAdmin;

    int cant = ArchAdmin.contarRegistros();
    Admin *admin= new Admin[cant];

    for(int i=0;i<cant;i++){
        admin[i] = ArchAdmin.leerRegistro(i);
    }

    for(int j=0;j<cant;j++){
        cabecera();
        if(admin[j].getEstado()==1){
            admin[j].mostrar();
            cout<<endl;
        }
        system("pause");
        cls();
    }
}


/// MODIFICAR USUARIO
void Menu::modificarUsuario(){

    ArchivoAdmin ArchAdmin;
    int Id;
    cout << "INGRESE EL ID A BUSCAR: ";
    cin >> Id;
    int pos = ArchAdmin.buscarRegistro(Id);
    Admin reg = ArchAdmin.leerRegistro(pos);
    reg.mostrar();
    if(reg.getEstado()== false){
        cout << "REGISTRO DADO DE BAJA, NO SE PUEDE MODIFICAR..." << endl;
        system("pause");
        return;
    }

    char respuesta;
    cout << "DESEA MODIFICAR ESTE REGISTRO? (s / n): ";
    cin >> respuesta;
    char dato[30];
    if(respuesta == 's' || respuesta == 'S'){
        cout << "MODIFICAR CLAVE? (s / n): ";
        cin >> respuesta;
        if(respuesta == 's' || respuesta == 'S'){
            cout << "INGRESE NUEVA CLAVE: ";

            cin >> dato;
            reg.setClave(dato);
        }

        cout << "MODIFICAR DESCRIPCION? (s / n): ";
        cin >> respuesta;
        if(respuesta == 's' || respuesta == 'S'){
            cout << "INGRESE NUEVA DESCRIPCION: ";
            cin >> dato;
            reg.setDescripcion(dato);
        }
    }
    else{
        return;
    }
    if(ArchAdmin.modificarRegistro(reg, pos)){
        cout << "MODIFICACION EXITOSA..." << endl;
        system("pause");
    }
    else{
        cout << "ERROR, NO SE HA REALIZADO LA MODIFICACION..." << endl;
    }
    system("pause");
}

/// ELIMINAR USUARIO
void Menu::eliminarUsuario(){

    int Id;
    ArchivoAdmin ArchAdmin;
    Admin reg;

    cout << "INGRESE EL ID A BUSCAR: ";
    cin >> Id;

    int pos = ArchAdmin.buscarRegistro(Id);
    reg = ArchAdmin.leerRegistro(pos);
    reg.mostrar();

    char respuesta;
    cout << "DESEA DAR DE BAJA ESTE REGISTRO? (s / n): ";
    cin >> respuesta;

    if(respuesta == 's' || respuesta == 'S'){
        reg.setEstado(false);
    }
    else{
        return;
    }
    if(ArchAdmin.modificarRegistro(reg, pos)){
        cout << "BAJA EXITOSA..." << endl;
        system("pause");
    }
    else{
        cout << "ERROR, NO SE HA REALIZADO LA BAJA..." << endl;
    }
    system("pause");
}


/// MENU STOCKS
void Menu::Stock(){
    int opcion;

    cabecera();

    gotoxy(30, 6);
    cout << "MENU STOCK";
    gotoxy(30, 8);
    cout << "1 - MISILES";
    gotoxy(30, 10);
    cout << "2 - AVIONES";
    gotoxy(30, 12);
    cout << "3 - BUQUES";
    gotoxy(30, 14);
    cout << "4 - TANQUES";
    gotoxy(30, 16);
    cout << "0 - VOLVER";
    gotoxy(30, 18);
    cout << "INGRESE UNA OPCION: ";
    cin >> opcion;

    switch(opcion) {
        case 1:
            StockMisiles();
            break;

        case 2:
            StockAviones();
            break;

        case 3:
            StockBuques();
            break;

        case 4:
            StockTanques();
            break;

        case 0:
            break;

        default:
            break;
    }
}


///----------------------------------  STOCK MISIL
void Menu::StockMisiles() {
    Misil misil;
    ArchivoMisil ArchMisil;
    char respuesta;
    int opcion;

    while (true) {
        system("cls");
        cabecera();

        gotoxy (2,6);
        cout<<"MENU MISILES";
        gotoxy (2,7);
        cout<<"------------------";
        gotoxy (2,10);
        cout<<"INGRESE UNA OPCION: ";
        gotoxy(2,13);
        cout << "1 - ALTA MISIL" << endl;
        gotoxy(2,14);
        cout << "2 - LISTAR MISILES" << endl;
        gotoxy(2,15);
        cout << "3 - MODIFICAR MISIL" << endl;
        gotoxy(2,16);
        cout << "4 - AGREGAR A STOCK" << endl;
        gotoxy(2,17);
        cout << "5 - BAJA MISIL" << endl;
        gotoxy(2,18);
        cout << "0 - VOLVER ATRAS" << endl;
        gotoxy(2,19);
        cout << "->: ";
        cin >> opcion;

        switch (opcion) {

            case 1: {
                cls();
                cabecera();
                gotoxy(29, 5);
                cout << "---------------";
                gotoxy(30, 6);
                cout << "CARGAR MISIL" << endl;
                gotoxy(29, 7);
                cout << "---------------";

                misil.cargar();
                ArchMisil.escribirEnDisco(misil);

                cls();
                cabecera();
                gotoxy(22, 6);
                cout << "MISIL CARGADO EXITOSAMENTE." << endl;
                break;
            }

            case 2: {
                cls();
                cabecera();
                gotoxy(30, 6);
                cout << "LISTAR REGISTROS DE MISILES";
                gotoxy(29, 7);
                cout << "---------------";

                ArchMisil.listarRegistros();
                break;
            }

            case 3: {
                cls();
                cabecera();
                gotoxy(29, 5);
                cout << "---------------";
                gotoxy(30, 6);
                cout << "MODIFICAR MISIL";
                gotoxy(29, 7);
                cout << "---------------";
                gotoxy(23, 10);
                cout << "INGRESE EL CODIGO DEL PRODUCTO: ";
                int codigo;
                cin >> codigo;

                int posicion = ArchMisil.buscarRegistro(codigo);
                misil = ArchMisil.leerRegistro(posicion);

                misil.mostrar();
                system("pause");

                cls();
                cabecera();
                int respuesta;
                cout << "DESEA MODIFICAR ESTE PRODUCTO?(1-SI / 2-NO) ";
                cin >> respuesta;
                if(respuesta==1){
                    misil.cargar();
                    if(ArchMisil.ModificarEnDisco(misil, posicion)){
                        cls();
                        cabecera();
                        cout << "MODIFICACION EXITOSA...";
                        system("pause");
                    } else {
                        cls();
                        cabecera();
                        cout << "NO SE HA PODIDO MODIFICAR...";
                        system("pause");
                    }
                }
                break;
            }

            case 4:{

                cls();
                cabecera();

                gotoxy(29, 5);
                cout << "---------------";
                gotoxy(30, 6);
                cout << "AGREGAR STOCK";
                gotoxy(29, 7);
                cout << "---------------";

                gotoxy(23, 10);
                cout << "INGRESE EL CODIGO DEL PRODUCTO: ";
                int codigo;
                cin >> codigo;

                int posicion = ArchMisil.buscarRegistro(codigo);
                misil = ArchMisil.leerRegistro(posicion);

                cls();
                cabecera();
                misil.mostrar();
                system("pause");

                cls();
                cabecera();
                int respuesta;
                cout << "DESEA ANIADIR STOCK A ESTE PRODUCTO?(1-SI / 2-NO) ";
                cin >> respuesta;
                if(respuesta==1){
                    cout << "INGRESE LA CANTIDAD: ";
                    int cantidad;
                    cin >> cantidad;
                    misil.setStock((misil.getStock() + cantidad));
                    ArchMisil.modificarStock(misil, posicion);
                    cls();
                    cabecera();
                    misil = ArchMisil.leerRegistro(posicion);
                    misil.mostrar();
                    system("pause");
                }
                break;

            }

            case 5: {
                    int Id, pos;
                    cls();
                    cabecera();
                    cout << "INGRESE EL ID A BUSCAR: ";
                    cin >> Id;
                    pos = ArchMisil.buscarRegistro(Id);
                    misil = ArchMisil.leerRegistro(pos);

                    cls();
                    cabecera();
                    misil.mostrar();
                    cout << "DESEA DAR DE BAJA ESTE REGISTRO? (s / n): ";
                    cin >> respuesta;
                    if(respuesta == 's' || respuesta == 'S'){
                        misil.setEstado(false);
                    }
                    else{
                        break;
                    }
                    if(ArchMisil.ModificarEnDisco(misil, pos)){
                        cls();
                        cabecera();
                        cout << "BAJA EXITOSA..." << endl;
                    }
                    else{
                        cls();
                        cabecera();
                        cout << "ERROR, NO SE HA REALIZADO LA BAJA..." << endl;
                    }
                    system("pause");
                    break;
                }
                break;

            case 0:
                return;

            default:
                gotoxy(30, 16);
                cout << "OPCION INCORRECTA." << endl;
                system("pause");
                break;
        }
    }
}


///----------------------------------  STOCK AVION
void Menu::StockAviones(){
    opcion = -1;
    Avion avion;
    ArchivoAvion ArchAvion;
    char respuesta;
    int Id, pos;

    while(opcion!=0){

        cabecera();

        gotoxy (2,6);
        cout<<"MENU AVIONES";
        gotoxy (2,7);
        cout<<"------------------";
        gotoxy (2,10);
        cout<<"INGRESE UNA OPCION: ";

        gotoxy (2,13);
        cout<<"1 - ALTA DE AVION: ";
        gotoxy (2,14);
        cout<<"2 - LISTAR AVIONES: ";
        gotoxy (2,15);
        cout<<"3 - MODIFICACION DE AVIONES: ";
        gotoxy(2,16);
        cout << "4 - AGREGAR A STOCK" << endl;
        gotoxy(2,17);
        cout << "5 - BAJA AVIONES" << endl;
        gotoxy(2,18);
        cout << "0 - VOLVER ATRAS" << endl;
        gotoxy(2,19);
        cout << "->: ";
        cin >> opcion;

        system("cls");

            switch(opcion){

                case 1: {
                    avion.cargar();
                    ArchAvion.grabarRegistro(avion);
                    break;
                }

                case 2: {
                    ArchAvion.listarRegistros();
                    break;
                }

                case 3: {

                    system("cls");

                    cout << "INGRESE EL ID A BUSCAR: ";
                    cin >> Id;
                    pos = ArchAvion.buscarRegistro(Id);
                    avion = ArchAvion.leerRegistro(pos);
                    avion.mostrar();
                    if(avion.getEstado()==false){
                        cout << "REGISTRO DADO DE BAJA, NO SE PUEDE MODIFICAR..." << endl;
                        system("pause");
                        break;
                    }
                    cout << "DESEA MODIFICAR ESTE REGISTRO? (s / n): ";
                    cin >> respuesta;
                    if(respuesta == 's' || respuesta == 'S'){
                        avion.cargar();
                        if(ArchAvion.modificarRegistro(avion, pos)){
                        cout << "MODIFICACION EXITOSA..." << endl;
                        system("pause");
                        }
                    } else {
                        cout << "ERROR, NO SE HA REALIZADO LA MODIFICACION..." << endl;
                    }

                    system("pause");
                    break;
                }

                case 4:{
                    cls();
                    cabecera();
                    Avion avion;

                    gotoxy(29, 5);
                    cout << "---------------";
                    gotoxy(30, 6);
                    cout << "AGREGAR STOCK";
                    gotoxy(29, 7);
                    cout << "---------------";

                    gotoxy(23, 10);
                    cout << "INGRESE EL CODIGO DEL PRODUCTO: ";
                    int codigo;
                    cin >> codigo;

                    int posicion = ArchAvion.buscarRegistro(codigo);
                    avion = ArchAvion.leerRegistro(posicion);
                    cls();
                    cabecera();
                    avion.mostrar();
                    system("pause");
                    cls();
                    cabecera();
                    int respuesta;
                    cout << "DESEA ANIADIR STOCK A ESTE PRODUCTO?(1-SI / 2-NO) ";
                    cin >> respuesta;
                    if(respuesta==1){
                        cout << "INGRESE LA CANTIDAD: ";
                        int cantidad;
                        cin >> cantidad;
                        avion.setStock((avion.getStock() + cantidad));
                        ArchAvion.modificarStock(avion, posicion);
                        cls();
                        cabecera();
                        avion = ArchAvion.leerRegistro(posicion);
                        avion.mostrar();
                        system("pause");
                    }
                    break;

                }

                case 5: {
                    int Id, pos;
                    cout << "INGRESE EL ID A BUSCAR: ";
                    cin >> Id;
                    pos = ArchAvion.buscarRegistro(Id);
                    avion = ArchAvion.leerRegistro(pos);
                    avion.mostrar();
                    cout << "DESEA DAR DE BAJA ESTE REGISTRO? (s / n): ";
                    cin >> respuesta;
                    if(respuesta == 's' || respuesta == 'S'){
                        avion.setEstado(false);
                    }
                    else{
                        break;
                    }
                    if(ArchAvion.modificarRegistro(avion, pos)){
                        cout << "BAJA EXITOSA..." << endl;
                        system("pause");
                    }
                    else{
                        cout << "ERROR, NO SE HA REALIZADO LA BAJA..." << endl;
                    }
                    system("pause");
                    break;
                }

                case 0:
                    opcion = 0;
                    break;

                default:
                    break;
             }
        }
}


///----------------------------------  STOCK BUQUE
void Menu::StockBuques(){
    opcion = -1;
    Buque buque;
    ArchivoBuque archivoBuque;
    char respuesta;
    int Id, pos;

    while(opcion!=0){

        cabecera();

        gotoxy (2,6);
        cout<<"MENU BUQUES";
        gotoxy (2,7);
        cout<<"------------------";
        gotoxy (2,10);
        cout<<"INGRESE UNA OPCION: ";

        gotoxy (2,13);
        cout<<"1 - ALTA DE BUQUE";
        gotoxy (2,14);
        cout<<"2 - LISTAR BUQUES";
        gotoxy (2,15);
        cout<<"3 - MODIFICACION DE BUQUE";
        gotoxy(2,16);
        cout << "4 - AGREGAR A STOCK" << endl;
        gotoxy(2,17);
        cout << "5 - BAJA DE BUQUE" << endl;
        gotoxy(2,18);
        cout << "0 - VOLVER ATRAS" << endl;
        gotoxy(2,19);
        cout << "->: ";
        cin >> opcion;

        system("cls");

            switch(opcion){

                case 1: {
                    buque.cargar();
                    archivoBuque.grabarRegistro(buque);
                    break;
                }

                case 2: {
                    archivoBuque.listarRegistros();
                    system("pause");
                    break;
                }

                case 3: {
                    system("cls");

                    cout << "INGRESE EL ID A BUSCAR: ";
                    cin >> Id;
                    pos = archivoBuque.buscarRegistro(Id);
                    buque =archivoBuque.leerRegistro(pos);
                    buque.mostrar();
                    if(buque.getEstado()==false){
                        cout << "REGISTRO DADO DE BAJA, NO SE PUEDE MODIFICAR..." << endl;
                        system("pause");
                        break;
                    }
                    cout << "DESEA MODIFICAR ESTE REGISTRO? (s / n): ";
                    cin >> respuesta;
                    if(respuesta == 's' || respuesta == 'S'){
                        buque.cargar();
                        if(archivoBuque.modificarRegistro(buque, pos)){
                        cout << "MODIFICACION EXITOSA..." << endl;
                        system("pause");
                        }
                    } else {
                        cout << "ERROR, NO SE HA REALIZADO LA MODIFICACION..." << endl;
                    }

                    system("pause");
                    break;
                }

                case 4:{
                    cls();
                    cabecera();
                    Buque buque;

                    gotoxy(29, 5);
                    cout << "---------------";
                    gotoxy(30, 6);
                    cout << "AGREGAR STOCK";
                    gotoxy(29, 7);
                    cout << "---------------";

                    gotoxy(23, 10);
                    cout << "INGRESE EL CODIGO DEL PRODUCTO: ";
                    int codigo;
                    cin >> codigo;

                    int posicion = archivoBuque.buscarRegistro(codigo);
                    buque = archivoBuque.leerRegistro(posicion);
                    cls();
                    cabecera();
                    buque.mostrar();
                    system("pause");
                    cls();
                    cabecera();
                    int respuesta;
                    cout << "DESEA ANIADIR STOCK A ESTE PRODUCTO?(1-SI / 2-NO) ";
                    cin >> respuesta;
                    if(respuesta==1){
                        cout << "INGRESE LA CANTIDAD: ";
                        int cantidad;
                        cin >> cantidad;
                        buque.setStock((buque.getStock() + cantidad));
                        archivoBuque.modificarStock(buque, posicion);
                        cls();
                        cabecera();
                        buque = archivoBuque.leerRegistro(posicion);
                        buque.mostrar();
                        system("pause");
                    }
                    break;

                }

                case 5: {
                    int Id, pos;
                    cout << "INGRESE EL ID A BUSCAR: ";
                    cin >> Id;
                    pos = archivoBuque.buscarRegistro(Id);
                    buque = archivoBuque.leerRegistro(pos);
                    buque.mostrar();
                    cout << "DESEA DAR DE BAJA ESTE REGISTRO? (s / n): ";
                    cin >> respuesta;
                    if(respuesta == 's' || respuesta == 'S'){
                        buque.setEstado(false);
                    }
                    else{
                        break;
                    }
                    if(archivoBuque.modificarRegistro(buque, pos)){
                        cout << "BAJA EXITOSA..." << endl;
                        system("pause");
                    }
                    else{
                        cout << "ERROR, NO SE HA REALIZADO LA BAJA..." << endl;
                    }
                    system("pause");
                    break;
                }

                case 0:
                    opcion = 0;
                    break;

                default:
                    break;
             }
        }
}


///----------------------------------  STOCK TANQUE
void Menu::StockTanques(){
    opcion = -1;
    Tanque tanque;
    ArchivoTanque archivoTanque;
    char respuesta;
    int Id, pos;

    while(opcion!=0){

        cabecera();
        gotoxy (2,6);
        cout<<"MENU TANQUES";
        gotoxy (2,7);
        cout<<"------------------";
        gotoxy (2,10);
        cout<<"INGRESE UNA OPCION: ";

        gotoxy (2,13);
        cout<<"1 - ALTA DE TANQUE: ";
        gotoxy (2,14);
        cout<<"2 - LISTAR TANQUES: ";
        gotoxy (2,15);
        cout<<"3 - MODIFICACION DE TANQUES: ";
        gotoxy (2,16);
        cout<<"4 - BAJA DE TANQUE: ";
        gotoxy (2,17);
        cout<<"0 - VOLVER ATRAS: ";
        gotoxy (2,18);
        cout<<"->: ";
        cin>>opcion;

        system("cls");

            switch(opcion){

                case 1:{
                    tanque.cargar();
                    archivoTanque.grabarRegistro(tanque);
                    break;
                }

                case 2: {
                    archivoTanque.listarRegistros();
                    system("pause");
                    break;
                }

                case 3: {
                    system("cls");
                    cout << "INGRESE EL ID A BUSCAR: ";
                    cin >> Id;
                    pos = archivoTanque.buscarRegistro(Id);
                    tanque = archivoTanque.leerRegistro(pos);
                    tanque.mostrar();
                    if(tanque.getEstado()==false){
                        cout << "REGISTRO DADO DE BAJA, NO SE PUEDE MODIFICAR..." << endl;
                        system("pause");
                        break;
                    }
                    cout << "DESEA MODIFICAR ESTE REGISTRO? (s / n): ";
                    cin >> respuesta;
                    if(respuesta == 's' || respuesta == 'S'){
                        tanque.cargar();
                        if(archivoTanque.modificarRegistro(tanque, pos)){
                        cout << "MODIFICACION EXITOSA..." << endl;
                        system("pause");
                        }
                    } else {
                        cout << "ERROR, NO SE HA REALIZADO LA MODIFICACION..." << endl;
                    }
                    system("pause");
                    break;
                }

                case 4: {
                    cls();
                    cabecera();
                    Tanque tanque;

                    gotoxy(29, 5);
                    cout << "---------------";
                    gotoxy(30, 6);
                    cout << "AGREGAR STOCK";
                    gotoxy(29, 7);
                    cout << "---------------";

                    gotoxy(23, 10);
                    cout << "INGRESE EL CODIGO DEL PRODUCTO: ";
                    int codigo;
                    cin >> codigo;

                    int posicion = archivoTanque.buscarRegistro(codigo);
                    tanque = archivoTanque.leerRegistro(posicion);
                    cls();
                    cabecera();
                    tanque.mostrar();
                    system("pause");
                    cls();
                    cabecera();
                    int respuesta;
                    cout << "DESEA ANIADIR STOCK A ESTE PRODUCTO?(1-SI / 2-NO) ";
                    cin >> respuesta;
                    if(respuesta==1){
                        cout << "INGRESE LA CANTIDAD: ";
                        int cantidad;
                        cin >> cantidad;
                        tanque.setStock((tanque.getStock() + cantidad));
                        archivoTanque.modificarStock(tanque, posicion);
                        cls();
                        cabecera();
                        tanque = archivoTanque.leerRegistro(posicion);
                        tanque.mostrar();
                        system("pause");
                    }
                    break;
                }

                case 5: {
                    int Id, pos;
                    cout << "INGRESE EL ID A BUSCAR: ";
                    cin >> Id;
                    pos = archivoTanque.buscarRegistro(Id);
                    tanque = archivoTanque.leerRegistro(pos);
                    tanque.mostrar();
                    cout << "DESEA DAR DE BAJA ESTE REGISTRO? (s / n): ";
                    cin >> respuesta;
                    if(respuesta == 's' || respuesta == 'S'){
                        tanque.setEstado(false);
                    }
                    else{
                        break;
                    }
                    if(archivoTanque.modificarRegistro(tanque, pos)){
                        cout << "BAJA EXITOSA..." << endl;
                        system("pause");
                    }
                    else{
                        cout << "ERROR, NO SE HA REALIZADO LA BAJA..." << endl;
                    }
                    system("pause");
                    break;
                }

                case 0:
                    opcion = 0;
                    break;

                default:
                    break;
             }
        }
}


/// MENU CLIENTES
void Menu::Clientes(){
    opcion = -1;

    while(opcion!=0){

        cabecera();

        gotoxy (2,6);
        cout<<"MENU ADMINISTRADOR CLIENTES PAISES";
        gotoxy (2,7);
        cout<<"------------------";
        gotoxy (2,10);
        cout<<"INGRESE UNA OPCION: ";

        gotoxy (2,13);
        cout<<"1 - ALTA DE CLIENTE PAIS: ";
        gotoxy (2,14);
        cout<<"2 - LISTAR CLIENTES PAISES: ";
        gotoxy (2,15);
        cout<<"3 - MODIFICACION DE CLIENTE PAIS: ";
        gotoxy (2,16);
        cout<<"4 - BAJA DE CLIENTE PAIS: ";
        gotoxy (2,17);
        cout<<"0 - VOLVER ATRAS: ";
        gotoxy (2,18);
        cout<<"->: ";
        cin>>opcion;
        system("cls");

            switch(opcion){

                case 1:
                    altaCliente();
                    break;

                case 2:
                    listarClientes();
                    break;

                case 3:
                    modificarCliente();
                    break;

                case 4:
                    eliminarCliente();
                    break;

                case 0:
                    opcion = 0;
                    break;

                default:
                    break;
             }
        }

}


/// ALTA CLIENTE
void Menu::altaCliente(){

    Pais reg;
    ArchivoPais ArchPais;
    int Id;
    Id = ArchPais.contarRegistros();
    reg.cargar(Id);
    if(ArchPais.grabarRegistro(reg)){
        cout << "ALTA EXITOSA...";
        system("pause");
    } else {
        cout << "NO SE HA PODIDO GRABAR EL REGISTRO.";
        system("pause");
    }
}


/// LISTAR CLIENTES
void Menu::listarClientes(){

    ArchivoPais ArchPais;
    int cant = ArchPais.contarRegistros();
    Pais *pais = new Pais[cant];

    for(int i=0;i<cant;i++){
        pais[i] = ArchPais.leerRegistro(i);
    }

    for(int j=0;j<cant;j++){
        if(pais[j].getEstado() == true){
            cabecera();
            pais[j].mostrar();
            cout<<endl;
            system("pause");
            cls();
        }
    }
}


/// MODIFICAR CLIENTE
void Menu::modificarCliente(){

    Pais reg;
    ArchivoPais ArchPais;
    char respuesta;
    char dato[30];
    int Id;

    cout << "INGRESE EL ID A BUSCAR: ";
    cin >> Id;

    int pos = ArchPais.buscarRegistro(Id);
    reg = ArchPais.leerRegistro(pos);
    reg.mostrar();

    if(reg.getEstado()==false){
        cout << "REGISTRO DADO DE BAJA, NO SE PUEDE MODIFICAR..." << endl;
        system("pause");
        return;
    }
    cout << "DESEA MODIFICAR ESTE REGISTRO? (s / n): ";
    cin >> respuesta;
    if(respuesta == 's' || respuesta == 'S'){
        cout << "MODIFICAR CLAVE? (s / n): ";
        cin >> respuesta;
        if(respuesta == 's' || respuesta == 'S'){
            cout << "INGRESE NUEVA CLAVE: ";
            cin >> dato;
            reg.setClave(dato);
        }

        cout << "MODIFICAR DESCRIPCION? (s / n): ";
        cin >> respuesta;
        if(respuesta == 's' || respuesta == 'S'){
            cout << "INGRESE NUEVA DESCRIPCION: ";
            cin >> dato;
            reg.setDescripcion(dato);
        }
    }
    else{
        return;
    }
    if(ArchPais.modificarRegistro(reg, pos)){
        cout << "MODIFICACION EXITOSA..." << endl;
    }
    else{
        cout << "ERROR, NO SE HA REALIZADO LA MODIFICACION..." << endl;
    }
    system("pause");
}


/// ELIMINAR CLIENTE
void Menu::eliminarCliente(){

    Pais reg;
    ArchivoPais ArchPais;

    int Id;
    char respuesta;

    cout << "INGRESE EL ID A BUSCAR: ";
    cin >> Id;
    int pos = ArchPais.buscarRegistro(Id);
    reg = ArchPais.leerRegistro(pos);
    reg.mostrar();
    cout << "DESEA DAR DE BAJA ESTE REGISTRO? (s / n): ";
    cin >> respuesta;
    if(respuesta == 's' || respuesta == 'S'){
        reg.setEstado(false);
    }
    else{
        exit(-1);
    }
    if(ArchPais.modificarRegistro(reg, pos)){
        cout << "BAJA EXITOSA..." << endl;
        system("pause");
    }
    else{
        cout << "ERROR, NO SE HA REALIZADO LA BAJA..." << endl;
    }
    system("pause");
}


/// MENU REPORTES
void Menu::Reportes(){

    opcion = -1;

    while(opcion!=0){

        cabecera();

        gotoxy (2,6);
        cout<<"REPORTES";
        gotoxy (2,7);
        cout<<"------------------";
        gotoxy (2,10);
        cout<<"INGRESE UNA OPCION: ";

        gotoxy (2,13);
        cout<<"1 - VER FACTURAS";
        gotoxy (2,14);
        cout<<"2 - BUSCAR FACTURAS";
        gotoxy (2,15);
        cout<<"3 - RANKING DE CLIENTES";
        gotoxy (2,16);
        cout<<"4 - RANKING DE PRODUCTOS";
        gotoxy (2,17);
        cout<<"0 - MENU ANTERIOR ";
        gotoxy (2,27);
        cout<<"->: ";
        cin>>opcion;
        system("cls");

            switch(opcion){

                case 1:
                    mostrarFacturas();
                    break;

                case 2:
                    buscarFacturas();
                    break;

                case 3:
                    rankingClientes();
                    break;

                case 4:
                    rankingProductos();
                    break;

                case 0:
                    break;

                default:
                    break;
             }
        }
}


/// MOSTRAR FACTURAS
void Menu::mostrarFacturas() {
    ArchivoVenta archivoVenta;
    ArchivoDetalleVenta archivoDetalle;

    int cantidadVentas = archivoVenta.contarRegistros();
    Venta *ventas = new Venta[cantidadVentas];

    for (int i = 0; i < cantidadVentas; ++i) {
        ventas[i] = archivoVenta.leerRegistro(i);
    }

    int cantidadDetalles = archivoDetalle.contarTotalRegistros();
    DetalleVenta *detalles = new DetalleVenta[cantidadDetalles];

    for (int i = 0; i < cantidadDetalles; ++i) {
        detalles[i] = archivoDetalle.leerRegistro(i);
    }

    for (int i = 0; i < cantidadVentas; ++i) {
        cabecera();

        Fecha fecha = ventas[i].getFecha();

        gotoxy(32,5);
        fecha.Mostrar();

        gotoxy(4,6);
        cout << "CLIENTE: " << ventas[i].getCliente();
        cout << " ---- ";
        cout << "ITEMS: " << ventas[i].getCantidadItems();
        cout << " ---- ";
        cout << "TOTAL: u$d" << ventas[i].getMontoTotal();
        cout << " ---- ";
        cout << "ID VENTA: " << ventas[i].getId();
        cout << endl;
        cout << endl;
        int contadorScreen = 0;

        for (int j = 0; j < cantidadDetalles; ++j) {
            if (detalles[j].getIdVenta() == ventas[i].getId()) {
                cout << "TIPO PRODUCTO: " << detalles[j].gettipoProducto() << "\t";
                cout << "DESCRIPCION: " << detalles[j].getDescripcion() << "\t";
                cout << "ID PRODUCTO: " << detalles[j].getIdProducto() << endl;
                cout << "PRECIO UNITARIO: u$d" << detalles[j].getPrecioUnitario() << "\t";
                cout << "CANTIDAD: " << detalles[j].getCantidad() << "\t";
                cout << "PRECIO TOTAL: u$d" << detalles[j].getPrecioTotal() << endl;
                cout << "..................................................." << endl;
                contadorScreen++;
                if(contadorScreen%4==0){
                        system("pause");
                        system("cls");
                        cabecera();
                        cout << endl;
                }
            }
        }
        system("pause");
        cls();
    }
    delete[] ventas;
    delete[] detalles;
}


/// BUSCAR FACTURAS
void Menu::buscarFacturas(){

    ArchivoVenta archivoVenta;
    ArchivoDetalleVenta archivoDetalle;
    char nombre[30];
    cabecera();
    gotoxy(20,10);
    cout << "INGRESE EL NOMBRE DEL CLIENTE: ";
    cin >> nombre;

    int cantidadVentas = archivoVenta.contarRegistros();
    Venta *ventas = new Venta[cantidadVentas];

    for (int i = 0; i < cantidadVentas; ++i) {
        ventas[i] = archivoVenta.leerRegistro(i);
    }

    int cantidadDetalles = archivoDetalle.contarTotalRegistros();
    DetalleVenta *detalles = new DetalleVenta[cantidadDetalles];

    for (int i = 0; i < cantidadDetalles; ++i) {
        detalles[i] = archivoDetalle.leerRegistro(i);
    }
    cls();
    for (int i = 0; i < cantidadVentas; ++i) {
        if (strcmp(ventas[i].getCliente(), nombre) == 0){

            Fecha fecha = ventas[i].getFecha();

            cabecera();

            gotoxy(32,5);
            fecha.Mostrar();

            gotoxy(4,6);
            cout << "CLIENTE: " << ventas[i].getCliente();
            cout << " ---- ";
            cout << "ITEMS: " << ventas[i].getCantidadItems();
            cout << " ---- ";
            cout << "TOTAL: " << ventas[i].getMontoTotal();
            cout << " ---- ";
            cout << "ID VENTA: " << ventas[i].getId();
            cout << endl;
            cout << endl;
            int contadorScreen = 0;

            for (int j = 0; j < cantidadDetalles; ++j) {
                if (detalles[j].getIdVenta() == ventas[i].getId()) {
                    cout << "TIPO PRODUCTO: " << detalles[j].gettipoProducto() << "\t";
                    cout << "DESCRIPCION: " << detalles[j].getDescripcion() << "\t";
                    cout << "ID PRODUCTO: " << detalles[j].getIdProducto() << endl;
                    cout << "PRECIO UNITARIO: u$d" << detalles[j].getPrecioUnitario() << "\t";
                    cout << "CANTIDAD: " << detalles[j].getCantidad() << "\t";
                    cout << "PRECIO TOTAL: u$d" << detalles[j].getPrecioTotal() << endl;
                    cout << "..................................................." << endl;
                    contadorScreen++;
                    if(contadorScreen%4==0){
                        system("pause");
                        system("cls");
                        cabecera();
                        cout << endl;
                    }
                }
            }
            system("pause");
            cls();
        }
    }
    delete[] ventas;
    delete[] detalles;
}


/// RANKING DE CLIENTES
void Menu::rankingClientes() {
    Pais pais;
    ArchivoPais archivoPais;
    ArchivoVenta archivoVenta;

    int cantidadClientes = archivoPais.contarRegistros();
    STRClientes *ranking = new STRClientes[cantidadClientes];

    for (int i = 0; i < cantidadClientes; i++) {
        pais = archivoPais.leerRegistro(i);
        ranking[i].setNombre(pais.getNombrePais());
        ranking[i].setTotalGastado(0);
    }

    int cantidadVentas = archivoVenta.contarRegistros();
    Venta *ventas = new Venta[cantidadVentas];

    for (int j = 0; j < cantidadVentas; j++) {
        ventas[j] = archivoVenta.leerRegistro(j);
        for (int k = 0; k < cantidadClientes; k++) {
            if (strcmp(ventas[j].getCliente(), ranking[k].getNombre()) == 0) {
                ranking[k].setTotalGastado(ranking[k].getTotalGastado() + ventas[j].getMontoTotal());
            }
        }
    }

    for (int a = 0; a < cantidadClientes - 1; a++) {
        for (int b = 0; b < cantidadClientes - a - 1; b++) {
            if (ranking[b].getTotalGastado() < ranking[b + 1].getTotalGastado()) {
                STRClientes aux = ranking[b];
                ranking[b] = ranking[b + 1];
                ranking[b + 1] = aux;
            }
        }
    }

    cls();
    for (int l = 0; l < cantidadClientes; l++) {

        cabecera();
        gotoxy(32, 10);
        cout << "CLIENTE: " << ranking[l].getNombre() << endl;
        gotoxy(24, 12);
        cout << "TOTAL u$d EN COMPRAS: u$d" << ranking[l].getTotalGastado() << endl;
        cout << endl << endl << endl << endl << endl << endl;
        system("pause");
    }

    delete[] ranking;
    delete[] ventas;
}


/// RANKING DE PRODUCTOS
void Menu::rankingProductos(){
    DetalleVenta detalle;
    ArchivoDetalleVenta archivoDetalle;

    int cantidad = archivoDetalle.contarTotalRegistros();
    StockProducto *ranking = new StockProducto[cantidad];

    for(int j = 0; j < cantidad; j++){
        ranking[j].setTipo("Nada");
        ranking[j].setNombre("Nada");
        ranking[j].setStock(0);
        ranking[j].setId(-1);
    }

    for(int i = 0; i < cantidad; i++){
        detalle = archivoDetalle.leerRegistro(i);
        bool esta = false;

        for(int k = 0; k < cantidad; k++){
            if (strcmp(ranking[k].getNombre(), detalle.getDescripcion()) == 0) {
                ranking[k].setStock(ranking[k].getStock() + detalle.getCantidad());
                esta = true;
                break;
            }
        }

        if (!esta) {
            for(int k = 0; k < cantidad; k++){
                if (ranking[k].getId() == -1) {
                    ranking[k].setTipo(detalle.gettipoProducto());
                    ranking[k].setNombre(detalle.getDescripcion());
                    ranking[k].setId(detalle.getIdProducto());
                    ranking[k].setStock(detalle.getCantidad());
                    break;
                }
            }
        }
    }

    for (int a = 0; a < cantidad - 1; a++) {
        for (int b = 0; b < cantidad - a - 1; b++) {
            if (ranking[b].getStock() < ranking[b + 1].getStock()) {
                StockProducto aux = ranking[b];
                ranking[b] = ranking[b + 1];
                ranking[b + 1] = aux;
            }
        }
    }

    cls();
    for (int l = 0; l < cantidad; l++) {
        if((ranking[l].getId() >= 0)&&(strcmp(ranking[l].getTipo(), "SIN STOCK.") != 0)){
            cabecera();
            gotoxy(32, 6);
            cout << "PRODUCTO: " << ranking[l].getTipo() << endl;
            gotoxy(29, 10);
            cout << "NOMBRE: " << ranking[l].getNombre() << endl;
            gotoxy(29, 12);
            cout << "ID PRODUCTO: " << ranking[l].getId() << endl;
            gotoxy(29, 14);
            cout << "UNIDADES VENDIDAS: " << ranking[l].getStock() << endl;
            cout << endl << endl << endl << endl << endl << endl;
            system("pause");
        }
    }
    delete[] ranking;
}


///===========================================================================================================================///
///===========================================================================================================================///


/// MENU PRINCIPAL PAIS
void Menu::menuPrincipalPais(Pais reg){
    cls();
    int opcion = -1;
    system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
    system("COLOR 70"); //SE DA UN COLOR DE FONDO Y COLOR A LAS LETRAS
    dibujarCuadro(0,0,78,24); //SE DIBUJA EL CUADRO PRINCIPAL
    dibujarCuadro(1,1,77,3); //SE DIBUJA EL CUADRO DEL TITULO
    gotoxy(22,2);
    cout<<"SGA - SISTEMA GESTION ARMAMENTISTICO";
    gotoxy(29, 3);
    cout << "PROGRAMANDO TU DEFENSA" << endl;

    gotoxy (2,6);
    cout<<"MENU CLIENTE";
    gotoxy (2,7);
    cout<<"------------------";
    gotoxy (2,10);
    cout<<"INGRESE UNA OPCION: ";

    gotoxy (2,13);
    cout<<"1 - SOLICITUD DE ADQUISICIONES: ";
    gotoxy (2,14);
    cout<<"2 - CONSULTA DE DINERO EN CUENTA: ";
    gotoxy (2,15);
    cout<<"3 - INGRESO DE DINERO EN CUENTA: ";
    gotoxy (2,16);
    cout<<"0 - SALIR DEL PROGRAMA: ";
    gotoxy (2,17);
    cout<<"->: ";
    cin>>opcion;

        switch(opcion){

            case 1:
                Solicitud(reg);   /// Compra de armamento (linea 1017)
                break;

            case 2:
                ConsultaDinero(reg);
                break;

            case 3:
                IngresoDinero(reg);
                break;

            case 0:
                return;

            default:
                break;
        }
}


/// CONSULTA DE DINERO
void Menu::ConsultaDinero(Pais reg){
    cls();
    cabecera();
    ArchivoPais archivo;

    int posicion = archivo.buscarRegistro(reg.getId());
    reg = archivo.leerRegistro(posicion);

    gotoxy (25,6);
    cout<<"-----------------------------";
    cout<<endl;
    gotoxy (25,8);
    cout <<"DINERO DISPONIBLE: U$D " << reg.getDineroCaja() <<endl;
    cout<<endl;
    gotoxy (25,10);
    cout<<"-----------------------------";
    cout<<endl;
    cout<<endl;
    system("pause");
    menuPrincipalPais(reg);
}


/// INGRESO DE DINERO
void Menu::IngresoDinero(Pais reg){
    cls();
    cabecera();
    ArchivoPais archivo;
    long long saldoNuevo = 0;

    int posicion = archivo.buscarRegistro(reg.getId());
    reg = archivo.leerRegistro(posicion);

    gotoxy (25,6);
    cout<<"-----------------------------";
    cout<<endl;
    gotoxy (28,8);
    cout<<"SALDO ACTUAL: U$D"<< setprecision(0) << reg.getDineroCaja() <<endl;
    cout<<endl;
    gotoxy (25,10);
    cout<<"-----------------------------";

    gotoxy (20,12);
    cout<<"MONTO QUE DESEA INGRESAR A SU CUENTA: U$D ";
    cin>> saldoNuevo;
    saldoNuevo = saldoNuevo + reg.getDineroCaja(); ///Carga del reg en memoria con el valor de saldo a agregar.

    reg.setDineroCaja(saldoNuevo); ///Set del saldo del reg en memoria.

    archivo.modificarRegistro(reg,posicion);/// Modificar el saldo del registro en el archivo.
    cout<<endl;
    reg = archivo.leerRegistro(posicion);

    gotoxy (28,15);
    cout<<"SALDO ACTUAL: U$D " << setprecision(0) << reg.getDineroCaja() <<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    system("pause");
    menuPrincipalPais(reg);
}


/// COMPRA DE ARMAMENTO
void Menu::Solicitud(Pais &reg){
    cls();
    cabecera();
    int cuantos;

    gotoxy (22,6);
    cout << "CUANTOS PRODUCTOS VA A COMPRAR: ";
    cin>>cuantos;
    cout<<endl;

///-------
    /// Verificando stock Misil
    ArchivoMisil archivoMisil;
    Misil misil;

    int tamanioMisil = archivoMisil.contarRegistros();
    StockProducto *productosMisil = new StockProducto[tamanioMisil];

    for (int i = 0; i < tamanioMisil; i++) {
        misil = archivoMisil.leerRegistro(i);
        productosMisil[i].setId(misil.getId());
        productosMisil[i].setStock(misil.getStock());
    }

        /// Verificando stock Avion
    ArchivoAvion archivoAvion;
    Avion avion;

    int tamanioAvion = archivoAvion.contarRegistros();
    StockProducto *productosAvion = new StockProducto[tamanioAvion];

    for (int i = 0; i < tamanioAvion; i++) {
        avion = archivoAvion.leerRegistro(i);
        productosAvion[i].setId(avion.getId());
        productosAvion[i].setStock(avion.getStock());
    }

        /// Verificando stock Buque
   ArchivoBuque archivoBuque;
   Buque buque;

    int tamanioBuque = archivoBuque.contarRegistros();
    StockProducto *productosBuque = new StockProducto[tamanioBuque];

    for (int i = 0; i < tamanioBuque; i++) {
        buque = archivoBuque.leerRegistro(i);
        productosBuque[i].setId(buque.getId());
        productosBuque[i].setStock(buque.getStock());
    }

        /// Verificando stock Tanque
   ArchivoTanque archivoTanque;
   Tanque tanque;

    int tamanioTanque = archivoTanque.contarRegistros();
    StockProducto *productosTanque = new StockProducto[tamanioTanque];

    for (int i = 0; i < tamanioTanque; i++) {
        tanque = archivoTanque.leerRegistro(i);
        productosTanque[i].setId(tanque.getId());
        productosTanque[i].setStock(tanque.getStock());
    }
///-------

    DetalleVenta *vecDetalle = new DetalleVenta[cuantos];
    float dineroAcumulado = 0;
    for(int i = 0; i < cuantos; i++){

        cls();
        cabecera();
        gotoxy (25,6);
        cout << "SELECCIONE SU ARMAMENTO";
        gotoxy (25,8);
        cout << "1 - MISILES";
        gotoxy (25,10);
        cout << "2 - AVIONES";
        gotoxy (25,12);
        cout << "3 - BUQUES";
        gotoxy (25,14);
        cout << "4 - TANQUES";
        gotoxy (25,16);
        cout << "5 - CANCELAR";
        gotoxy (25,18);
        cout << "->  ";
        cin >> opcion;

        switch(opcion){

            case 1:
                comprarMisil(reg, vecDetalle[i], dineroAcumulado, productosMisil, tamanioMisil);
                break;

            case 2:
                comprarAvion(reg, vecDetalle[i], dineroAcumulado, productosAvion, tamanioAvion);
                break;

            case 3:
                comprarBuque(reg, vecDetalle[i], dineroAcumulado, productosBuque, tamanioBuque);
                break;

            case 4:
                comprarTanque(reg, vecDetalle[i], dineroAcumulado, productosTanque, tamanioTanque);
                break;

            case 5:
                delete[] vecDetalle;
                delete[] productosMisil;
                delete[] productosAvion;
                delete[] productosBuque;
                delete[] productosTanque;
                menuPrincipalPais(reg);
                break;
        }
    }

    /// Confirmar Compra.
    cls();
    cabecera();
    int num;
    gotoxy(10,8);
    cout << "DESEA CONFIRMAR SU COMPRA? (1-SI / 2-NO)";
    cin >> num;
    if(num==1){
        confirmarCompra(reg, dineroAcumulado, vecDetalle, cuantos, productosMisil, productosAvion, productosBuque, productosTanque);
    } else {
        delete[] vecDetalle;
        delete[] productosMisil;
        delete[] productosAvion;
        delete[] productosBuque;
        delete[] productosTanque;
        menuPrincipalPais(reg);
    }

    delete[] vecDetalle;
    delete[] productosMisil;
    delete[] productosAvion;
    delete[] productosBuque;
    delete[] productosTanque;
    system("pause");
    menuPrincipalPais(reg);
}


/// CONFIRMAR COMPRA
void Menu::confirmarCompra(Pais reg, float TotalDeVenta, DetalleVenta *detalle, int cantidadRegistros, StockProducto *productosMisil,
                                        StockProducto *productosAvion, StockProducto *productosBuque, StockProducto *productosTanque){

        Fecha _fecha;

        Venta venta;
        ArchivoVenta archivoVenta;
        ArchivoDetalleVenta archivoDetalle;

        ArchivoPais archivoPais;
        Misil misil;
        ArchivoMisil archivoMisil;
        Avion avion;
        ArchivoAvion archivoAvion;
        Buque buque;
        ArchivoBuque archivoBuque;
        Tanque tanque;
        ArchivoTanque archivoTanque;

        /// Generando, guardando y generando idVenta.
        int numeroDeVenta;
        if(archivoVenta.contarRegistros() <= 0){
            numeroDeVenta = 0;
        } else {
            numeroDeVenta = archivoVenta.contarRegistros();
        }
        venta.setId(numeroDeVenta);

        venta.setCliente(reg.getNombrePais());

        venta.setFecha(_fecha);
        venta.setCantidadItems(cantidadRegistros);
        venta.setMontoTotal(TotalDeVenta);

        if(archivoVenta.grabarRegistro(venta)){

            /// Modificando el IdVenta del vector DetalleVentas
            for (int i = 0; i < cantidadRegistros; ++i) {
                detalle[i].setId(i+1); ///*
                detalle[i].setIdVenta(venta.getId()); ///*
            }

            if(archivoDetalle.grabarRegistros(detalle, cantidadRegistros)){
                ///modificando el stock de Misil.
                int cantidad = archivoMisil.contarRegistros();
                for(int i=0;i<cantidad;i++){
                    misil = archivoMisil.leerRegistro(i);
                    for(int j=0;j<cantidad;j++){
                        if(productosMisil[j].getId()== misil.getId()){
                            misil.setStock(productosMisil[j].getStock());
                            archivoMisil.ModificarEnDisco(misil, i);
                        }
                    }
                }

                ///modificando el stock de Avion.
                cantidad = archivoAvion.contarRegistros();
                for(int i=0;i<cantidad;i++){
                    avion = archivoAvion.leerRegistro(i);
                    for(int j=0;j<cantidad;j++){
                        if(productosAvion[j].getId()== avion.getId()){
                            avion.setStock(productosAvion[j].getStock());
                            archivoAvion.modificarRegistro(avion, i);
                        }
                    }
                }

                ///modificando el stock de Buque.
                cantidad = archivoBuque.contarRegistros();
                for(int i=0;i<cantidad;i++){
                    buque = archivoBuque.leerRegistro(i);
                    for(int j=0;j<cantidad;j++){
                        if(productosBuque[j].getId()== buque.getId()){
                            buque.setStock(productosBuque[j].getStock());
                            archivoBuque.modificarRegistro(buque, i);
                        }
                    }
                }

                ///modificando el stock de Tanque.
                cantidad = archivoTanque.contarRegistros();
                for(int i=0;i<cantidad;i++){
                    tanque = archivoTanque.leerRegistro(i);
                    for(int j=0;j<cantidad;j++){
                        if(productosTanque[j].getId()== tanque.getId()){
                            tanque.setStock(productosTanque[j].getStock());
                            archivoTanque.modificarRegistro(tanque, i);
                        }
                    }
                }

                ///modificando la billetera del pais
                reg.setDineroCaja(reg.getDineroCaja() - TotalDeVenta);
                int posPais = archivoPais.buscarRegistro(reg.getId());
                archivoPais.modificarRegistro(reg,posPais);

                cls();
                cabecera();
                gotoxy(10,8);
                cout << "SE HA GUARDADO SU COMPRA SATISFACTORIAMENTE.";
                cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;

            } else {
                cls();
                cabecera();
                gotoxy(10,8);
                cout << "LO SENTIMOS, NO HEMOS PODIDO CONFIRMAR SU COMPRA.";
            }
        } else {
            cls();
            cabecera();
            gotoxy(10,8);
            cout << "LO SENTIMOS, NO HEMOS PODIDO CONFIRMAR SU COMPRA.";
        }
}


/// COMPRAR MISIL
void Menu::comprarMisil(Pais &reg, DetalleVenta &detalle, float &dineroAcumulado, StockProducto *productosMisil, int tamanioMisil){
    cls();
    cabecera();
    Misil misil;
    ArchivoMisil archivo;

    int _id;
    cout << "INGRESE EL ID DEL MISIL QUE DESEA: ";
    cin >> _id;
    int posicion = archivo.buscarRegistro(_id);

    cls();
    cabecera();
    char respuesta;
    misil = archivo.leerRegistro(posicion);

    if(misil.getEstado() == 1){
        misil.mostrar();

        cout << "DESEA AGREGAR ESTE ARTICULO? (S/N)";
        cin >> respuesta;

        int cantidad;
        cout << "INGRESE LA CANTIDAD QUE DESEA: ";
        cin >> cantidad;

        if(reg.getDineroCaja()> dineroAcumulado){

            if((respuesta=='S')||(respuesta == 's')){

                for(int j=0; j<tamanioMisil; j++){

                    if(productosMisil[j].getId() == _id){

                        if((productosMisil[j].getStock() >= cantidad) && (productosMisil[j].getStock() > 0)){
                            productosMisil[j].setStock(productosMisil[j].getStock() - cantidad);

                            float totalItem = cantidad * misil.getPrecio();

                            if(totalItem <= (reg.getDineroCaja()- dineroAcumulado)){

                                dineroAcumulado += totalItem;
                                detalle.setIdProducto(misil.getId());
                                detalle.setPrecioUnitario(misil.getPrecio());
                                detalle.setCantidad(cantidad);
                                detalle.setDescripcion(misil.getNombre());
                                detalle.setPrecioTotal(totalItem);
                                char descripAuxMisil[20] = "MISIL";
                                detalle.setTipoProducto(descripAuxMisil);

                            } else {
                                cout << "NO DISPONE DE SALDO SUFICIENTE" << endl;
                                system("pause");
                                detalle = DetalleVenta();
                            }
                        } else {
                            cout << "NO HAY STOCK SUFICIENTE PARA LA CANTIDAD QUE DESEA.";
                            system("pause");
                        }
                    }
                }
            } else {
                detalle = DetalleVenta();
            }
        }

    } else {
        cout << "PRODUCTO NO DISPONIBLE." << endl;
        system("pause");
    }
}


/// COMPRAR AVION
void Menu::comprarAvion(Pais &reg, DetalleVenta &detalle, float &dineroAcumulado, StockProducto *productosAvion, int tamanioAvion){

    cls();
    cabecera();
    Avion avion;
    ArchivoAvion archivo;

    int _id;
    cout << "INGRESE EL ID DEL AVION QUE DESEA: ";
    cin >> _id;
    int posicion = archivo.buscarRegistro(_id);

    cls();
    cabecera();
    char respuesta;
    avion = archivo.leerRegistro(posicion);

    if(avion.getEstado() == 1){
        avion.mostrar();

        cout << "DESEA AGREGAR ESTE ARTICULO? (S/N)";
        cin >> respuesta;

        int cantidad;
        cout << "INGRESE LA CANTIDAD QUE DESEA: ";
        cin >> cantidad;

        if(reg.getDineroCaja()> dineroAcumulado){

            if((respuesta=='S')||(respuesta == 's')){

                for(int j=0; j<tamanioAvion; j++){

                    if(productosAvion[j].getId() == _id){

                        if((productosAvion[j].getStock() >= cantidad) && (productosAvion[j].getStock() > 0)){
                            productosAvion[j].setStock(productosAvion[j].getStock() - cantidad);

                            float totalItem = cantidad * avion.getPrecio();

                            if(totalItem <= (reg.getDineroCaja()- dineroAcumulado)){
                                dineroAcumulado += totalItem;
                                detalle.setIdProducto(avion.getId());
                                detalle.setPrecioUnitario(avion.getPrecio());
                                detalle.setCantidad(cantidad);
                                detalle.setDescripcion(avion.getNombre());
                                detalle.setPrecioTotal(totalItem);
                                char descripAuxAvion[20] = "AVION";
                                detalle.setTipoProducto(descripAuxAvion);

                            } else {
                                cout << "NO DISPONE DE SALDO SUFICIENTE" << endl;
                                system("pause");
                                detalle = DetalleVenta();
                            }
                        } else {
                            cout << "NO HAY STOCK SUFICIENTE PARA LA CANTIDAD QUE DESEA.";
                            system("pause");
                        }
                    }
                }
            } else {
                detalle = DetalleVenta();
            }
        }
    } else {
        cout << "PRODUCTO NO DISPONIBLE." << endl;
        system("pause");
    }
}


/// COMPRAR BUQUE
void Menu::comprarBuque(Pais &reg, DetalleVenta &detalle, float &dineroAcumulado, StockProducto *productosBuque, int tamanioBuque){

    cls();
    cabecera();
    Buque buque;
    ArchivoBuque archivo;

    int _id;
    cout << "INGRESE EL ID DEL AVION QUE DESEA: ";
    cin >> _id;
    int posicion = archivo.buscarRegistro(_id);

    cls();
    cabecera();
    char respuesta;
    buque = archivo.leerRegistro(posicion);

    if(buque.getEstado() == 1){
        buque.mostrar();

        cout << "DESEA AGREGAR ESTE ARTICULO? (S/N)";
        cin >> respuesta;

        int cantidad;
        cout << "INGRESE LA CANTIDAD QUE DESEA: ";
        cin >> cantidad;

        if(reg.getDineroCaja()> dineroAcumulado){

            if((respuesta=='S')||(respuesta == 's')){

                for(int j=0; j<tamanioBuque; j++){

                    if(productosBuque[j].getId() == _id){

                        if((productosBuque[j].getStock() >= cantidad) && (productosBuque[j].getStock() > 0)){
                            productosBuque[j].setStock(productosBuque[j].getStock() - cantidad);

                            float totalItem = cantidad * buque.getPrecio();

                            if(totalItem <= (reg.getDineroCaja()- dineroAcumulado)){

                                dineroAcumulado += totalItem;
                                detalle.setIdProducto(buque.getId());
                                detalle.setPrecioUnitario(buque.getPrecio());
                                detalle.setCantidad(cantidad);
                                detalle.setDescripcion(buque.getNombre());
                                detalle.setPrecioTotal(totalItem);
                                char descripAuxBuque[20] = "BUQUE";
                                detalle.setTipoProducto(descripAuxBuque);

                            } else {
                                cout << "NO DISPONE DE SALDO SUFICIENTE" << endl;
                                system("pause");
                                detalle = DetalleVenta();
                            }
                        } else {
                            cout << "NO HAY STOCK SUFICIENTE PARA LA CANTIDAD QUE DESEA.";
                            system("pause");
                        }
                    }
                }
            } else {
                detalle = DetalleVenta();
            }
        }
    } else {
        cout << "PRODUCTO NO DISPONIBLE." << endl;
        system("pause");
    }
}


/// COMPRAR TANQUE
void Menu::comprarTanque(Pais &reg, DetalleVenta &detalle, float &dineroAcumulado, StockProducto *productosTanque, int tamanioTanque){

    cls();
    cabecera();
    Tanque tanque;
    ArchivoTanque archivo;

    int _id;
    cout << "INGRESE EL ID DEL AVION QUE DESEA: ";
    cin >> _id;
    int posicion = archivo.buscarRegistro(_id);

    cls();
    cabecera();
    char respuesta;
    tanque = archivo.leerRegistro(posicion);

    if(tanque.getEstado() == 1){
        tanque.mostrar();

        cout << "DESEA AGREGAR ESTE ARTICULO? (S/N)";
        cin >> respuesta;

        int cantidad;
        cout << "INGRESE LA CANTIDAD QUE DESEA: ";
        cin >> cantidad;

        if(reg.getDineroCaja()> dineroAcumulado){

            if((respuesta=='S')||(respuesta == 's')){

                for(int j=0; j<tamanioTanque; j++){

                    if(productosTanque[j].getId() == _id){

                        if((productosTanque[j].getStock() >= cantidad) && (productosTanque[j].getStock() > 0)){
                            productosTanque[j].setStock(productosTanque[j].getStock() - cantidad);

                            float totalItem = cantidad * tanque.getPrecio();

                            if(totalItem <= (reg.getDineroCaja()- dineroAcumulado)){

                                dineroAcumulado += totalItem;
                                detalle.setIdProducto(tanque.getId());
                                detalle.setPrecioUnitario(tanque.getPrecio());
                                detalle.setCantidad(cantidad);
                                detalle.setDescripcion(tanque.getNombre());
                                detalle.setPrecioTotal(totalItem);
                                char descripAuxTanque[20] = "TANQUE";
                                detalle.setTipoProducto(descripAuxTanque);

                            } else {
                                cout << "NO DISPONE DE SALDO SUFICIENTE" << endl;
                                system("pause");
                                detalle = DetalleVenta();
                            }
                        } else {
                            cout << "NO HAY STOCK SUFICIENTE PARA LA CANTIDAD QUE DESEA.";
                            system("pause");
                        }
                    }
                }
            } else {
                detalle = DetalleVenta();
            }
        }
    } else {
        cout << "PRODUCTO NO DISPONIBLE." << endl;
        system("pause");
    }
}



