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
        int experience;
        int level;
    protected:
        Player(string namae, int health, int attack, int defense, int speed, int experience, int level, string _arm);



    public:
        Player(char _name[30], int health, int attack, int defense, int speed, string arm, int experience, int level);
        Player(string, int health, int attack, int defense, int speed, string arm, int experience, int level);

        void doAttack(Character *target) override;

        void takeDamage(int damage) override;

        void gainExperience(int newExperience);

        void levelUp();

        //Funcion para que aumente su nivel//

        Character *getTarget(vector<Enemy *> enemies);

        void flee(vector<Enemy *> enemies);

        void emote();

        Action takeAction(vector<Enemy *> enemies);

    };
#endif //GAME_C___PLAYER_H
