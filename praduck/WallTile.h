//
//  WallTile.h
//  praduck
//
//  Created by aaron davis on 1/31/14.
//  Copyright (c) 2014 aaron davis. All rights reserved.
//

#ifndef __praduck__WallTile__
#define __praduck__WallTile__

#include <iostream>
#include "BaseTile.h"

class WallTile: public BaseTile {
public:
    WallTile() {
        representation = '#';
        traversable = false;
    }
};

#endif /* defined(__praduck__WallTile__) */
