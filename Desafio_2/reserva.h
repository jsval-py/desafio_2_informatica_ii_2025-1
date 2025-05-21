#ifndef RESERVA_H
#define RESERVA_H

#include "Fecha.h"

class Reserva {
private:
    int codigoReserva;
    Fecha fechaEntrada;
    int duracionNoches;
    char* anotaciones;
    char* estado;

public:
    // Constructores y destructor
    Reserva();
    Reserva(int codigo, Fecha entrada, int duracion, const char* notas);
    ~Reserva();

    // Getters y setters
    int getCodigoReserva() const;
    Fecha getFechaEntrada() const;
    int getDuracionNoches() const;
    const char* getAnotaciones() const;
    const char* getEstado() const;
    void setCodigoReserva(int codigo);
    void setFechaEntrada(Fecha fecha);
    void setDuracionNoches(int duracion);
    void setAnotaciones(const char* notas);
    void setEstado(const char* est);

    // Métodos
    Fecha calcularFechaSalida();
    bool anularReserva();
};

#endif // RESERVA_H
