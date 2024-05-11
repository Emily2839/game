//
// Created by Emanuel on 13/03/2024.
//

#ifndef GAME_C_COMBAT_H
#define GAME_C_COMBAT_H
#pragma once
#include "../character/character.h"
#include "../Player/Player.h"
#include "../Enemy/Enemy.h"
#include "Action.h"
#include <vector>
#include <string>
#include <queue>
#include <Combat.h>

using namespace std;
class Enemy;
class player;
class Combat {
private:

    vector<Character*> participants;
    vector<Player*> teamMembers;
    vector<Enemy*> enemies;

    priority_queue<Action> actions;

    void prepareCombat();
    Character* getTarget(Character* target);
    void registerActions();
    void executeActions();

    void checkParticipantStatus(Character* participant);
    void checkForFlee(Character* character);

public:
    Combat(vector<Character*> _participants);
    Combat(vector<Player*> _teamMembers, vector<Enemy*> _enemies);
    Combat();
    void addParticipant(Character *participant);
    void doCombat();
    string participantsToString();

    void increaseEnemyStats(int points);
};


#endif //GAME_C___COMBAT_H
