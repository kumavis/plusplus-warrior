//
//  main.cpp
//  praduck
//
//  Created by aaron davis on 1/24/14.
//  Copyright (c) 2014 aaron davis. All rights reserved.
//

#include <iostream>
#include "Game.h"

using namespace std;

int main() {
//    while(1){
        cout << "- - - - - - - -" << endl;
        cout << "  Game Start! " << endl;
        cout << "- - - - - - - -" << endl;
        Game *game = new Game();
        game->Start();
        delete game;
//    }
}
