//
//  Grid.hpp
//  SudokuSolver
//
//  Created by Melwan Chevassus on 22/02/2024.
//

#ifndef Grid_hpp
#define Grid_hpp

#include <list>
#include <string>
#include "Tile.hpp"
#include "Component.hpp"

enum gridType {
    SQUARE,
};

class Grid {
private:
    std::string possibleChars;
    gridType type;
    int gridSize;
public:
    std::vector<std::vector<Component>> components;
    Grid(gridType gridType, int size, std::string possible);
    std::string getPossibleChars();
    bool addTile(Tile tile);
    bool removeTile(Tile tile);
    Tile getTileAtCoords(int coordX, int coordY);
    void print();
    gridType getGridType();
    std::vector<std::vector<Component>> getComponents();
    int getSize();
    void populate();
    std::vector<Component> findAllComponentsOfTile(Tile tile);
};

#endif /* Grid_hpp */
