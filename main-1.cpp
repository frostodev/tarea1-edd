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
    archivoBinario.write((char*)&cantidadNaipes, sizeof(int));

    // Contadores
    int contadorPalos = 1;
    int contadorNaipe = 1;

    for (int i = 1; i <= cantidadNaipes; i++) {

        // Crear el naipe
        Naipe naipeActual;

        // Determinar el palo
        if (contadorPalos == 1) {
            naipeActual.palo = 'P';
        } else if (contadorPalos == 2) {
            naipeActual.palo = 'C';
        } else if (contadorPalos == 3) {
            naipeActual.palo = 'D';
        } else if (contadorPalos == 4) {
            naipeActual.palo = 'T';
        }

        // Cambiar el número de carta
        naipeActual.numero = contadorNaipe;

        // Determinar el color a partir del palo
        if (naipeActual.palo == 'P' || naipeActual.palo == 'T') {
            naipeActual.color = 'N';
        } else {
            naipeActual.color = 'R';
        }

        // Escribir el naipe al archivo
        archivoBinario.write((char*)&naipeActual, sizeof(Naipe));

        // Aumentar el contador del número de carta
        contadorNaipe++;

        // Cambiar al siguiente palo después de 13 cartas
        if (contadorNaipe > 13) {
            contadorNaipe = 1;
            contadorPalos++;
        }

        // Reiniciar el contador de palo
        if (contadorPalos > 4) {
            contadorPalos = 1;
        }
    }

    // Cerrar el archivo
    archivoBinario.close();
    return 0;
}
