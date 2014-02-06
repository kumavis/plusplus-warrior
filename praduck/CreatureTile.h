//
//  CreatureTile.h
//  praduck
//
//  Created by aaron davis on 2/3/14.
//  Copyright (c) 2014 aaron davis. All rights reserved.
//

#ifndef __praduck__CreatureTile__
#define __praduck__CreatureTile__

#include <iostream>
#include "BaseTile.h"

class CreatureTile: public BaseTile {
public:
    CreatureTile() {
        traversable = false;
        alive = true;
    }
    bool alive;
};

#endif /* defined(__praduck__CreatureTile__) */
