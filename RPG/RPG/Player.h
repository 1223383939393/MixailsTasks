#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Items.h"
using namespace std;

class Enemy; // вперёд объявляем, без include

class Player
{
    vector<string> potions;
    Items i;
    string playerName;
    int hp = 100;
    string weapon = "Sword";
    string armor = "Iron armor";
public:
    Player(string playerName, int hp) : playerName{ playerName }, hp{ hp } {}
    Player(string playerName) : Player(playerName, 100) {}
    Player(int hp) : Player("", hp) {}
    Player() : Player("", 100) {}

    int& getHp() {
        return hp;
    }

    // атакуем врага, которого нам передали
    void AttackEnemy(Enemy& enemy);

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

    void displayInfo(Enemy& enemy);

    void AddPotion(string potion) {
        potions.push_back(potion);
    }
};  