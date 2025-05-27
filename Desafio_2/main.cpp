#include <iostream>
#include <string>
#include "sistema.h"
#include "anfitrion.h"

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
        // Aquí se puede agregar lógica adicional según el tipo de usuario
        if (sistema.getTipoUsuarioActual() == 1) {
            int opcion;
            sistema.mostrarMenuHuesped();
            cout<<"Selecciona una opcion"<<endl;
            cin >> opcion;
            cin.ignore();
            switch (opcion)
            {
                case 1:
                    // Aquí se puede implementar la lógica para consultar habitaciones
                    cout << "Consultando habitaciones..." << endl;
                    break;
                case 2:
                    // Aquí se puede implementar la lógica para realizar una reserva
                    cout << "Realizando una reserva..." << endl;
                    break;
                case 3:
                    // Aquí se puede implementar la lógica para cancelar una reserva
                    cout << "Cancelando una reserva..." << endl;
                    break;
                default:
                    cout << "Opción no válida." << endl;
                    break;
            }
        } else if (sistema.getTipoUsuarioActual() == 2) {
            sistema.mostrarMenuAnfitrion();
        }
    } else {
        cout << "Usuario o contraseña incorrectos." << endl;
    }
}

int main() {
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
