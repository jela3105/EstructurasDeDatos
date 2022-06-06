#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#define infinito 1000

using namespace std;

int main() {
  unordered_map<string, int> estacion_a_numero;
  unordered_map<int, string> numero_a_estacion;

  int numero_lineas, numero_estaciones;
  cin >> numero_lineas >> numero_estaciones;
  vector<vector<int>> mapa(numero_estaciones,
                           vector<int>(numero_estaciones, infinito));

  vector<vector<string>> direcciones(numero_estaciones,
                                     vector<string>(numero_estaciones, ""));
  int ne = 0;
  while (numero_lineas--) {
    int linea;
    cin >> linea;
    string lineaVacia, direccion1, direccion2;
    getline(cin, lineaVacia);
    getline(cin, direccion1);
    getline(cin, direccion2);
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
      }
      if (anterior != "") {
        direcciones[estacion_a_numero[nombre_estacion]]
                   [estacion_a_numero[anterior]] = direccion1;
        direcciones[estacion_a_numero[anterior]]
                   [estacion_a_numero[nombre_estacion]] = direccion2;
      }
      anterior = nombre_estacion;
    }
  }

  vector<vector<int>> costos = mapa;
  return 0;
}
