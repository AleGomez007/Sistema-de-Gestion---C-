#ifndef TANQUE_H_INCLUDED
#define TANQUE_H_INCLUDED

#include "Producto.h"

class Tanque : public Producto{

    private:
            int AlcanceOperativo, Peso, TorretaCalibre, Velocidad;
            bool Ametralladora, TorretaBlindada, AntiTanque, LargoAlcance, Ocultamiento;
            char RangoVision[30], TipoBlindaje[30], Movilidad[30], Precision[30];

    public:

            void setTipoBlindaje(const char* _TipoBlindaje);
            void setMovilidad(const char* _Movilidad);
            void setOcultamiento(bool _Ocultamiento);
            void setRangoVision(const char* _RangoVision);
            void setLargoAlcance(bool _LargoAlcance);
            void setPrecision(const char* _Precision);
            void setAntiTanque(bool _AntiTanque);
            void setVelocidad(int _Velocidad);
            void setTorretaBlindada(bool _TorretaBlindada);
            void setTorretaCalibre(int _TorretaCalibre);
            void setPeso(int _Peso);
            void setAlcanceOperativo(int _AlcanceOperativo);
            void setAmetralladora(bool _Ametralladora);

            char* getTipoBlindaje();
            char* getMovilidad();
            bool getOcultamiento();
            char* getRangoVision();
            bool getLargoAlcance();
            char* getPrecision();
            bool getAntiTanque();
            int getVelocidad();
            bool getTorretaBlindada();
            int getTorretaCalibre();
            int getPeso();
            int getAlcanceOperativo();
            bool getAmetralladora();

            void cargar();
            void mostrar();
            bool escribirEnDisco();
            bool leerDeDisco(int _CodigoUnico);


};

#endif // TANQUE_H_INCLUDED
