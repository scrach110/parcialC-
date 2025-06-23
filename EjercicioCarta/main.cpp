#include <iostream>

using namespace std;

struct Carta {
    string palo;
    int valor;
};

Carta* crearCarta(string palo, int valor){
    Carta* carta = new Carta;

    carta -> palo = palo;
    carta -> valor = valor;

    return carta;
}

void incrementarValor(Carta* carta){
    if(carta -> valor == 12){
        carta -> valor = 1;
    }
    else {
        carta -> valor++;
    }

}

string toString(Carta* carta){
    return "palo:" + carta->palo + "" + "valor:" + to_string(carta->valor);
}

void liberarMemoria(Carta* carta){
    delete carta;
};

int main()
{
    string paloX;
    int valorY;

    cout << "ingrese el Palo" << endl;
    cin >> paloX;
    cout << "ingrese el valor" << endl;
    cin >> valorY;

    Carta* carta = crearCarta(paloX, valorY);

    incrementarValor(carta);

    cout << "Los valores de la carta son" << "" << "" << toString(carta) << endl;

    liberarMemoria(carta);

    return 0;
}
