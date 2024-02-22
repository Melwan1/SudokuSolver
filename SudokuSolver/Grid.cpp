//
//  Grid.cpp
//  SudokuSolver
//
//  Created by Melwan Chevassus on 22/02/2024.
//

#include "Tile.hpp"
#include "Grid.hpp"
#include <list>


Grid::Grid(gridType gridType, int size) {
    if (gridType == SQUARE) {
        grid = {};
    }
}
std::list<char> Grid::getListOfPossibleChars() {
    return {};
}

bool Grid::addTile(Tile tile) {
    return false;
}
bool Grid::removeTile(Tile tile) {
    return false;
}
Tile Grid::getTileAtCoords(int coordX, int coordY) {
    return Tile::Tile();
};
