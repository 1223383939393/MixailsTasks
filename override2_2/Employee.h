#pragma once
#include <iostream>
using namespace std;

// Это базовый класс для всех сотрудников компании.
// В нём описаны общие свойства и методы, которые будут у всех:
// Employee, Manager, Developer, Intern.
class Employee
{
protected:
    // Имя сотрудника ("John", "Alice" и т.д.)
    string name;

    // Идентификатор сотрудника (уникальный номер)
    int id;

    // Базовая зарплата — та сумма, которую сотрудник получает "по умолчанию"
    int baseSalary;

public:
    // Конструктор: создаёт сотрудника с именем, ID и базовой зарплатой.
    Employee(string name, int id, int baseSalary)
        : name{ name }, id{ id }, baseSalary{ baseSalary } {
    }

    // Виртуальный метод для вычисления зарплаты.
    // Для обычного сотрудника она равна базовой (без доплат).
    virtual int calculateSalary() const {
        return baseSalary;
    }

    // Виртуальный метод для вывода информации о сотруднике.
    // Выводит имя, ID и базовую зарплату.
    virtual void getInfo() const {
        cout << "Name: " << name << " ID: " << id << " Salary: " << baseSalary;
    }
};

// Менеджер — это тоже сотрудник, но с доплатами за подчинённых.
class Manager : public Employee
{
private:
    // Размер бонуса (например, сколько денег дают за одного подчинённого)
    int bonus;

    // Количество подчинённых людей, за которыми менеджер отвечает
    int countEmployee;

public:
    // Конструктор менеджера: создаёт его как обычного сотрудника (через Employee),
    // но дополнительно задаёт бонус и количество подчинённых.
    Manager(string name, int id, int baseSalary, int bonus, int countEmployee)
        : Employee(name, id, baseSalary), bonus{ bonus }, countEmployee{ countEmployee } {
    }

    // Переопределённый метод вычисления зарплаты для менеджера.
    // Формула: базовая зарплата + бонус * 100 * количество подчинённых.
    int calculateSalary() const override {
        return baseSalary + bonus * 100 * countEmployee;
    }

    // Переопределённый метод вывода информации.
    // Выводит имя, ID, базовую зарплату и сколько подчинённых у менеджера.
    void getInfo() const override {
        cout << "Name: " << name << " ID: " << id
            << " Salary: " << baseSalary
            << " How many employees? " << countEmployee << endl;
    }
};

// Разработчик — тоже сотрудник, но с доплатой за опыт.
class Developer : public Employee
{
private:
    // Язык программирования, на котором работает разработчик ("C++", "Java" и т.п.)
    string progLang;

    // Опыт работы в годах
    int exp;

public:
    // Конструктор разработчика: создаёт его как обычного сотрудника (через Employee),
    // но дополнительно задаёт язык программирования и опыт.
    Developer(string name, int id, int baseSalary, string proglang, int exp)
        : Employee(name, id, baseSalary), progLang{ proglang }, exp{ exp } {
    }

    // Переопределённый метод вычисления зарплаты для разработчика.
    // Формула: базовая зарплата + опыт * 5000
    int calculateSalary() const override {
        return baseSalary + exp * 5000;
    }

    // Переопределённый метод вывода информации.
    // Выводит имя, ID, базовую зарплату, язык программирования и опыт.
    void getInfo() const override {
        cout << "Name: " << name << " ID: " << id
            << " Salary: " << baseSalary
            << " What is your programming language? " << progLang
            << " How many years do you work here? " << exp << endl;
    }
};

// Стажёр — это сотрудник с пониженной зарплатой (70% от базовой).
class Intern : public Employee
{
private:
    // Признак: есть ли у стажёра наставник (true / false)
    bool haveCoach;

public:
    // Конструктор стажёра: создаёт его как обычного сотрудника (через Employee),
    // но дополнительно задаёт наличие наставника.
    Intern(string name, int id, int baseSalary, bool haveCoach)
        : Employee(name, id, baseSalary), haveCoach{ haveCoach } {
    }

    // Переопределённый метод вычисления зарплаты для стажёра.
    // Формула: 70% от базовой зарплаты (baseSalary * 0.70)
    int calculateSalary() const override {
        return baseSalary * 0.70;
    }

    // Переопределённый метод вывода информации.
    // Выводит имя, ID, базовую зарплату и есть ли у стажёра наставник.
    void getInfo() const override {
        cout << "Name: " << name << " ID: " << id
            << " Salary: " << baseSalary
            << " Do you have a coach? " << haveCoach << endl;
    }
};