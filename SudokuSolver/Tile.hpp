//
//  Tile.hpp
//  SudokuSolver
//
//  Created by Melwan Chevassus on 22/02/2024.
//

#ifndef Tile_hpp
#define Tile_hpp

#include <list>
#include <string>

class Tile {
private:
    int coordX;
    int coordY;
    char value;
    bool isProvided;
    std::string possibleValues;
    
public:
    Tile(int x, int y, char val, bool provided, std::string possible);
    void print();
    char getValue();
    void setValue(char newValue);
    void setProvided(bool b);
    bool equals(Tile tile);
};

#endif /* Tile_hpp */
