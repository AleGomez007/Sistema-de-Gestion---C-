# include<iostream>
# include<cstdlib>
# include <cstdio>
# include<string.h>
#include "Venta.h"
using namespace std;


void Venta::mostrar(){
cout << "ID: " << id << "." << endl;
cout << "CLIENTE: " << cliente << "." << endl;
fecha.Mostrar();
cout << "CANTIDAD DE ITEMS: "<< cantidadItems << "." << endl;
cout << "MONTO TOTAL: u$d" << montoTotal << "." << endl;
cout << endl;
system("pause");
system("cls");

}
