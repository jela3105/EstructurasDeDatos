#include <iostream>
using namespace std;

void push(int[8], int &);
int pop(int[8], int &);
void impresion(int[8], int);

int main() {
  int cola[8], fin = -1;
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
      push(cola, fin);
      break;
    case 2:
      numero = pop(cola, fin);
      if (numero != -1)
        cout << "\n    Ha salido el dato: " << numero << endl;
      break;
    case 3:
      impresion(cola, fin);
      break;
    }
  }
  return 0;
}

void push(int cola[8], int &fin) {
  if (fin == 7) {
    cout << "\n    No hay espacio para mas elementos" << endl;
    return;
  }
  fin++;
  int numero;
  cout << "\n    Ingresa el numero: ";
  cin >> numero;
  cola[fin] = numero;
}

int pop(int cola[8], int &fin) {
  if (fin == -1) {
    cout << "\n    No hay elementos en la cola" << endl;
    return -1;
  }
  int numero = cola[0];
  for (int i = 0; i < fin; i++) {
    cola[i] = cola[i + 1];
  }
  cola[fin] = 0;
  fin--;
  return numero;
}

void impresion(int cola[8], int fin) {
  if (fin == -1) {
    cout << "\n    No hay elementos en la cola";
  }
  cout << "\n    ";
  for (int i = 0; i <= fin; i++) {
    cout << cola[i] << " ";
  }
  cout << endl;
}
