#include "Venicle.h"  // предполагается, что твой код в файле Venicle.h
#include <iostream>

using namespace std;

int main() {
    // Создаём объекты транспортных средств
    Car car;
    Bike bike;
    Carriage carriage;

    int distance = 100;  // расстояние в км
    int speed = 80;      // скорость в км/ч

    cout << "=== Car ===" << endl;
    cout << "Time: " << car.getTime(distance, speed) << " hours" << endl;
    cout << "Cost: " << car.getCost(distance) << " rub" << endl;

    cout << "\n=== Bike ===" << endl;
    cout << "Time: " << bike.getTime(distance, speed) << " hours" << endl;
    cout << "Cost: " << bike.getCost(distance) << " rub" << endl;

    cout << "\n=== Carriage ===" << endl;
    cout << "Time: " << carriage.getTime(distance, speed) << " hours" << endl;
    cout << "Cost: " << carriage.getCost(distance) << " rub" << endl;

    return 0;
}