#pragma once
#include <iostream>
#include <vector>

#include "Grafo.h"
using namespace std;

class BellmanFord {
private:
    Grafo grafo;
    vector<int> distancias;
    vector<int> predecesores;

public:
    BellmanFord(Grafo grafo) : grafo(grafo) {}

    void calcularRuta(int origen) {
        inicializar(origen);

        for (int i = 0; i < grafo.getConexiones().size() - 1; ++i) {
            for (auto par : grafo.getConexiones()) {
                Connection conexion= conexion;
                relajar(conexion);
            }
        }

        // Verificar si hay ciclos negativos
        for ( auto conexion : grafo.getConexiones()) {
            if (distancias[conexion.getIdServidor()] > distancias[conexion.getIdCliente()] + conexion.getDistancia()) {
                cerr << "Error: Ciclo negativo detectado." << endl;
                exit(1);
            }
        }
    }

    int obtenerDistancia(int destino) const {
        return distancias.at(destino);
    }

    vector<int> obtenerRuta(int destino) const {
        vector<int> ruta;
        int actual = destino;

        while (actual != -1) {
            ruta.insert(ruta.begin(), actual);
            actual = predecesores.at(actual);
        }

        return ruta;
    }
    private:
    void inicializar(int origen) {
        for (const auto& nodo : grafo.getConexiones()) {
            distancias.push_back(INT_MAX);
            predecesores.push_back(-1);
        }

        distancias[origen] = 0;
    }

    void relajar(Connection conexion) {
        int idCliente = conexion.getIdCliente();
        int idServidor = conexion.getIdServidor();
        int nuevaDistancia = distancias[idCliente] + conexion.getDistancia();

        if (distancias[idServidor] > nuevaDistancia) {
            distancias[idServidor] = nuevaDistancia;
            predecesores[idServidor] = idCliente;
        }
    }
};
