//
//  TileController.cpp
//  praduck
//
//  Created by aaron davis on 2/4/14.
//  Copyright (c) 2014 aaron davis. All rights reserved.
//

#include "TileController.h"
#include "LevelMap.h"

int TileController::SetPosition(int x, int y) {
    return map->MoveTile(tile,x,y);
}

void TileController::DebugPosition() {
    int x = tile->x;
    int y = tile->y;
    std:cout << "x: " << std::to_string(x) << ", y: " << std::to_string(y) << endl;
}

int TileController::MoveNorth() {
    return SetPosition(tile->x,tile->y-1);
}
int TileController::MoveSouth() {
    return SetPosition(tile->x,tile->y+1);
}
int TileController::MoveWest() {
    return SetPosition(tile->x+1,tile->y);
}
int TileController::MoveEast() {
    return SetPosition(tile->x-1,tile->y);
}