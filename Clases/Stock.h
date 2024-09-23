#ifndef STOCK_H
#define STOCK_H


class Stock
{
    private:
        int cantidad;
        char nombre[30];
        bool estado;

    public:

        Stock(){};

        void dibujarCuadro(int x1, int y1, int x2, int y2);
        void gotoxy(int x, int y);

        void setCantidad (int c){cantidad = c;}

        void setEstado(bool e) {estado = e;}

        int getCantidad(){return cantidad;}

        bool getEstado() {return estado;}

        void Cargar();
        void Mostrar();
};

#endif // STOCK_H
