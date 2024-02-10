#include <iostream>
#include <cmath>

void drawLine(char grid[10][10], int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;

    int signX = (dx > 0) ? 1 : -1;
    int signY = (dy > 0) ? 1 : -1;

    dx = std::abs(dx);
    dy = std::abs(dy);

    int decision;

    int x = x1;
    int y = y1;

    // Mark starting point
    grid[y1][x1] = '*';

    // Output the starting coordinate
    std::cout << "(" << x1 << ", " << y1 << ")" << std::endl;

    if (dx > dy) {
        decision = 2 * dy - dx;

        for (int i = 0; i < dx; i++) {
            x += signX;

            if (decision >= 0) {
                decision -= 2 * dx;
                y += signY;
            }

            decision += 2 * dy;

            // Mark the point
            grid[y][x] = '*';

            // Output the current coordinate
            std::cout << "(" << x << ", " << y << ")" << std::endl;
        }
    } else {
        decision = 2 * dx - dy;

        for (int i = 0; i < dy; i++) {
            y += signY;

            if (decision >= 0) {
                decision -= 2 * dy;
                x += signX;
            }

            decision += 2 * dx;

            // Mark the point
            grid[y][x] = '*';

            // Output the current coordinate
            std::cout << "(" << x << ", " << y << ")" << std::endl;
        }
    }
}

void printGrid(const char grid[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            std::cout << grid[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

int main() {
    // Create a 10x10 grid
    char grid1[10][10], grid2[10][10];

    // Initialize grids with '.'
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            grid1[i][j] = '.';
            grid2[i][j] = '.';
        }
    }

    // Case 1: (1,1), (8,4)
    std::cout << "Case 1: (1,1), (8,4)" << std::endl;
    drawLine(grid1, 1, 1, 8, 4);
    printGrid(grid1);

    // Case 2: (1,1), (4,8)
    std::cout << "\nCase 2: (1,1), (4,8)" << std::endl;
    drawLine(grid2, 1, 1, 4, 8);
    printGrid(grid2);

    return 0;
}
