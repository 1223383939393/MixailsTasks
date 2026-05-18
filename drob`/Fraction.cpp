#include "Fraction.h"

// Внутренняя функция, которая ищет НОД (наибольший общий делитель) двух чисел a и b
// Простым перебором: смотрим все числа от 1 до наибольшего из a и b,
// и запоминаем наибольший делитель, который делит оба числа нацело
int Fraction::NOD(int a, int b) {
    int nod;
    if (a > b) {
        for (int i = 1; i <= a; i++) {
            if (a % i == 0 && b % i == 0) {
                nod = i;
            }
        }
        return nod;
    }
    else if (a < b) {
        for (int i = 1; i <= b; i++) {
            if (a % i == 0 && b % i == 0) {
                nod = i;
            }
        }
        return nod;
    }
}

// Реализация оператора +: дробь + дробь
// Формула: a/b + c/d = (a*d + c*b) / (b*d)
// После этого дробь сокращаем с помощью NOD
Fraction Fraction::operator +(const Fraction& ot) {
    int chisl = a * ot.b + ot.a * b; // новый числитель
    int znam = b * ot.b;             // новый знаменатель
    int res = NOD(chisl, znam);      // НОД для сокращения
    return Fraction(chisl / res, znam / res); // возвращаем новую сокращённую дробь
}

// Реализация оператора -: дробь - дробь
// Формула: a/b - c/d = (a*d - c*b) / (b*d)
// Сокращаем результат с помощью NOD
Fraction Fraction::operator -(const Fraction& ot) {
    int chisl = a * ot.b - ot.a * b; // новый числитель
    int znam = b * ot.b;             // новый знаменатель
    int res = NOD(chisl, znam);      // НОД для сокращения
    return Fraction(chisl / res, znam / res); // возвращаем новую сокращённую дробь
}

// Реализация оператора *: дробь * дробь
// Формула: (a/b) * (c/d) = (a*c) / (b*d)
// Сокращаем результат с помощью NOD
Fraction Fraction::operator *(const Fraction& ot) {
    int chisl = this->a * ot.a;      // новый числитель: a * ot.a
    int znam = this->b * ot.b;       // новый знаменатель: b * ot.b
    int res = NOD(chisl, znam);      // НОД для сокращения
    return Fraction(chisl / res, znam / res); // возвращаем новую сокращённую дробь
}

// Реализация метода Plus: считает "n + дробь ot"
// Формула: n + a/b = (n*b + a) / b
// То есть число n превращается в дробь (n*b)/b и складывается с ot = a/b
Fraction Fraction::Plus(int n, const Fraction& ot) {
    int chisl = n * ot.b + ot.a;     // числитель: n*b + a
    int znam = n * ot.b;             // !!! здесь логика немного странная: знаменатель n*b, а не просто b
    int res = NOD(chisl, znam);      // НОД для сокращения
    return Fraction(chisl / res, znam / res); // возвращаем новую сокращённую дробь
}

// Реализация метода Minus: считает "n - дробь ot"
// Формула: n - a/b = (n*b - a) / b
Fraction Fraction::Minus(int n, const Fraction& ot) {
    int chisl = n * ot.b - ot.a;     // числитель: n*b - a
    int znam = n * ot.b;             // !!! та же самая проблема: знаменатель n*b, а не ot.b
    int res = NOD(chisl, znam);      // НОД для сокращения
    return Fraction(chisl / res, znam / res); // возвращаем новую сокращённую дробь
}

// Реализация метода Multi: считает "n * дробь ot"
// Формула: n * (a/b) = (n*a) / (n*b)
// После сокращения это будет эквивалентно a/b, если n ≠ 0
Fraction Fraction::Multi(int n, const Fraction& ot) {
    int chisl = n * ot.a;            // числитель: n * a
    int znam = n * ot.b;             // знаменатель: n * b
    int res = NOD(chisl, znam);      // НОД для сокращения
    return Fraction(chisl / res, znam / res); // возвращаем новую сокращённую дробь
}