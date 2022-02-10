#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void imprime(int[]);
void inicializarManualmente(int[], int &);
void inicializarAleatoriamente(int[], int &);
void inicializarConN(int[], int &);
int sumatoria(int[], int &);
void valorMax(int[]);
void valorMin(int[], int &);
void busqueda(int[]);
float promedio(int[], int);
void mayoresPromedio(int[], int);
void insertarPosCero(int[], int &);
void insertarPosFinal(int[], int &);

int main() {

  int datos[20] = {0};
  int opcion, n, suma, maximo, minimo, subinidice, dato_buscar, encontrado,
      valor, elementos_arreglo = 0;
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
    cout << "11. Insertar al final\n";
    cout << "30. Salir\n";
    cout << "    Selecciona una opcion: ";
    cin >> opcion;

    switch (opcion) {
    case 0:
      imprime(datos);
      break;
    case 1:
      inicializarManualmente(datos, elementos_arreglo);
      break;
    case 2:
      inicializarAleatoriamente(datos, elementos_arreglo);
      break;
    case 3:
      inicializarConN(datos, elementos_arreglo);
      break;
    case 4:
      cout << "\n    La suma es: " << sumatoria(datos, elementos_arreglo)
           << endl;
      break;
    case 5:
      valorMax(datos);
      break;
    case 6:
      valorMin(datos, elementos_arreglo);
      break;
    case 7:
      busqueda(datos);
      break;
    case 8:
      cout << promedio(datos, elementos_arreglo);
      break;
    case 9:
      mayoresPromedio(datos, elementos_arreglo);
      break;
    case 10:
      insertarPosCero(datos, elementos_arreglo);
      break;
    case 11:
      insertarPosFinal(datos, elementos_arreglo);
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

void inicializarManualmente(int x[20], int &elementos_arreglo) {
  int n;
  cout << "    Cuantos datos deseas ingresar?: ";
  cin >> n;
  if (n > elementos_arreglo)
    elementos_arreglo = n;
  if (n <= 20) {
    for (int i = 0; i < n; i++) {
      cout << "    Ingresa el valor de datos[" << i << "]: ";
      cin >> x[i];
    }
  } else {
    cout << "    Se excede el tamano del arreglo" << endl;
  }
}

void inicializarAleatoriamente(int x[20], int &elementos_arreglo) {
  int n;
  cout << "    Cuantos datos aleatoreos desea?: ";
  cin >> n;
  if (n > elementos_arreglo)
    elementos_arreglo = n;
  if (n <= 20) {
    for (int i = 0; i < n; i++) {
      x[i] = 1 + rand() % 100;
    }
  } else {
    cout << "    Se excede el tamano del arreglo\n";
  }
}

void inicializarConN(int x[20], int &elementos_arreglo) {
  int n, valor;
  cout << "\n    Cuantos datos deseas ingresar?: ";
  cin >> n;
  if (n > elementos_arreglo)
    elementos_arreglo = n;

  cout << "\n    Cual es el valor con el que iniciaran?: ";
  cin >> valor;
  for (int i = 0; i < n; i++) {
    x[i] = valor;
  }
}

int sumatoria(int x[20], int &elementos_arreglo) {
  int suma = 0;
  for (int i = 0; i < 20; i++) {
    suma += x[i];
  }
  return suma;
}

void valorMax(int x[20]) {
  int maximo, subinidice;
  maximo = x[0];
  for (int i = 1; i < 20; i++) {
    if (maximo < x[i]) {
      maximo = x[i];
      subinidice = i;
    }
  }
  cout << "\n    El maximo es: " << maximo << endl
       << "    Y el subinidice es: " << subinidice << endl;
}

void valorMin(int x[20], int &elementos_arreglo) {
  int minimo = x[0], subinidice = 0;
  for (int i = 1; i < elementos_arreglo; i++) {
    if (minimo > x[i]) {
      minimo = x[i];
      subinidice = i;
    }
  }
  cout << "\n    El minimo es: " << minimo << endl
       << "    Y el subinidice es: " << subinidice << endl;
}

void busqueda(int datos[20]) {
  int dato_buscar, encontrado, subinidice;
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
}

float promedio(int datos[20], int elementos_arreglo) {
  int suma = 0;
  float promedio;
  for (int i = 0; i < elementos_arreglo; i++) {
    suma += datos[i];
  }
  promedio = (float)suma / elementos_arreglo;
  cout << "\n    El promedio es: " << promedio << endl;
  return promedio;
}

void mayoresPromedio(int datos[20], int elementos_arreglo) {
  float p = promedio(datos, elementos_arreglo);
  cout << "\n    Los valores mayores al promedio son: " << endl;
  cout << "    Posicion		Valor " << endl;
  for (int i = 0; i < elementos_arreglo; i++) {
    if (datos[i] > p) {
      cout << "    " << i << "\t\t\t" << datos[i] << endl;
    }
  }
}

void insertarPosCero(int datos[20], int &elementos_arreglo) {
  int valor;
  cout << "\n    Ingrese el numero: ";
  cin >> valor;
  for (int i = elementos_arreglo; i > 0; i--) {
    datos[i] = datos[i - 1];
  }
  datos[0] = valor;
  if (elementos_arreglo < 20)
    elementos_arreglo++;
}

void insertarPosFinal(int datos[20], int &elementos_arreglo) {
  int valor;
  cout << "\n    Ingrese el numero: ";
  cin >> valor;
  if (elementos_arreglo < 20) {
    datos[elementos_arreglo] = valor;
    elementos_arreglo++;
  } else
    datos[19] = valor;
}
