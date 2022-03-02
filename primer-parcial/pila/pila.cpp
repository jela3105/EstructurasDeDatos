// pila con arreglo
#include <iostream>

using namespace std;

void push(int[], int &);
int pop(int[], int &);
void impresion(int[], int);

int main() {
  int pila[8];
  int cima = -1;
  int opcion;
  int numero;
  while (true) {
    cout << "\n----------------------Menu----------------------\n";
    cout << "1. Push (entrada)" << endl;
    cout << "2. Pop (salida)" << endl;
    cout << "3. Impresion" << endl;
    cout << "Selecciona una opcion: ";
    cin >> opcion;
    switch (opcion) {
    case 1:
      push(pila, cima);
      break;
    case 2:
      numero = pop(pila, cima);
      if (numero != -1)
        cout << "\n    Ha salido el dato: " << numero << endl;
      break;
    case 3:
      impresion(pila, cima);
      break;
    }
  }
  return 0;
}

void push(int pila[8], int &cima) {
  if (cima == 7) {
    cout << "    \nNo hay espacio para agregar mas elementos" << endl;
    return;
  }
  cima++;
  int numero;
  cout << "\n    Ingresa el dato: ";
  cin >> numero;
  pila[cima] = numero;
}

int pop(int pila[8], int &cima) {
  if (cima == -1) {
    cout << "\n    No hay elementos por eliminar" << endl;
    return -1;
  }
  int numero = pila[cima];
  pila[cima] = 0;
  cima--;
  return numero;
}

void impresion(int pila[8], int cima) {
  if (cima == -1) {
    cout << "\n    No hay datos en la pila" << endl;
    return;
  }
  cout << "\n    Datos en la pila:" << endl;
  for (int i = cima; i >= 0; i--) {
    cout << "\t" << pila[i] << endl;
  }
}
