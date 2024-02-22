//
//  Grid.cpp
//  SudokuSolver
//
//  Created by Melwan Chevassus on 22/02/2024.
//

#include "Tile.hpp"
#include "Grid.hpp"
#include <iostream>
#include <list>
#include <string>
#include <vector>

Grid::Grid(enum gridType gridType, int size, std::string possibleValues) {
    possibleChars = possibleValues;
    type = gridType;
    gridSize = size;
    if (gridType == SQUARE) {
        // create a new grid with a list of 3 lists of components : lines, columns and blocks.
        // The size of the blocks are sqrt(size).
        for (int i = 0; i < 3; i++) {
            components.push_back({});
        }
        
        for (int line = 0; line < size; line++) {
            std::vector<Tile> list = {};
            for (int column = 0; column < size; column++) {
                Tile tile(line, column, 0, false, possibleChars);
                list.push_back(tile);
            }
            components.at(0).push_back(list);
        }
        
        for (int column = 0; column < size; column++) {
            std::vector<Tile> list = {};
            for (int line = 0; line < size; line++) {
                std::vector<Tile> tileList = components.at(0).at(line).getTileList();
                Tile& tile = tileList.at(column);
                list.push_back(tile);
            }
            components.at(1).push_back(list);
        }
        
        for (int block = 0; block < size; block++) {
            int side = sqrt(size);
            std::vector<Tile> list = {};
            for (int index = 0; index < size; index++) {
                std::vector<Tile> tileList = components.at(0).at(block / side * side + index / side).tileList;
                Tile& tile = tileList.at(block % side * side + index % side);
                list.push_back(tile);
            }
            components.at(2).push_back(list);
        }
        
    }
}
std::string Grid::getPossibleChars() {
    return possibleChars;
}

bool Grid::addTile(Tile tile) {
    return false;
}
bool Grid::removeTile(Tile tile) {
    return false;
}
Tile Grid::getTileAtCoords(int coordX, int coordY) {
    return Tile(coordX, coordY, 0, false, {});
};

gridType Grid::getGridType() {
    return type;
}

std::vector<std::vector<Component>> Grid::getComponents() {
    return components;
}

int Grid::getSize() {
    return gridSize;
}


void Grid::print() {
    if (getGridType() == SQUARE) {
        int side = sqrt(getSize());
        int lineSize = (getSize() + side + 1) * 2 - 1;
        for (int index = 0; index < lineSize; index++) {
            putchar('-');
        }
        putchar('\n');
        for (int line = 0; line < getSize(); line++) {
            printf("| ");
            for (int column = 0; column < getSize(); column++) {
                Tile tile = components.at(0).at(line).tileList.at(column);
                tile.print();
                putchar(' ');
                if (column % side == side - 1) {
                    printf("| ");
                }
            }
            putchar('\n');
            if (line % side == side - 1) {
                for (int index = 0; index < lineSize; index++) {
                    putchar('-');
                }
                putchar('\n');
            }
        }
    }
}

void Grid::populate() {
    char providedChar;
    for (int line = 0; line < getSize(); line++) {
        for (int column = 0; column < getSize(); column++) {
            Tile& tile = components.at(0).at(line).tileList.at(column);
            tile.setValue('_');
            print();
            std::cout << "Enter value for this tile (s to skip): ";
            std::cin >> providedChar;
            if (providedChar == 's') {
                tile.setValue(0);
                continue;
            }
            else if (possibleChars.find(providedChar) != std::string::npos) {
                tile.setValue(providedChar);
                tile.setProvided(true);
            }
        }
    }
}

std::vector<Component> Grid::findAllComponentsOfTile(Tile tile) {
    std::vector<Component> result = {};
    for (std::vector<Component> vector : components)
    {
        for (Component component : vector) {
            if (component.containsTile(tile)) {
                result.push_back(component);
            }
        }
    }
    return result;
}

