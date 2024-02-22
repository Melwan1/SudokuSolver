//
//  main.cpp
//  SudokuSolver
//
//  Created by Melwan Chevassus on 22/02/2024.
//

#include <iostream>
using namespace std;

#include "Grid.hpp"

int main(int argc, const char * argv[]) {
    cout << "====================================\n";
    cout << "Welcome to Sudoku Solver\n";
    cout << "====================================\n";
    cout << "Grid types:\n";
    cout << "-----------------------\n";
    int numberGridTypes = 1;
    cout << "1 - Normal square grid\n";
    cout << "-----------------------\n";
    cout << "Enter the grid type (from 1 to " << numberGridTypes << "): ";
    int gridType = 0;
    cin >> gridType;
    if (gridType <= 0 || gridType > numberGridTypes) {
        cout << "Entered grid type is invalid!\n";
        return 1;
    }
    Grid grid(SQUARE, 9, "123456789");
    Component component({});
    grid.populate();
    grid.print();
    return 0;
    
}
