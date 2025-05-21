#include "habitacion.h"

//Constructores
Habitacion::Habitacion() {
    codigoId = 0;
    nombre = nullptr;
    tipo = nullptr;
    precioPorNoche = 0.0;
    amenidades = nullptr;
    numAmenidades = 0;
    ubicacion = nullptr;
    anfitrion = nullptr;
}

Habitacion::Habitacion(int id, const char* nom, const char* t, double precio, Ubicacion* ubi, Anfitrion* anf) {
    codigoId = id;
    nombre = new char[strlen(nom) + 1];
    strcpy(nombre, nom);
    tipo = new char[strlen(t) + 1];
    strcpy(tipo, t);
    precioPorNoche = precio;
    amenidades = nullptr;
    numAmenidades = 0;
    ubicacion = ubi;
    anfitrion = anf;
}

//Destructor
Habitacion::~Habitacion() {
    delete[] nombre;
    delete[] tipo;
    for (int i = 0; i < numAmenidades; i++) {
        delete[] amenidades[i];
    }
    delete[] amenidades;
    delete ubicacion;
    delete anfitrion;
}

//Getters y setters
int Habitacion::getCodigoId() const { return codigoId; }
const char* Habitacion::getNombre() const { return nombre; }
const char* Habitacion::getTipo() const { return tipo; }
double Habitacion::getPrecioPorNoche() const { return precioPorNoche; }
Ubicacion* Habitacion::getUbicacion() const { return ubicacion; }
Anfitrion* Habitacion::getAnfitrion() const { return anfitrion; }

//Métodos
bool Habitacion::agregarAmenidad(const char* amenidad) {
    char** temp = new char*[numAmenidades + 1];
    for (int i = 0; i < numAmenidades; i++) {
        temp[i] = new char[strlen(amenidades[i]) + 1];
        strcpy(temp[i], amenidades[i]);
    }
    temp[numAmenidades] = new char[strlen(amenidad) + 1];
    strcpy(temp[numAmenidades], amenidad);

    delete[] amenidades;
    amenidades = temp;
    numAmenidades++;

    return true;
}

bool Habitacion::estaDisponible(Fecha inicio, int noches) {
    return true;
}

bool Habitacion::eliminarHabitacion() {
    return true;
}
