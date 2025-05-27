#ifndef ANFITRION_H
#define ANFITRION_H
#define MAX_HABITACIONES 50
#define MAX_RESERVAS 100

#include <string>
#include "habitaciones.h"

class Habitacion;
class Reserva;
class Sistema; // Forward declaration for Sistema

class Anfitrion {
private:
    std::string nombre;
    int antiguedad;
    int calificacion;
    std::string numIdentidad; // Número de identidad del anfitrión
    Habitacion* habitaciones[MAX_HABITACIONES]; // Suponiendo un máximo de habitaciones
    Reserva* reservas[MAX_RESERVAS]; // Suponiendo un máximo de reservas

public:
    // Constructores
    Anfitrion();
    Anfitrion(const char* nom, int ant, int cal);

    // Destructor
    ~Anfitrion();

    // Getters y setters
    std::string getNombre() const;
    int getAntiguedad() const;
    float getCalificacion() const;
    std::string getnumIdentidad() const;
    void setNombre(const char* nom);
    void setAntiguedad(int ant);
    void setCalificacion(float cal);
    void setnumIdentidad(const std::string& id);

    // Métodos
    void consultarHabitaciones(Sistema* sistema);
    // consultarReservas()
    // anularReserva()
};

#endif // ANFITRION_H
