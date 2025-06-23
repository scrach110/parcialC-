#include <iostream>

using namespace std;

template <typename T> T myMax(T x, T y) {
    return (x>y) ? x : y;

}

template <typename T> class Geek {
public:
    T x;
    T y;

    Geek(T valor1, T valor2) :
        x(valor1), y(valor2){}


    void getValues(){
        cout << x << " " << y;
    }

};

template <typename T1, typename T2, typename T3> class Geek2 {
public:
    T1 x;
    T2 y;
    T3 z;

    Geek2(T1 val1, T2 val2, T3 val3):
        x(val1),y(val2),z(val3) {}

    void getValues(){
        cout << x << " " << y << " " << z;
    };
};

template <typename T> constexpr T pi = T(3.14159);

template <typename T1, typename T2 = double, typename T3 = string> class Geek3 {
public:
    T1 x;
    T2 y;
    T3 z;

    Geek3(T1 val1, T2 val2, T3 val3) :
        x(val1), y(val2), z(val3){};

    getValues(){
        cout << x << "  " << y << " " << z;
    };
};


int main()
{
    cout << myMax<int>(2,5) << endl;
    cout << myMax<double>(4.5, 2.1) << endl;
    cout << myMax<char>('c','f') << endl;

    Geek<int> intGeek(10,20);
    Geek<double> doubleGeek(3.14,6.28);

    intGeek.getValues();
    cout << endl;
    doubleGeek.getValues();

    Geek2<int, double, string> intDoubleStringGeek(10, 3.14, "Hola tonotos");

    intDoubleStringGeek.getValues();

    cout << "Pi como float:" << pi<float> << endl;
    cout << "Pi como double:" << pi<double> << endl;

    Geek3<int,float,string> intFloatStringGreek(10,5.67,"holanda");
    Geek3<char> charDoubleStringGreek('A',3.14, "moldavia");
    intFloatStringGreek.getValues();
    cout << endl;
    charDoubleStringGreek.getValues();

    return 0;
}
