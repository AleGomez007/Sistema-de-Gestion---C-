#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED

#include "Entidad.h"
#include<cstring>

class Admin : public Entidad{
        private:
            char NombreAdmin[30];

        public:
            Admin(){};

            void setNombreAdmin(const char* _NombreAdmin);

            char* getNombreAdmin();

            void cargar(int _Id);
            void mostrar();
};

#endif // ADMIN_H_INCLUDED
