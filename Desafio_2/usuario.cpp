#include <cstring>
#include "usuario.h"

//Constructores
Usuario::Usuario() : tipoIdentidad(nullptr), numIdentidad(nullptr), password(nullptr) {}
Usuario::Usuario(char* tipoIdentidad, int numIdentidad, int password) {
    this->tipoIdentidad = new char[strlen(tipoIdentidad) + 1];
    strcpy(this->tipoIdentidad, tipoIdentidad);
    this->numIdentidad = numIdentidad;
    this->password = password;
}

//Destructor
Usuario::~Usuario() {
    delete[] tipoIdentidad;
}

//Getters y setters
const char* Usuario::getTipoIdentidad() const {
    return tipoIdentidad;
}
int Usuario::getNumIdentidad() const {
    return numIdentidad;
}
int Usuario::getPassword() const {
    return password;
}
void Usuario::setTipoIdentidad(const char* tipoId) {
    delete[] tipoIdentidad;
    tipoIdentidad = new char[strlen(tipoId) + 1];
    strcpy(tipoIdentidad, tipoId);
}
void Usuario::setNumIdentidad(int numId) {
    numIdentidad = numId;
}
void Usuario::setPassword(int pass) {
    password = pass;
}

//Métodos
Usuario* Usuario::logIn(const char* tipoId, int numId, int pass) {
    if (iniciarSesion(tipoId, numId, pass)) {
        return this;
    }
    return nullptr;
}

bool Usuario::iniciarSesion(const char* tipoId, int numId, int pass) {
    return (strcmp(tipoIdentidad, tipoId) == 0 && numIdentidad == numId && password == pass);
}

