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


BaseTile* LevelMap::TileFromChar(char c)
{
    switch (c) {
        case '#': {
            return new WallTile();
            break;
        }
        case ' ': {
            return new EmptyTile();
            break;
        }
        case '@': {
            PlayerTile* player = new PlayerTile();
            TileController* controller = new PlayerController(player, this);
            creatures[creatureCount] = player;
            controllers[creatureCount] = controller;
            creatureCount++;
            return player;
            break;
        }
        case '=': {
            return new ExitTile();
            break;
        }
    }
    cerr << "tile not recognized" << endl;
    return new BaseTile();
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
    if (GetTile(x,y)->traversable) {
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
            BaseTile* tile = TileFromChar(c);
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


