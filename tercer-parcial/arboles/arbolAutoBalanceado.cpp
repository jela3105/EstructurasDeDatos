#include <iostream>
using namespace std;

void leerArbolConsola();
void leerArbol(struct nodo *);
void agregarNodo(int n, struct nodo *raiz);
void balancearArbol(struct nodo *, int);
void inOrden(struct nodo *);
void rotacionDD(struct nodo *);
void rotacionII(struct nodo *);
void rotacionDI(struct nodo *);
void rotacionID(struct nodo *);
struct nodo *encontrarDesbalanceo(struct nodo *);

struct nodo {
  int dato;
  nodo *der, *izq;
  nodo() {
    dato = -1;
    izq = nullptr;
    der = nullptr;
  }
  nodo(int n) {
    this->dato = n;
    izq = nullptr;
    der = nullptr;
  }
};

int main() {
  struct nodo *raiz = new nodo();
  // leerArbolConsola();
  leerArbol(raiz);
  // imprimirArbol();
  return 0;
}

void leerArbol(struct nodo *raiz) {
  int n, dato;
  cin >> n;
  while (n--) {
    cin >> dato;
    agregarNodo(dato, raiz);
    struct nodo *subArbolDesbalanceado = encontrarDesbalanceo(raiz);
    if (subArbolDesbalanceado != nullptr) {
      cout << "El que desbalancea es: " << dato << ": ";
      cout << subArbolDesbalanceado->dato << endl;
      balancearArbol(subArbolDesbalanceado, dato);
    }
    // imprimirArbol(raiz);
  }
}

void agregarNodo(int n, struct nodo *raiz) {

  if (raiz == nullptr)
    return;

  if (raiz->dato == -1) {
    raiz->dato = n;
    return;
  }

  if (n == raiz->dato) {
    cout << "El dato ya se encuentra en el arbol" << endl;
    return;
  }

  if (n > raiz->dato and raiz->der == nullptr) {
    nodo *nuevoNodo = new nodo(n);
    raiz->der = nuevoNodo;
    return;
  }

  if (n < raiz->dato and raiz->izq == nullptr) {
    nodo *nuevoNodo = new nodo(n);
    raiz->izq = nuevoNodo;
    return;
  }

  (n > raiz->dato) ? agregarNodo(n, raiz->der) : agregarNodo(n, raiz->izq);
}

int calcularFactoresBalanceo(struct nodo *raiz, int &desbalanceado) {
  if (raiz == nullptr)
    return 0;

  int profundidadIzquerda = calcularFactoresBalanceo(raiz->izq, desbalanceado);
  int profundidadDerecha = calcularFactoresBalanceo(raiz->der, desbalanceado);
  int factorBalanceo = profundidadIzquerda - profundidadDerecha;
  // cout << raiz->dato << ": " << factorBalanceo << ", ";

  if (profundidadDerecha != profundidadIzquerda) {
    if (factorBalanceo > 1 or factorBalanceo < -1)
      desbalanceado = raiz->dato;

    if (profundidadDerecha > profundidadIzquerda)
      return profundidadDerecha + 1;
    return profundidadIzquerda + 1;
  }
  return profundidadDerecha + 1;
}

struct nodo *buscar(int n, struct nodo *raiz) {
  if (n == raiz->dato)
    return raiz;
  if (n > raiz->dato)
    return buscar(n, raiz->der);
  else
    return buscar(n, raiz->izq);
}

struct nodo *encontrarDesbalanceo(struct nodo *raiz) {
  int nodoDesvalanceado = -1;
  calcularFactoresBalanceo(raiz, nodoDesvalanceado);
  if (nodoDesvalanceado == -1)
    return nullptr;
  return buscar(nodoDesvalanceado, raiz);
}

void balancearArbol(struct nodo *raiz, int x) {
  // rotacion II
  if (x < raiz->dato and x < raiz->izq->dato) {
    cout << "Se hace RII" << endl;
    rotacionII(raiz);
    return;
  }

  // rotacion DD
  if (x > raiz->dato and x > raiz->der->dato) {
    cout << "Se hace RDD" << endl;
    rotacionDD(raiz);
    return;
  }

  // rotacion ID
  if (x < raiz->dato and x > raiz->izq->dato) {
    cout << "Se hace RID" << endl;
    rotacionID(raiz);
    return;
  }

  // rotacion DI
  if (x > raiz->dato and x < raiz->der->dato) {
    cout << "Se hace RDI" << endl;
    rotacionDI(raiz);
    return;
  }
}

void inOrden(struct nodo *raiz) {
  if (raiz == nullptr)
    return;
  inOrden(raiz->izq);
  cout << raiz->dato << " ";
  inOrden(raiz->der);
}

void rotacionDD(struct nodo *raiz) {}
