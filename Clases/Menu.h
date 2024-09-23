#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "Pais.h"
#include "Venta.h"
#include "DetalleVenta.h"
#include "StockProducto.h"

class Menu{
    private:
            int opcion;
    public:
            Menu(){};
            void dibujarCuadro(int x1, int y1, int x2, int y2);
            void gotoxy(int x, int y);
            void cabecera();

            bool menuOpcion(); // MENU INGRESO USERS/ADMINS
            void menuPrincipalAdmin();

            void Usuarios();
            void altaUsuario();
            void listarUsuarios();
            void modificarUsuario();
            void eliminarUsuario();

            void Stock();
            void StockMisiles();
            void StockAviones();
            void StockBuques();
            void StockTanques();

            void Clientes();
            void altaCliente();
            void listarClientes();
            void modificarCliente();
            void eliminarCliente();

            void Reportes();
            void mostrarFacturas();
            void buscarFacturas();
            void rankingClientes();
            void rankingProductos();

            void menuPrincipalPais(Pais pais);
            void ConsultaDinero(Pais pais);
            void IngresoDinero(Pais pais);
            void Solicitud(Pais &pais);
            void comprarMisil(Pais &reg, DetalleVenta &vecDetalle, float &dineroAcumulado, StockProducto *productosMisil, int tamanioMisil);
            void comprarAvion(Pais &reg, DetalleVenta &vecDetalle, float &dineroAcumulado, StockProducto *productosAvion, int tamanioAvion);
            void comprarBuque(Pais &reg, DetalleVenta &vecDetalle, float &dineroAcumulado, StockProducto *productosBuque, int tamanioBuque);
            void comprarTanque(Pais &reg, DetalleVenta &vecDetalle, float &dineroAcumulado, StockProducto *productosTanque, int tamanioTanque);
            void confirmarCompra(Pais reg, float montoTotal, DetalleVenta *vecDetalle, int cantidadRegistros, StockProducto *productosMisil,
                                 StockProducto *productosAvion, StockProducto *productosBuque, StockProducto *productosTanque);
};

#endif // MENU_H_INCLUDED
