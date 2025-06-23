#include <iostream>

using namespace std;

template <typename T1, typename T2> class Pair{
public:
    T1 x;
    T2 y;

    Pair(T1 val1, T2 val2):
        x(val1), y(val2){};

    T1 getFirst(){
        return x;
    };
    T2 getSecond() {
    return y;
    };

    void setFirst(T1 val){
        x = val;
    };

    void setSecond(T2 val){
        y = val;
    };


};

class Person {
private:
    string nombre;
    int edad;

public:
    Person(string nom, int ed){
        nombre = nom;
        edad = ed;
    }

    string getName(){
        return this->nombre;
    };
    int getAge(){
        return this->edad;
    }

    void setName(string name){
        this->nombre = name;
    }

    void setAge(int age){
        this->edad = age;
    }

    ~Person() {};


};

int main()
{
    Pair<int,double> p1(10,20.5);
    cout << "Pair 1:("<< p1.getFirst() << ","<< p1.getSecond() << ")" << endl;

    Pair<string,char> p2("hello",'A');
    cout << "Pair 2: (" << p2.getFirst() << "," << p2.getSecond() << ")" << endl;

    p1.setFirst(15);
    p1.setSecond(25.5);
    p2.setFirst("world");
    p2.setSecond('B');

    cout << "Modified pair 1: (" << p1.getFirst() << "," << p1.getSecond() << ")" << endl;
    cout << "Modified pair 2: (" << p2.getFirst() << "," << p2.getSecond() << ")" << endl;

    Person* person = new Person("John Doe", 30);

    Pair<int, Person*> p3(1, person);
    cout << "Pair3: (" << p3.getFirst() << "," << p3.getSecond()->getName() << "," << p3.getSecond()->getAge() << ")" << endl;

    p3.getSecond()->setName("Jane Doe");
    p3.getSecond()->setAge(25);

    cout << "Modified pair 3: (" << p3.getFirst() << "," << p3.getSecond()->getName() << "," << p3.getSecond()->getAge() << ")" << endl;

    delete person;


     return 0;
}
