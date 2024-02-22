//
//  Tile.hpp
//  SudokuSolver
//
//  Created by Christophe Chevassus on 22/02/2024.
//

#ifndef Tile_hpp
#define Tile_hpp

#include <list>

class Tile {
private:
    int coordX;
    int coordY;
    char value;
    bool isProvided;
    std::list<char> possibleValues;
    
public:
    Tile(int x, int y, char val, bool provided, std::list<char> possible);
};

#endif /* Tile_hpp */
