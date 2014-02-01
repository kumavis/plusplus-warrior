//
//  BaseTile.cpp
//  praduck
//
//  Created by aaron davis on 1/31/14.
//  Copyright (c) 2014 aaron davis. All rights reserved.
//

#include "BaseTile.h"

using namespace std;


ostream& operator<<(ostream& os, BaseTile& tile)
{
    os << tile.representation;
    return os;
}