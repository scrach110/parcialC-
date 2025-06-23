#include <iostream>

using namespace std;
sum(int x)
{
    if(x==0)
    {
        return 0;
    }
    else
    {
        return x+sum(x-1);
    }
}

int sumFor(int x)
{
    int suma = 0;
    for (int i=1; i<=x; i++)
    {
        suma+= i;
    }

    return suma;
}
/*
void contarHasta(int n)
{
    if(n>1)
    {
        cout << contarHasta(n-1) << ++ n ;
        else
        {
            cout << n <<
        }
    }
}

void contarHastaFor(int n)
{

    for(int i=1; i<=n; i++)
    {
                << i << ""
    }
    count << endl;
}
*/

void positivos(int array[], int size)
{
    if(size=0)
    {
                "";
    }
    else if(array[0]<= 0)
    {
        positivos(++array,size-1);
    }
    else
    {
        cout << array[0] <<  positivos(++array, size-1)
    }
}

void negativos(int array[], int size){
    if(size=0)
    {
        <<""<<
    }
    else if(array[0]>=0){
        negativos(++array,size-1);
    }
    else {
        cout << array[0] << negativos(++array, size-1)
    }

}

void separarNumeros(int array[], int size)
{
    return positivos(array, size) << "" << negativos(array, size);
}




int main()
{
    array manuel =[1,2,5,-2,-4,0,2,1]
    //cout << sum(5) << endl;
    //cout << sumFor(5) << endl;
    //contarHastaFor(5)
    //contarHasta(5)
    separarNumeros(manuel,8)
    return 0;
}


