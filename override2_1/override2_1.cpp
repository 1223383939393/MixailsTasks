// main.cpp
#include "Shape.h"
#include <iostream>

using namespace std;

int main() {
    cout << "=== Testing Shape hierarchy ===\n" << endl;

    // 1) Создаём фигуры
    // Важно: указатели на Shape, а хранятся в них Circle/Rectangle/Triangle
    Shape* shapes[] = {
        new Circle(5),        // круг, r = 5
        new Rectangle(3),     // квадрат, a = 3
        new Triangle(4, 5, 6, 3)  // треугольник: a=4, b=5, c=6, h=3 (h к стороне a)
    };

    // 2) Проверяем счётчик фигур
    cout << "Total shapes created (Shape::count): " << Shape::count << endl << endl;

    // 3) Проходим по массиву и вызываем виртуальные методы
    for (int i = 0; i < 3; ++i) {
        cout << "Shape " << i << ":" << endl;

        // Вызов print() через Shape*
        shapes[i]->print();

        // Вызов area() через Shape*
        cout << "Area = " << shapes[i]->area() << endl;

        // Вызов perimeter() через Shape*
        cout << "Perimeter = " << shapes[i]->perimeter() << endl;

        cout << endl;
    }

    // 4) Пример, как в задании: через Shape* и area()
    cout << "=== Example from task ===" << endl;
    cout << "Circle area (shapes[0]->area()): " << shapes[0]->area() << endl;
    // shapes[0] -> Circle(5) -> area = π * 5² ≈ 78.5

    // 5) Не забываем удалить фигуры, чтобы не было утечек
    for (int i = 0; i < 3; ++i) {
        delete shapes[i];
    }

    return 0;
}
