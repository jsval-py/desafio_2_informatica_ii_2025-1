#include "pago.h"

// Constructor
Pago::Pago() {
    metodo = nullptr;
    fechaPago = Fecha();
    monto = 0.0;
}
Pago::Pago(const char* met, Fecha fecha, double mon) {
    metodo = new char[strlen(met) + 1];
    strcpy(metodo, met);
    fechaPago = fecha;
    monto = mon;
}
// Destructor
Pago::~Pago() {
    delete[] metodo;
}

// Getters y setters
const char* Pago::getMetodo() const {
    return metodo;
}
Fecha Pago::getFechaPago() const {
    return fechaPago;
}
double Pago::getMonto() const {
    return monto;
}
void Pago::setMetodo(const char* met) {
    delete[] metodo;
    metodo = new char[strlen(met) + 1];
    strcpy(metodo, met);
}
void Pago::setFechaPago(Fecha fecha) {
    fechaPago = fecha;
}
void Pago::setMonto(double mon) {
    monto = mon;
}

// Métodos
bool Pago::verificarPago() {
    return true;
}
bool Pago::confirmarPago() {
    return true;
}
