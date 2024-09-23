#ifndef ENTIDAD_H_INCLUDED
#define ENTIDAD_H_INCLUDED
#include<cstdio>

class Entidad{
        private:
            char Usuario[30], Clave[30], Descripcion[30];
            bool PropiedadAdmin, Estado;
            int Id;

        public:
            Entidad(){};

            void setClave(char* _Clave);
            void setUsuario(char* _Usuario);
            void setDescripcion(char* _Descripcion);
            void setPropiedadAdmin(bool _PropiedadAdmin);
            void setId(int _Id);
            void setEstado(bool _Estado);

            char* getUsuario();
            char* getClave();
            char* getDescripcion();
            int getId();
            bool getPropiedadAdmin();
            bool getEstado();
};

#endif // ENTIDAD_H_INCLUDED
