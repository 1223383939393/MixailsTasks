#include "Employer.h"
#include <iostream>
using namespace std;

int main()
{
    President president;
    Manager manager;
    Worker worker;

    Employer* staff[3];
    staff[0] = &president;
    staff[1] = &manager;
    staff[2] = &worker;

    cout << "=== Company staff info ===" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "Employee #" << i + 1 << ": ";
        staff[i]->Print();
    }

    cout << endl;
    cout << "=== Demo finished ===" << endl;

    return 0;
}