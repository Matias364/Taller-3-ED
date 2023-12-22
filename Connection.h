#pragma once
#include <iostream>
using namespace std;

class Connection {
private:
    int idCliente, idServidor, velocidad, distancia;

public:
    Connection(int idC, int idS, int vel, int distancia) {
        this->idCliente = idC;
        this->idServidor = idS;
        this->velocidad = vel;
        this->distancia = distancia;
    }

    int getIdCliente() {
        return this->idCliente;
    }

    int getIdServidor() {
        return this->idServidor;
    }

    int getVelocidad() {
        return this->velocidad;
    }

    int getDistancia() {
        return this->distancia;
    }
};