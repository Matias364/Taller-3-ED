#pragma once
#include <iostream>
#include <vector>

#include "Nodo.h"
#include "Connection.h"
using namespace std;

class Grafo {
private:
    vector<Nodo> nodos;
    vector<Connection> conexiones;

public:
    void agregarNodo(Nodo nodo) {
        nodos.push_back(nodo);
    }

    void agregarConexion(Connection conexion) {
        conexiones.push_back(conexion);
    }

    Nodo getNodoId(int id) {
        for (Nodo n : nodos) {
            if (n.getID() == id) {
                return n;
            }
        }
        cout << "Nodo no encontrado" << endl;
        // Retorna un nodo inválido en caso de no encontrarlo
        return Nodo(-1, "", "");
    }

    vector<Connection> getConexiones() {
        return conexiones;
    }
};