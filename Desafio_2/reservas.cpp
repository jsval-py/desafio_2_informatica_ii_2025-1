#include "reservas.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

Reserva::Reserva() {
    idReserva[0] = '\0';
    idHabitacion[0] = '\0';
    idHuesped[0] = '\0';
    montoTotal = 0.0;
    activa = true;
}

Reserva::Reserva(const char* idReserva_, const char* idHabitacion_, const char* idHuesped_,
                 const Fecha& fechaInicio_, const Fecha& fechaFin_, double montoTotal_, bool activa_) :
    fechaInicio(fechaInicio_), fechaFin(fechaFin_) {
    strncpy(idReserva, idReserva_, MAX_ID);
    idReserva[MAX_ID-1] = '\0';
    strncpy(idHabitacion, idHabitacion_, MAX_ID);
    idHabitacion[MAX_ID-1] = '\0';
    strncpy(idHuesped, idHuesped_, MAX_ID);
    idHuesped[MAX_ID-1] = '\0';
    montoTotal = montoTotal_;
    activa = activa_;
}

const char* Reserva::getIdReserva() const { return idReserva; }
const char* Reserva::getIdHabitacion() const { return idHabitacion; }
const char* Reserva::getIdHuesped() const { return idHuesped; }
Fecha Reserva::getFechaInicio() const { return fechaInicio; }
Fecha Reserva::getFechaFin() const { return fechaFin; }
double Reserva::getMontoTotal() const { return montoTotal; }
bool Reserva::estaActiva() const { return activa; }
void Reserva::setActiva(bool estado) { activa = estado; }

void Reserva::mostrarInformacion() const {
    std::cout << "ID Reserva: " << idReserva << std::endl;
    std::cout << "ID Habitación: " << idHabitacion << std::endl;
    std::cout << "ID Huésped: " << idHuesped << std::endl;
    std::cout << "Fecha inicio: "; fechaInicio.mostrar();
    std::cout << "Fecha fin: "; fechaFin.mostrar();
    std::cout << "Monto total: $" << montoTotal << std::endl;
    std::cout << "Estado: " << (activa ? "Activa" : "Cancelada") << std::endl;
}

// Persistencia
int Reserva::cargarReservasDeArchivo(Reserva reservas[], int maxReservas, const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo.c_str());
    if (!archivo.is_open()) return 0;
    std::string linea;
    int count = 0;
    while (std::getline(archivo, linea) && count < maxReservas) {
        std::istringstream iss(linea);
        std::string idR, idH, idHuesp, fInicio, fFin, montoStr, activaStr;
        if (std::getline(iss, idR, ',') &&
            std::getline(iss, idH, ',') &&
            std::getline(iss, idHuesp, ',') &&
            std::getline(iss, fInicio, ',') &&
            std::getline(iss, fFin, ',') &&
            std::getline(iss, montoStr, ',') &&
            std::getline(iss, activaStr)) {
            Fecha fechaIni = Fecha::fromString(fInicio);
            Fecha fechaF = Fecha::fromString(fFin);
            double monto = std::stod(montoStr);
            bool activaB = (activaStr == "1");
            reservas[count] = Reserva(idR.c_str(), idH.c_str(), idHuesp.c_str(), fechaIni, fechaF, monto, activaB);
            count++;
        }
    }
    archivo.close();
    return count;
}
