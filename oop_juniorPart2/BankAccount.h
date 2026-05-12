#pragma once  // Защищает от повторного включения заголовка

#include <iostream>  // Для вывода в консоль (cout)
#include <cstring>   // Для работы со строками (strlen, strcpy_s)

class BankAccount {  // Класс моделирует банковский счёт
private:  // Приватные поля — доступны только внутри класса
    char* Owner;        // Указатель на имя владельца (динамическая память)
    int AccountNumber;  // Номер банковского счёта
    double Balance;     // Текущий баланс в рублях

public:  // Публичные методы — доступны извне
    BankAccount(const char* owner, int accountNumber, double balance);  // Конструктор — создаёт счёт
    void deposit(double amount);     // Пополнение счёта
    bool withdraw(double amount);    // Снятие денег (возвращает true/false)
    double getBalance();             // Получить текущий баланс
    void printInfo();                // Вывести информацию о счёте
    ~BankAccount();                  // Деструктор — освобождает память
};