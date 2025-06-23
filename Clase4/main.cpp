#include <iostream>

using namespace std;


void duplicateReference(int& a , int& b, int& c) {
        a*=2; b*=2;c*=2;
        }

void duplicateValor(int a, int b, int c){
    a*=2; b*=2; c*=2;
}

int* returnDobleReference(int& y){
    y = y*2;

    return &y;
}

int global;

int* returnDoubleGlobal(int y){
    global = y*2;

    return &global;
}

int returnDobleValue(int y){
    int a = y*2;

    return a;
}

int main()
{
    int x=1, y=3, z=7;

    duplicateValor(x,y,z);

    cout << x << " " << y << " " << z << endl;

    duplicateReference(x,y,z);
    cout << x << " " << y << " " << z << endl;

    int value= returnDobleValue(x);

    cout << value << " " << x<< endl;

    int* value1= returnDobleReference(x);

    cout << "memory" << " " << value1 << endl;
    cout << "valor" << " " << *value1 << endl;

    int* value2 = returnDoubleGlobal(x);

    cout << "memory" << " " << value2 << endl;
    cout << "valor" << " " << *value2 << endl;
    cout << "global" << " " << global << endl;

    return 0;
}
