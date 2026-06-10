#include "Player.h"
#include "Enemy.h"
#include <iostream>
using namespace std;

void Player::AttackEnemy(Enemy& enemy) {
    enemy.getHp() -= 13;
}

void Player::displayInfo(Enemy& enemy) {
    cout << "HP: " << hp << endl;
    cout << "Name: " << playerName << endl;
    cout << "u have " << potions.size() << " healing potions" << endl;

    cout << "Opponent info: " << endl
        << "HP: " << enemy.getHp() << endl;
}