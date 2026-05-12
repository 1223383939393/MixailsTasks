#include <iostream>
#include "Termometer.h"
using namespace std;
int main()
{
    Termometer num1;
    cout << num1.getCelcius() << endl;
    cout << num1.getFahrenheit() << endl;
    num1.printInfo();
    cout << endl;

    Termometer num2(23.0);
    cout << num2.getCelcius() << endl;
    cout << num2.getFahrenheit() << endl;
    num2.printInfo();
    cout << endl;
    
    Termometer num3("Kostroma", 32.0);
    cout << num3.getCelcius() << endl;
    cout << num3.getFahrenheit() << endl;
    num3.printInfo();
    cout << endl;
}

