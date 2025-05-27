#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "sistema.h"
#include "huesped.h"
#include "anfitrion.h"

//Constructor
Sistema::Sistema(){
    numIdentidad= "";
    password= "";
    tipoUsuarioActual = 0; // 1 para huésped, 2 para anfitrión
    std::cout<<"Bienvenido a UdeaStay"<<std::endl;
}

//Destructor
Sistema::~Sistema(){
}

//Metodos
bool Sistema::validarUsuarioDB(const std::string& numIdentidad, const std::string& password, int& tipoUsuarioIdentificado, float& puntuacion, int& antiguedad) {
    std::ifstream archivo("C:/Users/eeval/Desktop/informatica ii/GitHub/desafio_2_informatica_ii_2025-1/Desafio_2/Memoria/usuarios.txt");
    if (!archivo) {
        std::cout << "Error al abrir el archivo de usuarios." << std::endl;
        return false;
    }
    std::string linea;

    while (std::getline(archivo, linea)) {
        std::istringstream iss(linea);
        std::string numIdentidadStr, passwordDB, nombre, tipoStr, puntuacionStr, antiguedadStr;;

        if (std::getline(iss, numIdentidadStr, ',') &&
            std::getline(iss, passwordDB, ',') &&
            std::getline(iss, nombre, ',') &&
            std::getline(iss, tipoStr, ',') &&
            std::getline(iss, puntuacionStr, ',') &&
            std::getline(iss, antiguedadStr)) {

            if (numIdentidadStr == numIdentidad) {
                if (passwordDB == password) {
                    // Usuario y contraseña correctos
                    if (tipoStr == "huesped") {
                        tipoUsuarioIdentificado = 1;
                    } else if (tipoStr == "anfitrion") {
                        tipoUsuarioIdentificado = 2;
                    } else {
                        std::cout << "Tipo de usuario no reconocido en la base de datos" << std::endl;
                        archivo.close();
                        return false;
                    }

                    puntuacion = std::stof(puntuacionStr);
                    antiguedad = std::stoi(antiguedadStr);
                    std::cout << "Usuario autenticado correctamente." << std::endl;
                    std::cout << "Nombre: " << nombre << std::endl;
                    std::cout << "Tipo de usuario: " << tipoStr << std::endl;
                    archivo.close();
                    return true;
                } else {
                    std::cout << "Contraseña incorrecta." << std::endl;
                    archivo.close();
                    return false;
                }
            }
        }
    }
    archivo.close();
    std::cout << "Usuario no encontrado." << std::endl;
    return false;
}

bool Sistema::iniciarSesion (const std::string& numIdentidad, const std::string& password){
    int tipoUsuarioIdentificado = 0;
    float puntuacion = 0.0f;
    int antiguedad = 0;

    if (validarUsuarioDB(numIdentidad, password, tipoUsuarioIdentificado, puntuacion, antiguedad)) {
        std::cout<<"Sesión iniciada, bienvenido"<<std::endl;
        cargarDBUsuarios(numIdentidad, tipoUsuarioIdentificado);
        return true;
    }

    return false;
}

void Sistema::cargarDBUsuarios (const std::string& numIdentidad, int tipoUsuario) {
    std::ifstream archivo("C:/Users/eeval/Desktop/informatica ii/GitHub/desafio_2_informatica_ii_2025-1/Desafio_2/Memoria/usuarios.txt");
    if (!archivo.is_open()) {
        return;
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

            if (numIdentidadStr == numIdentidad) {
                // Cargar datos según el tipo de usuario encontrado
                if (tipoUsuario == 1) { // Huésped
                    tipoUsuarioActual = 1;
                    huesped = new Huesped();
                    huesped->setNombre(nombre.c_str());
                    huesped->setAntiguedad(std::stoi(antiguedadStr));
                    huesped->setCalificacion(std::stof(calificacionStr));
                    std::cout << "Datos de huésped cargados: " << nombre
                              << " (Antigüedad: " << antiguedadStr
                              << ", Calificación: " << calificacionStr << ")" << std::endl;
                } else if (tipoUsuario == 2) { // Anfitrión
                    // necesito que el setter de tipoUsuarioActual sea 2 para el anfitrión
                    tipoUsuarioActual = 2;
                    anfitrion = new Anfitrion();
                    anfitrion->setnumIdentidad(numIdentidadStr);
                    anfitrion->setNombre(nombre.c_str());
                    anfitrion->setAntiguedad(std::stoi(antiguedadStr));
                    anfitrion->setCalificacion(std::stof(calificacionStr));
                    std::cout << "Datos de anfitrión cargados: " << nombre
                              << " (Antigüedad: " << antiguedadStr
                              << ", Calificación: " << calificacionStr << ")" << std::endl;
                }
                break;
            }
        }
    }

    archivo.close();
}

bool Sistema::acceso (const std::string& usuario, const std::string& password) {
    return iniciarSesion(usuario, password);
}

void Sistema::mostrarMenuHuesped() {
    std::cout << "\n=== MENÚ ===" << std::endl;
    std::cout << "1. Crear nueva reserva" << std::endl;
    std::cout << "2. Cancelar reserva" << std::endl;
    std::cout << "3. Ver habitaciones disponibles" << std::endl;
    std::cout << "4. Cerrar sesión" << std::endl;
}

void Sistema::mostrarMenuAnfitrion() {
    std::cout << "\n=== MENÚ ===" << std::endl;
    std::cout << "1. Consultar mis habitaciones" << std::endl;
    std::cout << "2. Consultar reservas recibidas" << std::endl;
    std::cout << "3. Cancelar reserva recibida" << std::endl;
    std::cout << "4. Cerrar sesión" << std::endl;
}
