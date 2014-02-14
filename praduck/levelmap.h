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
private:
    int width, height;
    int _creatureCount = 0;

protected:
    BaseTile* map[20][20];
    BaseTile* TileFromChar(char c, int x, int y);

public:
    ~LevelMap();
    CreatureTile** creatures = new CreatureTile*[20];
    TileController** controllers = new TileController*[20];
    BaseTile* GetTile  (int x, int y);
    void SetTile(int x, int y, BaseTile* value);
    int MoveTile(BaseTile* tile, int x, int y);
    void PrintMap(ostream& output);
    void LoadMap(string filename);
    int creatureCount();
    int goalX;
    int goalY;
};

ostream& operator<<(ostream& os, LevelMap& lm);


#endif /* defined(__praduck__LevelMap__) */