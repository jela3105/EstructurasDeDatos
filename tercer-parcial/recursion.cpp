#include <iostream>

using namespace std;

int potencia(int, int);
int MCD(int, int);
void decimalABinario(int);

int main() {
  while (true) {
    int opcion, x, y;
    cout << "\n\nIngresa una opcion:" << endl;
    cout << "1. Potencia" << endl;
    cout << "2. Maximo comun divisor" << endl;
    cout << "3. Decimal a binario" << endl;
    cin >> opcion;
    switch (opcion) {
    case 1:
      cout << "Ingresa la base: ";
      cin >> x;
      cout << "Ingresa la potencia: ";
      cin >> y;
      cout << "La potencia es: " << potencia(x, y) << endl;
      break;
    case 2:
      cout << "Ingresa x: ";
      cin >> x;
      cout << "Ingresa y: ";
      cin >> y;
      cout << "El maximo comun divisor es: " << MCD(x, y);
      break;
    case 3:
      cout << "Ingresa el numero decimal: ";
      cin >> x;
      cout << "El numero decimal es: ";
      decimalABinario(x);
      break;
    }
  }
  return 0;
};

int potencia(int base, int exponente) {
  if (base == 0)
    return 0;
  if (exponente == 0)
    return 1;
  return base * potencia(base, exponente - 1);
}

int MCD(int x, int y) {
  if (x == 0)
    return y;
  if (y == 0)
    return x;
  else
    return MCD(y % x, x);
}

void decimalABinario(int x) {
  if (x > 1)
    decimalABinario(x / 2);
  cout << x % 2;
}
