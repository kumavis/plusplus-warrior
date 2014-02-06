//
//  PlayerTile.h
//  praduck
//
//  Created by aaron davis on 2/3/14.
//  Copyright (c) 2014 aaron davis. All rights reserved.
//

#ifndef __praduck__PlayerTile__
#define __praduck__PlayerTile__

#include <iostream>
#include "CreatureTile.h"

class PlayerTile: public CreatureTile {
public:
    PlayerTile() {
        representation = '@';
    }
    virtual void run();
};

#endif /* defined(__praduck__PlayerTile__) */
