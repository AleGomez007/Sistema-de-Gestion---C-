#ifndef VENTA_H
#define VENTA_H
#include "Fecha.h"

class Venta
{
    private:
        int id;
        char cliente[30];
        Fecha fecha;
        int cantidadItems;
        long long montoTotal;
    public:
        void setId(int Id){id = Id;}
        void setCliente(const char *_cliente){strcpy(cliente, _cliente);}
        void setFecha(Fecha f){fecha = f;}
        void setCantidadItems(int cant){cantidadItems = cant;}
        void setMontoTotal(long long total){montoTotal = total;}

        int getId(){return id;}
        const char *getCliente(){return cliente;}
        Fecha getFecha(){return fecha;}
        int getCantidadItems(){return cantidadItems;}
        long long getMontoTotal(){return montoTotal;}
        void mostrar();
};

#endif // VENTA_H
