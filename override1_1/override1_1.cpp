#include <iostream>
#include <string>
#include "Fraction.h"
using namespace std;

int main()
{
    Fraction a(1, 2); // 1/2
    Fraction b(3, 4); // 3/4
    Fraction c = a + b; // 5/4
    cout << c; // Вывод: 5/4

}

