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
  void eliminar();
  struct cancion *buscar(string, bool);
  void buscarYReproducir();
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
    cout << "7. Buscar y reproducir" << endl;
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
      lista.eliminar();
      break;
    case 6:
      lista.agregarCancion();
      break;
    case 7:
      lista.buscarYReproducir();
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

void ListaReproduccion::eliminar() {
  if (primera == nullptr) {
    cout << "\n    Lista vacia";
    return;
  }

  cout << "\n    Ingresa el nombre de la cancion: ";
  string lineaVacia;
  getline(cin, lineaVacia);
  string nombre;
  getline(cin, nombre);

  struct cancion *aux = primera;
  bool encontrado = false;
  do {
    if (aux->nombre == nombre) {
      encontrado = true;
      break;
    }
    aux = aux->siguiente;
  } while (aux != primera);

  if (!encontrado) {
    cout << "\n    La cancion no fue encontrada";
    return;
  }

  if (aux == primera and aux->siguiente == primera) {
    delete aux;
    primera = nullptr;
    ultima = nullptr;
    return;
  }

  aux->anterior->siguiente = aux->siguiente;
  aux->siguiente->anterior = aux->anterior;

  delete aux;

  if (aux == primera) {
    primera = primera->siguiente;
    return;
  }

  if (aux == ultima)
    ultima = ultima->anterior;
}

struct cancion *ListaReproduccion::buscar(string nombre, bool porCancion) {
  // porCancion = true: va a buscar la cancion
  // porCancion = false: va a buscar por artista
  struct cancion *aux = primera;
  bool encontrado = false;
  do {
    if ((nombre == aux->nombre and porCancion) or
        (nombre == aux->artista and !porCancion)) {
      encontrado = true;
      break;
    }
    aux = aux->siguiente;
  } while (aux != primera);

  if (encontrado)
    return aux;
  return nullptr;
}

void ListaReproduccion::buscarYReproducir() {
  bool buscarCancion;
  string nombre;
  cout << "Ingresa 0 si desea buscar por artista" << endl;
  cout << "Ingresa 1 si desea buscar por cancion" << endl;
  cin >> buscarCancion;
  cout << "Ingrese el nombre: " << endl;
  cin >> nombre;
  struct cancion *cancionAReproducir = buscar(nombre, buscarCancion);
  if (cancionAReproducir == nullptr) {
    cout << "\n    No se ha encontrado la cancion";
    return;
  }
  // reproducir cancion
}
