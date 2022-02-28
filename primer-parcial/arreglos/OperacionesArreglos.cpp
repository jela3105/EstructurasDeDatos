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
int busqueda(int[20], int);
float promedio(int[], int);
void mayoresPromedio(int[], int);
void insertarPosCero(int[], int &);
void insertarPosFinal(int[], int &);
void insertarBloqueInicio(int[], int &);
void insertarBloqueFinal(int[], int &);
void insertarBloqueX(int[], int &);
int eliminarInicio(int[20], int &);
int eliminarFinal(int[20], int &);
void eliminarPares(int[20], int &);
bool buscarYEliminar(int[20], int &, int);
bool buscarYModificar(int[20], int &, int, int);
void ordenarAscendente(int[20], int);

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
    cout << "12. Insertar bloque al inicio\n";
    cout << "13. Insertar bloque al final\n";
    cout << "14. Insertar bloque en posicion X\n";
    cout << "15. Eliminar inicio\n";
    cout << "16. Eliminar final\n";
    cout << "17. Eliminar pares\n";
    cout << "18. Buscar y eliminar\n";
    cout << "19. Buscar modificar\n";
    cout << "20. Ordenar burbuja\n";
    cout << "21. Shakersort\n";
    cout << "22. Insercion directa\n";
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
      cout << "\n    Ingresa el dato a buscar: ";
      cin >> dato_buscar;
      encontrado = busqueda(datos, dato_buscar);
      if (encontrado != -1)
        cout << "\n    El dato " << dato_buscar << " si fue encontrado"
             << " en el subinidice " << encontrado << endl;
      else
        cout << " \n   El dato " << dato_buscar << " no fue encontrado";
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
    case 12:
      insertarBloqueInicio(datos, elementos_arreglo);
      break;
    case 13:
      insertarBloqueFinal(datos, elementos_arreglo);
      break;
    case 14:
      insertarBloqueX(datos, elementos_arreglo);
      break;
    case 15:
      cout << "\n    Se elimino el dato: "
           << eliminarInicio(datos, elementos_arreglo);
      break;
    case 16:
      cout << "\n    Se elimino el dato: "
           << eliminarFinal(datos, elementos_arreglo);
      break;
    case 17:
      eliminarPares(datos, elementos_arreglo);
      break;
    case 18:
      cout << "\n    Ingresa el dato a eliminar: ";
      cin >> n;
      buscarYEliminar(datos, elementos_arreglo, n)
          ? cout << "\n    Se ha eliminado el elemento"
          : cout << "\n    El elemento " << n << " no existe";
      break;
    case 19:
      cout << "\n    Ingresa el dato a modificar: ";
      cin >> n;
      cout << "\n    Ingresa el nuevo valor: ";
      cin >> valor;
      buscarYModificar(datos, elementos_arreglo, n, valor)
          ? cout << "\n    Se ha modificado el elemento"
          : cout << "\n    El elemento " << n << " no se ha encontrado";
      break;
    case 20:
      ordenarAscendente(datos, elementos_arreglo);
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

int busqueda(int datos[20], int dato_buscar) {
  int encontrado, subinidice;
  encontrado = false;
  for (int i = 0; i < 20; i++) {
    if (datos[i] == dato_buscar) {
      encontrado = true;
      subinidice = i;
      break;
    }
  }
  if (encontrado)
    return subinidice;
  return -1;
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
  if (elementos_arreglo < 20) {
    int valor;
    cout << "\n    Ingrese el numero: ";
    cin >> valor;
    for (int i = elementos_arreglo; i > 0; i--) {
      datos[i] = datos[i - 1];
    }
    datos[0] = valor;
    elementos_arreglo++;
  } else
    cout << "    El arreglo excede el tamano";
}

void insertarPosFinal(int datos[20], int &elementos_arreglo) {
  if (elementos_arreglo < 20) {
    int valor;
    cout << "\n    Ingrese el numero: ";
    cin >> valor;
    datos[elementos_arreglo] = valor;
    elementos_arreglo++;
  } else
    cout << "    El arreglo excede el tamano";
}

void insertarBloqueInicio(int datos[20], int &elementos_arreglo) {
  int n;
  cout << "\n    Ingrese el numero de elementos a agregar: ";
  cin >> n;
  if (elementos_arreglo + n <= 20) {
    for (int i = elementos_arreglo - 1; i >= 0; i--) {
      datos[i + n] = datos[i];
    }
    for (int i = 0; i < n; i++) {
      datos[i] = 1 + rand() % 100;
    }
    elementos_arreglo += n;
  } else
    cout << "\n    No pueden haber mas de 20 elementos";
}

