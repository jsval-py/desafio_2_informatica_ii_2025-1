#ifndef RESERVAS_H
#define RESERVAS_H

#include <string>
#include "fecha.h"

#define MAX_ID 20

class Reserva {
private:
    char idReserva[MAX_ID];      // ID único de reserva
    char idHabitacion[MAX_ID];   // ID de la habitación
    char idHuesped[MAX_ID];      // ID del huésped (número de identidad)
    Fecha fechaInicio;           // Fecha inicio reserva
    Fecha fechaFin;              // Fecha fin reserva
    double montoTotal;           // Total a pagar
    bool activa;                 // true = activa, false = cancelada

public:
    Reserva();
    Reserva(const char* idReserva, const char* idHabitacion, const char* idHuesped,
            const Fecha& fechaInicio, const Fecha& fechaFin, double montoTotal, bool activa = true);

    // Getters
    const char* getIdReserva() const;
    const char* getIdHabitacion() const;
    const char* getIdHuesped() const;
    Fecha getFechaInicio() const;
    Fecha getFechaFin() const;
    double getMontoTotal() const;

    // Métodos
    void mostrarInformacion() const;
    void cancelarReserva();
    bool estaActiva() const;
    void setActiva(bool estado);

    // Persistencia
    static int cargarReservasDeArchivo(Reserva reservas[], int maxReservas, const std::string& nombreArchivo);
    static bool actualizarReservaEnArchivo(const char* nombreArchivo, const char* idReserva, bool nuevoEstado);
};

#endif // RESERVAS_H
