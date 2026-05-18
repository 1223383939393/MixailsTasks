#pragma once
#include <iostream>
using namespace std;

// Это класс "Fraction" — дробь вида a / b
class Fraction
{
private:
    int a; // числитель дроби (верхнее число)
    int b; // знаменатель дроби (нижнее число)

    // Внутренняя вспомогательная функция, которая считает НОД ("наибольший общий делитель")
    // Нужно, чтобы дроби сокращались: 2/4 → 1/2
    int NOD(int a, int b);

public:
    // Основной конструктор: создаёт дробь из числителя и знаменателя
    // Если ничего не задали, по умолчанию будет 0/1
    Fraction(int chisl, int znam = 1) : a{ chisl }, b{ znam } {
        NOD(a, b);
    }

    // Пустой конструктор — делает дробь 0/1
    // Но компилятор ругается, что у нас уже есть конструктор по умолчанию выше
    Fraction() : Fraction(0, 1) {}

    // Метод Info выводит текущую дробь на экран в виде: "Your fraction is a / b"
    void Info() {
        cout << "Your fraction is " << a << " / " << b << endl;
    }

    // Перегрузка оператора +: складывает две дроби и возвращает новую (сокращённую)
    Fraction operator +(const Fraction& ot);

    // Перегрузка оператора -: вычитает дробь "ot" из текущей дроби и возвращает новую (сокращённую)
    Fraction operator -(const Fraction& ot);

    // Перегрузка оператора *: умножает текущую дробь на дробь "ot" и возвращает новую (сокращённую)
    Fraction operator *(const Fraction& ot);

    // Метод Plus: считает выражение "n + дробь ot"
    // То есть целое число n + дробь ot → новая дробь
    Fraction Plus(int n, const Fraction& ot);

    // Метод Minus: считает выражение "n - дробь ot"
    // То есть целое число n - дробь ot → новая дробь
    Fraction Minus(int n, const Fraction& ot);

    // Метод Multi: считает выражение "n * дробь ot"
    // То есть целое число n умножить на дробь ot → новая дробь
    Fraction Multi(int n, const Fraction& ot);
};

