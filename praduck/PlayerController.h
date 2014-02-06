//
//  PlayerController.h
//  praduck
//
//  Created by aaron davis on 2/5/14.
//  Copyright (c) 2014 aaron davis. All rights reserved.
//

#ifndef __praduck__PlayerController__
#define __praduck__PlayerController__

#include <iostream>
#include "TileController.h"
#include "BaseTile.h"
#include "PlayerTile.h"

class PlayerController : public TileController {
public:
    PlayerController(PlayerTile* tile, LevelMap* map) : TileController(tile, map) {

    }
    void Run();
};
    
#endif /* defined(__praduck__PlayerController__) */
