#ifndef USUARIO_H
#define USUARIO_H

class Usuario{
private:
    char* tipoIdentidad;
    int numIdentidad;
    int password;
public:
    //Constructor
    Usuario();
    Usuario(char* tipoIdentidad, int numIdentidad, int password);

    //Destructor
    ~Usuario();

    //Getters y setters
    const char* getTipoIdentidad() const;
    int getNumIdentidad() const;
    int getPassword() const;
    void setTipoIdentidad(const char* tipoId);
    void setNumIdentidad(int numId);
    void setPassword(int pass);

    //Métodos
    Usuario* logIn(const char* tipoId, int numId, int pass);
    bool iniciarSesion(const char* tipoId, int numId, int pass);
};

#endif // USUARIO_H
