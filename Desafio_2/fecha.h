#ifndef FECHA_H
#define FECHA_H

class Fecha {
private:
    int dia;
    int mes;
    int anio;

public:
    // Constructores
    Fecha();
    Fecha(int d, int m, int a);

    // Getters y setters
    int getDia() const;
    int getMes() const;
    int getAnio() const;
    void setDia(int d);
    void setMes(int m);
    void setAnio(int a);

    // Métodos
    Fecha toString() const;
    Fecha calcularFechaSalida(int noches) const;
};

#endif // FECHA_H
