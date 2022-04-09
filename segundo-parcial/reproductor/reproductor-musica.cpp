#include <iostream>
using namespace std;

struct cancion {
  string nombre, genero, artista;
  struct cancion *anterior, *siguiente;
};

bool reproducirCancion(struct cancion) {}

int main() {
  int opcion;
  while (true) {
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
      break;
    case 7:
      break;
    }
  }
}
