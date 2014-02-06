#ifndef __praduck__LevelMap__
#define __praduck__LevelMap__

#include <iostream>
#include <fstream>
#include <iomanip>
#include "BaseTile.h"
#include "CreatureTile.h"

class TileController;

using namespace std;

class LevelMap {
protected:
    BaseTile* map[20][20];
    BaseTile* TileFromChar(char c);
public:
    int width, height;
    CreatureTile** creatures = new CreatureTile*[20];
    TileController** controllers = new TileController*[20];
    int creatureCount = 0;
    BaseTile* GetTile  (int x, int y);
    void SetTile(int x, int y, BaseTile* value);
    int MoveTile(BaseTile* tile, int x, int y);
    void PrintMap(ostream& output);
    void LoadMap(string filename);
};

ostream& operator<<(ostream& os, LevelMap& lm);


#endif /* defined(__praduck__LevelMap__) */