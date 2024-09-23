#ifndef MISIL_H_INCLUDED
#define MISIL_H_INCLUDED
#include "Producto.h"
class Misil : public Producto{

    private:
            int CantCabezasExplosivas, VelocidadMax, Peso, CodigoUnico;
            char TipoCombustible[30], TipoCarga[30], Tipo[30], TipoPropulsion[30], TipoGuia[30];
            bool Hipersonico;
            bool Estado;

    public:
            Misil(){};

            void setTipoPropulsion(const char* _TipoPropulsion);
            void setTipoGuia(const char* _TipoGuia);
            void setCantCabezasExplosivas(int _CantCabezasExplosivas);
            void setVelocidadMax(int _VelocidadMax);
            void setPeso(int _Peso);
            void setTipoCombustible(const char* _TipoCombustible);
            void setTipoCarga(const char* _TipoCarga);
            void setHipersonico(bool _Hipersonico);
            void setTipo(const char* _Tipo);
            void setCodigoUnico(int codigo) {CodigoUnico = codigo;}
            void setEstado(bool estado) { Estado = estado; }

            char* getTipoPropulsion();
            char* getTipoGuia();
            int getCantCabezasExplosivas();
            int getVelocidadMax();
            int getPeso();
            char* getTipoCombustible();
            char* getTipoCarga();
            bool gethipersonico();
            int getCodigoUnico() {return CodigoUnico;}
            bool getEstado() { return Estado; }

            void cargar();
            void mostrar();




};

#endif // MISIL_H_INCLUDED
