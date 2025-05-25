#ifndef SISTEMA_H
#define SISTEMA_H
#include <string>
#include "huesped.h"
#include "anfitrion.h"
#include "habitaciones.h"
#include "reservas.h"
#include <gestorDB.h>

class Sistema{
private:
    std::string numIdentidad;
    std::string password;

    // Funciones privadas para autenticación
    bool validarUsuarioDB(const std::string& usuario, const std::string& password, int& tipoUsuarioIdentificado, float& puntuacion);
    void cargarDBUsuarios(const std::string& usuario, int tipoUsuario);
    // Objetos/clases que harán parte del sistema
    Huesped* huesped;
    Anfitrion* anfitrion;
    Habitacion* habitacion;
    Reserva* reserva;
    GestorReservas* gestorDB;

public:
    //Constructor
    Sistema();
    //Destructor
    ~Sistema();

    // Getters y setters
    std::string getNumIdentidad() const { return numIdentidad; }
    void setNumIdentidad(const std::string& id) { numIdentidad = id; }
    std::string getPassword() const { return password; }

    //Métodos
    bool iniciarSesion(const std::string& usuario, const std::string& password);
    bool iniciarSesion(const std::string& usuario, const std::string& password, int tipoUsuario);
    bool acceso(const std::string& usuario, const std::string& password);
};

#endif // SISTEMA_H
