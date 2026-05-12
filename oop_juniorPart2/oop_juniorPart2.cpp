#include "BankAccount.h"  // Подключаем класс BankAccount
#include <iostream>       // Для cout
using namespace std;      // Используем стандартное пространство имён

int main() {
    // Создаём первый счёт с положительным балансом
    BankAccount acc1("Marat Safarov", 123456, 1000.50);
    acc1.printInfo();  // Выводим начальную информацию

    cout << endl << "=== Testing deposit ===" << endl;
    acc1.deposit(500.75);  // Тестируем пополнение
    acc1.printInfo();

    cout << endl << "=== Testing withdraw ===" << endl;
    bool success = acc1.withdraw(300.0);  // Тестируем снятие в пределах баланса
    cout << "Withdraw: " << (success ? "Success" : "Failed") << endl;
    acc1.printInfo();

    cout << endl << "=== Attempt to withdraw more than balance ===" << endl;
    success = acc1.withdraw(2000.0);  // Тест: снятие больше баланса
    cout << "Withdraw: " << (success ? "Success" : "Failed") << endl;
    acc1.printInfo();

    cout << endl << "=== Checking getBalance() ===" << endl;
    cout << "Balance: " << acc1.getBalance() << " rub." << endl;  // Проверяем геттер

    cout << endl << "=== Test negative deposit ===" << endl;
    acc1.deposit(-100.0);  // Тест отрицательного пополнения

    // Тестируем конструктор с отрицательным балансом
    cout << endl << "=== Account with negative balance ===" << endl;
    BankAccount acc2("Ivan Ivanov", 789012, -500.0);
    acc2.printInfo();  // Баланс должен стать 0

    // Память освободится автоматически при вызове деструкторов
    // при выходе из main()

    cout << endl << "All tests completed!" << endl;
    return 0;  // Завершение программы
}