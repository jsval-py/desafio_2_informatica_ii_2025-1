#include "reserva.h"

//Constructor
Reserva::Reserva() {
    codigoReserva = 0;
    fechaEntrada = Fecha(1, 1, 2000);
    duracionNoches = 0;
    anotaciones = nullptr;
    estado = nullptr;
}
Reserva::Reserva(int codigo, Fecha entrada, int duracion, const char* notas) {
    codigoReserva = codigo;
    fechaEntrada = entrada;
    duracionNoches = duracion;
    anotaciones = new char[strlen(notas) + 1];
    strcpy(anotaciones, notas);
    estado = nullptr;
}

//Destructor
Reserva::~Reserva() {
    delete[] anotaciones;
    delete[] estado;
}
//Getters y setters
int Reserva::getCodigoReserva() const {
    return codigoReserva;
}
Fecha Reserva::getFechaEntrada() const {
    return fechaEntrada;
}
int Reserva::getDuracionNoches() const {
    return duracionNoches;
}
const char* Reserva::getAnotaciones() const {
    return anotaciones;
}
const char* Reserva::getEstado() const {
    return estado;
}
void Reserva::setCodigoReserva(int codigo) {
    codigoReserva = codigo;
}
void Reserva::setFechaEntrada(Fecha fecha) {
    fechaEntrada = fecha;
}
void Reserva::setDuracionNoches(int duracion) {
    duracionNoches = duracion;
}
void Reserva::setAnotaciones(const char* notas) {
    delete[] anotaciones;
    anotaciones = new char[strlen(notas) + 1];
    strcpy(anotaciones, notas);
}
void Reserva::setEstado(const char* est) {
    delete[] estado;
    estado = new char[strlen(est) + 1];
    strcpy(estado, est);
}

//Métodos
Fecha Reserva::calcularFechaSalida() {
    return fechaEntrada.calcularFechaSalida(duracionNoches);
}
bool Reserva::anularReserva() {
    setEstado("Anulada");
    return true;
}
