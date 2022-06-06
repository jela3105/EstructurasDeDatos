#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

#define infinito 1000

using namespace std;
int main() {
  unordered_map<string, int> estacion_a_numero;
  unordered_map<int, string> numero_a_estacion;
  unordered_map<string, int> linea_de_direccion;

  int numero_lineas, numero_estaciones;
  cin >> numero_lineas >> numero_estaciones;

  vector<vector<int>> mapa(numero_estaciones,
                           vector<int>(numero_estaciones, infinito));

  vector<vector<string>> direcciones(numero_estaciones,
                                     vector<string>(numero_estaciones, ""));

  for (int i = 0; i < mapa.size(); i++) {
    for (int j = 0; j < mapa.size(); j++) {
      if (i == j)
        mapa[i][j] = 0;
    }
  }

  int ne = 0;
  while (numero_lineas--) {
    int linea;
    cin >> linea;
    string lineaVacia, direccion1, direccion2;
    getline(cin, lineaVacia);
    getline(cin, direccion1);
    getline(cin, direccion2);
    linea_de_direccion[direccion1] = linea;
    linea_de_direccion[direccion2] = linea;
    int n_estaciones_ingresar;
    cin >> n_estaciones_ingresar;
    string anterior = "";
    getline(cin, lineaVacia);
    while (n_estaciones_ingresar--) {
      string nombre_estacion;
      getline(cin, nombre_estacion);
      if (estacion_a_numero.find(nombre_estacion) == estacion_a_numero.end()) {
        estacion_a_numero[nombre_estacion] = ne;
        numero_a_estacion[ne] = nombre_estacion;
        ne++;
      } else {
        // cout << nombre_estacion << " " << anterior << endl;
      }
      if (anterior != "") {
        mapa[estacion_a_numero[anterior]][estacion_a_numero[nombre_estacion]] =
            1;
        mapa[estacion_a_numero[nombre_estacion]][estacion_a_numero[anterior]] =
            1;
        direcciones[estacion_a_numero[nombre_estacion]]
                   [estacion_a_numero[anterior]] = direccion1;
        direcciones[estacion_a_numero[anterior]]
                   [estacion_a_numero[nombre_estacion]] = direccion2;
      }
      anterior = nombre_estacion;
    }
  }

  vector<int> camino;
  set<int> visitados;

  string origen, estacion_destino;
  getline(cin, origen);
  cout << "Estacion de partida: " << origen << endl;
  getline(cin, estacion_destino);
  cout << "Destino: " << estacion_destino << endl;

  int destino_numero = estacion_a_numero[estacion_destino];
  int nodo_actual = estacion_a_numero[origen];

  camino.push_back(nodo_actual);
  while (destino_numero != nodo_actual) {
    // cout << numero_a_estacion[nodo_actual] << endl;
    visitados.insert(nodo_actual);
    bool encontrado = false;
    for (int i = 0; i < mapa.size(); i++) {
      if (mapa[nodo_actual][i] == 1 and visitados.find(i) == visitados.end()) {
        nodo_actual = i;
        camino.push_back(i);
        encontrado = true;
        break;
      }
    }
    if (!encontrado) {
      camino.pop_back();
      nodo_actual = camino[camino.size() - 1];
    }
  }

  string direccion = direcciones[camino[0]][camino[1]];

  cout << "------------Direccion " << direccion << " de la linea "
       << linea_de_direccion[direccion] << endl;

  for (int i = 0; i < camino.size(); i++) {
    cout << numero_a_estacion[camino[i]] << endl;
    if (direcciones[camino[i]][camino[i + 1]] != direccion and
        i + 1 < camino.size() - 1) {
      cout << "------------Transbordo a direccion ";
      direccion = direcciones[camino[i]][camino[i + 1]];
      cout << direccion << " de la linea " << linea_de_direccion[direccion]
           << endl;
    }
  }

  return 0;
}
