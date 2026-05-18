// Подключаем наш базовый класс, чтобы иметь доступ к Shape, Circle, Rectangle, Triangle.
#include "Shape.h"
#include <iostream>
using namespace std;

// Определение статического члена класса Shape: общий счётчик фигур.
// Всё время, пока работает программа, этот счётчик будет общим для всех объектов Shape.
int Shape::count = 0;

// Реализация метода периметра для Circle.
// Вычисляет периметр круга по формуле: P = 2 * π * radius.
double Circle::perimeter() const {
    double P = 2 * (radius * pi);   // 2 * π * radius
    return P;
}

// Реализация метода площади для Circle.
// Вычисляет площадь круга по формуле: S = π * radius².
double Circle::area() const {
    double S = pi * (radius * radius);   // π * r²
    return S;
}

// Реализация метода периметра для Rectangle (квадрата).
// Вычисляет периметр квадрата: P = 4 * сторона.
double Rectangle::perimeter() const {
    double P = 4 * a;   // четыре стороны одной длины a
    return P;
}

// Реализация метода площади для Rectangle (квадрата).
// Вычисляет площадь квадрата: S = сторона * сторона.
double Rectangle::area() const {
    double S = a * a;   // сторона в квадрате
    return S;
}

// Реализация метода периметра для Triangle.
// Вычисляет периметр треугольника: сумма всех трёх сторон.
double Triangle::perimeter() const {
    double P = a + b + c;   // a + b + c
    return P;
}

// Реализация метода площади для Triangle.
// Вычисляет площадь треугольника по формуле: S = 0.5 * основание * высота.
// В данном случае основание — это сторона a, а высота — h.
double Triangle::area() const {
    double S = 0.5 * (a * h);   // 0.5 * a * h
    return S;
}