#include "Enemy.h"
#include "Player.h"

void Enemy::AttackEnemy(Player& player) {
    player.getHp() -= 13;
}
