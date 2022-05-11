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
void buscar(struct nodo *, int);

struct nodo {
  int dato;
  nodo *der, *izq;
};

int main() {
  int m = -1;
  nodo *raiz;
  raiz = new (nodo);
  crearArbolConsola(raiz);

  while (true) {
    int opt;
    cout << "\n\nARBOL BINARIO" << endl;
    cout << "1. Recorrido preOrden" << endl;
    cout << "2. Recorrido inOrden" << endl;
    cout << "3. Recorrido postOrden" << endl;
    cout << "4. Sumatoria" << endl;
    cout << "5. Promedio" << endl;
    cout << "6. Maximo" << endl;
    cout << "7. Busqueda" << endl;
    cout << "Ingresa una opcion: ";
    cin >> opt;
    switch (opt) {
    case 1:
      cout << "Recorrido preOrden" << endl;
      preOrden(raiz);
      break;
    case 2:
      cout << endl << "Recorrido InOrden" << endl;
      inOrden(raiz);
      break;
    case 3:
      cout << endl << "Recorrido postOrden" << endl;
      postOrden(raiz);
      break;
    case 4:
      cout << endl << "Sumatoria: ";
      cout << sumatoria(raiz);
      break;
    case 5:
      cout << endl << "Promedio: ";
      cout << (float)sumatoria(raiz) / contarHijos(raiz);
      break;
    case 6:
      m = -1;
      maximo(raiz, m);
      cout << endl << "Maximo: ";
      cout << m;
      break;
    case 7:
      cout << "Ingresa el numero a buscar: ";
      cin >> m;
      buscar(raiz, m);
      break;
    }
  }
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

void buscar(struct nodo *raiz, int n) {
  if (raiz == NULL)
    return;

  if (raiz->dato == n) {
    cout << "Dato encontrado";
    return;
  }

  buscar(raiz->der, n);
  buscar(raiz->izq, n);
}
