#ifndef PAIS_H_INCLUDED
#define PAIS_H_INCLUDED

#include "Entidad.h"

class Pais : public Entidad{
    private:
            char NombrePais[30];
            long long DineroCaja;

    public:
            void setNombrePais(const char* _NombrePais);
            void setDineroCaja(long long _DineroCaja);

            char* getNombrePais(){return NombrePais;}
            long long getDineroCaja(){return DineroCaja;}

            void cargar(int _Id);
            void mostrar();
};

#endif // PAIS_H_INCLUDED
