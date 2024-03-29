# Bresenham's Line Drawing Algorithm

## Overview
Bresenham's Line Drawing Algorithm is an incremental algorithm used for drawing lines on a discrete grid. It efficiently determines the coordinates of points that approximate a line segment between two given points. One of the notable features of the algorithm is its ability to use only integer arithmetic, making it computationally efficient.

This repository contains a C++ implementation of Bresenham's Line Drawing Algorithm for two cases: when the slope (m) is 0 < m < 1 and when m > 1. The algorithm efficiently draws a line on a grid using only integer arithmetic.

## Files
- `bresenham_line.cpp`: The C++ code implements the algorithm and generates a grid with '*' characters to represent the drawn line.
- `README.md`: This file, provides an overview of the algorithm and the generated output.

## Bresenham's Line Drawing Algorithm
### Decision Parameter
At the heart of Bresenham's algorithm is the decision parameter, a value that helps determine which pixel to choose next along the line. The decision parameter is crucial for efficiently selecting points on the line.

### Case 1: 0 < m < 1
When the slope `m` of the line is between 0 and 1, the algorithm increments the x-coordinate by 1 for each step and adjusts the y-coordinate based on the decision parameter.

#### Decision Parameter Update
- If the decision parameter is greater than or equal to 0, the y-coordinate is incremented by 1, and the decision parameter is adjusted.
- If the decision parameter is less than 0, only the decision parameter is adjusted.

### Case 2: m > 1
When the slope `m` is greater than 1, the algorithm increments the y-coordinate by 1 for each step and adjusts the x-coordinate based on the decision parameter.

#### Decision Parameter Update
- If the decision parameter is greater than or equal to 0, the x-coordinate is incremented by 1, and the decision parameter is adjusted.
- If the decision parameter is less than 0, only the decision parameter is adjusted.

## Key Steps of the Algorithm
1. Calculate the differences in x and y coordinates: `dx = x2 - x1` and `dy = y2 - y1`.
2. Determine the signs of increments: `signX = (dx > 0) ? 1 : -1` and `signY = (dy > 0) ? 1 : -1`.
3. Use absolute values for increments: `dx = abs(dx)` and `dy = abs(dy)`.
4. Initialize the decision parameter: `decision = 2 * dy - dx`.
5. Iterate through the steps of the algorithm:
   - Update coordinates and decision parameters based on the selected case.
   - Mark the corresponding point on the grid.
## Output
The generated output consists of a 10x10 grid for each test case, with the line represented by '*' characters. The coordinates of the points on the line are also outputted, providing a clear representation of the drawn line.

### Case 1: (1,1), (8,4)
```
. . . . . . . . . . 
. * * . . . . . . . 
. . . * * . . . . . 
. . . . . * * . . . 
. . . . . . . * * . 
. . . . . . . . . . 
. . . . . . . . . . 
. . . . . . . . . . 
. . . . . . . . . .
   
Coordinates:  
(1, 1)  
(2, 1)  
(3, 2)  
(4, 2)  
(5, 3)  
(6, 3)  
(7, 4)  
(8, 4)   
```
### Case 2: (1,1), (4,8)  
```
. . . . . . . . . .
. * . . . . . . . .
. * . . . . . . . .
. . * . . . . . . .
. . * . . . . . . .
. . . * . . . . . .
. . . * . . . . . .
. . . . * . . . . .
. . . . * . . . . .
. . . . . . . . . .

Coordinates:  
(1, 1)
(1, 2)
(2, 3)
(2, 4)
(3, 5)
(3, 6)
(4, 7)
(4, 8) 
```
