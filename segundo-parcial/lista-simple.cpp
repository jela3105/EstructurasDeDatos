#include <iostream>
#include <time.h>
struct nodo {
  int dato;   // C1
  nodo *liga; // C2
};

using namespace std;
int main() {
  int opc, n, i, suma, d, band, x;
  srand(time(NULL));
  nodo *p = NULL, *f, *aux;
  while (1) {
    cout << "\n* * * * MENU * * * *\n";
    cout << "0. Imprimir\n";
    cout << "1. Insertar a la derecha\n";
    cout << "2. Insertar a la izquierda\n";
    cout << "3. Inserta datos aleatoreos a la derecha\n";
    cout << "4. Inserta datos aleatoreos a la izquierda\n";
    cout << "\n   Seleccione una opcion: ";
    cin >> opc;
    switch (opc) {
    case 0: // Imprimir
      aux = p;
      if (aux == NULL)
        cout << "* * * Lista vacia * * *\n";
      else {
        cout << "* * * Contenido de la lista * * *\n";
        while (aux != NULL) {
          cout << aux->dato << " ";
          aux = aux->liga;
        }
        cout << "\n";
      }
      break;
    case 1: // Insertar a la derecha
      if (p == NULL) {
        p = new (nodo);
        cout << "Ingresa el dato: ";
        cin >> p->dato;
        p->liga = NULL;
        f = p;
      } else {
        aux = new (nodo);
        cout << "Ingresa el dato: ";
        cin >> aux->dato;
        aux->liga = NULL;
        f->liga = aux;
        f = aux;
      }
      break;
    case 2:
      if (p == NULL) {
        p = new (nodo);
        cout << "Ingresa el dato: ";
        cin >> p->dato;
        p->liga = NULL;
        f = p;
      } else {
        aux = new (nodo);
        cout << "Ingresa el dato: ";
        cin >> aux->dato;
        aux->liga = p;
        p = aux;
      }
      break;
    case 3:
      cout << "Ingresa la cantidad de datos: ";
      cin >> n;
      while (n) {
        if (p == NULL) {
          p = new (nodo);
          p->dato = 1 + rand() % 100;
          p->liga = NULL;
          f = p;
        } else {
          aux = new (nodo);
          aux->dato = 1 + rand() % 100;
          aux->liga = NULL;
          f->liga = aux;
          f = aux;
        }
        n--;
      }
      break;
    case 4:
      cout << "Ingresa la cantidad de datos: ";
      cin >> n;
      while (n) {
        if (p == NULL) {
          p = new (nodo);
          p->dato = 1 + rand() % 100;
          p->liga = NULL;
          f = p;
        } else {
          aux = new (nodo);
          aux->dato = 1 + rand() % 100;
          aux->liga = p;
          p = aux;
        }
        n--;
      }
      break;
    }
  }
}
