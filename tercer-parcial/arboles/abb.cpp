#include <iostream>
using namespace std;

struct nodo {
  int dato;
  struct nodo *izq, *der;
  nodo() {
    dato = -1;
    izq = NULL;
    der = NULL;
  }
  nodo(int n) {
    this->dato = n;
    izq = NULL;
    der = NULL;
  }
};

void agregarDato(int, struct nodo *);
void inOrden(struct nodo *);

int main() {
  int opt, n;
  nodo *raiz = new nodo();
  while (1) {
    cout << endl << endl;
    cout << "1. Ingresar un dato" << endl;
    cout << "2. inOrden" << endl;
    cout << "3. Imprimir raiz" << endl;
    cin >> opt;
    switch (opt) {
    case 1:
      cout << "Ingresa el dato" << endl;
      cin >> n;
      agregarDato(n, raiz);
      break;
    case 2:
      inOrden(raiz);
      break;
    case 3:
      cout << raiz->dato << endl;
      break;
    }
  }

  return 0;
}

void inOrden(struct nodo *raiz) {
  if (raiz == NULL)
    return;

  if (raiz->dato == -1) {
    cout << "No hay datos en el arbol" << endl;
    return;
  }

  inOrden(raiz->izq);
  cout << raiz->dato << " ";
  inOrden(raiz->der);
}

void agregarDato(int n, struct nodo *raiz) {

  if (raiz == NULL)
    return;

  if (raiz->dato == -1) {
    raiz->dato = n;
    return;
  }

  if (n == raiz->dato) {
    cout << "El dato ya se encuentra en el arbol" << endl;
    return;
  }

  if (n > raiz->dato and raiz->der == NULL) {
    nodo *nuevoNodo = new nodo(n);
    raiz->der = nuevoNodo;
    return;
  }

  if (n < raiz->dato and raiz->izq == NULL) {
    nodo *nuevoNodo = new nodo(n);
    raiz->izq = nuevoNodo;
    return;
  }

  (n > raiz->dato) ? agregarDato(n, raiz->der) : agregarDato(n, raiz->izq);
}
