//
// Created by Emanuel on 13/03/2024.
#include <iostream>
#include "enemy/enemy.h"
#include "player/player.h"
#include "combat/combat.h"
#include <vector>

using namespace std;

int main() {
    Player *player = new Player("Capi", 100, 7, 2, 10);
    Enemy *enemy = new Enemy("Trol", 20, 5, 2, 7);
    Enemy *enemy2 = new Enemy("Mo", 30, 4, 2, 2);

    vector<Character*> participants;
    participants.push_back(player);
    participants.push_back(enemy); // Corregir aquí
    participants.push_back(enemy2); // Corregir aquí

    Combat* combat = new Combat(participants);
    combat->doCombat();

    delete player;
    delete enemy;
    delete enemy2;
    delete combat;

    return 0;
}
