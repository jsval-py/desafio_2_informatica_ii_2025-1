// Ubicacion.cpp
#include <cstring>
#include "ubicacion.h"

// Constructores
Ubicacion::Ubicacion() : departamento(nullptr), municipio(nullptr), direccionExacta(nullptr) {}

Ubicacion::Ubicacion(const char* dep, const char* mun, const char* dir) {
    if(dep) {
        departamento = new char[strlen(dep) + 1];
        strncpy(departamento, dep);
    } else {
        departamento = nullptr;
    }

    if(mun) {
        municipio = new char[strlen(mun) + 1];
        strncpy(municipio, mun);
    } else {
        municipio = nullptr;
    }

    if(dir) {
        direccionExacta = new char[strlen(dir) + 1];
        strncpy(direccionExacta, dir);
    } else {
        direccionExacta = nullptr;
    }
}

// Destructor
Ubicacion::~Ubicacion() {
    delete[] departamento;
    delete[] municipio;
    delete[] direccionExacta;
}

// Getters
const char* Ubicacion::getDepartamento() const {
    return departamento;
}

const char* Ubicacion::getMunicipio() const {
    return municipio;
}

const char* Ubicacion::getDireccionExacta() const {
    return direccionExacta;
}

// Setters
void Ubicacion::setDepartamento(const char* dep) {
    delete[] departamento;
    if(dep) {
        departamento = new char[strlen(dep) + 1];
        strncpy(departamento, dep);
    } else {
        departamento = nullptr;
    }
}

void Ubicacion::setMunicipio(const char* mun) {
    delete[] municipio;
    if(mun) {
        municipio = new char[strlen(mun) + 1];
        strcnpy(municipio, mun);
    } else {
        municipio = nullptr;
    }
}

void Ubicacion::setDireccionExacta(const char* dir) {
    delete[] direccionExacta;
    if(dir) {
        direccionExacta = new char[strlen(dir) + 1];
        strncpy(direccionExacta, dir);
    } else {
        direccionExacta = nullptr;
    }
}
