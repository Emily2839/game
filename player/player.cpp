//
// Created by Emanuel on 13/03/2024.
//
#include "Player.h"
#include <iostream>
#include <algorithm>
#include "../Utils.h"

using namespace std;
using namespace combat_utils;

bool compareSpeed(Enemy *a, Enemy *b) {
    return a->getSpeed() > b->getSpeed();
}

Player::Player(char _name[30], int health, int attack, int defense, int speed, string arm,int experience, int level) : Character(name, health, attack, defense, speed, true) {

}

void Player::doAttack(Character *target) {
    int rolledAttack = getRolledAttack(getAttack());
    int trueDamage = target->getDefense() > rolledAttack ? 0 : rolledAttack - target->getDefense();
    target->takeDamage(trueDamage);
}

void Player::takeDamage(int damage) {
    setHealth(health - damage);
    cout << "You have taken " << damage << " damage" << endl;
    if (health <= 0) {
        cout << "You have died" << endl;
    }
}

void Player::flee(vector<Enemy *> enemies) {
    std::sort(enemies.begin(), enemies.end(), compareSpeed);
    Enemy *fastestEnemy = enemies[0];
    bool fleed;
    fleed = false;
    if (this->getSpeed() > fastestEnemy->getSpeed()) {
        fleed = true;
    } else {
        srand(time(NULL));
        int chance;
        chance = rand() % 100;
        cout << "chance: " << chance << endl;
        fleed = chance > 90;{
            fleed = true;
            cout << "You can't be fleed, fight" << endl;
        }
    }

    this->fleed = fleed;
}

void Player::emote() {
    cout << "Jokes on you" << endl;
}

Character* Player::getTarget(vector<Enemy *> enemies) {
    cout << "Choose a target" << endl;
    int targetIndex = 0;
    for(int i = 0; i < enemies.size(); i++) {
        cout << i << ". " << enemies[i]->getName() << endl;
    }
    cin >> targetIndex;

    return enemies[targetIndex];
}


void Player::gainExperience(Enemy* enemy) {
    // Sber si el enemigo murio para tomar su experiencia
    if (enemy && enemy->getHealth() <= 0) {
        // Sumar la experiencia obtenida por derrotar al enemigo
        experience += enemy->getExperience();
        // Llamar a la función LevelUp para manejar el nivel y la experiencia restante
        levelUp();
    }
}

void Player::levelUp() {
    // Saber si el jugador tiene 100 o mas de experiencia para aumentar el Level
    while (experience >= 100) {
        level++;
        // Reiniciar
        experience -= 100;

// Atributos aumentados
        setHealth(getHealth() + 10);
        setAttack(getAttack() + 5);
        setDefense(getDefense() + 5);
        setSpeed(getSpeed() + 5);
//        // Puntos ganados TOTAL
//        int totalPointsGained = healthGain + attackGain + defenseGain;
    }

}

Action Player::takeAction(vector<Enemy *> enemies) {
    int option = 0;
    cout << "Choose an action" << endl;
    cout << "1. Attack" << endl;
    cout << "2. Flee" << endl;
    cin >> option;
    Character *target = nullptr;


    Action myAction;

    myAction.speed = this->getSpeed();
    myAction.subscriber = this;

    switch (option) {
        case 1:
            target = getTarget(enemies);
            myAction.target = target;
            //1.
            myAction.action = [this, target]() {
                doAttack(target);

            };
            break;
        case 2:
            myAction.action = [this, enemies]() {
                flee(enemies);
            };
            break;
        default:
            cout << "Invalid option" << endl;
            break;
    }

    return myAction;
}





