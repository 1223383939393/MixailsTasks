#include "Vehicle.h"
#include <iostream>
using namespace std;

int main() {
    // Test 1: Car with full parameters
    cout << "=== Test 1: Car with full parameters ===" << endl;
    Car car1("Toyota Camry", 2022, 4, 17.0, "winter", 200, 2.5, "diesel", 4, true);
    car1.showCar();

    // Test 2: Car with default wheels
    cout << "\n=== Test 2: Car with default wheels ===" << endl;
    Car car2("Lada Vesta", 2021);
    car2.showCar();

    // Test 3: Car without parameters
    cout << "\n=== Test 3: Car without parameters ===" << endl;
    Car car3;
    car3.showCar();

    return 0;
}