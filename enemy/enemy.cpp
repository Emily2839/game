//
// Created by Emanuel on 13/03/2024.
//
#include "../enemy/enemy.h"
#include "../character/character.h"
#include <iostream>
#include "../player/player.h"

using namespace std;


//TODO: Check the circular dependency
int getRolledAttack(int attack) {
    int lowerLimit = attack * .80;
    return (rand() % (attack - lowerLimit)) + lowerLimit;
}
//Constructor de enemy
Enemy::Enemy(char name[30], int health, int attack, int defense, int speed, string _arm, int _experience, int _level) : Character(name, health, attack, defense, speed, false){
    maxHealth = health;
    arm = _arm;
    experience = _experience;
    level = _level;
}

void Enemy::doAttack(Character *target) {

    int rolledAttack = getRolledAttack(getAttack());
    int trueDamage = target->getDefense() > rolledAttack ? 0 : rolledAttack - target->getDefense();
    if (target->getHealth() > 0){
        target->takeDamage(trueDamage);
    }
}

void Enemy::takeDamage(int damage) {
    setHealth(getHealth() - damage);
    if(getHealth() <= 0) {
        cout<<getName()<<" Se fue con el gallo de oro..."<<endl;
    }
    else {
        cout<<getName()<<" Ha perdido " << damage << " Loser" << endl;
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
    if (this->getHealth() < maxHealth * 0.2){       //Si el enemigo tiene menos de 20% de la vida maxima escapa
        myAction.action = [this, target]() {
            cout << "El enemigo "<< this->getStringName() <<" escapo" << endl;
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

