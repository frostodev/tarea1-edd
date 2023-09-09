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
  /*******************************************************************************************************************
  * Naipe *crear_baraja
  * *****************************************************************************************************************
  * Extrae informacion del archivo "baraja.dat" 
  *
  * Importante: Retorna 1 si no se pudo abrir el archivo.
  * *****************************************************************************************************************
  * Imput:
  * int &cartas_disponibles : Usando paso por referencia para devolver al programa la cantidad de cartas disponibles sin hacer un retorno directo 
  * *****************************************************************************************************************
  * Returns:
  * arregloBaraja : Un arreglo con todas la baraja extraída de "barajas.dat"
  *******************************************************************************************************************/
  
  ifstream archivo_entrada;
  archivo_entrada.open("baraja.dat", ios::binary);

  // Comprueba si se abrió bien el archivo
  if(!archivo_entrada.is_open()){
    cout << "Error al abrir el archivo" << endl;
    return 1;
  }
  
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
  /*******************************************************************************************************************
  * Naipe robar_carta
  * *****************************************************************************************************************
  * Desde el arreglo de cartas disponibles usa la función rand() para extraer una de forma aleatoria
  *
  * *****************************************************************************************************************
  * Imput:
  * int &cartas_disponibles : Usando paso por referencia para devolver al programa la cantidad de cartas disponibles sin hacer un retorno directo 
  * Naipe *arreglo : Recibe un arreglo de todas las cartas disponibles para escoger una al azar
  * *****************************************************************************************************************
  * Returns:
  * carta_robada : Retorna la carta que fue robada del arreglo entregado
  *******************************************************************************************************************/
  int indice = rand() % cartas_disponibles;
  Naipe carta_robada = arreglo[indice];

  arreglo[indice] = arreglo[cartas_disponibles - 1];
  cartas_disponibles--;

  return carta_robada;
}

int leer_carta(Naipe carta_robar) {
  /********************************************************************************************************************
  * int leer_carta
  * *******************************************************************************************************************
  * Lee la baraja original del archivo "baraja.dat" y genera un archivo de tamaño n que está en la primera linea del 
  * archivo, luego genera un arreglo de ese tamaño y empieza a comparar carta por carta hasta encontrar la carta que 
  * coincida con la carta robada, luego guarda su posición y la retorna al main
  * *******************************************************************************************************************
  * Imput:
  * Naipe carta_robar : Recibe una carta que fue robada y la compara con la baraja original para encontrar la posición
  * *******************************************************************************************************************
  * Returns:
  * posición : retorna un entero que es la posición de la carta robada en el arreglo original del archivo "baraja.dat"
  *********************************************************************************************************************/
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
    int Rojo, Negro = 0;
    int cartas_disponibles;

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
        if (carta_robada.color == 'R'){
          Rojo++;
        }
        else{
          Negro++;
        }
        salida << leer_carta(carta_robada) << " ";
      }
      salida << endl;
    }
  
    salida.close();

    delete[] baraja;
    cout << "Cartas rojas: " << Rojo<< endl;
    cout << "Cartas negras: " << Negro << endl;
  }
  if (juego == "B") {
      int Rojo, Negro = 0;
      int cartas_disponibles;

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
        if (carta_robada.color == 'R'){
          Rojo++;
        }
        else{
          Negro++;
        }
          salida << leer_carta(carta_robada) << " ";
        }
        salida << endl;
      }
      salida.close();

      delete[] baraja;
      cout << "Cartas rojas: " << Rojo<< endl;
      cout << "Cartas negras: " << Negro << endl;
  }
      if (juego == "C") {
        int Rojo, Negro = 0;
        int cartas_disponibles;

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
                if (carta_robada.color == 'R'){
                  Rojo++;
                }
                else{
                  Negro++;
                }
                salida << leer_carta(carta_robada) << " ";
            }
            salida << endl;
        }
        salida.close();
      
        delete[] baraja;
        cout << "Cartas rojas: " << Rojo<< endl;
        cout << "Cartas negras: " << Negro << endl;
      }
      return 0;
    }
  
