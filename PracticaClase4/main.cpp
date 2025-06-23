#include <iostream>

using namespace std;

int* returnDoubleValue(int& y) {
    int a = y*2;
    return &a;
}

void swapFunc(int& i, int& j){
    int valueI = i;
    i=j; j=valueI;
}

void elevarAlCuadrado(int& x) {
    x*=x;

}

void otra(){
    double* pvalue= NULL;

    double a;

    pvalue= &a;

    pvalue= new double;
    cout << pvalue << endl;

    *pvalue=29.5;

    cout << *pvalue << endl;


    delete pvalue;
    pvalue=NULL;

}

int main () {
    /*
    int x = 7;

    int* p = returnDoubleValue(x);

    cout << "memory" << " " << p << endl;
    cout << "value" << " " << *p << endl;
    cout << "x" << " " << x << endl;


    int x=10 , y=5;

    swapFunc(x,y);

    cout << "i" << " " << x << " " << "j" << " " << y << endl;

    elevarAlCuadrado(x);

    cout << "el resultado es" << " " << x << endl;
    */

    otra();

    return 0;

}
