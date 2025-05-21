TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        anfitrion.cpp \
        fecha.cpp \
        gestorReservas.cpp \
        habitacion.cpp \
        huesped.cpp \
        main.cpp \
        pago.cpp \
        repositorioReservas.cpp \
        reserva.cpp \
        ubicacion.cpp \
        usuario.cpp

HEADERS += \
    anfitrion.h \
    fecha.h \
    gestorReservas.h \
    habitacion.h \
    huesped.h \
    pago.h \
    repositorioReservas.h \
    reserva.h \
    ubicacion.h \
    usuario.h
