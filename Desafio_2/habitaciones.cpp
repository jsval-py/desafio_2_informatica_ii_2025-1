#include "habitaciones.h"
#include "anfitrion.h"
#include "sistema.h"
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

Habitacion::Habitacion() {
    idHabitacion = "";
    nombreHabitacion = "";
    tipoHabitacion = "";
    direccion = "";
    municipio = "";
    departamento = "";
    //Amenidades
    for (int i = 0; i < MAX_AMENIDADES; ++i) {
        amenidades[i] = "";
    }
    precioNoche = 0.0;
    anfitrion = nullptr;
    sistema = nullptr;
}

Habitacion::Habitacion(const std::string& id, const std::string& nombre, const std::string& tipo, const std::string& dir,
                       const std::string& muni, const std::string& depto, double precio, Anfitrion* anfitrion) {
    idHabitacion = id;
    nombreHabitacion = nombre;
    tipoHabitacion = tipo;
    direccion = dir;
    municipio = muni;
    // Amenidades
    for (int i = 0; i < MAX_AMENIDADES; ++i) {
        amenidades[i] = ""; // Inicializar las amenidades
    }
    departamento = depto;
    precioNoche = precio;
    this->anfitrion = anfitrion; // Asignar el anfitrión
    this->sistema = nullptr; // Initialize sistema
}

Habitacion::~Habitacion() {
    // Que destruir
}

std::string Habitacion::getIdHabitacion() const {
    return idHabitacion;
}
void Habitacion::setIdHabitacion(const std::string& id) {
    idHabitacion = id;
}
std::string Habitacion::getNombreHabitacion() const {
    return nombreHabitacion;
}
void Habitacion::setNombreHabitacion(const std::string& nombre) {
    nombreHabitacion = nombre;
}
std::string Habitacion::getTipoHabitacion() const {
    return tipoHabitacion;
}
void Habitacion::setTipoHabitacion(const std::string& tipo) {
    tipoHabitacion = tipo;
}
std::string Habitacion::getDireccion() const {
    return direccion;
}
void Habitacion::setDireccion(const std::string& dir) {
    direccion = dir;
}
std::string Habitacion::getMunicipio() const {
    return municipio;
}
void Habitacion::setMunicipio(const std::string& muni) {
    municipio = muni;
}
std::string Habitacion::getDepartamento() const {
    return departamento;
}
void Habitacion::setDepartamento(const std::string& depto) {
    departamento = depto;
}

std::string Habitacion::getAmenidades() const {
    std::string amenidadesStr;
    for (int i = 0; i < MAX_AMENIDADES; ++i) {
        if (!amenidades[i].empty()) {
            if (!amenidadesStr.empty()) {
                amenidadesStr += ";"; // Separador entre amenidades
            }
            amenidadesStr += amenidades[i];
        }
    }
    return amenidadesStr;
}

void Habitacion::setAmenidades(const std::string& amenidadesStr) {
    // Limpiar el arreglo primero
    for (int i = 0; i < MAX_AMENIDADES; ++i) {
        amenidades[i] = "";
    }

    std::istringstream iss(amenidadesStr);
    std::string amenidad;
    int index = 0;

    while (std::getline(iss, amenidad, ';') && index < MAX_AMENIDADES) {
        amenidades[index++] = amenidad;
    }
}

double Habitacion::getPrecioNoche() const {
    return precioNoche;
}
void Habitacion::setPrecioNoche(double precio) {
    precioNoche = precio;
}

std::string Habitacion::getIdAnfitrion() const {
    if (anfitrion != nullptr) {
        return anfitrion->getnumIdentidad();
    }
    return "";
}

void Habitacion::mostrarInformacion() const {
    std::cout << "ID: " << idHabitacion << std::endl;
    std::cout << "Nombre: " << nombreHabitacion << std::endl;
    std::cout << "Tipo: " << tipoHabitacion << std::endl;
    std::cout << "Dirección: " << direccion << std::endl;
    std::cout << "Municipio: " << municipio << std::endl;
    std::cout << "Departamento: " << departamento << std::endl;
    std::cout << "Amenidades: " << getAmenidades() << std::endl;
    std::cout << "Precio por noche: $" << precioNoche << std::endl;
    if (anfitrion != nullptr) {
        std::cout << "Anfitrión: " << anfitrion->getNombre() << " (ID: " << anfitrion->getnumIdentidad() << ")" << std::endl;
    }
}

