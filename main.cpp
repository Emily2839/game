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
    char PlayerName[30];
    cin.getline(PlayerName, 30);

    cout << "Write a name for the ENEMY:" << endl;
    char EnemyName[30];
    cin.getline(EnemyName, 30);

    cout<<"Write an arm for your PLAYER: "<< endl;
    char PlayerArm [30];
    cin.getline(PlayerArm, 30);

    cout<<"Write an arm for your ENEMY: "<< endl;
    char EnemyArm[30];
    cin.getline(EnemyArm, 30);



    Player *player;
    player = new Player("Capi", 76, 7, 2, 10, EnemyArm, 10,1);
    Enemy *enemy;
    enemy = new Enemy("Trol", 20, 5, 2, 7, PlayerArm, 10, 1);
    Enemy *enemy2;
    enemy2 = new Enemy("Mo", 30, 4, 2, 2, PlayerArm, 10,1);

    vector<Character*> participants;
    participants.push_back(player);
    participants.push_back(enemy); // Corregir aquí
    participants.push_back(enemy2); // Corregir aquí

    Combat *combat;
    combat = new Combat(participants);
    combat->doCombat();

    char* buffer = player->serialize();


    delete player;
    delete enemy;
    delete enemy2;
    delete combat;


    return 0;
}
