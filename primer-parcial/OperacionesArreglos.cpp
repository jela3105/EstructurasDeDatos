#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {

  int datos[20] = {0};
  int opcion, n, i;
  srand(time(NULL));

  while (true) {
    cout << "\n			MENU\n";
    cout << "-------------------------------------------------\n";
    cout << "0.  Impresion\n";
    cout << "1.  Inicializacion manual\n";
    cout << "2.  Inicializacion aleatoria\n";
    cout << "30. Salir\n";
    cout << "    Selecciona una opcion: ";
    cin >> opcion;

    switch (opcion) {
    case 0:
      cout << "Contenido del arreglo \n";
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
    }
  }

  return 0;
}
