#include <iostream>
using namespace std;

// Persona

class Person {
private:
    string name;
    int age;

public:
    Person(string name, int age) : name(name), age(age) {}

    string getName() const
    { return name; }
    int getAge() const
    { return age; }

    void setName(string newName)
    { name = newName; }
    void setAge(int newAge)
     { age = newAge; }
};
string to_string(Person* p)
{
    return p->getName();
}

// Nodo

template <typename T>
class Nodo {
public:
    T dato; // juan
    Nodo* siguiente; // siguiente persona en la fila (maria)

    Nodo(T dato) : dato(dato), siguiente(nullptr) {}
    //[NODO: Juan] -> [NODO: Maria] -> [NODO: Tomas] -> null
};

// Queue

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

    // Enqueue
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

    // Dequeue
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

    // Look
    T look() const {
        if (isEmpty()) {
            throw runtime_error("error: la queue está vacía.");
        }
        return primero->dato;
    }

    // isEmpty
    bool isEmpty() const {
        return primero == nullptr;
    }

    // size
    int size() const {
        return cantidad;
    }

    // toString: concatenar los elemntos, un string q se le agregan cosas lo termino lo devuelve y lo imprime.
    //erores

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


    // clone
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



// Main

int main()
{
     // Create a Queue of int
    Queue<int>* intQueue = new Queue<int>();
    intQueue->enqueue(1);
    intQueue->enqueue(2);
    intQueue->enqueue(3);
    cout << "Front of intQueue: " << intQueue->look() << endl;
    cout << "Dequeue of intQueue: " << intQueue->dequeue() << endl;
    cout << "Front of intQueue after dequeue: " << intQueue->look() << endl;
    cout <<  "Size: "<< intQueue->size()<< endl;
    cout << "Aca va el toString" << endl;
    cout << "toString" << intQueue->toString()<< endl;


    // !!! Luego que este main inicial ande, agregar un to string
    // que devuelva representación en formato string de lo que
    // tiene la cola para poder imprimirlo si sacar los datos
    // El método devuelve un string y lo imprimo desde aca afuera.

    cout <<  "Size: "<< intQueue->size()<< endl;
     intQueue->enqueue(4);
     cout <<  "Size: "<< intQueue->size()<< endl;

    // Create a Queue of string
    Queue<string>* stringQueue = new Queue<string>();
    stringQueue->enqueue("Hello");
    stringQueue->enqueue("World");
    cout<< "Size: "<<stringQueue->size()<<endl;
    cout<< "Empty: "<<stringQueue-> isEmpty()<<endl;
    cout << "Front of stringQueue: " << stringQueue->look() << endl;
    stringQueue->dequeue();
    cout << "Front of stringQueue after dequeue: " << stringQueue->look() << endl;
    cout<< "Size: "<<stringQueue->size()<<endl;
    cout<< "Empty: "<<stringQueue-> isEmpty()<<endl;

    Queue<Person*>* personQueue = new Queue<Person*>();
    Person* p1 = new Person("John Doe", 30);
    Person* p2 = new Person("Jane Doe", 25);
    personQueue->enqueue(p1);
    personQueue->enqueue(p2);
    cout << "Front of personQueue: " << personQueue->look()->getName() << ", " << personQueue->look()->getAge() << endl;
    personQueue->dequeue();
    cout << "Front of personQueue after dequeue: " << personQueue->look()->getName() << ", " << personQueue->look()->getAge() << endl;
    cout << "toString persona" << personQueue->toString() << endl;

    // Clean up
    delete p1;
    delete p2;
    delete intQueue;
    delete stringQueue;
    delete personQueue;

    return 0;
}
