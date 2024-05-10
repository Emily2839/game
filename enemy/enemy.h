//
// Created by Victor Navarro on 13/02/24.
//

#ifndef RPG_ENEMY_H
#define RPG_ENEMY_H
#include "../character/character.h"
#include "../Player/Player.h"
#include "../Combat/Action.h"

struct Action;
class Player;

class Enemy: public Character {
public:
    int MaxHealth;

private:
    Enemy(char *name, int health, int attack, int defense, int speed, char *arm, int experience, int level);

public:
    Enemy(char [30], int, int, int, int, char[20], int, int );

    void doAttack(Character *target) override;
    void takeDamage(int damage) override;
    Character* getTarget(vector<Player*> teamMembers);
    Action takeAction(vector<Player*> player);

};


#endif //RPG_ENEMY_H
