#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#define infinito 1000

using namespace std;

void floyd(vector<vector<int>> &, vector<vector<int>> &);
void inicializarRutas(vector<vector<int>> &);
vector<int> findPath(vector<vector<int>>, int, int);
void printMatrix(vector<vector<int>>);

int main() {
  unordered_map<string, int> estacion_a_numero;
  unordered_map<int, string> numero_a_estacion;

  int numero_lineas, numero_estaciones;
  cin >> numero_lineas >> numero_estaciones;

  vector<vector<int>> mapa(numero_estaciones,
                           vector<int>(numero_estaciones, infinito));

  vector<vector<int>> rutas(numero_estaciones,
                            vector<int>(numero_estaciones, infinito));
  inicializarRutas(rutas);
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

  vector<vector<int>> costos = mapa;

  // printMatrix(mapa);
  cout << endl;
  //  printMatrix(costos);
  cout << endl;
  //  printMatrix(rutas);
  cout << endl;

  floyd(costos, rutas);
  string origen, destino;

  getline(cin, origen);
  cout << origen << endl;
  getline(cin, destino);
  cout << destino << endl;

  vector<int> camino =
      findPath(rutas, estacion_a_numero[origen], estacion_a_numero[destino]);
  cout << "caminos " << endl;

  string direccion = direcciones[camino[0]][camino[1]];
  string anterior = direccion;

  for (auto estacion : camino) {
    cout << numero_a_estacion[estacion] << endl;
    anterior = numero_a_estacion[estacion];
  }
  cout << destino << endl;

  return 0;
}

void inicializarRutas(vector<vector<int>> &routes) {
  for (int i = 0; i < routes.size(); i++) {
    for (int j = 0; j < routes.size(); j++) {
      routes[j][i] = i;
    }
  }
  for (int i = 0; i < routes.size(); i++) {
    for (int j = 0; j < routes.size(); j++) {
      if (i == j)
        routes[i][j] = infinito;
    }
  }
}

void floyd(vector<vector<int>> &costs, vector<vector<int>> &routes) {
  for (int compared = 0; compared < costs.size(); compared++) {
    for (int i = 0; i < costs.size(); i++) {
      if (i == compared)
        continue;
      for (int j = 0; j < costs.size(); j++) {
        if (j == compared)
          continue;
        int cost = costs[i][compared] + costs[compared][j];
        if (cost < costs[i][j]) {
          costs[i][j] = cost;
          routes[i][j] = compared;
        }
      }
    }
  }
}

vector<int> findPath(vector<vector<int>> routes, int origin, int destiny) {
  int position = destiny;
  vector<int> path;
  while (routes[origin][position] != position) {
    path.insert(path.begin(), routes[origin][position]);
    position = routes[origin][position];
  }
  return path;
}

void printMatrix(vector<vector<int>> matrix) {
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[0].size(); j++) {
      matrix[i][j] == infinito ? cout << "i\t" : cout << matrix[i][j] << "\t";
    }
    cout << endl;
  }
}
