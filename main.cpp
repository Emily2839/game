//
// Created by Emanuel on 13/03/2024.
#include <iostream>
#include "enemy/enemy.h"
#include "Player/Player.h"
#include "combat/combat.h"
#include <vector>

using namespace std;

int main() {
    cout << "WELCOME. Please write a name for your PLAYER: " << endl;
    string PlayerName;
    cin >> PlayerName;

    cout << "Write a name for the ENEMY:" << endl;
    string EnemyName;
    cin >> EnemyName;

    cout<<"Write an weapon for your PLAYER: "<< endl;
    string PlayerW;
    cin >> PlayerW;

    cout<<"Write an weapon for your ENEMY: "<< endl;
    string EnemyW;
    cin >> EnemyW;


    Player *player;
    player = new Player("Capi", 76, 7, 2, 10, PlayerW, 10, 1);
    Enemy *enemy;
    // Enemy(char *name, int health, int attack, int defense, int speed, string *arm, int experience, int level);
    enemy = new Enemy("Trol", 5, 5, 2, 7, EnemyW, 10, 1);
    Enemy *enemy2;
    enemy2 = new Enemy("Mo", 5, 4, 2, 2, EnemyW, 10,1);

    vector<Character*> participants;
    participants.push_back(player);
    participants.push_back(enemy); // Corregir aquí
    participants.push_back(enemy2); // Corregir aquí

    Combat *combat;
    combat = new Combat(participants);
    combat->doCombat();



    delete player;
    delete enemy;
    delete enemy2;
    //delete combat;


    return 0;
}