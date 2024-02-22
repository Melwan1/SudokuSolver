//
//  Component.cpp
//  SudokuSolver
//
//  Created by Christophe Chevassus on 22/02/2024.
//

#include "Component.hpp"
#include <iostream>
#include <list>

Component::Component(std::vector<Tile> list) {
    tileList = list;
}

std::vector<Tile> Component::getTileList() {
    return tileList;
}

void Component::addTile(Tile tile) {
   tileList.push_back(tile);
}

void Component::changeTile(Tile tile, int index) {
    tileList.at(index) = tile;
}

void Component::print() {
    for (Tile tile : tileList) {
        tile.print();
        putchar(' ');
    }
}

bool Component::containsTile(Tile tile) {
    for (Tile componentTile : tileList) {
        if (componentTile.equals(tile)) {
            return true;
        }
    }
    return false;
}
