//
//  Grid.hpp
//  SudokuSolver
//
//  Created by Melwan Chevassus on 22/02/2024.
//

#ifndef Grid_hpp
#define Grid_hpp

#include <list>
#include "Tile.hpp"

enum gridType {
    SQUARE,
};

class Grid {
private:
    std::list<Tile> grid;
    std::list<char> possibleChars;
public:
    Grid(gridType gridType, int size);
    std::list<char> getListOfPossibleChars();
    bool addTile(Tile tile);
    bool removeTile(Tile tile);
    Tile getTileAtCoords(int coordX, int coordY);
};

#endif /* Grid_hpp */
