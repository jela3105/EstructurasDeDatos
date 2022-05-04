#include <iostream>

using namespace std;

void crearArbolConsola(struct nodo *);
void preOrden(struct nodo *);
void inOrden(struct nodo *);
void postOrden(struct nodo *);
void llenarArbol(struct nodo *);
void crearArbol(struct nodo *);
int sumatoria(struct nodo *);
int contarHijos(struct nodo *);
void maximo(struct nodo *, int &);

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
  cout << endl << "Sumatoria: ";
  cout << sumatoria(raiz);
  cout << endl << "Promedio: ";
  cout << (float)sumatoria(raiz) / contarHijos(raiz);
  int m = -1;
  maximo(raiz, m);
  cout << endl << "Maximo: ";
  cout << m;
}

void crearArbolConsola(struct nodo *raiz) {
  int resp;
  nodo *nuevo;
  cout << "Ingresa el valor: ";
  cin >> raiz->dato;
  cout << raiz->dato << " Tiene hijo a la izquierda: ";
  cin >> resp;
  if (resp == 1) {
    nuevo = new nodo();
    raiz->izq = nuevo;
    crearArbolConsola(nuevo);
  } else
    raiz->izq = NULL;

  cout << raiz->dato << " Tiene hijo a la derecha: ";
  cin >> resp;
  if (resp == 1) {
    nuevo = new (nodo);
    raiz->der = nuevo;
    crearArbolConsola(nuevo);
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
  if (raiz == NULL)
    return;

  inOrden(raiz->izq);

  cout << raiz->dato << " ";

  inOrden(raiz->der);
}

void postOrden(struct nodo *raiz) {
  if (raiz == NULL)
    return;

  postOrden(raiz->izq);

  postOrden(raiz->der);

  cout << raiz->dato << " ";
}

void crearArbol(struct nodo *raiz) {
  int resp;
  nodo *nuevo;
  cin >> raiz->dato;
  cin >> resp;

  if (resp == 1) {
    nuevo = new nodo();
    raiz->izq = nuevo;
    crearArbol(nuevo);
  } else
    raiz->izq = NULL;

  cin >> resp;
  if (resp == 1) {
    nuevo = new (nodo);
    raiz->der = nuevo;
    crearArbol(nuevo);
  } else
    raiz->der = NULL;
}

int sumatoria(struct nodo *raiz) {
  if (raiz == NULL)
    return 0;
  int suma = sumatoria(raiz->izq) + sumatoria(raiz->der);
  return suma + raiz->dato;
}

int contarHijos(struct nodo *raiz) {
  if (raiz == NULL)
    return 0;
  return 1 + contarHijos(raiz->izq) + contarHijos(raiz->der);
}

void maximo(struct nodo *raiz, int &m) {
  if (raiz == NULL)
    return;
  if (raiz->dato > m)
    m = raiz->dato;
  maximo(raiz->izq, m);
  maximo(raiz->der, m);
}
