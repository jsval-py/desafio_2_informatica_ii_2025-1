#include "anfitrion.h"

//Constructor
Anfitrion::Anfitrion() {
    nombre = nullptr;
    antiguedad = 0;
    calificacion = 0;
}
Anfitrion::Anfitrion(const char* nom, int ant, int cal) {
    nombre = new char[strlen(nom) + 1];
    strcpy(nombre, nom);
    antiguedad = ant;
    calificacion = cal;
}

//Destructor
Anfitrion::~Anfitrion() {
    delete[] nombre;
}
//Getters y setters
const char* Anfitrion::getNombre() const {
    return nombre;
}
int Anfitrion::getAntiguedad() const {
    return antiguedad;
}
int Anfitrion::getCalificacion() const {
    return calificacion;
}
void Anfitrion::setNombre(const char* nom) {
    delete[] nombre;
    nombre = new char[strlen(nom) + 1];
    strcpy(nombre, nom);
}
void Anfitrion::setAntiguedad(int ant) {
    antiguedad = ant;
}
void Anfitrion::setCalificacion(int cal) {
    calificacion = cal;
}
//Métodos
Anfitrion* Anfitrion::login(const char* tipo, int num, const char* pass) {
    return nullptr;
}
bool Anfitrion::agregarHabitacion(Habitacion* hab) {
    return false;
}
bool Anfitrion::eliminarHabitacionPorCodigo(int codigo) {
    return false;
}
Habitacion* Anfitrion::consultarReservas(Fecha inicio, Fecha fin) {
    return nullptr;
}
