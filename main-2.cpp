#include <fstream>
#include <iostream>
#include <string>
using namespace std;

struct Naipe {
  int numero;
  char palo;
  char color;
};

Naipe *crear_baraja(int &cartas_disponibles) {
  ifstream archivo_entrada;
  archivo_entrada.open("baraja.dat", ios::binary);

  // Leer la cantidad de naipes en el archivo
  archivo_entrada.read((char *)(&cartas_disponibles), sizeof(int));

  Naipe *arregloBaraja = new Naipe[cartas_disponibles];

  for (int j = 0; j < cartas_disponibles; j++) {
    archivo_entrada.read((char *)(&arregloBaraja[j]), sizeof(Naipe));
  }

  archivo_entrada.close();
  return arregloBaraja;
}

Naipe robar_carta(Naipe *arreglo, int &cartas_disponibles) {
  int indice = rand() % cartas_disponibles;
  Naipe carta_robada = arreglo[indice];

  arreglo[indice] = arreglo[cartas_disponibles - 1];
  cartas_disponibles--;

  return carta_robada;
}
int leer_carta(Naipe carta_robar) {
  ifstream archivoBinario;
  archivoBinario.open("baraja.dat", ios::binary);

  int cantidadNaipes;
  archivoBinario.read((char *)&cantidadNaipes, sizeof(int));
  int posicion;

  Naipe naipeActual;
  for (int a = 0; a < cantidadNaipes; a++) {
    archivoBinario.read((char *)&naipeActual, sizeof(Naipe));
    if (carta_robar.numero == naipeActual.numero ||
        carta_robar.color == naipeActual.color ||
        carta_robar.palo == naipeActual.palo) {
      posicion = a;
    }
  }

  archivoBinario.close();
  return posicion;
}
int main() {
  srand(time(nullptr));
  ofstream salida;
  int jugadores;
  string juego;

  cout << "Ingrese la cantidad de jugadores: " << endl;
  cin >> jugadores;
  cout << "Ingrese el juego: " << endl;
  cin >> juego;

  if (juego == "P") {
    int cartas_disponibles = 52;

    salida.open(juego + to_string(jugadores) + ".txt");

    Naipe *baraja = crear_baraja(cartas_disponibles);
    int cartas_repartir = 5;

    if (jugadores < 2 || jugadores > 8) {
      cout << "La cantidad de jugadores no es valida" << endl;
      delete[] baraja;
      return 0;
    }

    for (int i = 0; i < jugadores; i++) {

      for (int j = 0; j < cartas_repartir; j++) {

        Naipe carta_robada = robar_carta(baraja, cartas_disponibles);

        salida << leer_carta(carta_robada) << " ";
      }
      salida << endl;
    }
  
    salida.close();
  }
    if (juego == "B") {
      int cartas_disponibles = 52;

      salida.open(juego + to_string(jugadores) + ".txt");

      Naipe *baraja = crear_baraja(cartas_disponibles);
      int cartas_repartir = 4;

      if (jugadores < 2 || jugadores > 7) {
        cout << "La cantidad de jugadores no es valida" << endl;
        delete[] baraja;
        return 0;
      }

      for (int i = 0; i < jugadores; i++) {

        for (int j = 0; j < cartas_repartir; j++) {

          Naipe carta_robada = robar_carta(baraja, cartas_disponibles);

          salida << leer_carta(carta_robada) << " ";
        }
        salida << endl;
      }
      salida.close();
    }
      if (juego == "C") {

        int cartas_disponibles = 104;

        salida.open(juego + to_string(jugadores) + ".txt");

        Naipe *baraja = crear_baraja(cartas_disponibles);
        int cartas_repartir = 15;

        if (jugadores < 2 || jugadores > 7) {
          cout << "La cantidad de jugadores no es valida" << endl;
          delete[] baraja;
          return 0;
        }

        for (int i = 0; i < jugadores; i++) {

            for (int j = 0; j < cartas_repartir; j++) {

                Naipe carta_robada = robar_carta(baraja, cartas_disponibles);

                salida << leer_carta(carta_robada) << " ";
            }
            salida << endl;
        }
        salida.close();
      
        delete[] baraja;
      }
       else {
        cout << "Juego no reconocido" << endl;
      }

      return 0;
    }
  
