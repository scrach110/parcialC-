#include <iostream>

using namespace std;

template<typename T> class Iterator;
template<typename T> class FowardIterator;
template<typename T> class BackwardIterator;

template<typename T>
class Nodo {
private:
    T dato;
    Nodo<T>* anterior;
    Nodo<T>* siguiente;

public:
    Nodo(T dato) {
        this->dato = dato;
        anterior = nullptr;
        siguiente = nullptr;
    }

    T getValor() {
        return dato;
    }

    Nodo<T>* getAnterior() {
        return anterior;
    }

    Nodo<T>* getSiguiente() {
        return siguiente;
    }

    void setAnterior(Nodo<T>* ant) {
        this->anterior = ant;
    }

    void setSiguiente(Nodo<T>* sig) {
        this->siguiente = sig;
    }
};

template<typename T>
class Lista {
private:
    int length;
    Nodo<T>* primero;
    Nodo<T>* ultimo;

    Nodo<T>* getNodoDePosicion(int pos) {
            Nodo<T>* ptrActual = primero;
            int posActual = 0;

            while(ptrActual!= nullptr && posActual < pos){
                posActual++;
                ptrActual = ptrActual->getSiguiente();
            };

            return ptrActual;
    };

public:
    Lista() {
        primero = nullptr;
        ultimo = nullptr;
        length = 0;
    }

    Iterator<T>* fowardIterator(){
        return new FowardIterator<T>(primero);
    };
    Iterator<T>* backwardIterator(){
        return new BackwardIterator<T>(ultimo);
    };

    bool isEmpty() {
        return length == 0;
    }

    int getLength() {
        return length;
    }

    void add(int pos, T val) {
        Nodo<T>* nodo = new Nodo<T>(val);

        if (isEmpty()) {
            primero = ultimo = nodo;
        } else if (pos <= 0) {
            nodo->setSiguiente(primero);
            primero->setAnterior(nodo);
            primero = nodo;
        } else if (pos >= length) {
            nodo->setAnterior(ultimo);
            ultimo->setSiguiente(nodo);
            ultimo = nodo;
        } else {
            Nodo<T>* actual = getNodoDePosicion(pos);
            Nodo<T>* anterior = actual->getAnterior();

            anterior->setSiguiente(nodo);
            nodo->setAnterior(anterior);

            nodo->setSiguiente(actual);
            actual->setAnterior(nodo);
        }

        length++;
    }

    bool exist(int pos) {
        return getNodoDePosicion(pos)!=nullptr;
    }

    T get(int pos) {
        Nodo<T>* nodo = getNodoDePosicion(pos);
        return nodo->getValor();
    }

    void remove(int pos) {
        if (!exist(pos)) {
            throw out_of_range("Posicion invalida");
        }

        Nodo<T>* nodo = getNodoDePosicion(pos);

        if (nodo == primero && nodo == ultimo) {
            primero = ultimo = nullptr;
        } else if (nodo == primero) {
            primero = nodo->getSiguiente();
            primero->setAnterior(nullptr);
        } else if (nodo == ultimo) {
            ultimo = nodo->getAnterior();
            ultimo->setSiguiente(nullptr);
        } else {
            Nodo<T>* anterior = nodo->getAnterior();
            Nodo<T>* siguiente = nodo->getSiguiente();

            anterior->setSiguiente(siguiente);
            siguiente->setAnterior(anterior);
        }

        delete nodo;
        length--;
    }


    ~Lista() {
        while (!isEmpty()) {
            remove(0);
        };
    };
};



template<typename T> class Iterator{
public:
    virtual bool hasNext() = 0;
    virtual T next() = 0;

};

template<typename T> class FowardIterator : public Iterator<T>{
private:
     Nodo<T>* actual = nullptr;
public:
    FowardIterator(Nodo<T>* act){
        actual = act;
    };

    bool hasNext() override {
        return actual != nullptr;
    };

    T next() override {
        T valor = actual->getValor();
        actual = actual->getSiguiente();
        return valor;
    };
};

template<typename T> class BackwardIterator : public Iterator<T> {
private:
    Nodo<T>* actual = nullptr;

public:
    BackwardIterator(Nodo<T>* act){
        actual = act;
    };

    bool hasNext() override {
      return actual != nullptr;
    };

    T next() override {
        T valor = actual->getValor();
        actual = actual->getAnterior();
        return valor;
    };
};


int main() {
    Lista<int> listaInt = Lista<int>();
    cout << listaInt.isEmpty() << endl;
    listaInt.add(0,3);
    listaInt.remove(0);
    listaInt.add(1,4);
    listaInt.add(10,5);
    listaInt.add(2,10);
    listaInt.add(3,12);
    listaInt.add(4,41);
    listaInt.add(5,20);
    for(int i=0; i<listaInt.getLength(); i++){
        cout <<  listaInt.get(i) << ",";
    };
    cout<< "]" << endl;
    cout << listaInt.getLength() << endl;

    listaInt.remove(3);
    listaInt.isEmpty();
    cout << listaInt.getLength() << endl;
    cout << "la lista es [";
    for(int i=0; i<listaInt.getLength(); i++){
        cout <<  listaInt.get(i) << ",";
    };
    cout<< "]" << endl;
    Iterator<int>* foward = listaInt.fowardIterator();
    cout << "la lista foward es: [";
    listaInt.get(0);
    while(foward->hasNext()){
        cout <<foward->next() << ",";
    };
    cout<< "]" << endl;

    Iterator<int>* backward = listaInt.backwardIterator();
    cout << "la lista backward es: [";
    listaInt.get(0);
    while(backward->hasNext()){
        cout <<backward->next() << ",";
    };
    cout<< "]" << endl;

    return 0;
}
