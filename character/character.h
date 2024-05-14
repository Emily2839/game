//
// Created by Emanuel on 13/03/2024.
//

#ifndef GAME_C_CHARACTER_H
#define GAME_C_CHARACTER_H
#include <string>
#include "../Combat/Action.h"
#include <vector>
#include <cstring>
#define RED  "\033[31m"
#define RESET  "\033[0m"
using namespace std;

class Character {
protected:
    char name[30] = {'D','e','v','o','i','d'};
    int health;
    int maxHealth;
    int attack;
    int defense;
    int speed;
    bool isPlayer;
    bool fleed;
    int experience = 10;
    int level = 1;
    string arm = "nothing";


public:
    Character(char[40], int, int, int, int, bool ); //como se declaran? como se heredan?

    virtual void doAttack(Character *target) = 0;
    virtual void takeDamage(int damage) = 0;

    void setName(char*);
    char* getName();
    string getStringName();
    void setHealth(int);
    int getHealth();
    void setAttack(int);
    int getAttack();
    void setDefense(int);
    int getDefense();
    void setSpeed(int);
    int getSpeed();
    string toString();
    bool getIsPlayer();
    bool hasFleed();
    int getLevel();
    int getExperience();

    void setArm(string);
    string getArm();
};


#endif  //GAME_C_CHARACTER_H
