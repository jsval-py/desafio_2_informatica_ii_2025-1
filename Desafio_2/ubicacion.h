#ifndef UBICACION_H
#define UBICACION_H

class Ubicacion {
private:
    char* departamento;
    char* municipio;
    char* direccionExacta;

public:
    // Constructores
    Ubicacion();
    Ubicacion(const char* dep, const char* mun, const char* dir);

    // Destructor
    ~Ubicacion();

    // Getters y setters
    const char* getDepartamento() const;
    const char* getMunicipio() const;
    const char* getDireccionExacta() const;
    void setDepartamento(const char* dep);
    void setMunicipio(const char* mun);
    void setDireccionExacta(const char* dir);
};

#endif // UBICACION_H
