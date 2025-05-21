#ifndef REPOSITORIORESERVAS_H
#define REPOSITORIORESERVAS_H

class Reserva;

class RepositorioReservas {
private:
    char* rutaArchivoActivas;
    char* rutaArchivoHistorico;

public:
    // Constructores
    RepositorioReservas();
    RepositorioReservas(const char* rutaActivas, const char* rutaHistorico);

    // Destructor
    ~RepositorioReservas();

    // Getters y setters
    const char* getRutaArchivoActivas() const;
    const char* getRutaArchivoHistorico() const;
    void setRutaArchivoActivas(const char* ruta);
    void setRutaArchivoHistorico(const char* ruta);

    // Métodos
    Reserva* leerReservasActivas();
    Reserva* leerReservasHistoricas();
    bool guardarReserva(Reserva* res);
    bool eliminarReserva(Reserva* res);
    bool moverAHistorico(Reserva* res);
};
#endif // REPOSITORIORESERVAS_H
