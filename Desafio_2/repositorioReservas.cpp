#include "repositorioReservas.h"

//Constructor
RepositorioReservas::RepositorioReservas() {
    // Inicializar variables necesarias
}
RepositorioReservas::RepositorioReservas(const char* rutaActivas, const char* rutaHistorico) {
    rutaArchivoActivas = new char[strlen(rutaActivas) + 1];
    strcpy(rutaArchivoActivas, rutaActivas);

    rutaArchivoHistorico = new char[strlen(rutaHistorico) + 1];
    strcpy(rutaArchivoHistorico, rutaHistorico);
}
//Destructor
RepositorioReservas::~RepositorioReservas() {
    delete[] rutaArchivoActivas;
    delete[] rutaArchivoHistorico;
}
//Getters y setters
const char* RepositorioReservas::getRutaArchivoActivas() const {
    return rutaArchivoActivas;
}
const char* RepositorioReservas::getRutaArchivoHistorico() const {
    return rutaArchivoHistorico;
}
void RepositorioReservas::setRutaArchivoActivas(const char* ruta) {
    delete[] rutaArchivoActivas;
    rutaArchivoActivas = new char[strlen(ruta) + 1];
    strcpy(rutaArchivoActivas, ruta);
}
void RepositorioReservas::setRutaArchivoHistorico(const char* ruta) {
    delete[] rutaArchivoHistorico;
    rutaArchivoHistorico = new char[strlen(ruta) + 1];
    strcpy(rutaArchivoHistorico, ruta);
}
//Métodos
Reserva* RepositorioReservas::leerReservasActivas() {
    return nullptr;
}
Reserva* RepositorioReservas::leerReservasHistoricas() {
    return nullptr;
}
bool RepositorioReservas::guardarReserva(Reserva* res) {
    return false;
}
bool RepositorioReservas::eliminarReserva(Reserva* res) {
    return false;
}
bool RepositorioReservas::moverAHistorico(Reserva* res) {
    return false;
}
