#ifndef DETALLEVENTA_H
#define DETALLEVENTA_H


class DetalleVenta
{
    private:
        int id, idVenta, idProducto, cantidad, tipo;
        char descripcion [50], tipoProducto[30];
        long long precioUnitario, precioTotal;

    public:
        DetalleVenta() : id(0), idVenta(0), idProducto(0), cantidad(0), precioUnitario(0), precioTotal(0){strcpy(tipoProducto, "SIN STOCK."),
        strcpy(descripcion, "SIN STOCK.");}

        void setId(int Id){id = Id;}
        void setIdVenta(int _Id){idVenta = _Id;}
        void setIdProducto(int id){idProducto = id;}
        void setCantidad(int cant){cantidad = cant;}
        void setTipo(int t){tipo = t;}
        void setDescripcion(const char *desc){strcpy(descripcion, desc);}
        void setPrecioUnitario(long long precioU){precioUnitario = precioU;}
        void setPrecioTotal(long long precioT){precioTotal = precioT;}
        void setTipoProducto(const char* _tipoProducto){strcpy(tipoProducto, _tipoProducto);}

        int getId(){return id;}
        int getIdVenta(){return idVenta;}
        int getIdProducto(){return idProducto;}
        int getCantidad(){return cantidad;}
        int getTipo(){return tipo;}
        const char *getDescripcion(){return descripcion;}
        const char *gettipoProducto(){return tipoProducto;}
        long long getPrecioUnitario(){return precioUnitario;}
        long long getPrecioTotal(){return precioTotal;}
        void mostrar();
};

#endif // DETALLEVENTA_H
