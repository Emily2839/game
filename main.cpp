//
// Created by Emanuel on 13/03/2024.
#include <iostream>
#include "enemy/enemy.h"
#include "Player/Player.h"
#include "combat/combat.h"
#include <vector>

using namespace std;

int main() {
    cout << "Welcome enter a name for your player " << endl;
    string PlayerName = "lol";
    cin >> PlayerName;

//    cout << "Write a name for the ENEMY:" << endl;
    string EnemyName = "No sirve lol"; //NO IMPLEMENTAR
//    cin >> EnemyName;

//    cout<<"Write an weapon for your PLAYER: "<< endl;
    string PlayerW = "lol";
//    cin >> PlayerW;

//    cout<<"Write an weapon for your ENEMY: "<< endl;
    string EnemyW = "lol";
//    cin >> EnemyW;


    Player *player;
    player = new Player(PlayerName, 50, 10, 2, 10, PlayerW, 10, 1);
    Enemy *enemy;
    // Enemy(char *name, int health, int attack, int defense, int speed, string *arm, int experience, int level);
    enemy = new Enemy("Trol", 10, 5, 2, 7, EnemyW, 10, 1);
    Enemy *enemy2;
    enemy2 = new Enemy("Mo", 10, 5, 2, 5, EnemyW, 10,1);

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
    delete combat;


    return 0;
}