#pragma once
#include <iostream>
using namespace std;
class Nodo {
private:
    int id;
    string nombre, tipo;

public:
    Nodo(int id, string nombre, string tipo) {
        this->id = id;
        this->nombre = nombre;
        this->tipo = tipo;
    }

    int getID() {
        return this->id;
    }

    string getNombre() {
        return this->nombre;
    }

    string getTipo() {
        return this->tipo;
    }
};