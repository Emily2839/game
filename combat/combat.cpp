//
// Created by Victor Navarro on 19/02/24.
//
#include "Combat.h"
#include <iostream>
#include <algorithm>

using namespace std;

bool compareSpeed(Character *a, Character *b) {
    return a->getSpeed() > b->getSpeed();
}

// CONSTRUCTORES -- INICIA
Combat::Combat(vector<Character *> _participants) {
    participants = std::move(_participants);
    for(auto participant: participants) {
        if(participant->getIsPlayer()) {
            teamMembers.push_back((Player*)participant);
        }
        else {
            enemies.push_back((Enemy*)participant);
        }
    }
}

Combat::Combat(vector<Player*> _teamMembers, vector<Enemy*> _enemies) {
    teamMembers = std::move(_teamMembers);
    enemies = std::move(_enemies);
}

Combat::Combat() {
    participants = vector<Character*>();
}
// CONSTRUCTORES -- INICIA

void Combat::addParticipant(Character *participant) {
    participants.push_back(participant);
    if(participant->getIsPlayer()) {
        teamMembers.push_back((Player*)participant);
    }
    else {
        enemies.push_back((Enemy*)participant);
    }
}

void Combat::prepareCombat() {
    sort(participants.begin(), participants.end(), compareSpeed);
}

void Combat::doCombat() {
    prepareCombat();

    //Este while es 1 iteracion por ronda
    while(enemies.size() != 0 && teamMembers.size() != 0) {
        registerActions();
        executeActions();

    }

    //No se imprime el nombre del ganador
    if(enemies.empty()) {
        cout << "Ganaste el combate jajaj =)" << endl;
        // Iterar a través de todos los miembros del equipo
        for (Player *player : teamMembers) {
            // Imprimir la experiencia total ganada por el jugador
            cout << "Jugador " << player->getName() << " tiene " << player->getExperience() << " experiencia." << endl;
        }
    }
    else {
        cout<<"Los enemigos pudieron mas - Game Over"<<endl;
    }
}

void Combat::increaseEnemyStats(int points) {
    // DAR LOS PUNTOS A LOS ENEMIGOS
    for (Enemy *enemy: enemies) {
        // Aumentar atributos
        int healthIncrease = points / 3;
        int attackIncrease = points / 3;
        int defenseIncrease = points - healthIncrease - attackIncrease;
        enemy->setHealth(healthIncrease);
        enemy->setAttack(attackIncrease);
        enemy->setDefense(defenseIncrease);
    }
}

void Combat::registerActions() {
    vector<Character*>::iterator participant = participants.begin();
    //Una iteracion por turno de cada participante (player y enemigo)
    while(participant != participants.end()) {
        Action currentAction;
        if((*participant)->getIsPlayer()) {
            currentAction = ((Player*)*participant)->takeAction(enemies);
        }
        else {
            currentAction = ((Enemy*)*participant)->takeAction(teamMembers);
        }
        actions.push(currentAction);
        participant++;
    }
}

void Combat::executeActions() {
    //Aqui se ejecutan las acciones
    while(!actions.empty()) {
        Action currentAction = actions.top();
        if (currentAction.subscriber->getHealth() > 0) {
            cout<<"> " << currentAction.subscriber->getStringName() << " decide actuar!\n";
            currentAction.action();
            checkForFlee(currentAction.subscriber);
            checkParticipantStatus(currentAction.subscriber);
            checkParticipantStatus(currentAction.target);
            actions.pop();
        } else {
            cout << "> Participante " << currentAction.subscriber->getStringName() << " esta " << RED << "MUERTO!! " << RESET << "asi que no puede actuar...\n";
            checkParticipantStatus(currentAction.subscriber);
            checkParticipantStatus(currentAction.target);
            //checar si es un enemigo
            // de la accion actual sacar el subscriber que seria el player que ataco
            //y mandar a llamar su gain experience
            actions.pop();
        }
    }
}

void Combat::checkParticipantStatus(Character* participant) {
    if (participant == nullptr) return;
    if(participant->getHealth() <= 0) {
        if(participant->getIsPlayer()) {
            teamMembers.erase(remove(teamMembers.begin(), teamMembers.end(), participant), teamMembers.end());
        }
        else {
            enemies.erase(remove(enemies.begin(), enemies.end(), participant), enemies.end());
        }
        participants.erase(remove(participants.begin(), participants.end(), participant), participants.end());
    }
}

void Combat::checkForFlee(Character *character) {
    // Verificar si  murio para que no escape una vez ya muerto
    if (character->getHealth() > 0) {
        bool fleed = character->hasFleed();
        if (fleed) {
            if (character->getIsPlayer()) {
                cout << "te faltaron ganas -_-" << endl;
                teamMembers.erase(remove(teamMembers.begin(), teamMembers.end(), character), teamMembers.end());
            } else {
                cout << "pero que cobarde!" << endl;
                enemies.erase(remove(enemies.begin(), enemies.end(), character), enemies.end());
            }
            participants.erase(remove(participants.begin(), participants.end(), character), participants.end());
        }
    }
}

string Combat::participantsToString() {
    string result = "";
    for (int i = 0; i < participants.size(); i++) {
        result += participants[i]->toString() + "\n";
    }
    return result;
}