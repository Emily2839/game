//
// Created by Emanuel on 13/03/2024.
//
#include "../enemy/enemy.h"
#include "../character/character.h"
#include <iostream>
#include "..//player/player.h"
#include "Enemy.h"

using namespace std;


//TODO: Check the circular dependency
int getRolledAttack(int attack) {
    int lowerLimit = attack * .80;
    return (rand() % (attack - lowerLimit)) + lowerLimit;
}
//Constructor de enemy
Enemy::Enemy(char* name, int health, int attack, int defense, int speed , char arm[20], int experience, int level) : Character(name, health, attack, defense, speed, false){

}

void Enemy::doAttack(Character *target) {

    int rolledAttack = getRolledAttack(getAttack());
    int trueDamage = target->getDefense() > rolledAttack ? 0 : rolledAttack - target->getDefense();
    target->takeDamage(trueDamage);
}

void Enemy::takeDamage(int damage) {
    setHealth(getHealth() - damage);
    if(getHealth() <= 0) {
        cout<<getName()<<" has died"<<endl;

    }
    else {
        cout<<getName()<<" has taken " << damage << " damage" << endl;
    }
}

Character* Enemy::getTarget(vector<Player *> teamMembers) {

    // Obtiene el miembro del equipo con menos vida
    int targetIndex = 0;
    int lowestHealth = INT_MAX;
    for(int i=0; i < teamMembers.size(); i++) {
        if(teamMembers[i]->getHealth() < lowestHealth) {
            lowestHealth = teamMembers[i]->getHealth();
            targetIndex = i;
        }
    }

    return teamMembers[targetIndex];
}

Action Enemy::takeAction(vector<Player *> player) {
    Action myAction;
    myAction.speed = getSpeed();
    myAction.subscriber = this;

    Character* target = getTarget(std::move(player));
    if (this->getHealth()< 9){
        myAction.action = [this, target]() {
            cout << "El enemigo escapo" << endl;
            this->fleed = true;
        };
    } else {
        myAction.target = target;
        myAction.action = [this, target]() {
            doAttack(target);
        };
    }

    return myAction;


}

