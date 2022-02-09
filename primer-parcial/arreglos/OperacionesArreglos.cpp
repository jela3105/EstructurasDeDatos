#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void imprime(int[]);
int iniManu(int[], int);
int iniAlea(int[], int);
int iniN(int[], int);
int sumatoria(int[], int);
void valorMax(int[], int);
void valorMin(int[], int);
void busqueda(int[], int, int);
float promedio(int[], int);
void mayoresPromedio(int[], int);
int insertarPosCero(int[], int);
int insertarPosFinal(int[], int);

int main() {

  int datos[20] = {0};
  int opcion, n, suma, maximo, minimo, subinidice, dato_buscar, encontrado,
      valor, elementos_arreglo = 0;
  float promedio;
  srand(time(NULL));

  while (true) {
    cout << "\n			MENU\n";
    cout << "-------------------------------------------------\n";
    cout << "0.  Impresion\n";
    cout << "1.  Inicializacion manual\n";
    cout << "2.  Inicializacion aleatoria\n";
    cout << "3.  Inicializacion con N\n";
    cout << "4.  Sumatoria del contenido del arreglo\n";
    cout << "5.  Maximo\n";
    cout << "6.  Minimo\n";
    cout << "7.  Busqueda\n";
    cout << "8.  Pomedio\n";
    cout << "9.  Mayores al promedio\n";
    cout << "10. Insertar al inicio\n";
    cout << "11. Insertar un bloque al inicio\n";
    cout << "12. Insertar al final\n";

    cout << "30. Salir\n";
    cout << "    Selecciona una opcion: ";
    cin >> opcion;

    switch (opcion) {
    case 0:
      imprime(datos);
      break;

    case 1:
      cout << "    Cuantos datos deseas ingresar?: ";
      cin >> n;
      if (n > elementos_arreglo)
        elementos_arreglo = n;
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
      if (n > elementos_arreglo)
        elementos_arreglo = n;
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

    case 7:
      suma = 0;
      for (int i = 0; i < elementos_arreglo; i++) {
        suma += datos[i];
      }
      promedio = (float)suma / elementos_arreglo;
      cout << "\n    El promedio es: " << promedio << endl;
      break;

    case 8:
      suma = 0;
      for (int i = 0; i < elementos_arreglo; i++) {
        suma += datos[i];
      }
      promedio = (float)suma / elementos_arreglo;
      cout << "\n    Los valores mayores al promedio son: " << endl;
      cout << "    Posicion		Valor " << endl;
      for (int i = 0; i < elementos_arreglo; i++) {
        if (datos[i] > promedio) {
          cout << "    " << i << "\t\t\t" << datos[i] << endl;
        }
      }
      break;

    case 9:
      cout << "\n    Cuantos datos deseas ingresar?: ";
      cin >> n;
      if (n > elementos_arreglo)
        elementos_arreglo = n;
      cout << "\n    Cual es el valor con el que iniciaran?: ";
      cin >> valor;
      for (int i = 0; i < n; i++) {
        datos[i] = valor;
      }
      break;

    case 10:
      cout << "\n    Ingrese el numero: ";
      cin >> valor;
      for (int i = elementos_arreglo; i > 0; i--) {
        datos[i] = datos[i - 1];
      }
      datos[0] = valor;
      if (elementos_arreglo < 20)
        elementos_arreglo++;
      break;

    case 11:
      cout << "\n    Ingrese el numero de elementos a agregar: ";
      cin >> n;
      if (elementos_arreglo + n <= 20) {
        for (int i = 0; i < n; i++) {
          datos[i + n] = datos[i];
          cout << "    Ingresa dato[" << i << "]: ";
          cin >> datos[i];
        }
        elementos_arreglo += n;
      } else
        cout << "\n    No pueden haber mas de 20 elementos";
      break;

    case 12:
      cout << "\n    Ingrese el numero: ";
      cin >> valor;
      if (elementos_arreglo < 20) {
        datos[elementos_arreglo] = valor;
        elementos_arreglo++;
      } else
        datos[19] = valor;
      break;

    case 13:
      cout << "\n    Ingrese el numero de elementos a ingresar: ";
      cin >> n;
      if (elementos_arreglo + n <= 20) {
        for (int i = 0; i < n; i++) {
          cout << "Ingrese el elemento datos[" << elementos_arreglo + i
               << "]: ";
          cin >> datos[elementos_arreglo + i];
        }
        elementos_arreglo += n;
      } else
        cout << "\n    No pueden haber mas de 20 elementos";
      break;
    case 30:
      return 0;
    }
  }
  return 0;
}

void imprime(int x[20]) {
  cout << "\nContenido del arreglo \n";
  cout << "Subindice	Valor almacenado\n";
  for (int i = 0; i < 20; i++)
    cout << "    " << i << "\t\t\t\t" << x[i] << endl;
}
