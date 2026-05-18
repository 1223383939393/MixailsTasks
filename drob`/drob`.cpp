// main.cpp
#include "Fraction.h"
#include <iostream>

using namespace std;

int main() {
    cout << "=== Testing Fraction class ===\n" << endl;

    // 1) Constructors
    Fraction f1(2, 4);   // 2/4 = 1/2
    Fraction f2(3, 5);   // 3/5
    Fraction f3;         // 0/1

    cout << "1) Created fractions:" << endl;
    f1.Info();
    f2.Info();
    f3.Info();
    cout << endl;

    // 2) Test operator +
    cout << "2) Testing operator +:" << endl;
    Fraction sum = f1 + f2;
    sum.Info();          // 2/4 + 3/5 = 11/10
    cout << endl;

    // 3) Test operator -
    cout << "3) Testing operator -:" << endl;
    Fraction diff = f2 - f1;
    diff.Info();         // 3/5 - 2/4 = 1/10
    cout << endl;

    // 4) Test operator *
    cout << "4) Testing operator *:" << endl;
    Fraction prod = f1 * f2;
    prod.Info();         // 2/4 * 3/5 = 3/10
    cout << endl;

    // 5) Test Plus(int n, Fraction)
    int n = 2;
    cout << "5) Testing Plus(int n, Fraction): n + ot" << endl;
    Fraction p = f1.Plus(n, f2);
    p.Info();            // 2 + 3/5 = 13/5
    cout << endl;

    // 6) Test Minus(int n, Fraction)
    cout << "6) Testing Minus(int n, Fraction): n - ot" << endl;
    Fraction m = f1.Minus(n, f2);
    m.Info();            // 2 - 3/5 = 7/5
    cout << endl;

    // 7) Test Multi(int n, Fraction)
    cout << "7) Testing Multi(int n, Fraction): n * ot" << endl;
    Fraction mu = f1.Multi(n, f2);
    mu.Info();           // 2 * 3/5 = 6/5
    cout << endl;

    // 8) Test 0 + fraction
    cout << "8) Testing 0 + fraction:" << endl;
    Fraction zero_plus = f3 + f2;
    zero_plus.Info();    // 0/1 + 3/5 = 3/5
    cout << endl;

    cout << "=== Fraction class tests completed ===" << endl;

    return 0;
}