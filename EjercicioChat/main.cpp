#include <iostream>
using namespace std;

class Persona {
    private:
        string nombre;
        int edad;

    public:
        Persona(string nom, int eda){
            this->nombre = nom;
            this->edad = eda;
        };

        string getNombre(){
            return this->nombre;
        };
        void setNombre(string nom){
            this->nombre = nom;
        };
        int getEdad(){
            return this->edad;
        }
        void setEdad(int eda){
            this->edad = eda;
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

int main()
{
    Persona* juan = new Persona("Juan", 29);
    Persona* miguel = new Persona("Miguel", 20);
    Persona* facu = new Persona("Facu", 9);
    Persona* santi = new Persona("Santi", 2);

    Queue<Persona*>* clinica = new Queue<Persona*>();

    clinica->enqueue(juan);
    clinica->enqueue(miguel);
    clinica->enqueue(facu);
    clinica->enqueue(santi);

    clinica->toString();
    
    Queue<Persona*>* listaAtendidos = new Queue<Persona*>();

    listaAtendidos->enqueue(clinica->dequeue());

    cout << listaAtendidos->toString(); << endl;




    return 0;
}
