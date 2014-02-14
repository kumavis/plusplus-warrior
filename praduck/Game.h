//
//  Game.h
//  praduck
//
//  Created by aaron davis on 2/3/14.
//  Copyright (c) 2014 aaron davis. All rights reserved.
//

#ifndef __praduck__Game__
#define __praduck__Game__

#include <iostream>
#include "LevelMap.h"
#include "TileController.h"

class Game {
    string levelDir;
    void DrawMap();
public:
    Game();
    ~Game();
    int levelIndex;
    LevelMap* map;
    void Start();
    bool RunLevel();
    void LoadLevel(int newLevelIndex);
    void RunEntities();
    bool CheckSuccess();
};

#endif /* defined(__praduck__Game__) */