Anfitrion* Habitacion::buscarAnfitrionporId(Sistema*, const std::string& idAnfitrionStr){
    // Primero intentamos con ruta relativa
    std::ifstream archivo("habitaciones.txt");
    if (!archivo.is_open()) {
        // Si no funciona, intentamos con la ruta absoluta
        archivo.open("C:/Users/eeval/Desktop/informatica ii/GitHub/desafio_2_informatica_ii_2025-1/Desafio_2/Memoria/usuarios.txt");
        if (!archivo.is_open()) {
            std::cerr << "Error: No se pudo abrir el archivo de usuarios" << std::endl;
            return nullptr;
        }
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        std::istringstream iss(linea);
        std::string numIdentidadStr, passwordDB, nombre, tipoStr, calificacionStr, antiguedadStr;

        if (std::getline(iss, numIdentidadStr, ',') &&
            std::getline(iss, passwordDB, ',') &&
            std::getline(iss, nombre, ',') &&
            std::getline(iss, tipoStr, ',') &&
            std::getline(iss, calificacionStr, ',') &&
            std::getline(iss, antiguedadStr)) {

            if (numIdentidadStr == idAnfitrionStr && tipoStr == "anfitrion") {
                Anfitrion* anfitrion = new Anfitrion();
                anfitrion->setnumIdentidad(numIdentidadStr);
                anfitrion->setNombre(nombre.c_str());
                anfitrion->setAntiguedad(std::stoi(antiguedadStr));
                anfitrion->setCalificacion(std::stof(calificacionStr));
                archivo.close();
                return anfitrion;
            }
        }
    }
    archivo.close();
    return nullptr;
}

// Método estático para cargar todas las habitaciones desde la base de datos
int Habitacion::cargarTodasLasHabitaciones(Sistema* sistema, Habitacion habitaciones[], int maxHabitaciones) {
    // Primero intentamos con ruta relativa
    std::ifstream archivo("habitaciones.txt");
    if (!archivo.is_open()) {
        // Si no funciona, intentamos con la ruta absoluta
        archivo.open("C:/Users/eeval/Desktop/informatica ii/GitHub/desafio_2_informatica_ii_2025-1/Desafio_2/Memoria/habitaciones.txt");
        if (!archivo.is_open()) {
            std::cout << "Error: No se pudo abrir el archivo habitaciones.txt" << std::endl;
            return 0;
        }
    }

    std::cout << "Cargando habitaciones desde la base de datos..." << std::endl;

    std::string linea;
    int contador = 0;

    while (std::getline(archivo, linea) && contador < maxHabitaciones) {
        // Verificar que la línea no esté vacía
        if (linea.empty()) {
            continue;
        }

        std::string id, nombre, tipo, dir, muni, depto, amenidadesStr, precioStr, idAnfitrionStr;
        std::istringstream iss(linea);

        // Parse de la línea CSV
        if (std::getline(iss, id, ',') &&
            std::getline(iss, nombre, ',') &&
            std::getline(iss, tipo, ',') &&
            std::getline(iss, dir, ',') &&
            std::getline(iss, muni, ',') &&
            std::getline(iss, depto, ',') &&
            std::getline(iss, amenidadesStr, ',') &&
            std::getline(iss, precioStr, ',') &&
            std::getline(iss, idAnfitrionStr)) {

            // Configurar la habitación en el arreglo
            habitaciones[contador].setIdHabitacion(id);
            habitaciones[contador].setNombreHabitacion(nombre);
            habitaciones[contador].setTipoHabitacion(tipo);
            habitaciones[contador].setDireccion(dir);
            habitaciones[contador].setMunicipio(muni);
            habitaciones[contador].setDepartamento(depto);

            // Convertir precio de string a double
            try {
                habitaciones[contador].setPrecioNoche(std::stod(precioStr));
            } catch (const std::exception& e) {
                std::cerr << "Error convirtiendo precio: " << precioStr << std::endl;
                habitaciones[contador].setPrecioNoche(0.0);
            }

            habitaciones[contador].setAmenidades(amenidadesStr);

            // Buscar y asignar el anfitrión
            habitaciones[contador].anfitrion = buscarAnfitrionporId(sistema, idAnfitrionStr);

            if (habitaciones[contador].anfitrion != nullptr) {
                contador++;
            } else {
                // Aún así agregamos la habitación sin anfitrión
                contador++;
            }
        } else {
            std::cerr << "Error parseando línea: " << linea << std::endl;
        }
    }

    archivo.close();
    std::cout << "Total de habitaciones cargadas: " << contador << std::endl;
    return contador;
}

