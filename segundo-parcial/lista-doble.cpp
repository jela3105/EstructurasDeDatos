#include <iostream>
#include <time.h>

using namespace std;

struct nodo {
  int dato;
  struct nodo *der, *izq;
};

int main() {
  srand(time(NULL));
  nodo *p = NULL, *f = NULL, *aux = NULL, *aux2 = NULL, *inicio = NULL,
       *ultimo = NULL;
  bool band;
  int opc, x, n, contador, temp;
  while (true) {
    cout << "\n\n=========== LISTA DOBLEMENTE ENLAZADA ===========" << endl;
    cout << "0. Imprimir de izquierda a derecha" << endl;
    cout << "1. Imprimir de derecha a izquierda" << endl;
    cout << "2. Insertar al final" << endl;
    cout << "3. Insertar a la izquierda" << endl;
    cout << "4. Ingresar aleatorios a la derecha" << endl;
    cout << "5. Ingresar aleatorios a izquierda" << endl;
    cout << "6. Ingresar consecutivos de 1 a N a la derecha" << endl;
    cout << "7. Eliminar inicio" << endl;
    cout << "8. Eliminar final" << endl;
    cout << "9. Busqueda" << endl;
    cout << "10. Elimina x" << endl;
    cout << "11. Ordenamiento burbuja" << endl;
    cout << "12. Shaker sort" << endl;
    cout << "13. Inserccion directa" << endl;
    cout << "14. Seleccion directa" << endl;
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
      while (aux != NULL) {
        cout << aux->dato << " ";
        aux = aux->der;
      }
      break;
    case 1:
      if (f == NULL) {
        cout << "\n    Lista vacia";
        break;
      }
      aux = p;
      aux = f;
      cout << endl;
      while (aux != NULL) {
        cout << aux->dato << " ";
        aux = aux->izq;
      }
      break;
    case 2:
      cout << "\n    Ingresa x: ";
      cin >> x;
      if (p == NULL) {
        p = new nodo;
        p->dato = x;
        p->izq = NULL;
        f = p;
        break;
      }
      aux = new nodo;
      aux->dato = x;
      aux->der = NULL;
      aux->izq = f;
      f->der = aux;
      f = aux;
      break;
    case 3:
      cout << "\n    Ingresa x: ";
      cin >> x;
      if (p == NULL) {
        p = new nodo;
        p->dato = x;
        p->izq = NULL;
        p->der = NULL;
        f = p;
        break;
      }
      aux = new nodo;
      aux->dato = x;
      aux->izq = NULL;
      aux->der = p;
      p->izq = aux;
      p = aux;
      break;
    case 4: // aleatorios a la derecha
      cout << "\n    Ingresa cuantos numeros: ";
      cin >> n;
      while (n) {
        if (p == NULL) {
          p = new nodo;
          p->dato = 1 + rand() % 100;
          p->der = NULL;
          p->izq = NULL;
          f = p;
        } else {
          aux = new nodo;
          aux->dato = 1 + rand() % 100;
          aux->der = NULL;
          aux->izq = f;
          f->der = aux;
          f = aux;
        }
        n--;
      }
      break;
    case 5: // aleatorios a la izquierda
      cout << "\n    Ingresa cuantos numeros: ";
      cin >> n;
      while (n) {
        if (p == NULL) {
          p = new nodo;
          p->dato = 1 + rand() % 100;
          p->der = NULL;
          p->izq = NULL;
          f = p;
        } else {
          aux = new nodo;
          aux->dato = 1 + rand() % 100;
          aux->der = p;
          aux->izq = NULL;
          p->izq = aux;
          p = aux;
        }
        n--;
      }
      break;
    case 6: // consecutivos
      cout << "\n   Ingresa el numero n: ";
      cin >> n;
      x = 1;
      while (x <= n) {
        if (p == NULL) {
          p = new nodo;
          p->dato = x;
          p->der = NULL;
          p->izq = NULL;
          f = p;
        } else {
          aux = new nodo;
          aux->dato = x;
          aux->der = NULL;
          aux->izq = f;
          f->der = aux;
          f = aux;
        }
        x++;
      }
      break;
    case 7:
      if (p == NULL) {
        cout << "\n    Lista vacia";
        break;
      }
      aux = p;
      if (aux == f) {
        delete aux;
        p = NULL;
        f = NULL;
        break;
      }
      p = p->der;
      p->izq = NULL;
      aux->der = NULL;
      delete aux;
      break;
    case 8:
      if (f == NULL) {
        cout << "\n    Liesta vacia";
        break;
      }
      aux = f;
      if (f == p) {
        f = NULL;
        p = NULL;
        delete aux;
        break;
      }
      f = f->izq;
      f->der = NULL;
      aux->izq = NULL;
      delete aux;
      break;
    case 9:
      cout << "\n    Ingresa x: ";
      cin >> x;
      aux = p;
      band = 0;
      while (aux != NULL) {
        if (aux->dato == x) {
          band = 1;
          cout << "    El dato fue encontrado" << endl;
          break;
        }
        aux = aux->der;
      }
      if (!band)
        cout << "    Dato NO encontrado en la lista" << endl;
      break;
    case 10:
      if (p == NULL) {
        cout << "\n   Lista vacia";
        break;
      }
      cout << "\n    Ingresa x: ";
      cin >> x;
      aux = p;
      band = 0;
      while (aux != NULL) {
        if (aux->dato == x) {
          band = 1;
          break;
        }
        aux = aux->der;
      }
      if (!band) {
        cout << "    El dato no fue encontrado";
        break;
      }
      if (aux == p) {
        p = p->der;
        p->izq = NULL;
        aux->der = NULL;
        delete aux;
        break;
      }
      if (aux == f) {
        f = f->izq;
        f->der = NULL;
        aux->izq = NULL;
        delete aux;
        break;
      }
      aux2 = aux->izq;
      aux2->der = aux->der;
      delete aux;
      break;
    case 11:
      if (p == NULL) {
        cout << "\n    Lista vacia";
        break;
      }
      contador = 0;
      aux = p;
      while (aux != NULL) {
        contador++;
        aux = aux->der;
      }
      cout << "Total de datos: " << contador << endl;
      cout << "Metodo burbuja" << endl;
      for (int i = 1; i < contador; i++) {
        aux = p;
        aux2 = aux->der;
        for (int j = 1; j < contador; j++) {
          if (aux->dato > aux2->dato) {
            temp = aux->dato;
            aux->dato = aux2->dato;
            aux2->dato = temp;
          }
          aux = aux2;
          aux2 = aux2->der;
        }
      }
      break;
    case 12: // shaker sort
      contador = 0;
      aux = p;
      while (aux != NULL) {
        contador++;
        aux = aux->der;
      }
      if (contador <= 1) {
        cout << "\n    No hay suficientes elementos para ordenar" << endl;
        break;
      }
      cout << "Total de datos: " << contador << endl;
      cout << "Shaker sort" << endl;
      inicio = p;
      ultimo = f;
      while (inicio != ultimo) {
        aux = ultimo;
        cout << "    De derecha a izquierda" << endl;
        while (aux != inicio) {
          cout << aux->izq->dato << " > " << aux->dato;
          if (aux->izq->dato > aux->dato) {
            cout << "\tV\t";
            temp = aux->izq->dato;
            aux->izq->dato = aux->dato;
            aux->dato = temp;
          } else
            cout << "\tF\t";
          aux2 = p;
          while (aux2 != NULL) {
            cout << aux2->dato << " ";
            aux2 = aux2->der;
          }
          cout << endl;
          aux = aux->izq;
        }
        inicio = inicio->der;
        cout << "    Izquierda a derecha" << endl;
        aux = inicio;
        while (aux != ultimo) {
          cout << aux->dato << " > " << aux->der->dato;
          if (aux->dato > aux->der->dato) {
            cout << "\tV\t";
            temp = aux->dato;
            aux->dato = aux->der->dato;
            aux->der->dato = temp;
          } else
            cout << "\tF\t";
          aux2 = p;
          while (aux2 != NULL) {
            cout << aux2->dato << " ";
            aux2 = aux2->der;
          }
          cout << endl;
          aux = aux->der;
        }
        ultimo = ultimo->izq;
      }
      break;
    case 13:
      break;
    }
  }
  return 0;
}
