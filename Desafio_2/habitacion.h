#ifndef HABITACION_H
#define HABITACION_H

#include "ubicacion.h"
#include "fecha.h"

class Anfitrion;

class Habitacion{
private:
    int codigoId;
    char* nombre;
    char* tipo;
    double precioPorNoche;
    char** amenidades;
    int numAmenidades;
    Ubicacion* ubicacion;
    Anfitrion* anfitrion;
public:
    //Constructor
    Habitacion();
    Habitacion(int id, const char* nom, const char* t, double precio, Ubicacion* ubi, Anfitrion* anf);

    //Destructor
    ~Habitacion();

    //Getters y setters
    int getCodigoId() const;
    const char* getNombre() const;
    const char* getTipo() const;
    double getPrecioPorNoche() const;
    Ubicacion* getUbicacion() const;
    Anfitrion* getAnfitrion() const;

    //Metodos
    bool agregarAmenidad(const char* amenidad);
    bool estaDisponible(Fecha inicio, int noches);
    bool eliminarHabitacion();
}

#endif // HABITACION_H
