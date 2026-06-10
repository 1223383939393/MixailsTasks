#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Items.h"
using namespace std;

class Player; // forward declaration

class Enemy {
    vector<string> potions;
    Items i;
    string playerName;
    int hp = 100;
    string potion = "Healing potion";
    string weapon = "Sword";
    string armor = "Iron armor";
public:
    Enemy(string playerName, int hp) : playerName{ playerName }, hp{ hp } {}
    Enemy(string playerName) : Enemy(playerName, 100) {}
    Enemy(int hp) : Enemy("", hp) {}
    Enemy() : Enemy("", 100) {}

    int& getHp() {
        return hp;
    }

    void AttackEnemy(Player& player);

    void HealPlayer() {
        if (hp < 100 && 100 - hp >= 50) {
            if (!potions.empty()) {
                hp += 50;
                potions.pop_back();
            }
        }
        else if (100 - hp < 50) {
            if (!potions.empty()) {
                hp += 100 - hp;
                potions.pop_back();
            }
        }
    }

    void AddPotion(string potion) {
        potions.push_back(potion);
    }

    void displayInfo() {
        cout << "HP: " << hp << endl;
        cout << "Name: " << playerName << endl;
    }
};