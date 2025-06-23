#include <iostream>
#include <string>
using namespace std;





string to_string(string s){
    return s;
}


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

    string imprimir(){
        string resultado = "[ ";
        Nodo<T>* actual = primero;
        while(actual != nullptr){
            resultado = resultado + " , " + to_string(actual->getValor());
            actual = actual->getSiguiente();
        }
        return resultado + " ]";
    }

    ~Lista() {
        while (!isEmpty()) {
            remove(0);
        };
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

template<typename Codigo> class Producto {
    private:
        Codigo codigo;
        string nombre;
        int cantidadStock;

    public:
        Producto(Codigo cod, string nom, int cant){
            this->codigo = cod;
            this->nombre = nom;
            this->cantidadStock = cant;
        };

    string nombreProducto(){
        return this->nombre;
    };
    void setNombreProducto(string nom){
        this->nombre = nom;
    };
    int cantidadStock(){
        return this->cantidadStock;
    };
    void setCantidadStock(int cant){
        this->cantidadStock = cant;
    };
    Codigo getCodigo(){
        return this->codigo;
    };
    void setCodigo(Codigo cod){
        this->codigo = cod;
    };
};

int main()
{

    Tree<int,string>* tree = new Tree<int,string>();
    tree->agregar(5, "hola");

    tree->agregar(10,"chau");

    tree->agregar(2,"cahula");

    cout << tree->buscar(5) << endl;
    cout << tree->buscar(10) << endl;

    cout << tree->listar()->imprimir() << endl;


    Producto<int>* maniqui = new Producto<int>(5, "maniqui", 20);
    Producto<int>* pulsera = new Producto<int>(2, "pulsera", 32);
    Producto<int>* jarron = new Producto<int>(4, "jarron", 2);
    Producto<int>* tijera = new Producto<int>(8, "tijera", 21);
    Producto<int>* arbol = new Producto<int>(1, "arbol", 10);

    Tree<int,Producto<int>*>* treeInventario = new Tree<int,Producto<int>*>();

    treeInventario->agregar(maniqui->getCodigo(), maniqui);
    treeInventario->agregar(pulsera->getCodigo(), pulsera);
    treeInventario->agregar(jarron->getCodigo(), jarron);
    treeInventario->agregar(tijera->getCodigo(), tijera);
    treeInventario->agregar(arbol->getCodigo(), arbol);

    treeInventario->buscar(jarron->getCodigo())->nombreProducto();

    treeInventario->listar();

    treeInventario->~Tree();

    delete maniqui;
    delete pulsera;
    delete jarron;
    delete tijera;
    delete arbol;
    delete treeInventario;

    return 0;
}
