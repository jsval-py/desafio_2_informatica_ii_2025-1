#include "huesped.h"

//Constructores
Huesped::Huesped() {
    nombre = nullptr;
    antiguedad = 0;
    calificacion = 0;
    puntuacion = 0.0f;
}
Huesped::Huesped(const char* nom, int num, int pass) {
    nombre = new char[strlen(nom) + 1];
    strcpy(nombre, nom);
    antiguedad = num;
    calificacion = pass;
    puntuacion = 0.0f;
}

//Destructor
Huesped::~Huesped() {
    delete[] nombre;
}

//Getters y setters
const char* Huesped::getNombre() const {
    return nombre;
}
int Huesped::getAntiguedad() const {
    return antiguedad;
}
int Huesped::getCalificacion() const {
    return calificacion;
}
float Huesped::getPuntuacion() const {
    return puntuacion;
}
void Huesped::setNombre(const char* nom) {
    delete[] nombre;
    nombre = new char[strlen(nom) + 1];
    strcpy(nombre, nom);
}
void Huesped::setAntiguedad(int ant) {
    antiguedad = ant;
}
void Huesped::setCalificacion(int cal) {
    calificacion = cal;
}
void Huesped::setPuntuacion(float punt) {
    puntuacion = punt;
}

//Métodos
Huesped* Huesped::login(const char* tipo, int num, int pass) {
    return this;
}
Reserva* Huesped::consultarReservas() {
    return nullptr;
}
Reserva* Huesped::crearReserva(Reserva* res) {
    return res;
}
bool Huesped::anularReserva(int codigoReserva) {
    return true;
}
