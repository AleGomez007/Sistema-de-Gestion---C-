#ifndef AVION_H_INCLUDED
#define AVION_H_INCLUDED
#include "Producto.h"

class Avion : public Producto{

    private:
            int VelocidadMax, CantMisiles, AlcanceOperativo;
            bool Ametralladora;
            char Tipo[30], Proposito[30], Tamanio[30], Maniobrabilidad[30];

    public:
            Avion(){};
            void setTipo(const char* _Tipo);
            void setProposito(const char* _Proposito);
            void setTamanio(const char* _Tamanio);
            void setVelocidadMax(int _VelocidadMax);
            void setManiobrabilidad(const char* _Maniobrabilidad);
            void setCantMisiles(int _CantMisiles);
            void setAmetralladora(bool _Ametralladora);
            void setAlcanceOperativo(int _AlcanceOperativo);

            char* getTipo();
            char* getProposito();
            char* getTamanio();
            int getVelocidadMax();
            char* getManiobrabilidad();
            int getCantMisiles();
            bool getAmetralladora();
            int getAlcanceOperativo();
            void cargar();
            void mostrar();
};

#endif // AVION_H_INCLUDED
