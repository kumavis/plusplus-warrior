//
//  BaseTile.h
//  praduck
//
//  Created by aaron davis on 1/31/14.
//  Copyright (c) 2014 aaron davis. All rights reserved.
//

#ifndef __praduck__BaseTile__
#define __praduck__BaseTile__

#include <iostream>
#include <iomanip>

using namespace std;

class BaseTile {
public:
    int x;
    int y;
    char representation = '?';
    bool traversable;
};

ostream& operator<<(ostream& os, BaseTile& tile);

#endif /* defined(__praduck__BaseTile__) */
