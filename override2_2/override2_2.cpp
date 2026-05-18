// main.cpp
#include "Employee.h"
#include <iostream>

using namespace std;

int main() {
    cout << "=== Testing Employee hierarchy ===\n" << endl;

    // 1) Создаём разные сотрудники
    // Важно: указатели на Employee, а внутри хранятся Manager / Developer / Intern
    Employee* staff[] = {
        new Employee("John", 1000, 50000),          // обычный сотрудник
        new Manager("Alice", 1001, 70000, 100, 5),  // 5 подчинённых, бонус 100
        new Developer("Bob", 1002, 60000, "C++", 3), // 3 года опыта
        new Intern("Kate", 1003, 40000, true)       // Intern с наставником
    };

    // 2) Проверяем полиморфизм: getInfo() и calculateSalary()
    for (int i = 0; i < 4; ++i) {
        cout << "Employee #" << i << ":" << endl;
        staff[i]->getInfo();           // вызывается getInfo() конкретного класса
        cout << " -> Real salary: " << staff[i]->calculateSalary() << endl;
        cout << endl;
    }

    // 3) Пример: вызов методов через Employee*
    cout << "=== Example calls through Employee* ===" << endl;

    cout << "Staff[0] salary (Employee): " << staff[0]->calculateSalary() << endl;
    cout << "Staff[1] salary (Manager): " << staff[1]->calculateSalary() << endl;
    cout << "Staff[2] salary (Developer): " << staff[2]->calculateSalary() << endl;
    cout << "Staff[3] salary (Intern): " << staff[3]->calculateSalary() << endl;

    // 4) Не забываем освобождать память
    for (int i = 0; i < 4; ++i) {
        delete staff[i];
    }

    return 0;
}