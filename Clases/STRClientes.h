#ifndef STRCLIENTES_H
#define STRCLIENTES_H


class STRClientes
{
    private:
        char nombre[30];
        float totalGastado;
    public:
        void setNombre(const char *n){strcpy(nombre, n);}
        void setTotalGastado(float monto){totalGastado = monto;}

        char *getNombre(){return nombre;}
        int getTotalGastado(){return totalGastado;}
};

#endif // STRCLIENTES_H
