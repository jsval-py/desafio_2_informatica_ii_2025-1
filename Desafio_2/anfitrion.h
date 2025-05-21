#ifndef ANFITRION_H
#define ANFITRION_H
#include "Fecha.h"

class Habitacion;
class Reserva;

class Anfitrion {
private:
    char* nombre;
    int antiguedad;
    int calificacion;

public:
    // Constructores
    Anfitrion();
    Anfitrion(const char* nom, int ant, int cal);

    // Destructor
    ~Anfitrion();

    // Getters y setters
    const char* getNombre() const;
    int getAntiguedad() const;
    int getCalificacion() const;
    void setNombre(const char* nom);
    void setAntiguedad(int ant);
    void setCalificacion(int cal);

    // Métodos
    Anfitrion* login(const char* tipo, int num, const char* pass);
    bool agregarHabitacion(Habitacion* hab);
    bool eliminarHabitacionPorCodigo(int codigo);
    Habitacion* consultarReservas(Fecha inicio, Fecha fin);
};

#endif // ANFITRION_H
