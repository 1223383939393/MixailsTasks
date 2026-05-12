#include "BankAccount.h"  // Подключаем объявления класса
using namespace std;

// Конструктор — вызывается при создании объекта BankAccount
BankAccount::BankAccount(const char* owner, int accountNumber, double balance) {
    AccountNumber = accountNumber;  // Сохраняем номер счёта

    // Вычисляем размер для имени + 1 байт для завершающего нуля '\0'
    size_t namelen = strlen(owner) + 1;
    Owner = new char[namelen];      // Выделяем динамическую память под имя
    strcpy_s(Owner, namelen, owner); // Безопасно копируем имя в выделенную память

    // Проверяем начальный баланс
    if (balance < 0) {
        cout << "Balance is below zero" << endl;  // Предупреждение
        Balance = 0;  // Устанавливаем нулевой баланс
    }
    else {
        Balance = balance;  // Используем переданный баланс
    }
}

// Деструктор — автоматически вызывается при уничтожении объекта
BankAccount::~BankAccount() {
    delete[] Owner;  // Освобождаем динамическую память под имя
}

// Пополнение счёта
void BankAccount::deposit(double amount) {
    if (amount >= 0) {  // Сумма должна быть неотрицательной
        double res = Balance += amount;  // Добавляем к балансу и сохраняем результат
        cout << "Operation Deposit is success!" << endl;
        cout << "Your Balance right now is " << res;  // Выводим новый баланс
    }
    else {
        cout << "You are a mistake!" << endl;  // Ошибка — отрицательная сумма
    }
}

// Снятие денег
bool BankAccount::withdraw(double amount) {
    if (!(amount > Balance) && amount > 0) {  // Сумма положительная И не превышает баланс
        double res = Balance - amount;        // Вычисляем остаток
        Balance = res;                        // Обновляем баланс
        cout << "Operation Withdraw is success!" << endl;
        cout << "Your Balance right now is " << res << endl;
        return true;  // Успех
    }
    else {
        cout << "You are a mistake!" << endl;  // Ошибка — недостаточно средств
        return false;  // Неудача
    }
}

// Возвращает текущий баланс
double BankAccount::getBalance() {
    return Balance;
}

// Выводит полную информацию о счёте
void BankAccount::printInfo() {
    cout << "Welcome to our OmniBank! Trust Us!" << endl;
    cout << "Owner: " << Owner << endl;
    cout << "AccountNumber: " << AccountNumber << endl;
    cout << "Balance: " << Balance << "rubles" << endl;
}