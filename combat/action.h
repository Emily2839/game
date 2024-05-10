//
// Created by Emanuel on 13/03/2024.
//
#include <functional>
#ifndef GAME_C___ACTION_H
#define GAME_C___ACTION_H
#include<functional>
#include "../Character/Character.h"

class Character;

struct Action {
    int speed = 0;
    Character* subscriber = nullptr;
    Character* target = nullptr;
    std::function<void(void)> action = nullptr;

    Action(std::function<void(void)> _action, int _speed, Character* _subscriber, Character* _target) {
        action = _action;
        speed = _speed;
        subscriber = _subscriber;
        target = _target;
    }
    Action(){};

    bool operator<(const Action& p) const
    {
        return this->speed < p.speed;
    }
};

#endif //GAME_C___ACTION_H
