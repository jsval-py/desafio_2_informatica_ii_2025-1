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
void Anfitrion::consultarHabitaciones(Sistema* sistema) {
    std::cout << "\n=== HABITACIONES DEL ANFITRIÓN: " << nombre << " ===" << std::endl;

    // Crear arreglo para almacenar las habitaciones del anfitrión
    Habitacion habitacionesDelAnfitrion[MAX_HABITACIONES];

    // Obtener las habitaciones que pertenecen a este anfitrión
    int numHabitaciones = Habitacion::obtenerHabitacionesPorAnfitrion(sistema, numIdentidad,
                                                                      habitacionesDelAnfitrion, MAX_HABITACIONES);

    if (numHabitaciones == 0) {
        std::cout << "No tiene habitaciones registradas en el sistema." << std::endl;
        return;
    }

    std::cout << "Sus habitaciones registradas:\n" << std::endl;

    // Mostrar cada habitación usando el método de la clase Habitacion
    for (int i = 0; i < numHabitaciones; i++) {
        std::cout << "--- HABITACIÓN " << (i + 1) << " ---" << std::endl;
        habitacionesDelAnfitrion[i].mostrarInformacion();
        std::cout << "--------------------------------" << std::endl;
    }

    std::cout << "\nTotal de habitaciones: " << numHabitaciones << std::endl;
}
