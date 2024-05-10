cmake_minimum_required(VERSION 3.27)
project(Game_c__)

set(CMAKE_CXX_STANDARD 14)
include_directories(character)
include_directories(enemy)
include_directories(player)
include_directories(combat)

add_executable(Game_c__ main.cpp

        utils.h
        player/player.cpp
        player/player.h
        enemy/enemy.cpp
        enemy/enemy.h
        combat/combat.cpp
        combat/combat.h
        character/character.cpp
        character/character.h

)
