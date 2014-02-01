//
//  main.cpp
//  praduck
//
//  Created by aaron davis on 1/24/14.
//  Copyright (c) 2014 aaron davis. All rights reserved.
//

#include <iostream>
#include "levelMap.h"

using namespace std;

int main() {
    string filename = "/Users/aarondavis/Development/kumavis/cpp/f1rst/praduck/praduck/0.lvl";
    LevelMap levelMap;
    levelMap.load_map(filename);
    cout << levelMap;
    return 0;
}
