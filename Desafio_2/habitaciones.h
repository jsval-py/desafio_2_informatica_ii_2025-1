#ifndef HABITACIONES_H
#define HABITACIONES_H
#include <string>
#include "fecha.h"
#include "sistema.h"
#include "anfitrion.h"

class Anfitrion;
class Sistema;
#define MAX_AMENIDADES 10
#define MAX_HABITACIONES_TOTAL 100

class Habitacion {
private:
    std::string idHabitacion;
    std::string nombreHabitacion;
    std::string tipoHabitacion;
    std::string direccion;
    std::string municipio;
    std::string departamento;
    double precioNoche;
    std::string amenidades[MAX_AMENIDADES];
    Anfitrion* anfitrion;
    Sistema* sistema;
    Reserva* reservas[MAX_RESERVAS];
    int totalReservas;

public:
    // Constructores
    Habitacion();
    Habitacion(const std::string& id, const std::string& nombre, const std::string& tipo, const std::string& dir,
               const std::string& muni, const std::string& depto, double precio, Anfitrion* anfitrion);

    // Destructor
    ~Habitacion();

    // Getters y setters
    std::string getIdHabitacion() const;
    void setIdHabitacion(const std::string& id);
    std::string getNombreHabitacion() const;
    void setNombreHabitacion(const std::string& nombre);
    std::string getTipoHabitacion() const;
    void setTipoHabitacion(const std::string& tipo);
    std::string getDireccion() const;
    void setDireccion(const std::string& dir);
    std::string getMunicipio() const;
    void setMunicipio(const std::string& muni);
    std::string getDepartamento() const;
    void setDepartamento(const std::string& depto);
    std::string getAmenidades() const;
    void setAmenidades(const std::string& amenidadesStr);
    double getPrecioNoche() const;
    void setPrecioNoche(double precio);
    std::string getIdAnfitrion() const;


    // Métodos para mostrar información
    void mostrarInformacion() const;

    // Métodos estáticos para manejo de habitaciones
    static int cargarTodasLasHabitaciones(Sistema* sistema, Habitacion habitaciones[], int maxHabitaciones);
    static int obtenerHabitacionesPorAnfitrion(Sistema* sistema, const std::string& idAnfitrion,
                                               Habitacion habitacionesDelAnfitrion[], int maxHabitaciones);

    // Métodos originales
    void cargarDBHabitaciones(Sistema* sistema);
    static Anfitrion* buscarAnfitrionporId(Sistema* sistema, const std::string& idAnfitrionStr);
    // Métodos de gestión de reservas
    void mostrarReservas() const;
    void agregarReserva(const Reserva& reserva);
    bool cancelarReservaPorId(const char* idReserva);

    // Métodos para la persistencia de reservas
    void cargarReservasDeArchivo(const char* nombreArchivo);
    void guardarReservasEnArchivo(const char* nombreArchivo) const;

};

#endif // HABITACIONES_H
