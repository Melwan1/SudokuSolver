//
//  Tile.cpp
//  SudokuSolver
//
//  Created by Melwan Chevassus on 22/02/2024.
//

#include "Tile.hpp"
#include <list>
#include <string>

Tile::Tile(int x, int y, char val, bool provided, std::string possible) {
    coordX = x;
    coordY = y;
    value = val;
    isProvided = provided;
    possibleValues = possible;
}

char Tile::getValue() {
    return value;
}

void Tile::print() {
    char c = getValue();
    if (!c) {
        putchar('X');
    }
    else {
        putchar(c);
    }
}

void Tile::setProvided(bool b) {
    isProvided = b;
}

void Tile::setValue(char newValue) {
    value = newValue;
}

bool Tile::equals(Tile tile) {
    return (coordX == tile.coordX && coordY == tile.coordY);
}
