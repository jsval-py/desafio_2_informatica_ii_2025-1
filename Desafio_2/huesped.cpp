#include <cstring>
#include "huesped.h"

Huesped::Huesped(){
    nombre = "";
    antiguedad = 0;
    calificacion = 0.0f;
    numIdentidad = "";
}

Huesped::~Huesped() {
    // Destructor vacío, ya que no hay memoria dinámica que liberar
}

std::string Huesped::getNombre() const { return nombre; }
int Huesped::getAntiguedad() const { return antiguedad; }
float Huesped::getCalificacion() const { return calificacion; }
std::string Huesped::getnumIdentidad() const { return numIdentidad; }
void Huesped::setNombre(const char* nom) {
    if (nom != nullptr) {
        nombre = nom;
    } else {
        nombre = "";
    }
}
void Huesped::setAntiguedad(int ant) { antiguedad = ant; }
void Huesped::setCalificacion(float cal) { calificacion = cal; }
void Huesped::setnumIdentidad(const std::string& id) { numIdentidad = id; }
