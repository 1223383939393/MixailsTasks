#include <iostream>
#include "Enemy.h"
#include "Items.h"
#include "Player.h"
using namespace std;

int main()
{
    int c;
    Player p;
    Enemy e;
    bool f = 1;
    bool exit = false;
    cout << "Welcome to RPG ..." << endl;
    while (!exit) {
        cout << "Choose an option: " << endl;
        cout << "1 - Attack enemy" << endl
            << "2 - drink pivo(potion)" << endl
            << "3 - put potion inside your inventory" << endl;
        cin >> c;
        if (f == 1) {
            switch (c) {
            case 1: {
                p.AttackEnemy(e);
                p.displayInfo(e);
                f = 0;
                break;
            }
            case 2: {
                p.HealPlayer();
                p.displayInfo(e);
                f = 0;
                break;
            }
            case 3: {
                string qw = "Healing potion";
                p.AddPotion(qw);
                p.displayInfo(e);
                f = 0;
                break;
            }
            default:
                break;
            }
        }
        else if (f == 0) {
            int chance = rand() % 10;

            switch (chance) {
            case 0: case 1: case 2: case 3: case 4: case 5: {
                e.AttackEnemy(p);
                p.displayInfo(e);
                f = 1;
                break;
            }
            case 6: case 7: {
                e.HealPlayer();
                p.displayInfo(e);
                f = 1;
                break;
            }
            case 8: case 9: {
                string qw = "Healing potion";
                e.AddPotion(qw);
                p.displayInfo(e);
                f = 1;
                break;
            }
            }
        }
        if (e.getHp() <= 0) {
            cout << "You won! Congrats!!!" << endl;
            exit = true;
        }
        else if (p.getHp() <= 0) {
            cout << "You lost!! Keep trying!" << endl;
            exit = true;
        }
    }
}