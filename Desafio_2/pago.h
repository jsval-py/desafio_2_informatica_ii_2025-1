#ifndef PAGO_H
#define PAGO_H

#include "Fecha.h"

class Pago {
private:
    char* metodo;
    Fecha fechaPago;
    double monto;

public:
    // Constructores
    Pago();
    Pago(const char* met, Fecha fecha, double mon);

    // Destructor
    ~Pago();

    // Getters y setters
    const char* getMetodo() const;
    Fecha getFechaPago() const;
    double getMonto() const;
    void setMetodo(const char* met);
    void setFechaPago(Fecha fecha);
    void setMonto(double mon);

    // Métodos
    bool verificarPago();
    bool confirmarPago();
};

#endif // PAGO_H
