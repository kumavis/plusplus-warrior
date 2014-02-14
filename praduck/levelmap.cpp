#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include "LevelMap.h"
#include "BaseTile.h"
#include "EmptyTile.h"
#include "ExitTile.h"
#include "WallTile.h"
#include "PlayerTile.h"
#include "PlayerController.h"

using namespace std;

#pragma mark - Constructor/Destructor

LevelMap::~LevelMap() {
    for (int x=0; x++; x < this->width) {
        for (int y=0; y++; y < this->height) {
            delete map[x][y];
        }
    }
    for (int i=0; i++; i < this->creatureCount()) {
        delete creatures[i];
        delete controllers[i];
    }
}

#pragma mark - Getters/Setters

int LevelMap::creatureCount() {
    return this->_creatureCount;
}

#pragma mark - Other


void LoadFile(string filename, ifstream *input)
{
    (*input).open(filename.c_str());
    if (!(*input).is_open())
    {
        cerr << "Cannot find the file " << filename << endl;
    }
}

string GetLine(ifstream *input)
{
    string result;
    getline(*input, result);
    return result;
}


BaseTile* LevelMap::TileFromChar(char c, int x, int y)
{
    BaseTile* newTile;
    switch (c) {
        case '#': {
            newTile = new WallTile();
            break;
        }
        case ' ': {
            newTile = new EmptyTile();
            break;
        }
        case '@': {
            PlayerTile* player = new PlayerTile();
            TileController* controller = new PlayerController(player, this);
            creatures[_creatureCount] = player;
            controllers[_creatureCount] = controller;
            _creatureCount++;
            newTile = player;
            break;
        }
        case '=': {
            goalX = x;
            goalY = y;
            newTile = new ExitTile();
            break;
        }
        default: {
            cerr << "tile not recognized" << endl;
            newTile = new BaseTile();
        }
    }
    return newTile;
}

void LevelMap::SetTile (int x, int y, BaseTile* tile)
{
    map[x][y] = tile;
    tile->x = x;
    tile->y = y;
}

BaseTile* LevelMap::GetTile (int x, int y)
{
    return map[x][y];
}

int LevelMap::MoveTile(BaseTile* tile, int x, int y) {
    int oldX = tile->x;
    int oldY = tile->y;
    BaseTile* targetTile = GetTile(x,y);
    if (targetTile->traversable) {
        delete targetTile;
        SetTile(x,y,tile);
        SetTile(oldX,oldY,new EmptyTile());
        return 1;
    } else {
        return 0;
    }
}

void LevelMap::PrintMap(ostream& output)
{
    for (int y=0; y<height; y++) {
        for (int x=0; x<width; x++) {
            BaseTile* tile = map[x][y];
            output << *tile;
        }
        output << endl;
    }
}

void LevelMap::LoadMap(string filename)
{
    ifstream input;
    LoadFile(filename, &input);
    // read header
    string line = GetLine(&input);
    istringstream header(line);
    header >> width;
    header >> height;
    // read each tile
    typedef std::istreambuf_iterator<char> buf_iter;
    int x = 0;
    int y = 0;
    for(buf_iter token(input), e; token != e; ++token){
        char c = *token;
        if (c == '\n') {
            x = 0;
            y++;
        } else {
            BaseTile* tile = TileFromChar(c,x,y);
            SetTile(x,y,tile);
            x++;
        }

    }
}

ostream& operator<<(ostream& os, LevelMap& lm)
{
    lm.PrintMap(os);
    return os;
}


