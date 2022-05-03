#include <iostream>

using namespace std;

void crearArbol(struct nodo *);
void preOrden(struct nodo *);
void inOrden(struct nodo *);
void postOrden(struct nodo *);
void llenarArbol(struct nodo *);

struct nodo {
  int dato;
  nodo *der, *izq;
};

int main() {
  nodo *raiz;
  raiz = new (nodo);
  crearArbol(raiz);
  cout << "Recorrido preOrden" << endl;
  preOrden(raiz);
  cout << endl << "Recorrido InOrden" << endl;
  inOrden(raiz);
  cout << endl << "Recorrido postOrden" << endl;
  postOrden(raiz);
}

void crearArbol(struct nodo *raiz) {
  int resp;
  nodo *nuevo;
  cout << "Ingresa el valor: ";
  cin >> raiz->dato;
  cout << raiz->dato << " Tiene hijo a la izquierda: ";
  cin >> resp;
  if (resp == 1) {
    nuevo = new nodo();
    raiz->izq = nuevo;
    crearArbol(nuevo);
  } else
    raiz->izq = NULL;

  cout << raiz->dato << " Tiene hijo a la derecha: ";
  cin >> resp;
  if (resp == 1) {
    nuevo = new (nodo);
    raiz->der = nuevo;
    crearArbol(nuevo);
  } else
    raiz->der = NULL;
}

void preOrden(struct nodo *raiz) {
  if (raiz == NULL)
    return;

  cout << raiz->dato << " ";

  preOrden(raiz->izq);

  preOrden(raiz->der);
}

void inOrden(struct nodo *raiz) {
  preOrden(raiz->izq);

  cout << raiz->dato << " ";

  preOrden(raiz->der);
}

void postOrden(struct nodo *raiz) {
  preOrden(raiz->izq);

  preOrden(raiz->der);

  cout << raiz->dato << " ";
}
