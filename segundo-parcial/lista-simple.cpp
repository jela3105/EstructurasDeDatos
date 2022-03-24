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
  nodo *p = NULL, *f, *aux, *aux2, *nuevo;
  while (1) {
    cout << "\n* * * * MENU * * * *\n";
    cout << "0. Imprimir\n";
    cout << "1. Insertar a la derecha\n";
    cout << "2. Insertar a la izquierda\n";
    cout << "3. Inserta datos aleatoreos a la derecha\n";
    cout << "4. Inserta datos aleatoreos a la izquierda\n";
    cout << "5. Sumatoria\n";
    cout << "6. Buscar un dato\n";
    cout << "7. Insertar antes de X valor\n";
    cout << "8. Insertar despues de X valor\n";
    cout << "9. Modificar x\n";
    cout << "10. Eliminar primer nodo\n";
    cout << "11. Eliminar ultimo nodo\n";
    cout << "12. Eliminar nodo x\n";
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
    case 5:
      suma = 0;
      aux = p;
      if (aux == NULL)
        cout << "La lista esta vacia\n";
      else {
        while (aux != NULL) {
          suma += aux->dato;
          aux = aux->liga;
        }
        cout << "La suma total es: " << suma << endl;
      }
      break;
    case 6:
      aux = p;
      if (aux == NULL)
        cout << "Lista vacia\n";
      else {
        band = 0;
        cout << "Ingresa el dato a buscar: ";
        cin >> d;
        while (aux != NULL) {
          if (aux->dato == d) {
            band = 1;
            break;
          }
          aux = aux->liga;
        }
        (band == 1) ? cout << "Dato encontrado" << endl
                    : cout << "Dato no encontrado" << endl;
      }
      break;
    case 7:
      if (p == NULL)
        cout << "Lista vacia\n";
      else {
        cout << "Ingresa x: ";
        cin >> x;
        aux = p;
        band = 0;
        while (aux != NULL) {
          if (aux->dato == x) {
            band = 1;
            nuevo = new nodo;
            cout << "Ingresa el dato: ";
            cin >> nuevo->dato;
            nuevo->liga = aux;
            if (aux == p)
              p = nuevo;
            else
              aux2->liga = nuevo;
            break;
          }
          aux2 = aux;
          aux = aux->liga;
        }
        band == 1 ? cout << "El dato se ha insertado"
                  : cout << "No se encontro el dato";
      }
      break;
    case 8:
      if (p == NULL)
        cout << "Lista vacia\n";
      else {
        cout << "Ingresa x: ";
        cin >> x;
        aux = p;
        band = 0;
        while (aux != NULL) {
          if (aux->dato == x) {
            band = 1;
            nuevo = new nodo;
            cout << "ingresa el dato: ";
            cin >> nuevo->dato;
            if (aux->liga == NULL) {
              nuevo->liga = NULL;
              aux->liga = nuevo;
              f = aux->liga;
            } else {
              aux2 = aux->liga;
              aux->liga = nuevo;
              nuevo->liga = aux2;
            }
            break;
          }
          aux = aux->liga;
        }
        (band == 1) ? cout << "Se ha agregado correctamente\n"
                    : cout << "No se ha encontrado el dato de x\n";
      }
      break;
    case 9:
      if (p == NULL) {
        cout << "Lista vacia\n";
      } else {
        cout << "Ingresa x: ";
        cin >> x;
        aux = p;
        band = 0;
        while (aux != NULL) {
          if (aux->dato == x) {
            band = 1;
            cout << "Dato encontrado." << endl << "Ingresa el nuevo valor: ";
            cin >> aux->dato;
            break;
          }
          aux = aux->liga;
        }
        if (!band)
          cout << "No se ha encontrado el dato" << endl;
      }
      break;
    case 10:
      if (p == NULL or f == NULL) {
        cout << "Lista vacia" << endl;
        break;
      }
      aux = p;
      p = p->liga;
      aux->liga = NULL;
      delete aux;
      break;
    case 11:
      if (p == NULL or f == NULL) {
        cout << "Lista vacia" << endl;
        break;
      }
      if (p == f) {
        delete p;
        p = NULL;
        f = NULL;
        break;
      }
      aux = p;
      while (aux->liga != f) {
        aux = aux->liga;
      }
      delete f;
      aux->liga = NULL;
      f = aux;
      break;
    case 12:
      if (p == NULL) {
        cout << "Lista vacia" << endl;
        break;
      }
      cout << "Ingresa x: ";
      cin >> x;
      band = 0;
      if (p->dato == x) {
        aux = p;
        p = p->liga;
        aux->liga = NULL;
        delete aux;
        break;
      }
      aux = p;
      band = 0;
      while (aux != NULL) {
        if (aux->dato == x) {
          band = 1;
          break;
        }
        aux2 = aux;
        aux = aux->liga;
      }
      if (band) {
        aux2->liga = aux->liga;
        aux->liga = NULL;
        delete aux;
      } else
        cout << "No se ha encontrado el dato" << endl;
      break;
    }
  }
}
