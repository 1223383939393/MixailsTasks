#include <iostream>
#include "Client.h"
#include "Autopark.h"
#include <vector>
using namespace std;

int main()
{
    bool exit = false;
    cout << "Hello, our dear client! You came to our car dealership to buy best vehicle?" << endl;
    cout << "Please say your name ";
    string g;
    cin >> g;
    Client c(g);
    int q;
    while (exit == 0) { // чтобы бесконечно выбирать
        cout << "Which vehicle do u wanna buy?" << endl;
        cout << "1 - Car" << endl << "2 - cabriolet" << endl << "3 - Truck" << endl << "4 - See your cars" << endl;
        cin >> q;
        switch (q) {
        case 1: {
            Car* r = new Car("BMW", 1000); // создаем указатель на класс, и передаем его, оно работает
            c.buyCar(r);
            break;
        }
        case 2: {
            Cabriolet* cab = new Cabriolet("Audi", 2000);
            c.buyCar(cab);
            break;
        }
        case 3: {
            Truck* t = new Truck("Kamaz", 500);
            c.buyCar(t);
            break;
        }
        case 4: {
            c.getClientCars();
            break;
        }
        default: {
            cout << "We dont have that type of car! Sowwy ;(" << endl;
            exit = true; // выход из программы
            break;
        }
        }
    }

}


