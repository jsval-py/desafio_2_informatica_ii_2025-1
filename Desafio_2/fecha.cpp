#include "fecha.h"
#include <iostream>
#include <iomanip>
#include <sstream>

//Constructores
Fecha::Fecha() : dia(1), mes(1), anio(2000) {}
Fecha::Fecha(int d, int m, int a) : dia(d), mes(m), anio(a) {}

//Getters y setters
int Fecha::getDia() const { return dia; }
int Fecha::getMes() const { return mes; }
int Fecha::getAnio() const { return anio; }
void Fecha::setDia(int d) { dia = d; }
void Fecha::setMes(int m) { mes = m; }
void Fecha::setAnio(int a) { anio = a; }

//Métodos
void Fecha::mostrar() const {
    // Imprime la fecha en formato DD/MM/AAAA
    std::cout << std::setfill('0') << std::setw(2) << dia << "/"
              << std::setw(2) << mes << "/"
              << anio << std::endl;
}

std::string Fecha::toString() const {
    std::ostringstream oss;
    oss << anio << "-";
    if (mes < 10) oss << "0";
    oss << mes << "-";
    if (dia < 10) oss << "0";
    oss << dia;
    return oss.str();
}

Fecha Fecha::fromString(const std::string& str) {
    int y, m, d;
    char sep1, sep2;
    std::istringstream iss(str);
    iss >> y >> sep1 >> m >> sep2 >> d;
    return Fecha(d, m, y); // Ajusta según tu constructor
}

// Método para calcular la fecha de salida sumando noches a la fecha actual
Fecha Fecha::calcularFechaSalida(int noches) const {
    Fecha fechaSalida = *this;
    fechaSalida.dia += noches;

    // Ajustar el día y mes según la cantidad de días en el mes
    while (true) {
        int diasEnMes = 31;
        if (fechaSalida.mes == 2) {
            if ((fechaSalida.anio % 4 == 0 && fechaSalida.anio % 100 != 0) || (fechaSalida.anio % 400 == 0)) {
                diasEnMes = 29; // Año bisiesto
            } else {
                diasEnMes = 28;
            }
        } else if (fechaSalida.mes == 4 || fechaSalida.mes == 6 || fechaSalida.mes == 9 || fechaSalida.mes == 11) {
            diasEnMes = 30;
        }

        if (fechaSalida.dia > diasEnMes) {
            fechaSalida.dia -= diasEnMes;
            fechaSalida.mes++;
            if (fechaSalida.mes > 12) {
                fechaSalida.mes = 1;
                fechaSalida.anio++;
            }
        } else {
            break;
        }
    }

    return fechaSalida;
}

