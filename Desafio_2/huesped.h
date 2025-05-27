#ifndef HUESPED_H
#define HUESPED_H
#include <string>
class Reserva;

class Huesped {
private:
    std::string nombre;
    int antiguedad;
    float calificacion;
    std::string numIdentidad;

public:
    // Constructores
    Huesped();
    // Destructor
    ~Huesped();

    // Getters y setters
    std::string getNombre() const;
    int getAntiguedad() const;
    float getCalificacion() const;
    std::string getnumIdentidad() const;
    void setNombre(const char* nom);
    void setAntiguedad(int ant);
    void setCalificacion(float cal);
    void setnumIdentidad(const std::string& id);

    // Métodos
    Reserva* crearReserva(Reserva* res);
    bool anularReserva(int codigoReserva);
    void consultarReservas() const;
};

#endif // HUESPED_H
