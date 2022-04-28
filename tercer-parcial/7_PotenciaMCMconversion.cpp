#include <iostream>
using namespace std;

int potencia(int, int);
int MCD(int, int);
void conversion(int);

int main() {
  bool band = true;
  int x, n, r, opc;
  while (band == true) {
    cout << "* * * * MENU * * * *\n";
    cout << "1. Potencia\n2. Maximo Comun Divisor\n3. Conversion\n0. Salir";
    cout << "\n   Elije una opcion: ";
    cin >> opc;
    switch (opc) {
    case 0: // Salir
      band = false;
      break;
    case 1: // Potencia
      cout << "	Ingresa un numero: ";
      cin >> x;
      cout << "	Ingresa la potencia: ";
      cin >> n;
      r = potencia(x, n);
      cout << "\n	El resultado es: " << r << "\n\n";
      break;
    case 2: // MCD
      cout << "	Ingresa un numero: ";
      cin >> x;
      cout << "	Ingresa otro numero: ";
      cin >> n;
      r = MCD(x, n);
      cout << "\n	El MCD es: " << r << "\n\n";
      break;
    case 3: // Conversion
      do {
        cout << "	Ingresa un numero: ";
        cin >> n;
      } while (n < 0);
      cout << "\n	" << n << " = ";
      conversion(n);
      cout << "\n\n";
      break;
    }
  }
  return 0;
}

int potencia(int x, int n) {
  if (n == 0 && x != 0)
    return 1;
  if (x == 0)
    return 0;
  if (x == 1)
    return x;
  else
    return x * potencia(x, n - 1);
}

int MCD(int a, int b) {
  if (a == 0)
    return b;
  if (b == 0)
    return a;
  else
    return MCD(b % a, a);
}

void conversion(int n) {
  if (n > 1)
    conversion(n / 2);
  cout << n % 2;
}
