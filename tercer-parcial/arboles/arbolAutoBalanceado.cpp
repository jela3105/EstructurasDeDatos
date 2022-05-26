#include <iostream>
using namespace std;

void leerArbolConsola();
void leerArbol(struct nodo *);
void agregarNodo(int n, struct nodo *raiz);
void balancearArbol(struct nodo *, int, struct nodo **);
void inOrden(struct nodo *);
void rotacionDD(struct nodo *);
void rotacionII(struct nodo *);
void rotacionDI(struct nodo *);
void rotacionID(struct nodo *);
void verArbol(struct nodo *, int);
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
  int opt;
  while (true) {
    cout << "Ingresa un opcion" << endl;
    cout << "1. Agregar datos" << endl;
    cout << "2. Ver arbol" << endl;
    cin >> opt;
    switch (opt) {
    case 1:
      leerArbol(raiz);
      break;
    case 2:
      verArbol(raiz, 1);
      break;
    }
  }
  // leerArbol(raiz);
  return 0;
}

void leerArbol(struct nodo *raiz) {
  int n, dato;
  cout << "Ingresa la cantidad de nodos : ";
  cin >> n;
  while (n--) {
    cin >> dato;
    agregarNodo(dato, raiz);
    cout << endl;
    verArbol(raiz, 1);
    struct nodo *subArbolDesbalanceado = encontrarDesbalanceo(raiz);
    if (subArbolDesbalanceado != nullptr) {
      cout << "El que desbalancea es: " << dato
           << ", La raiz del sub arbol desbalanceado: "
           << subArbolDesbalanceado->dato << endl;
      balancearArbol(subArbolDesbalanceado, dato, &raiz);
      // cout << raiz->dato << endl;
      verArbol(raiz, 1);
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

struct nodo *buscarPadre(struct nodo *raiz, struct nodo *hijo) {
  if (raiz->der == hijo or raiz->izq == hijo) {
    return raiz;
  }

  if (hijo->dato > raiz->dato)
    return buscarPadre(raiz->der, hijo);

  return buscarPadre(raiz->izq, hijo);
}

void balancearArbol(struct nodo *raiz, int x, struct nodo **raizPrincipal) {
  // rotacion II
  if (x < raiz->dato and x < raiz->izq->dato) {
    cout << "Se hace RII" << endl;
    if (raiz == *raizPrincipal)
      *raizPrincipal = raiz->izq;
    else {
      struct nodo *padre = buscarPadre(*raizPrincipal, raiz);
      padre->izq = raiz->izq;
    }
    cout << raiz->dato << endl;
    rotacionII(raiz);
    return;
  }

  // rotacion DD
  if (x > raiz->dato and x > raiz->der->dato) {
    cout << "Se hace RDD" << endl;
    if (raiz == *raizPrincipal)
      *raizPrincipal = raiz->der;
    else {
      struct nodo *padre = buscarPadre(*raizPrincipal, raiz);
      padre->der = raiz->der;
    }
    rotacionDD(raiz);
    return;
  }

  // rotacion ID
  if (x < raiz->dato and x > raiz->izq->dato) {
    cout << "Se hace RID" << endl;
    if (raiz == *raizPrincipal)
      *raizPrincipal = raiz->izq->der;
    else {
      struct nodo *padre = buscarPadre(*raizPrincipal, raiz);
      padre->izq = raiz->izq->der;
    }
    rotacionID(raiz);
    return;
  }

  // rotacion DI
  if (x > raiz->dato and x < raiz->der->dato) {
    cout << "Se hace RDI" << endl;
    if (raiz == *raizPrincipal)
      *raizPrincipal = raiz->der->izq;
    else {
      struct nodo *padre = buscarPadre(*raizPrincipal, raiz);
      padre->izq = raiz->der->izq;
    }
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

void rotacionID(struct nodo *raiz) {
  struct nodo *a, *b, *c, *aux;
  c = raiz;
  a = raiz->izq;
  b = raiz->izq->der;
  if (b->der != nullptr)
    aux = b->der;
  else
    aux = b->izq;
  b->der = c;
  if (aux->dato > b->dato) {
    c->izq = aux;
    a->der = nullptr;
  } else {
    a->der = aux;
    c->izq = nullptr;
  }
  b->izq = a;
}

void rotacionDD(struct nodo *raiz) {
  struct nodo *a, *b, *c, *aux;
  a = raiz;
  b = raiz->der;
  c = raiz->der->der;
  aux = b->izq;
  b->izq = a;
  a->der = aux;
}

void rotacionDI(struct nodo *raiz) {
  struct nodo *a = raiz, *c = raiz->der, *b = raiz->der->izq, *aux;
  if (b->der != nullptr)
    aux = b->der;
  else
    aux = b->izq;
  b->der = c;
  b->izq = a;
  if (b->dato > aux->dato) {
    a->der = aux;
    c->izq = nullptr;
  } else {
    c->izq = aux;
    a->der = nullptr;
  }
}

void rotacionII(struct nodo *raiz) {
  struct nodo *c = raiz, *b = raiz->izq, *a = raiz->izq->izq, *aux = b->der;
  c->izq = aux;
  b->der = c;
}

void verArbol(struct nodo *raiz, int nro) {
  int i;
  if (raiz == NULL)
    return;
  verArbol(raiz->der, nro + 1);
  for (i = 0; i < nro; i++)
    cout << " ";
  cout << raiz->dato << endl;
  verArbol(raiz->izq, nro + 1);
}
