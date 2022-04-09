#include <iostream>
#include <string>

using namespace std;

struct cancion {
  string nombre, genero, artista;
  struct cancion *anterior = nullptr, *siguiente = nullptr;
};

struct ListaReproduccion {
  struct cancion *primera, *ultima, *actual;
  ListaReproduccion() : primera(nullptr), ultima(nullptr), actual(nullptr) {}
  void agregarCancion();
  void imprimirLista();
};

int main() {
  int opcion;
  struct ListaReproduccion lista;
  while (true) {
    cout << "\n-------------REPRODUCTOR DE MUSICA-----------------\n";
    cout << "1. Lista de reproduccion" << endl;
    cout << "2. Siguiente" << endl;
    cout << "3. Anterior" << endl;
    cout << "4. Reproduccion aleatoria" << endl;
    cout << "5. Eliminar cancion" << endl;
    cout << "6. Agregar cancion" << endl;
    cout << "7. Buscar" << endl;
    cout << "Seleccione una opcion: ";
    cin >> opcion;
    switch (opcion) {
    case 1:
      lista.imprimirLista();
      break;
    case 2:
      break;
    case 3:
      break;
    case 4:
      break;
    case 5:
      break;
    case 6:
      lista.agregarCancion();
      break;
    case 7:
      break;
    }
  }
}

void ListaReproduccion::agregarCancion() {
  struct cancion *nuevaCancion = new cancion;
  // para que no lea una linea vacia hay que ignorar la line en la que esta
  string lineaVacia;
  std::getline(cin, lineaVacia);
  cout << "\n    Ingresa el nombre de la cancion: ";
  std::getline(cin, nuevaCancion->nombre);
  cout << "\n    Ingresa el artista: ";
  std::getline(cin, nuevaCancion->artista);
  cout << "\n    Ingresa el genero: ";
  std::getline(cin, nuevaCancion->genero);

  if (primera == nullptr) {
    primera = nuevaCancion;
    ultima = nuevaCancion;
  }

  ultima->siguiente = nuevaCancion;
  nuevaCancion->siguiente = primera;
  primera->anterior = nuevaCancion;
  nuevaCancion->anterior = ultima;
  ultima = nuevaCancion;
}

void ListaReproduccion::imprimirLista() {
  if (primera == nullptr) {
    cout << "\n    Lista vacia" << endl;
    return;
  }
  cout << endl;
  struct cancion *aux = new cancion;
  aux = primera;
  do {
    cout << aux->nombre << endl;
    cout << "    artista: " << aux->artista << endl;
    cout << "    genero: " << aux->genero << endl;
    cout << endl;
    ;
    aux = aux->siguiente;
  } while (aux != primera);
}
