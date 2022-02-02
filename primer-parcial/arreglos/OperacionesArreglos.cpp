#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {

  int datos[20] = {0};
  int opcion, n, i, suma, maximo, minimo, subinidice, dato_buscar, encontrado;
  srand(time(NULL));

  while (true) {
    cout << "\n			MENU\n";
    cout << "-------------------------------------------------\n";
    cout << "0.  Impresion\n";
    cout << "1.  Inicializacion manual\n";
    cout << "2.  Inicializacion aleatoria\n";
    cout << "3.  Sumatoria del contenido del arreglo\n";
    cout << "4.  Maximo\n";
    cout << "5.  Minimo\n";
    cout << "6.  Busqueda\n";
    /*
    cout << "6.  Busqueda\n"
    */
    cout << "30. Salir\n";
    cout << "    Selecciona una opcion: ";
    cin >> opcion;

    switch (opcion) {
    case 0:
      cout << "\nContenido del arreglo \n";
      cout << "Subindice	Valor almacenado\n";
      for (int i = 0; i < 20; i++)
        cout << "    " << i << "\t\t\t\t" << datos[i] << endl;
      break;

    case 1:
      cout << "    Cuantos datos deseas ingresar?: ";
      cin >> n;
      if (n <= 20) {
        for (int i = 0; i < n; i++) {
          cout << "    Ingresa el alor de datos[" << i << "]: ";
          cin >> datos[i];
        }
      } else {
        cout << "    Se excede el tamano del arreglo" << endl;
      }
      break;

    case 2:
      cout << "    Cuantos datos aleatoreos desea?: ";
      cin >> n;
      if (n <= 20) {
        for (int i = 0; i < n; i++) {
          datos[i] = 1 + rand() % 100;
        }
      } else {
        cout << "    Se excede el tamano del arreglo\n";
      }
      break;

    case 3:
      suma = 0;
      for (int i = 0; i < 20; i++) {
        suma += datos[i];
      }
      cout << "\n    La suma es: " << suma << endl;
      break;

    case 4:
      maximo = datos[0];
      for (int i = 1; i < 20; i++) {
        if (maximo < datos[i]) {
          maximo = datos[i];
          subinidice = i;
        }
      }
      cout << "\n    El maximo es: " << maximo << endl
           << "    Y el subinidice es: " << subinidice << endl;
      break;

    case 5:
      minimo = datos[0];
      for (int i = 1; i < n; i++) {
        if (minimo > datos[i]) {
          minimo = datos[i];
          subinidice = i;
        }
      }
      cout << "\n    El minimo es: " << minimo << endl
           << "    Y el subinidice es: " << subinidice << endl;
      break;

    case 6:
      cout << "\n    Ingresa el dato a buscar: ";
      cin >> dato_buscar;
      encontrado = false;
      for (int i = 0; i < 20; i++) {
        if (datos[i] == dato_buscar) {
          encontrado = true;
          subinidice = i;
          break;
        }
      }
      if (encontrado)
        cout << "    El dato " << dato_buscar << " si fue encontrado"
             << " en el subinidice " << subinidice << endl;
      else
        cout << "    El dato " << dato_buscar << " no fue encontrado" << endl;
      break;

    case 30:
      return 0;
    }
  }

  return 0;
}
