#ifndef RPG_ENEMY_H
#define RPG_ENEMY_H

#include "../character/character.h"
#include "../Player/Player.h"
#include "../Combat/Action.h"

struct Action;
class Player;

class Enemy: public Character {
private:
    int maxHealth;

public:
    Enemy(char name[30], int health, int attack, int defense, int speed, string arm, int experience, int level);

    void doAttack(Character *target) override;
    void takeDamage(int damage) override;
    Character* getTarget(vector<Player*> teamMembers);
    Action takeAction(vector<Player*> player);
};

#endif //RPG_ENEMY_H
