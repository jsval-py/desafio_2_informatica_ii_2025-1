#ifndef GESTORDBH_H
#define GESTORDBH_H
#include "Fecha.h"

// Declaraciones adelantadas
class Huesped;
class Habitacion;
class Reserva;
class Anfitrion;

class GestorReservas {
public:
    // Constructor
    GestorReservas();
    //Destructor
    ~GestorReservas();

    // Métodos
    Huesped* buscarHuesped(int municipio, Fecha fechaInicio, Fecha fechaFin, double precioPorNoche);
    bool buscarReservas(Fecha fechaInicio, Fecha fechaFin);
    bool buscarHabitacionPorCodigo(int codigo, Fecha fecha, int noches);
    Reserva* realizarReserva(Huesped* huesped, Habitacion* hab, Fecha fecha, int noches, const char* anotaciones);
    bool anularReservaPorCodigo(int codigoReserva);
    Reserva* consultarReservaPorAnfitrion(Anfitrion* anf, Fecha fechaInicio, Fecha fechaFin);
    int actualizarHistorico(Fecha fechaHoy);
};
#endif // GESTORDBH_H
