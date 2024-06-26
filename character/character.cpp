//
// Created by Emanuel on 13/03/2024.
//
#include "character.h"
#include <cstring>
#include <sstream>
#include <iostream>

Character::Character(char _name[40], int _health, int _attack, int _defense, int _speed, bool _isPlayer) {
    if (_name != nullptr) strcpy(name, _name);
    health = _health;
    maxHealth = health;
    attack = _attack;
    defense = _defense;
    speed = _speed;
    isPlayer = _isPlayer;
    fleed = false;
}

void Character::setName(char* _name) {
    strcpy(name, _name);
}

char* Character::getName() {
    return name;
}

string Character::getStringName() {
    return name;
}

void Character::setHealth(int _health) {
    health = _health;
}

int Character::getHealth() {
    return health;
}

void Character::setAttack(int _attack) {
    attack = _attack;
}

int Character::getAttack() {
    return attack;
}

void Character::setDefense(int _defense) {
    defense = _defense;
}

int Character::getDefense() {
    return defense;
}

void Character::setSpeed(int _speed) {
    speed = _speed;
}

int Character::getSpeed() {
    return speed;
}

string Character::toString() {
    return "Name: " + this->getStringName() + "\nHealth: " + to_string(health) + "\nAttack: " + to_string(attack) + "\nDefense: " + to_string(defense) + "\nSpeed: " + to_string(speed);
}

bool Character::getIsPlayer() {
    return isPlayer;
}

bool Character::hasFleed() {
    return fleed;
}

int Character::getExperience() {
    return experience;
}

int Character::getLevel() {
    return level;
}

void Character::setArm(string _arm) {
    arm = _arm;
}

string Character::getArm() {
    return arm;
}

