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
void postOrden(struct nodo *);
void preOrden(struct nodo *);
void eliminar(int n, struct nodo *);
void eliminarHoja(int n, struct nodo *);
bool esHoja(int n, struct nodo *);
bool buscar(int, struct nodo *);
void verArbol(struct nodo *, int);
void inicializarArbol(struct nodo *);

int main() {
  int opt, n;
  nodo *raiz = new nodo();
  inicializarArbol(raiz);
  while (1) {
    cout << endl << endl;
    cout << "1. Ingresar un dato" << endl;
    cout << "2. inOrden" << endl;
    cout << "3. Eliminar" << endl;
    cout << "4. Buscar" << endl;
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
      cout << "Ingresa n: ";
      cin >> n;
      if (raiz->der == NULL and raiz->izq == NULL)
        raiz->dato = -1;
      if (buscar(n, raiz)) {
        cout << "encontrado" << endl;
        if (esHoja(n, raiz)) {
          cout << "Es hoja" << endl;
          eliminarHoja(n, raiz);
        } else
          eliminar(n, raiz);
      } else
        cout << "El dato no se encuentra";
      break;
    case 4:
      cout << "Ingresa n: ";
      cin >> n;
      buscar(n, raiz) ? cout << "Se encontro el dato" << endl
                      : cout << "El dato NO fue encontrado";
      break;
    case 5:
      verArbol(raiz, 0);
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

void postOrden(struct nodo *raiz) {

  if (raiz == NULL)
    return;

  if (raiz->dato == -1) {
    cout << "No hay datos en el arbol" << endl;
    return;
  }

  postOrden(raiz->izq);
  postOrden(raiz->der);
  cout << raiz->dato << " ";
}

void preOrden(struct nodo *raiz) {

  if (raiz == NULL)
    return;

  if (raiz->dato == -1) {
    cout << "No hay datos en el arbol" << endl;
    return;
  }

  cout << raiz->dato << " ";
  preOrden(raiz->izq);
  preOrden(raiz->der);
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

bool buscar(int n, struct nodo *raiz) {
  if (raiz == NULL)
    return false;

  if (n == raiz->dato)
    return true;

  if (n > raiz->dato)
    return buscar(n, raiz->der);

  return buscar(n, raiz->izq);
}

struct nodo *buscarMenor(struct nodo *raiz) {
  if (raiz->izq == NULL)
    return raiz;
  return buscarMenor(raiz->izq);
}

struct nodo *buscarMayor(struct nodo *raiz) {
  if (raiz->der == NULL)
    return raiz;
  return buscarMayor(raiz->der);
}

struct nodo *buscarPadre(struct nodo *raiz, struct nodo *hijo) {
  if (raiz->der == hijo or raiz->izq == hijo) {
    return raiz;
  }

  if (hijo->dato > raiz->dato)
    return buscarPadre(raiz->der, hijo);

  return buscarPadre(raiz->izq, hijo);
}

bool esHoja(int n, struct nodo *raiz) {
  if (raiz->dato == n and raiz->der == NULL and raiz->izq == NULL)
    return true;

  if (raiz->dato == n and (raiz->der != NULL or raiz->izq != NULL)) {
    return false;
  }
  if (n > raiz->dato)
    return esHoja(n, raiz->der);

  return esHoja(n, raiz->izq);
}
void eliminarHoja(int n, struct nodo *raiz) {
  if (raiz->der != NULL) {
    if (raiz->der->dato == n) {
      struct nodo *hoja = raiz->der;
      raiz->der = NULL;
      delete hoja;
      return;
    }
  }

  if (raiz->izq != NULL) {
    if (raiz->izq->dato == n) {
      struct nodo *hoja = raiz->izq;
      raiz->izq = NULL;
      delete hoja;
      return;
    }
  }

  (n > raiz->dato) ? eliminarHoja(n, raiz->der) : eliminarHoja(n, raiz->izq);
}

void eliminar(int n, struct nodo *raiz) {
  if (n == raiz->dato and raiz->der == NULL) {
    struct nodo *mayor = buscarMayor(raiz->izq);
    struct nodo *padre = buscarPadre(raiz, mayor);
    raiz->dato = mayor->dato;
    raiz != padre ? padre->der = NULL : padre->izq = NULL;
    delete mayor;
    return;
  }

  if (n == raiz->dato) {
    struct nodo *menor = buscarMenor(raiz->der);
    struct nodo *padre = buscarPadre(raiz, menor);
    raiz->dato = menor->dato;
    raiz != padre ? padre->izq = NULL : padre->der = NULL;
    delete menor;
    return;
  }

  if (n > raiz->dato)
    eliminar(n, raiz->der);
  else
    eliminar(n, raiz->izq);
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

void inicializarArbol(struct nodo *raiz) {
  // agregarDato(50, raiz);
  // agregarDato(40, raiz);
  // agregarDato(100, raiz);
  agregarDato(70, raiz);
  agregarDato(45, raiz);
  agregarDato(30, raiz);
  // agregarDato(200, raiz);
}
