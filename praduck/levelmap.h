#ifndef __praduck__LevelMap__
#define __praduck__LevelMap__

#include <iostream>
#include <fstream>
#include <iomanip>
#include "BaseTile.h"

using namespace std;

class LevelMap {
protected:
    BaseTile map[20][20];
    BaseTile get_tile  (int x, int y);
    void set_tile (int x, int y, BaseTile value);
public:
    int width, height;
    void print_map(ostream& output);
    void load_map(string filename);
};

ostream& operator<<(ostream& os, LevelMap& lm);


#endif /* defined(__praduck__LevelMap__) */