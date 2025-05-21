#include "gestorReservas.h"

//Constructor
GestorReservas::GestorReservas() {
    // Inicializar variables necesarias
}
//Destructor
GestorReservas::~GestorReservas() {
    // Liberar recursos si es necesario
}

//Métodos
Huesped* GestorReservas::buscarHuesped(int municipio, Fecha fechaInicio, Fecha fechaFin, double precioPorNoche) {
    return nullptr;
}
bool GestorReservas::buscarReservas(Fecha fechaInicio, Fecha fechaFin) {
    return false;
}
bool GestorReservas::buscarHabitacionPorCodigo(int codigo, Fecha fecha, int noches) {
    return false;
}
Reserva* GestorReservas::realizarReserva(Huesped* huesped, Habitacion* hab, Fecha fecha, int noches, const char* anotaciones) {
    return nullptr;
}
bool GestorReservas::anularReservaPorCodigo(int codigoReserva) {
    return false;
}
Reserva* GestorReservas::consultarReservaPorAnfitrion(Anfitrion* anf, Fecha fechaInicio, Fecha fechaFin) {
    return nullptr;
}
int GestorReservas::actualizarHistorico(Fecha fechaHoy) {
    return 0;
}
