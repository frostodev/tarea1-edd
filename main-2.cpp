#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Naipe {
    int numero;
    char palo;
    char color;
};

/****************************************
* Naipe * crearBaraja
* **************************************
* Lee el archivo baraja.dat y genera un arreglo de naipes (baraja)
* **************************************
*  Input:
*       No tiene
* **************************************
* Returns:
*       Naipe arregloBaraja[i], con i siendo un arreglo de naipes que será usado como
*       baraja.
***************************************/

Naipe *crear_baraja () {
    ifstream archivo_entrada;
    archivo_entrada.open("baraja.dat", ios::binary);
    
    // leer la cantidad de naipes en el archivo
    int i;
    archivo_entrada.read((char*)&i, sizeof(int));

    Naipe arregloBaraja[i];
    Naipe naipeActual;

    for (int j = 0; j < i; j++) {
        archivo_entrada.read((char*)&naipeActual, sizeof(Naipe));
        arregloBaraja[j].color = naipeActual.color;
        arregloBaraja[j].palo = naipeActual.palo;
        arregloBaraja[j].numero = naipeActual.numero;

    }

    archivo_entrada.close();
    return arregloBaraja;
}

/****************************************
* Naipe robar_carta
* **************************************
* Toma una carta del arreglo, y la elimina de este.
* **************************************
*  Input:
*      Naipe* arreglo   :   Arreglo de naipes (baraja)
*      int &cartas_disponibles  :   Referencia de entero que contiene la cantidad de
*                                   cartas disponibles
* **************************************
* Returns:
*      Naipe carta_robada   :   Un naipe sacado del arreglo
***************************************/

Naipe robar_carta(Naipe* arreglo, int& cartas_disponibles){
    int indice = rand() % cartas_disponibles;
    Naipe carta_robada = arreglo[indice];
    for(int i = indice; i < cartas_disponibles - 1; i++){
        arreglo[i] = arreglo[i + 1];
    }
    cartas_disponibles--;
    return carta_robada;
}

/****************************************
* int * comprarTarjeta
* **************************************
* Crea un contador de el color de los naipes
* **************************************
*  Input:
*      Naipe carta  :   Naipe de donde obtener el color
*      int cantidad_cartas  :   Entero que contiene la cantidad total de cartas
* **************************************
* Returns:
*       
***************************************/

char color_carta (Naipe carta, int cantidad_cartas){
    int Rojo = 0;
    int Negro = 0;
    for (int z = 0; z < cantidad_cartas; z++){
        if (carta.color == "R"){
            Rojo++;
        } else {
            Negro++
        }
    }
    int colores[2];
    colores[0] = Rojo;
    colores[1] = Negro;
    return colores;
}

int main(){
    ofstream archivo;
    int jugadores;
    string juego;
    cout << "Ingrese la cantidad de jugadores: " << endl;
    cin >> jugadores;
    cout << "Ingrese el juego: " << endl;
    cin >> juego;
    string jugadores_string = to_string(jugadores);

    Naipe jugador[jugadores]; // Arreglo de naipes por cada jugador

    if (juego == "P"){
        Naipe* baraja = crear_baraja();
        int cartas_repartir = 5;
        archivo.open(juego + jugadores_string + ".txt", ios::binary);
        if (jugadores < 2 or jugadores > 7){
            cout << "La cantidad de jugadores no es valida" << endl;   
            return 0;
        }for (int i = 0; i < jugadores; i++){
            for (int j = 0; j < cartas_repartir ; j++){
                robar_carta(baraja, cartas_repartir);
            }
        }
    }

    if(juego == "C"){
        for (int a = 0; a < 2; a++){
            Naipe* baraja = crear_baraja();
        }
        int cartas_repartir = 15;
        // son 2 barajas
        archivo.open(juego + jugadores_string + ".txt", ios::binary);
        if (jugadores < 2 or jugadores > 6){
            cout << "La cantidad de jugadores no es valida" << endl;   
            return 0;
        }for (int i = 0; i < jugadores; i++){

        }
    }

    if(juego == "B"){
        Naipe* baraja = crear_baraja();
        int cartas_repartir = 4;
        archivo.open(juego + jugadores_string + ".txt", ios::binary);
        if (jugadores < 2 or jugadores > 6){
            cout << "La cantidad de jugadores no es valida" << endl;   
            return 0;
        }for (int i = 0; i < jugadores; i++){
            robar_carta(baraja, cartas_repartir);
        }
    }

    return 0;
}
