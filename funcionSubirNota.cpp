#include <iostream>

using namespace std;

double* rellenarArrayNotas (int tama) { // Solo necesitamos su tamaño, estamos creando una copia. Está devolviendo un double (número con decimales)*
  double* array = new double[tama];
  string line;
  for (int i = 0;i < tama; i++) {
    cout << "Introduce una nota" << endl;
    getline(cin,line);
    array[i] = stod(line); // cuidado: stoi lo transforma  número entero (le quita los decimales). Hay que usar stod.
  }
  return array;
}

void imprimirArrayNotas(double* array, int tama) { // sobrecargamos el operador
  for (int i = 0; i < tama; i++) {
    cout << array[i] << " ";
  }
}

double* subirNotas(double* notasAntiguas, int tama, double porcentaje) {
  double* notasNuevas = new double[tama];
  for (int i = 0; i < tama; i++) {
    notasNuevas[i] = notasAntiguas[i]*porcentaje;
  }

  return notasNuevas;
}


int main () {

  double* notas = NULL;
  string line;
  string line2;
  int numero;
  double* notasSubidas = NULL;
  double porcentajeSubida;

  cout << "Introduce el numero de notas: " << endl;
  getline(cin,line);
  numero = stoi(line);

  notas = rellenarArrayNotas(numero);
  cout << "Las notas introducidas son:";
  cout << endl;
  imprimirArrayNotas(notas, numero);

  cout << "Introduce el porcentaje (%) a subir las notas: ";
  getline(cin,line2);
  porcentajeSubida = (stod(line2)/100)+1;
  notasSubidas = subirNotas(notas, numero, porcentajeSubida);
  cout << "Las notas subidas son:";
  cout << endl;
  imprimirArrayNotas(notasSubidas, numero);
  cout << "Las notas antiguas siguen siendo:" << endl;
  imprimirArrayNotas(notas, numero);




  return 0;
}
