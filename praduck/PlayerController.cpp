//
//  PlayerController.cpp
//  praduck
//
//  Created by aaron davis on 2/5/14.
//  Copyright (c) 2014 aaron davis. All rights reserved.
//

#include "PlayerController.h"

///*
 // turn right
void PlayerController::Run() {
    DebugPosition();
    bool wasAbleToMove = MoveDirection(moveDirection);
    if (!wasAbleToMove) {
        moveDirection += 1;
        moveDirection = moveDirection % 4;
    }
}
//*/

/*
 // random choice
void PlayerController::Run() {
    DebugPosition();
    bool wasAbleToMove = MoveDirection(moveDirection);
    if (!wasAbleToMove) {
        moveDirection = rand() % 4;
    }
}
*/