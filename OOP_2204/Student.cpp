#include <string>
#include <iostream>
#include <windows.h>
using namespace std;


    class Student {
        string fullName; // приватные поля
        int group;
        int grades[5];
    public: // начало публичных методов
        Student(string fullName, int group, int grades[5]) { // конструктор
            this->fullName = fullName; // задаем чтобы приватный метод был равен параметру
            this->group = group;
            for (int i = 0; i < 5; ++i) {
                this->grades[i] = grades[i];
            }
        };
        string getName() {
            return this->fullName; // свойство для чтения(не требует ввода имени и просто его возвращает)
        }
        int getGroup() {
            return this->group;
        }
        int GetAverageGrade() { // средняя оценка
            int sum = 0; // переменная для суммы
            for (int i = 0; i < 5; ++i) {
                sum += this->grades[i];
            }
            return sum / 5;
        }
        void DisplayInfo() {
            cout << fullName << " " << group; // вывод инфы
        }
    };

    class BankAccount {
        int accountNumber; // приватные поля
        int balance;
        string OwnerName;
    public:
        BankAccount(int accountNumber, int balance, string OwnerName) { // конструктор
            this->accountNumber = accountNumber; // задаем чтобы приватный метод был равен параметру
            this->balance = balance;
            this->OwnerName = OwnerName;
        }
        int getAccountNumber() { // свойство для чтения
            return this->accountNumber;
        }
        void getNwriteOwnerName(string OwnerName) {
            this->OwnerName = OwnerName; // свойство для записи и чтения
        }
        int getBalance() { // свойство для чтения
            return this->balance;
        }
        int Deposit(int Dep) { // функция для пополнения баланса, пополняемое число должн быть больше нуля
            if (Dep > 0) {
                return balance + Dep;
            }
        }
        int Withdraw(int Num) { // снятия денег, снимаемое число долно быть меньше баланса
            if (Num <= balance) {
                balance - Num;
                return Num;
          }
        }
        void DisplayInfo() { // вывод
            cout << accountNumber << " " << balance << " " << OwnerName;
        }
    };
    class Product {
        string name;
        int price;
        int quantity;
    public:
        string getName() {
            return this->name;
        }
        void setName(string name) {
            this->name = name;
        }
        int getPrice() {
            return this->price;
        }
        void setPrice(int price) {
            this->price = price;
        }
        int getQuantity() {
            return this->quantity;
        }
        void setQuantity(int quantity) {
            this->quantity = quantity;
        }
        Product(string name, int price, int quantity) {
            this->name = name;
            this->price = price;
            this->quantity = quantity;
        }
        int GetTotalValue() {
            return price * quantity;
        }
        bool Sell(int amount) {
            if (amount <= quantity) {
                quantity - amount;
                return true;
            }
            else {
                return false;
            }
        }
    };
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    int grades[5] = { 5, 3, 4, 2, 5 };
    Student student("Safarov Marat", 2, grades); // реализация
    student.DisplayInfo();
    cout << endl;
    
    BankAccount bankAccount(676767, 129, "Walter White"); // реализация
    /*bankAccount.DisplayInfo();*/
    bankAccount.getNwriteOwnerName("Gustavo Fring");
    bankAccount.DisplayInfo();
    cout << endl;

    Product product();
}



