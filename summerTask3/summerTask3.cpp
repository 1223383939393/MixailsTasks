#include "Pet.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Создаём животных с именами и характеристиками
    Dog dog("Buddy", "German Shepherd");
    Cat cat("Whiskers", "Persian");
    Parrot parrot("Kesha", "Cockatiel");
    Hamster hamster("Hamy", "Syrian");

    // Демонстрация работы методов
    cout << "=== DOG ===" << endl;
    dog.Show();
    dog.Type();
    dog.Sound();
    cout << endl;

    cout << "=== CAT ===" << endl;
    cat.Show();
    cat.Type();
    cat.Sound();
    cout << endl;

    cout << "=== PARROT ===" << endl;
    parrot.Show();
    parrot.Type();
    parrot.Sound();
    cout << endl;

    cout << "=== HAMSTER ===" << endl;
    hamster.Show();
    hamster.Type();
    hamster.Sound();
    cout << endl;

    return 0;
}