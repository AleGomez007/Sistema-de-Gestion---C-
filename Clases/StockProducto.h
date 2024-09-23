#ifndef STRSTOCKMISIL_H
#define STRSTOCKMISIL_H


class StockProducto
{
    private:
        char tipo[30], nombre[30];
        int id;
        int stock;
    public:
        void setTipo(const char * t){strcpy(tipo, t);}
        void setNombre(const char *n){strcpy(nombre, n);}
        void setId(int _id){id = _id;}
        void setStock(int cantidad){stock = cantidad;}

        const char *getTipo(){return tipo;}
        const char *getNombre(){return nombre;}
        int getId(){return id;}
        int getStock(){return stock;}

};

#endif // STRSTOCKMISIL_H