// Método estático para obtener habitaciones de un anfitrión específico
int Habitacion::obtenerHabitacionesPorAnfitrion(Sistema* sistema, const std::string& idAnfitrion,
                                                Habitacion habitacionesDelAnfitrion[], int maxHabitaciones) {
    Habitacion todasLasHabitaciones[MAX_HABITACIONES_TOTAL];
    int totalHabitaciones = cargarTodasLasHabitaciones(sistema, todasLasHabitaciones, MAX_HABITACIONES_TOTAL);

    int contador = 0;
    for (int i = 0; i < totalHabitaciones && contador < maxHabitaciones; i++) {
        if (todasLasHabitaciones[i].getIdAnfitrion() == idAnfitrion) {
            habitacionesDelAnfitrion[contador] = todasLasHabitaciones[i];
            contador++;
        }
    }

    return contador;
}

void Habitacion::cargarDBHabitaciones(Sistema* sistema) {
    // Primero intentamos con ruta relativa
    std::ifstream archivo("habitaciones.txt");
    if (!archivo.is_open()) {
        // Si no funciona, intentamos con la ruta absoluta
        archivo.open("C:/Users/eeval/Desktop/informatica ii/GitHub/desafio_2_informatica_ii_2025-1/Desafio_2/Memoria/habitaciones.txt");
        if (!archivo.is_open()) {
            std::cerr << "Error: No se pudo abrir el archivo habitaciones.txt" << std::endl;
            return;
        }
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        // Verificar que la línea no esté vacía
        if (linea.empty()) {
            continue;
        }

        //estructura de datos
        std::string id, nombre, tipo, dir, muni, depto, amenidadesStr, precioStr, idAnfitrionStr;
        std::istringstream iss(linea);

        if (std::getline(iss, id, ',') &&
            std::getline(iss, nombre, ',') &&
            std::getline(iss, tipo, ',') &&
            std::getline(iss, dir, ',') &&
            std::getline(iss, muni, ',') &&
            std::getline(iss, depto, ',') &&
            std::getline(iss, amenidadesStr, ',') &&
            std::getline(iss, precioStr, ',') &&
            std::getline(iss, idAnfitrionStr)) {

            this->idHabitacion = id;
            this->nombreHabitacion = nombre;
            this->tipoHabitacion = tipo;
            this->direccion = dir;
            this->municipio = muni;
            this->departamento = depto;

            // Convertir precio de string a double
            try {
                this->precioNoche = std::stod(precioStr);
            } catch (const std::exception& e) {
                std::cerr << "Error convirtiendo precio: " << precioStr << std::endl;
                this->precioNoche = 0.0;
            }

            this->setAmenidades(amenidadesStr);
            this->anfitrion = buscarAnfitrionporId(sistema, idAnfitrionStr);

            // Verificar si el anfitrión fue encontrado
            if (this->anfitrion == nullptr) {
                std::cout << "Advertencia: Anfitrión con ID " << idAnfitrionStr << " no encontrado para habitación " << nombre << std::endl;
            } else {
                std::cout << "Habitación cargada: " << nombre << " (ID: " << id << ")" << std::endl;
            }
        }
    }
    archivo.close();
}
