#include "levelmap.h"
#include "BaseTile.h"
#include "EmptyTile.h"
#include "WallTile.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>

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

BaseTile tile_from_char(char c)
{
    switch (c) {
        case '#':
            cout << "wall" << endl;
            return WallTile();
            break;
        case ' ':
            cout << "empty" << endl;
            return EmptyTile();
            break;
    }
    cout << "tile not recognized" << endl;
    return BaseTile();
}


void LevelMap::set_tile (int x, int y, BaseTile value)
{
    map[x][y] = value;
}

BaseTile LevelMap::get_tile (int x, int y)
{
    return map[x][y];
}

void LevelMap::print_map(ostream& output)
{
    output << "(width:" << width << ",height:" << height << ") " << endl;
    for (int x=0; x<width; x++) {
        for (int y=0; y<height; y++) {
            BaseTile tile = map[x][y];
//            output << "(x:" << x << ",y:" << y << ") " << tile << endl;
            output << tile;
        }
        output << endl;
    }
}

void LevelMap::load_map(string filename)
{
    ifstream input;
    LoadFile(filename, &input);
    // read header
    string line = GetLine(&input);
    istringstream header(line);
    header >> width;
    header >> height;
    // read each tile
//    for_each(istream_iterator<char>(input),istream_iterator<char>(),handleChar);
    typedef std::istreambuf_iterator<char> buf_iter;
    int x = 0;
    int y = 0;
    for(buf_iter token(input), e; token != e; ++token){
        char c = *token;
        cout << "token: " << c << endl;
        if (c == '\n') {
            x = 0;
            y++;
        } else {
            BaseTile tile = tile_from_char(c);
            cout << "tile: " << tile.representation << endl;
            map[x][y] = tile;
            x++;
        }

    }

//    int lineNumber = 0;
//    while (!input.fail())
//    {
//        string line = GetLine(&input);
//        this->set_line(lineNumber, line);
//        lineNumber++;
//    }
}

ostream& operator<<(ostream& os, LevelMap& lm)
{
    lm.print_map(os);
    return os;
}


