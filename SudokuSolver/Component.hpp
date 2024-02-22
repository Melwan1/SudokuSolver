//
//  Component.hpp
//  SudokuSolver
//
//  Created by Christophe Chevassus on 22/02/2024.
//

#ifndef Component_hpp
#define Component_hpp

#include "Tile.hpp"
#include <list>

class Component {

public:
    std::vector<Tile> tileList;
    Component(std::vector<Tile> list);
    bool isValid();
    bool solveTile(Tile tile);
    void addTile(Tile tile);
    bool removeTile(Tile tile);
    std::vector<Tile> getTileList();
    void print();
    void changeTile(Tile tile, int index);
    bool containsTile(Tile tile);


};

#endif /* Component_hpp */
