#ifndef HUESPED_H
#define HUESPED_H

class Reserva;

class Huesped {
private:
    char* nombre;
    int antiguedad;
    int calificacion;
    float puntuacion;

public:
    // Constructores
    Huesped();
    Huesped(const char* nom, int num, int pass);

    // Destructor
    ~Huesped();

    // Getters y setters
    const char* getNombre() const;
    int getAntiguedad() const;
    int getCalificacion() const;
    float getPuntuacion() const;
    void setNombre(const char* nom);
    void setAntiguedad(int ant);
    void setCalificacion(int cal);
    void setPuntuacion(float punt);

    // Métodos
    Huesped* login(const char* tipo, int num, int pass);
    Reserva* consultarReservas();
    Reserva* crearReserva(Reserva* res);
    bool anularReserva(int codigoReserva);
};

#endif // HUESPED_H