void insertarBloqueFinal(int datos[20], int &elementos_arreglo) {
  int n;
  cout << "\n    Ingrese el numero de elementos a agregar: ";
  cin >> n;
  if (elementos_arreglo + n <= 20) {
    for (int i = 0; i < n; i++) {
      datos[elementos_arreglo + i] = 1 + rand() % 100;
    }
    elementos_arreglo += n;
  } else
    cout << "\n    No pueden haber mas de 20 elementos";
}

void insertarBloqueX(int datos[20], int &elementos_arreglo) {
  int n, x;
  cout << "\n    Ingrese el numero de elementos a agregar: ";
  cin >> n;
  if (elementos_arreglo + n > 20) {
    cout << "\n    El numero de elementos nuevos excederia el limite";
    return;
  }
  cout
      << "\n    Ingrese el subinidice en el que quiere agregar los elementos: ";
  cin >> x;
  if (x + 1 > elementos_arreglo) {
    cout << "\n    Ese indice no esta dentro del rango";
    return;
  }

  for (int i = elementos_arreglo - 1; i >= x; i--) {
    datos[n + i] = datos[i];
  }
  elementos_arreglo += n;
  for (int i = x; i < x + n; i++) {
    cout << "\n    Ingresa el elemento datos[" << i << "]: ";
    cin >> datos[i];
  }
}

int eliminarInicio(int datos[20], int &elementos_arreglo) {
  int inicio = datos[0];
  for (int i = 1; i < elementos_arreglo; i++) {
    datos[i - 1] = datos[i];
  }
  datos[elementos_arreglo - 1] = 0;
  elementos_arreglo--;
  return inicio;
}

int eliminarFinal(int datos[20], int &elementos_arreglo) {
  int ultimo = datos[elementos_arreglo - 1];
  datos[elementos_arreglo - 1] = 0;
  elementos_arreglo--;
  return ultimo;
}

void eliminarPares(int datos[20], int &elementos_arreglo) {
  int encontrados = 0;

  for (int i = 0; i < elementos_arreglo; i++) {
    if (datos[i] % 2 == 0) {
      datos[i] = -1;
      encontrados++;
    }
  }

  int total_elementos = elementos_arreglo - encontrados;

  for (int i = 0; i < elementos_arreglo; i++) {
    if (datos[i] == -1 and encontrados) {
      for (int j = i + 1; j < elementos_arreglo; j++) {
        if (datos[j] == -1)
          continue;
        datos[i] = datos[j];
        datos[j] = -1;
        encontrados--;
        break;
      }
    }
  }

  for (int i = 0; i < 20; i++) {
    if (datos[i] == -1)
      datos[i] = 0;
  }

  elementos_arreglo = total_elementos;
}

bool buscarYEliminar(int datos[20], int &elementos_arreglo, int x) {
  int existe = busqueda(datos, x);
  if (existe == -1)
    return false;
  for (int i = existe; i < elementos_arreglo; i++) {
    datos[i] = datos[i + 1];
  }
  elementos_arreglo--;
  return true;
}

bool buscarYModificar(int datos[20], int &elementos_arreglo, int x, int ne) {
  int existe = busqueda(datos, x);
  if (existe == -1)
    return false;
  datos[existe] = ne;
  return true;
}

void ordenarAscendente(int datos[20], int elementos_arreglo) {
  if (elementos_arreglo <= 1) {
    cout << "    No hay suficientes elementos para ordenar";
    return;
  }

  cout << "    Metodo burbuja" << endl;
  int pasadas = elementos_arreglo - 1;
  for (int p = 0; p < pasadas; p++) {
    cout << "    \nPasada " << p + 1 << endl;
    for (int i = 1; i < elementos_arreglo; i++) {
      cout << datos[i - 1] << " > " << datos[i];
      if (datos[i - 1] > datos[i]) {
        cout << "\tV\t";
        int temp = datos[i];
        datos[i] = datos[i - 1];
        datos[i - 1] = temp;
      } else
        cout << "\tF\t";
      for (int k = 0; k < elementos_arreglo; k++)
        cout << datos[k] << " ";
      cout << endl;
    }
  }
}
