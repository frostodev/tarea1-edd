#include <iostream>
#include <fstream>

using namespace std;

struct Naipe {
    int numero;
    char palo;
    char color;
};

int main() {
    // Abrir el archivo de la baraja
    ofstream archivoBinario;
    archivoBinario.open("baraja.dat", ios::binary);

    // Guardar la cantidad de naipes
    int cantidadNaipes = 52;
    archivoBinario << cantidadNaipes;

    int contadorPalos = 1;
    int contadorNaipe = 1;

    for (int i = 1; i <= cantidadNaipes; i++) {
        Naipe* naipeActual = new Naipe;

        // Determinar el palo
        if (contadorPalos == 1) {
            naipeActual->palo = 'P';
        } else if (contadorPalos == 2) {
            naipeActual->palo = 'C';
        } else if (contadorPalos == 3) {
            naipeActual->palo = 'D';
        } else if (contadorPalos == 4) {
            naipeActual->palo = 'T';
        }

        // Cada 14 cartas, cambiar el palo
        if (contadorNaipe % 14 == 0) {
            contadorNaipe = 1;

            // Reiniciar el contador de naipe
            contadorPalos++;    

            // Cambiar al siguiente palo
            if (contadorPalos > 4) {
                contadorPalos = 1; // Reiniciar el contador de palo
            }
        }

        // Cambiar el número de carta
        naipeActual->numero = contadorNaipe;

        // Además reiniciarlo cada 14 cartas
        if (contadorNaipe == 14) {
            contadorNaipe = 1;
        }

        // Determinar el color a partir del palo
        if (naipeActual->palo == 'P' || naipeActual->palo == 'T') {
            naipeActual->color = 'N';
        } else {
            naipeActual->color = 'R';
        }

        // Escribir el naipe al archivo
        archivoBinario << naipeActual;

        // Aumentar el contador del número de carta
        contadorNaipe++;

        // Liberar la memoria
        delete naipeActual;
    }

    // Cerrar el archivo
    archivoBinario.close();
    return 0;
}