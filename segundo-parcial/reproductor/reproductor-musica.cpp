#include <iostream>
using namespace std;

struct cancion {
  string nombre, genero, artista;
  struct cancion *anterior, *siguiente;
};

int main() {
  while (true) {
    cout << "0. Imprimir de izquierda a derecha" << endl;
    cout << "1. Imprimir de derecha a izquierda" << endl;
    cout << "2. Insertar a la derecha" << endl;
    cout << "Ingresa una opcion: ";
  }
}
