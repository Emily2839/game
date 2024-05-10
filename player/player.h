//
// Created by Emanuel on 13/03/2024.
//

#ifndef GAME_C___PLAYER_H
#define GAME_C___PLAYER_H

#include <vector>
#include "../Character/Character.h"
#include "../Enemy/Enemy.h"
#include "../Combat/Action.h"


struct Action;
class Enemy;

class Player: public Character {

protected:
    int experience;
    int level;

public:
    Player(char* _name, int _health, int _attack, int _defense, int _speed);


    void doAttack(Character *target) override;
    void takeDamage(int damage) override;
    char* serialize();
    static const unsigned int BUFFER_SIZE = sizeof (name) + sizeof (health) + sizeof (attack) + sizeof (defense) + sizeof (speed) + sizeof (isPlayer) + sizeof (experience) + sizeof (level);

    static Player * unserializer(char* buffer);

    Character * getTarget(vector<Enemy*> enemies);

    void flee(vector<Enemy*> enemies);
    void emote();
    void levelUp();
    void gainExperience(int);

    //Podemos hacer que este vector sea polimorfico?
    Action takeAction(vector<Enemy*> enemies);

private:
    char buffer[Player::BUFFER_SIZE];
};

#endif //GAME_C___PLAYER_H
