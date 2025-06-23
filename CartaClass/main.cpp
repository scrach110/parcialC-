#include <iostream>

using namespace std;


class Carta {

    private:
        string palo;
        int* pValor;

      public:
          Carta(string paloX, int valorY){
            this->palo = paloX;
            pValor = new int;
            (*pValor) = valorY;
          };


     ~Carta(){
            delete pValor;
          };

     void incrementarValor(){
             if(*pValor == 12){
                (*pValor) = 1;
                }
                else {
                    (*pValor)++;
                }

          };

     string toString() {
        return "palo: " + this->palo + " | valor: " + to_string(*pValor);
            }

};



int main()
{
    Carta* carta = new Carta("basto",10);

    cout << "Los valores de la carta inicio" << "" << "" << carta -> toString() << endl;

    carta -> incrementarValor();

    cout << "Los valores de la carta son" << "" << "" << carta -> toString() << endl;

    delete carta;
    return 0;
}
