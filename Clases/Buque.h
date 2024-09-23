#ifndef BUQUE_H_INCLUDED
#define BUQUE_H_INCLUDED
#include "Producto.h"
class Buque : public Producto{

    private:
        int CantTorretas, VelocidadMax, Peso;
        char Tipo[30], Blindaje[30], TipoPropulsion[30], Maniobrabilidad[30];
        bool Ametralladora;

    public:
        Buque(){};

        void setTipo(const char* _Tipo);
        void setCantTorretas(int _CantTorretas);
        void setVelocidadMax(int _VelocidadMax);
        void setPeso(int _Peso);
        void setBlindaje(const char* _Blindaje);
        void setTipoPropulsion(const char* _TipoPropulsion);
        void setManiobrabilidad(const char* _Maniobrabilidad);
        void setAmetralladora(bool _Ametralladora);

        char* getTipo();
        int getCantTorretas();
        int getVelocidadMax();
        int getPeso();
        char* getBlindaje();
        char* getTipoPropulsion();
        char* getManiobrabilidad();
        bool getAmetralladora();

        void cargar();
        void mostrar();
        bool escribirEnDisco();
        bool leerDeDisco(int _CodigoUnico);


};

#endif // BUQUE_H_INCLUDED
