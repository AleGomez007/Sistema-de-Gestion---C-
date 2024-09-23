# include<iostream>
# include<cstdlib>
# include <cstdio>
# include<string.h>
#include "DetalleVenta.h"

using namespace std;


void DetalleVenta::mostrar(){
cout << "ID: " << id <<"." <<endl;
cout << "Id Venta:" << idVenta <<"." <<endl;
cout << "Id Producto: " << idProducto <<"." <<endl;
cout << "Cantidad: " << cantidad <<"." <<endl;
cout << "Descripcion: " << descripcion <<"." <<endl;
cout << "Precio Unitario: u$d" << precioUnitario <<"." <<endl;
cout << "Precio Total Item: u$d" << precioTotal <<"." <<endl;
system("pause");
system("cls");
}
