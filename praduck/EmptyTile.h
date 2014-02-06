//
//  EmptyTile.h
//  praduck
//
//  Created by aaron davis on 1/31/14.
//  Copyright (c) 2014 aaron davis. All rights reserved.
//

#ifndef __praduck__EmptyTile__
#define __praduck__EmptyTile__

#include <iostream>
#include "BaseTile.h"

class EmptyTile: public BaseTile {
public:
    EmptyTile() {
        representation = ' ';
        traversable = true;
    }
};

#endif /* defined(__praduck__EmptyTile__) */
