//
// Created by Emanuel on 13/03/2024.
//

#ifndef GAME_C___UTILS_H
#define GAME_C___UTILS_H
#include <cstdlib>

namespace combat_utils {
    int getRolledAttack (int attack) {
        srand(time(NULL));
        int lowerLimit = attack * .80;
        return (rand() % (attack - lowerLimit)) + lowerLimit;
    }
}
#endif //GAME_C___UTILS_H
