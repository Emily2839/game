//
// Created by Emanuel on 13/03/2024.
//

#ifndef GAME_C_CHARACTER_H
#define GAME_C_CHARACTER_H
#include <string>
#include "../Combat/Action.h"
#define RED = "\033[31m";
#define RESET = "\033[0m";11
using namespace std;

class Character {
protected:
    string name;
    int health;
    int attack;
    int defense;
    int speed;
    bool isPlayer;
    bool fleed;

public:
    Character(string, int, int, int, int, bool);

    virtual void doAttack(Character *target) = 0;
    virtual void takeDamage(int damage) = 0;

    void setName(string);
    string getName();
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
};


#endif  //GAME_C_CHARACTER_H
