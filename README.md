# Taller-3-ED
Taller 3 ED
Nombre: Matias Nicolas Cortes Borquez

Se ocupará el comando “g++ -o main main.cpp” para compilar el
proyecto.


Implementación de algoritmo:
Inicialmente se parte leyendo los csv, separando y ordenando los datos en sus respectivas clases para posteriormente utilizar esa información en la creación de la clase grafo que contendrá todos los nodos y conexiones existentes.
Para la implementación del algoritmo BellmanFord se parte entregando el grafo con todos los nodos a la clase y se llama al metodo para calcular una ruta a partir de un nodo de origen. El algoritmo mantiene una lista de distancias más cortas desde el origen hacia cada nodo, inicializando (comenzando camino) todas las distancias con un valor infinito excepto la distancia al propio nodo de origen, que se inicializa a cero. Luego, el algoritmo en un ciclo for pasa sobre todas las aristas en el grafo, relajando (actualizando camino más corto) las distancias almacenadas en cada recorrido del ciclo. En este ultimo lo que hace es comparar la distancia actual almacenada para un nodo con la nueva distancia calculada a través de una conexión y, si es menor, actualiza la distancia almacenada y el predecesor. Una vez obtenida la mejor ruta se puede calcular la distancia (tiempo).
