#include <iostream>
using namespace std;


class Carta {
    private:
        string palo;
        int valor;

    public:
        Carta(string pal, int val){
            this->palo = pal;
            this->valor = val;
        };

        void incrementarValor(){
            if(this->valor == 12){
                valor = 1;
            }
            else {
                valor++;
            }
        };

        int getValor(){
            return this->valor;
        };

        string toString() {
        return "palo: " + this->palo + " | valor: " + to_string(this->valor);
            };
};

class Pokemon {
    private:
        string nombre;
        int vida;

    public:
            Pokemon(string nom, int hp){
                this->nombre = nom;
                this->vida = hp;
            };
};



template <typename T>
class Nodo {
public:
    T dato; 
    Nodo* siguiente; 

    Nodo(T dato) : dato(dato), siguiente(nullptr) {}
};

template <typename T>
class Queue {
private:
    Nodo<T>* primero;
    Nodo<T>* ultimo;                                                                                                                                                                                                            
    int cantidad;

public:
    Queue() : primero(nullptr),
              ultimo(nullptr),
              cantidad(0) {}

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }


    void enqueue(T valor) {
        Nodo<T>* nuevo = new Nodo<T>(valor);
        if (isEmpty()) {
             primero = nuevo;
             ultimo = nuevo;
        } else {
            ultimo->siguiente = nuevo;
            ultimo = nuevo;
        }
        cantidad++;
    }


    T dequeue() {
        if (isEmpty()) {
            throw runtime_error("error: la queue esta vacia.");
        }
        Nodo<T>* temp = primero;
        T valor = temp->dato;
        primero = primero->siguiente;
        delete temp;
        cantidad--;
        if (primero == nullptr) {
            ultimo = nullptr;
        }
        return valor;
    }


    T look() const {
        if (isEmpty()) {
            throw runtime_error("error: la queue est� vac�a.");
        }
        return primero->dato;
    }

 
    bool isEmpty() const {
        return primero == nullptr;
    }

 
    int size() const {
        return cantidad;
    }


string toString() const
    {
        string result = "[ ";
        Nodo<T>* current = primero;

        while (current != nullptr)
        {
            result.append(to_string(current->dato));
            if (current->siguiente != nullptr)
                result.append(", ");
            current = current->siguiente;
        }

        result.append(" ]");
        return result;
    }


    Queue<T>* clone() const {
        Queue<T>* nueva = new Queue<T>();
        Nodo<T>* actual = primero;
        while (actual != nullptr) {
            nueva->enqueue(actual->dato);
            actual = actual->siguiente;
        }
        return nueva;
    }
};

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



template<typename Key, typename T>
class Node {
private:
    Key key;
    T value;
    Node<Key, T>* left;
    Node<Key, T>* right;

public:
    Node(Key k, T val){
        this->key = k;
        this->value = val;
        left  = nullptr;
        right = nullptr;
    };

    Key getKey(){
        return key;
    };

    T getValue(){
        return value;
    };

    void setLeft(Node<Key,T>* l){
        this->left = l;
    };

    Node<Key,T>* getLeft(){
        return left;
    };

    void setRight(Node<Key,T>* r){
        this->right = r;
    };

    Node<Key,T>* getRight(){
        return right;
    };

};


template<typename Key, typename T>
class Tree {
private:
    Node<Key, T>* base;

    T buscarValor(Key clave, Node<Key,T>* actual){

        if(actual == nullptr){
            throw runtime_error("no se encontro");
        }
        else if(clave == actual->getKey()){
            return actual->getValue();
        }
        else if(clave < actual->getKey()){
            return buscarValor(clave, actual->getLeft());
        }
        else {
            return buscarValor(clave, actual->getRight());
        };
    };

    void buscarNode(Key key, Node<Key,T>* actual, Node<Key,T>* nuevo){
        if(actual->getKey()> key && actual->getLeft() == nullptr){
            actual->setLeft(nuevo);
        }
        else if(actual->getKey()< key && actual->getRight() == nullptr){
            actual->setRight(nuevo);
        }
        else if(actual->getKey()> key){
            buscarNode(key, actual->getLeft(), nuevo);
        }
        else{
            buscarNode(key, actual->getRight(), nuevo);
        };

    };

    Lista<T>* listado(Lista<T>* lista, Node<Key,T>* actual){
            if(actual != nullptr){
                listado(lista, actual->getLeft());
                lista->add(lista->getLength(), actual->getValue());
                listado(lista, actual->getRight());
            }

            return lista;

    };

    void destruir(Node<Key, T>* nodo) {
        if (nodo != nullptr) {
            destruir(nodo->getLeft());
            destruir(nodo->getRight());
            delete nodo;
        }
    }

public:
    Tree(){
        base = nullptr;
    };



    T buscar(Key key){
        return this->buscarValor(key, base);
    };


    void agregar(Key key, T value){
        Node<Key,T>* nuevo = new Node<Key,T>(key,value);
        if(base == nullptr){
            base = nuevo;
        }
        else {
            buscarNode(key, base, nuevo);
        };

    };


    Lista<T>* listar(){
        Lista<T>* lista = new Lista<T>();

        return listado(lista, base);





    };



    ~Tree(){
        destruir(base);
    };

};



int main() {
    Queue<int> turnos;

    turnos.enqueue(12);
    turnos.enqueue(15);
   

    Lista<Pokemon*>* equipo = new Lista<Pokemon*>();

    Pokemon* pikachu = new Pokemon("Pikachu", 12);
    Pokemon* charizard = new Pokemon("Charizard", 200);

    equipo->enqueue(0,pikachu);
    equipo->enqueue(1,charizard);


    Tree<int, Carta*>* mazo = new Tree<int,Carta*>();

    Carta* copas3 = new Carta("Copa", 3);
    Carta* espada1 = new Carta("Espada", 1);
    Carta* anchoBasto = new Carta("Basto", 1);

    mazo->agregar(copas3->getValor(), copas3);
    mazo->agregar(espada1->getValor(), espada1);
    mazo->agregar(anchoBasto->getValor(), anchoBasto);



    auto it = equipo.forwardIterator();
    while (it->hasNext()) cout << it->next().getNombre() << " ";
    cout << endl;
    delete it;

    cout << "Turno atendido: " <<  << endl;
    cout << "Carta de valor 1: " <<  << endl;

    return 0;
}