//
//  TileController.h
//  praduck
//
//  Created by aaron davis on 2/4/14.
//  Copyright (c) 2014 aaron davis. All rights reserved.
//

#ifndef __praduck__TileController__
#define __praduck__TileController__

#include <iostream>
#include "BaseTile.h"

class LevelMap;

class TileController {
private:
    BaseTile* tile;
    LevelMap* map;
    int SetPosition(int x, int y);
public:
    TileController(BaseTile* tile, LevelMap* map) {
        this->tile = tile;
        this->map = map;
    }
    int MoveNorth();
    int MoveSouth();
    int MoveWest();
    int MoveEast();
    // 0 - North, 1 - East, 2 - South, 3 - West
    int MoveDirection(int directionalIndex);
    virtual void Run() = 0;
    void DebugPosition();
};


#endif /* defined(__praduck__TileController__) */
