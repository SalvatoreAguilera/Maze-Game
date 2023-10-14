# Maze-Game
Maze Solving with Depth-First Search (DFS)

This C++ program utilizes Depth-First Search (DFS) to navigate through a maze. The maze is represented as a grid, with openings marked as '0' and walls as '1'. The objective is to find a path from the starting point to the exit point marked as '3'.

Key Features:

Dynamic Maze Creation: You have the option to either use a predefined maze or create your own. For user-defined mazes, the program guides you to input a 6x6 grid, allowing for customization while ensuring proper maze formatting.
Intuitive Maze Display: The program provides clear visualization of the maze, showing openings as '-' and walls as 'x'. This visual representation aids in understanding the maze's structure.
DFS Algorithm: The depth-first search algorithm efficiently explores the maze, carefully backtracking when necessary. It systematically navigates through possible paths until it reaches the exit, or concludes that no path exists.
Informative Output: The program outputs the maze solving process, displaying the coordinates visited by the DFS algorithm. If a valid path is found, it confirms the successful traversal; otherwise, it notifies when no path is available.
Usage:

The program initiates with a 6x6 maze.
Optionally, you can choose to customize the maze by inputting your own grid.
The program visualizes and executes DFS to find a path from the starting point to the exit.
The result is displayed, indicating whether a path was found.
