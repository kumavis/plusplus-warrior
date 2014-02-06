//
//  Game.cpp
//  praduck
//
//  Created by aaron davis on 2/3/14.
//  Copyright (c) 2014 aaron davis. All rights reserved.
//

#include "Game.h"

using namespace std;

void Game::start() {
    LoadLevel(0);
    DrawMap();
    for (int i=0; i<10; i++) {
        RunEntities();
        DrawMap();
    }
}

void Game::LoadLevel(int newLevelIndex) {
    levelIndex = newLevelIndex;
    string filename = levelDir + to_string(levelIndex) + ".lvl";
    map->LoadMap(filename);
}

void Game::DrawMap() {
    cout << *map;
}

void Game::RunEntities() {
    for (int i=0; i<map->creatureCount; i++) {
        CreatureTile* creature = map->creatures[i];
        TileController* controller = map->controllers[i];
        if (creature->alive && controller) {
            controller->Run();
        }
    }
}