#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <climits>

#include "Nodo.h"
#include "Connection.h"
#include "Grafo.h"
#include "BellmanFord.h"
using namespace std;



int main() {
    ifstream archivoS("servidores.csv");
    string linea1;

    // Vector para almacenar los nodos
    vector<Nodo> nodos;

    getline(archivoS, linea1);
    while (getline(archivoS, linea1)) {
        stringstream ss(linea1);
        string nombre, tipo, idl;
        getline(ss, idl, ',');
        int id = stoi(idl);
        getline(ss, nombre, ',');
        getline(ss, tipo, ',');
        Nodo nodo(id, nombre, tipo);

        // Agregar el nodo al vector de nodos
        nodos.push_back(nodo);
    }

    ifstream archivoC("conexiones.csv");
    string linea;
    // Vector para almacenar las conexiones
    vector<Connection> conexiones;

    if (!archivoC.is_open()) {
        cerr << "Error al abrir el archivo: " << "conexiones" << endl;
        return 1; // Salir con un código de error
    }
    getline(archivoC, linea);
    while (getline(archivoC, linea)) {
        stringstream ss(linea);
        string idCL, idSL, velocidad, distancia;
        getline(ss, idCL, ',');
        int idCliente = stoi(idCL);
        getline(ss, idSL, ',');
        int idServidor = stoi(idSL);
        getline(ss, velocidad, ',');
        int vel = stoi(velocidad);
        getline(ss, distancia, ',');
        int dist = stoi(distancia);
        Connection conexion(idCliente, idServidor, vel, dist);

        // Agregar la conexión al vector de conexiones
        conexiones.push_back(conexion);
    }

    // Crear el grafo y agregar nodos y conexiones
    Grafo grafo;
    for (auto nodo : nodos) {
        grafo.agregarNodo(nodo);
    }

    for (auto conexion : conexiones) {
        grafo.agregarConexion(conexion);
    }

    // Solicitar entrada al usuario
    int origen, destino, tamanoArchivo;
    cout << "Ingrese el ID del nodo de origen: ";
    cin >> origen;
    cout << "Ingrese el ID del nodo de destino: ";
    cin >> destino;
    cout << "Ingrese el tamaño del archivo que desea enviar (en MB): ";
    cin >> tamanoArchivo;


    // Calcular ruta utilizando Bellman-Ford
    BellmanFord bellmanFord(grafo);
    bellmanFord.calcularRuta(origen);

    // Calcular la cantidad de partes en que se dividirá el archivo
    int partes = (tamanoArchivo % 600 == 0) ? tamanoArchivo / 600 : tamanoArchivo / 600 + 1;

    // Mostrar resultados
    cout << "Tiempo estimado de entrega total: " << partes * bellmanFord.obtenerDistancia(destino) << " segundos" << endl;

    vector<int> ruta = bellmanFord.obtenerRuta(destino);
    cout << "Ruta:" << endl;

    for (int i = 0; i < ruta.size() - 1; ++i) {
        int idCliente = ruta[i];
        int idServidor = ruta[i + 1];

        // Obtener información de nodos
        Nodo nodoCliente = grafo.getNodoId(idCliente);
        Nodo nodoServidor = grafo.getNodoId(idServidor);

        // Obtener información de conexión
        Connection conexion(-1,-1,-1,-1);
        for (auto con : grafo.getConexiones()) {
            if (con.getIdCliente() == idCliente && con.getIdServidor() == idServidor) {
                conexion = con;
                break;
            }
        }

        cout << nodoCliente.getNombre() << " -> " << nodoServidor.getNombre() << " en " << conexion.getDistancia() << " segundos" << endl;
    }

    return 0;
}