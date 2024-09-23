#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED
#include"Fecha.h"
class Producto{

    private:
            long long Precio;
            bool Estado;
            int Stock, Id;
            char Nombre[30], PaisOrigen[30], Descripcion[100];
            Fecha FechaAlta;

    public:
            Producto(){};

            void setPrecio(long long _Precio);
            void setEstado(bool _Estado);
            void setNombre(const char* _Nombre);
            void setDescripcion(const char* _Descripcion);
            void setId(int _Id);
            void setPaisOrigen(const char* _PaisOrigen);
            void setStock(int _Stock);
            void setFecha(Fecha _Fecha);

            long long getPrecio();
            bool getEstado();
            char* getNombre();
            char* getDescripcion();
            int getId();
            char* getPaisOrigen();
            int getStock();
            Fecha getFechaAlta();
            void cargar();
            void mostrar();
};

#endif // PRODUCTO_H_INCLUDED
