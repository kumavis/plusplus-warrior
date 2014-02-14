//
//  Game.cpp
//  praduck
//
//  Created by aaron davis on 2/3/14.
//  Copyright (c) 2014 aaron davis. All rights reserved.
//

#include "Game.h"

using namespace std;

Game::Game() {
    levelDir = "/Users/aarondavis/Development/kumavis/cpp/f1rst/praduck/praduck/";
    map = new LevelMap();
}

Game::~Game() {
    delete this->map;
}

void Game::Start() {
    int currentLevel = 0;
    bool didWin;
    while (true) {
        LoadLevel(currentLevel);
        didWin = RunLevel();
        if (didWin) {
            currentLevel++;
            cout << "- - - - - - -" << endl;
            cout << "next level: " << to_string(currentLevel) << endl;
            cout << "- - - - - - -" << endl;
        } else {
            cout << "- - - - - - -" << endl;
            cout << "you lose." << endl;
            cout << "- - - - - - -" << endl;
            break;
        }
    }
}

bool Game::RunLevel() {
    DrawMap();
    for (int i=0; i<100; i++) {
        RunEntities();
        bool didSucceed = CheckSuccess();
        DrawMap();
        if (didSucceed) {
            cout << "- - - - - - -" << endl;
            cout << "winner is you" << endl;
            cout << "- - - - - - -" << endl;
            return true;
            break;
        }
    }
    return false;
}

void Game::LoadLevel(int newLevelIndex) {
    levelIndex = newLevelIndex;
    string filename = levelDir + to_string(levelIndex) + ".lvl";
    delete map;
    map = new LevelMap();
    map->LoadMap(filename);
}

void Game::DrawMap() {
    cout << *map;
}

void Game::RunEntities() {
    for (int i=0; i<map->creatureCount(); i++) {
        CreatureTile* creature = map->creatures[i];
        TileController* controller = map->controllers[i];
        if (creature->alive && controller) {
            controller->Run();
        }
    }
}

bool Game::CheckSuccess() {
    bool didSucceed = false;
    for (int i=0; i<map->creatureCount(); i++) {
        CreatureTile* creature = map->creatures[i];
        if (creature->x == map->goalX && creature->y == map->goalY) {
            didSucceed = true;
            break;
        }
    }
    return didSucceed;
}