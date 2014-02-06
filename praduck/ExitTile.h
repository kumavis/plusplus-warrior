//
//  ExitTile.h
//  praduck
//
//  Created by aaron davis on 2/3/14.
//  Copyright (c) 2014 aaron davis. All rights reserved.
//

#ifndef __praduck__ExitTile__
#define __praduck__ExitTile__

#include <iostream>
#include "EmptyTile.h"

class ExitTile: public EmptyTile {
public:
    ExitTile() {
        representation = '=';
    }
};


#endif /* defined(__praduck__ExitTile__) */
