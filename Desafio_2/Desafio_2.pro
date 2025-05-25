TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        anfitrion.cpp \
        fecha.cpp \
        gestorDB.cpp \
        habitaciones.cpp \
        huesped.cpp \
        main.cpp \
        pago.cpp \
        reservas.cpp \
        sistema.cpp

HEADERS += \
    anfitrion.h \
    fecha.h \
    gestorDB.h \
    habitaciones.h \
    huesped.h \
    pago.h \
    reservas.h \
    sistema.h
