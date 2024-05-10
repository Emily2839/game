//
// Created by Emanuel on 13/03/2024.
//

#ifndef GAME_C_CHARACTER_H
#define GAME_C_CHARACTER_H
#include <string>
#include "../Combat/Action.h"
#include <vector>
#include <cstring>
#define RED = "\033[31m";
#define RESET = "\033[0m";11
using namespace std;

class Character {
protected:
    char name[30];
    int health;
    int attack;
    int defense;
    int speed;
    bool isPlayer;
    bool fleed;
    char arm[20];
    int experience;
    int level;

public:
    Character(char*, int, int, int, int, bool, char[20], int, int );

    virtual void doAttack(Character *target) = 0;
    virtual void takeDamage(int damage) = 0;

    void setName(char*);
    char* getName();
    void setHealth(int);
    int getHealth();
    void setAttack(int);
    int getAttack();
    void setDefense(int);
    int getDefense();
    void setSpeed(int);
    int getSpeed();
    char toString();
    bool getIsPlayer();
    bool hasFleed();
    void setArm(char[20]);
    char* getArm();
    int getExperience();
    int getLevel();
};


#endif  //GAME_C_CHARACTER_H
