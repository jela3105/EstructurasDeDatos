#include <iostream>
using namespace std;

struct nodo {
  int dato;
  struct nodo *anterior, *siguiente;
};

int main() {
  nodo *p = NULL, *f = NULL, *aux = NULL;
  int opc, x;
  while (true) {
    cout << "\n\n=========== LISTA DOBLE CIRCULAR===========" << endl;
    cout << "0. Imprimir de izquierda a derecha" << endl;
    cout << "1. Imprimir de derecha a izquierda" << endl;
    cout << "2. Insertar a la derecha" << endl;
    cout << "Ingresa una opcion: ";
    cin >> opc;
    switch (opc) {
    case 0:
      if (p == NULL) {
        cout << "\n    Lista vacia";
        break;
      }
      aux = p;
      cout << endl;
      do {
        cout << aux->dato << " ";
        aux = aux->siguiente;
      } while (aux != p);
      break;
    case 1:
      if (p == NULL) {
        cout << "\n    Lista vacia";
        break;
      }
      aux = f;
      cout << endl;
      do {
        cout << aux->dato << " ";
        aux = aux->anterior;
      } while (aux != f);
      break;
    case 2:
      aux = new nodo();
      cout << "\n    Ingresa el dato: ";
      cin >> x;
      aux->dato = x;
      if (p == NULL) {
        p = aux;
        f = aux;
      }
      f->siguiente = aux;
      aux->siguiente = p;
      p->anterior = aux;
      aux->anterior = f;
      f = aux;
      break;
    }
  }
  return 0;
}
