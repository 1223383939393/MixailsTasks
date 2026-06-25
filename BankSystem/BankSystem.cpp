#include <iostream>
#include <fstream>
#include "Card.h"
#include "CreditCard.h"
#include "DebitCard.h"
#include "Wallet.h"
using namespace std;

int main()
{
    CreditCard c;
    DebitCard d;
    Wallet w;
    int e;
    while (true) {
        cout << "Welcome to our Bank System!" << endl;
        cout << "What do u wanna do?" << endl;
        cout << "1 - top up debit card, 2 spend money debit card, 3 - top up credit card, 4 spend money credit card 5 - top up wallet, 6 - spend money wallet" << endl;
        cin >> e;
        switch (e) {
        case 1: {
            int y, m, a, p;
            cout << "Write a day " << endl;
            cin >> a;
            cout << "Write a month(number) " << endl;
            cin >> m;
            cout << "Write a year " << endl;
            cin >> p;
            cout << "Write a summ " << endl;
            cin >> y;
            d.topUp(y);
            break;
        }
        case 2: {
            int y, m, a, p;
            cout << "Write a day " << endl;
            cin >> a;
            cout << "Write a month(number) " << endl;
            cin >> m;
            cout << "Write a year " << endl;
            cin >> p;
            cout << "Write a summ " << endl;
            cin >> y;
            d.spend(y);
            break;
        }
        case 3: {
            int y, m, a, p;
            cout << "Write a day " << endl;
            cin >> a;
            cout << "Write a month(number) " << endl;
            cin >> m;
            cout << "Write a year " << endl;
            cin >> p;
            cout << "Write a summ " << endl;
            cin >> y;
            c.topUp(y);
            break;
        }
        case 4: {
            int y, m, a, p;
            cout << "Write a day " << endl;
            cin >> a;
            cout << "Write a month(number) " << endl;
            cin >> m;
            cout << "Write a year " << endl;
            cin >> p;
            cout << "Write a summ " << endl;
            cin >> y;
            c.spend(y);
            break;
        }
        case 5: {
            int y, m, a, p;
            cout << "Write a day " << endl;
            cin >> a;
            cout << "Write a month(number) " << endl;
            cin >> m;
            cout << "Write a year " << endl;
            cin >> p;
            cout << "Write a summ " << endl;
            cin >> y;
            w.topUp(y);
            break;
        }
        case 6: {
            int y, m, a, p;
            cout << "Write a day " << endl;
            cin >> a;
            cout << "Write a month(number) " << endl;
            cin >> m;
            cout << "Write a year " << endl;
            cin >> p;
            cout << "Write a summ " << endl;
            cin >> y;
            w.spend(y);
            break;
        }
        default: {
            break;
        }
            
        }

    }
    
    
}
