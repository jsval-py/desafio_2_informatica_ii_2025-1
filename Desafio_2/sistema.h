#ifndef SISTEMA_H
#define SISTEMA_H
#include <string>
#include "huesped.h"
#include "anfitrion.h"
#include <gestorDB.h>

class Sistema{
private:
    std::string numIdentidad;
    std::string password;
    std::string usuarioActual;

    // Objetos/clases que harán parte del sistema
    Huesped* huesped;
    Anfitrion* anfitrion;
    int tipoUsuarioActual;

public:
    //Constructor
    Sistema();
    //Destructor
    ~Sistema();

    // Getters y setters
    /*std::string getNumIdentidad() const { return numIdentidad; }
    void setNumIdentidad(const std::string& id) { numIdentidad = id; }
    std::string getPassword() const { return password; }*/
    int getTipoUsuarioActual() const { return tipoUsuarioActual; }
    void setTipoUsuarioActual(int tipo) { tipoUsuarioActual = tipo; }
    std::string getUsuarioActual() const;

    //Métodos
    bool validarUsuarioDB(const std::string& usuario, const std::string& password, int& tipoUsuarioIdentificado, float& puntuacion, int& antiguedad);
    void cargarDBUsuarios(const std::string& usuario, int tipoUsuario);
    bool iniciarSesion(const std::string& usuario, const std::string& password);
    bool iniciarSesion(const std::string& usuario, const std::string& password, int tipoUsuario);
    bool acceso(const std::string& usuario, const std::string& password);
    void mostrarMenuHuesped();
    void mostrarMenuAnfitrion();
};

#endif // SISTEMA_H
