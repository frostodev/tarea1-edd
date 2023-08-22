#include <iostream>
#include <fstream>

using namespace std;

struct Naipe {
    int numero;
    char palo;
    char color;
};

int main() {
    ifstream archivoBinario;
    archivoBinario.open("baraja.dat", ios::binary);

    int cantidadNaipes;
    archivoBinario.read((char*)&cantidadNaipes, sizeof(int));

    cout << "Cantidad de naipes en el archivo: " << cantidadNaipes << endl;

    Naipe naipeActual;

    for (int i = 0; i < cantidadNaipes; i++) {
        archivoBinario.read((char*)&naipeActual, sizeof(Naipe));

        cout << "Color: " << naipeActual.color << " Palo: " << naipeActual.palo << " Número: " << naipeActual.numero << endl;
    }

    archivoBinario.close();

    return 0;
}
