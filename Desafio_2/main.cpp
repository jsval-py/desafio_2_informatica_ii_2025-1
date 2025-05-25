#include <iostream>
#include <string>
#include "sistema.h"

using namespace std;

void menuPrincipal()
{
    cout << "1. Iniciar Sesion" << endl;
    cout << "2. Salir" << endl;
}

void InicioSesion(Sistema& sistema) {
    string usuario, password;

    cout << "\n=== INICIO DE SESIÓN ===" << endl;
    cout << "Usuario: ";
    getline(cin, usuario);
    cout << "Password: ";
    getline(cin, password);

    if (sistema.iniciarSesion(usuario, password)) {
        cout << "¡Bienvenido al sistema!" << endl;
    } else {
        cout << "Error en el inicio de sesión" << endl;
    }
}

int main()
{
    Sistema sistema;
    int opcion;

    do {
        menuPrincipal();
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore(); // Limpiar buffer

        switch (opcion) {
            case 1:
                InicioSesion(sistema);
                break;
            case 2:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
                break;
        }
    } while (opcion != 2);

    return 0;
}
