#include <cstring>
#include <fstream>
#include <iostream>
#include "anfitrion.h"
#include "habitaciones.h"

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
        std::cout << "-----------------------------" << std::endl;
        habitacionesDelAnfitrion[i].mostrarInformacion();

        // Submenú para gestionar reservas de la habitación
        int opcionReserva = 0;
        do {
            std::cout << "\nGestión de reservas para esta habitación:" << std::endl;
            std::cout << "1. Ver reservas" << std::endl;
            std::cout << "2. Agregar reserva" << std::endl;
            std::cout << "3. Cancelar reserva" << std::endl;
            std::cout << "4. Volver al listado de habitaciones" << std::endl;
            std::cout << "Seleccione una opción: ";
            std::cin >> opcionReserva;
            std::cin.ignore();

            switch(opcionReserva) {
            case 1:
                habitacionesDelAnfitrion[i].cargarReservasDeArchivo("C:/Users/eeval/Desktop/informatica ii/GitHub/desafio_2_informatica_ii_2025-1/Desafio_2/Memoria/reservasActivas.txt");
                habitacionesDelAnfitrion[i].mostrarReservas(); // Debes implementar este método
                break;
            case 2:
                /*habitacionesDelAnfitrion[i].agregarReserva(); // Debes implementar este método
                break;*/
            case 3:
                /*habitacionesDelAnfitrion[i].cancelarReserva(); // Debes implementar este método
                break;*/
            case 4:
                // Volver al listado de habitaciones
                break;
            default:
                std::cout << "Opción inválida." << std::endl;
            }
        } while(opcionReserva != 4);
    }
}
