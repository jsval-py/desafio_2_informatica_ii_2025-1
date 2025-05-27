#include "anfitrion.h"
#include "habitaciones.h"
#include <cstring>
#include <fstream>
#include <iostream>

//Constructor
Anfitrion::Anfitrion() {
    nombre = "";
    antiguedad = 0;
    calificacion = 0.0f;
    numIdentidad = "";
}

//Destructor
Anfitrion::~Anfitrion() {
    // Liberar memoria si es necesario
    /* for (int i = 0; i < MAX_HABITACIONES; ++i) {
        if (habitaciones[i] != nullptr) {
            delete habitaciones[i];
            habitaciones[i] = nullptr;
        }
    }
    for (int i = 0; i < MAX_RESERVAS; ++i) {
        if (reservas[i] != nullptr) {
            delete reservas[i];
            reservas[i] = nullptr;
        }
    } */
}

//Getters y setters
std::string Anfitrion::getNombre() const { return nombre; }
int Anfitrion::getAntiguedad() const { return antiguedad; }
float Anfitrion::getCalificacion() const { return calificacion; }
std::string Anfitrion::getnumIdentidad() const { return numIdentidad; }
void Anfitrion::setNombre(const char* nom) {
    if (nom != nullptr) {
        nombre = nom;
    } else {
        nombre = "";
    }
}
void Anfitrion::setAntiguedad(int ant) { antiguedad = ant; }
void Anfitrion::setCalificacion(float cal) { calificacion = cal; }
void Anfitrion::setnumIdentidad(const std::string& id) { numIdentidad = id; }

// Métodos
/*consultar habitaciones usando la clase habitacion, desde ahí se cargan todas las habitaciones que pertenezcan al
 * anfitrion que está consultando las habitaciones, utilizando los metodos que están en la clase habitacion.cpp*/
void Anfitrion::consultarHabitaciones(Sistema* sistema) {
    Habitacion habitacionesDelAnfitrion[MAX_HABITACIONES];
    int totalHabitaciones = Habitacion::obtenerHabitacionesPorAnfitrion(sistema, numIdentidad, habitacionesDelAnfitrion, MAX_HABITACIONES);

    if (totalHabitaciones == 0) {
        std::cout << "No hay habitaciones registradas para este anfitrión." << std::endl;
        return;
    }

    std::cout << "Habitaciones del anfitrión " << nombre << ":" << std::endl;
    for (int i = 0; i < totalHabitaciones; ++i) {
        habitacionesDelAnfitrion[i].mostrarInformacion();
    }
}
