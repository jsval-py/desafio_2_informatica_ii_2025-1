#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "sistema.h"

//Constructor
Sistema::Sistema(){
    numIdentidad= "";
    password= "";

    std::cout<<"Bienvenido a UdeaStay"<<std::endl;
}

//Destructor
Sistema::~Sistema(){
    // Liberar recursos si es necesario
}

//Metodos
bool Sistema::validarUsuarioDB(const std::string& usuario, const std::string& password, int& tipoUsuarioIdentificado, float& puntuacion){
    std::ifstream archivo("C:/Users/eeval/Desktop/informatica ii/GitHub/desafio_2_informatica_ii_2025-1/Desafio_2/Memoria/usuarios.txt");
    if (!archivo) {
        std::cout<< "Error al abrir el archivo de usuarios."<<std::endl;
        return false;
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        std::istringstream iss(linea);
        std::string usuarioDB, passwordDB, nombre, tipoStr, puntuacionStr;

        if (std::getline(iss, usuarioDB, ',') &&
            std::getline(iss, passwordDB, ',') &&
            std::getline(iss, nombre, ',') &&
            std::getline(iss, tipoStr, ',')
            && std::getline(iss, puntuacionStr)) {

            if (usuarioDB == usuario && passwordDB == password){
                archivo.close();

                if (tipoStr == "huesped"){
                    tipoUsuarioIdentificado = 1;
                } else if (tipoStr == "anfitrion") {
                    tipoUsuarioIdentificado = 2;
                } else {
                    std::cout << "Tipo de usuario no reconocido en la base de datos" << std::endl;
                    archivo.close();
                    return false;
                }
                puntuacion = std::stof(puntuacionStr);
                std::cout<< "Usuario autenticado correctamente." << std::endl;
                std::cout<<"Nombre: "<< nombre << std::endl;
                std::cout<<"Tipo de usuario: " << tipoStr << std::endl;
                std::cout<<"Puntuacion: " << puntuacion << std::endl;
            }
            else if (usuarioDB == usuario && passwordDB != password){
                std::cout<< "Contraseña incorrecta." << std::endl;
                archivo.close();
                return false;
            }
            else if (usuarioDB != usuario && passwordDB == password){
                std::cout<< "Usuario incorrecto." << std::endl;
                archivo.close();
                return false;
            }
            else if (usuarioDB != usuario && passwordDB != password){
                std::cout<< "Usuario y/o contraseña incorrectos." << std::endl;
                archivo.close();
                return false;
            }
        }
    }
    archivo.close();
    return true;
}

bool Sistema::iniciarSesion (const std::string& usuario, const std::string& password){
    int tipoUsuarioIdentificado = 0;
    float puntuacion = 0.0f;

    if (validarUsuarioDB(usuario, password, tipoUsuarioIdentificado, puntuacion)) {
        std::cout<<"Sesión iniciada, bienvenido"<<std::endl;
        cargarDBUsuarios(usuario, tipoUsuarioIdentificado);
        return true;
    }

    return false;
}

void Sistema::cargarDBUsuarios (const std::string& usuario, int tipoUsuario) {
    std::ifstream archivo("C:/Users/eeval/Desktop/informatica ii/GitHub/desafio_2_informatica_ii_2025-1/Desafio_2/Memoria/usuarios.txt");
    if (!archivo.is_open()) {
        return;
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        std::istringstream iss(linea);
        std::string usuarioDB, passwordDB, nombre, tipoStr;

        if (std::getline(iss, usuarioDB, ',') &&
            std::getline(iss, passwordDB, ',') &&
            std::getline(iss, nombre, ',') &&
            std::getline(iss, tipoStr)) {

            if (usuarioDB == usuario) {
                // Cargar datos según el tipo de usuario encontrado
                if (tipoUsuario == 1) { // Huésped
                   // huesped.setNombre(nombre);
                    // huesped.setNumIdentidad(usuario);
                    std::cout << "Datos de huésped cargados" << std::endl;
                } else if (tipoUsuario == 2) { // Anfitrión
                    // anfitrion.setNombre(nombre);
                    // anfitrion.setNumIdentidad(usuario);
                    std::cout << "Datos de anfitrión cargados" << std::endl;
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
