# Sudoku Solver
Applying Data Structures, SDL Graphics and Multi-Threading

## Description 

Firstly, this project uses a Backtracking algorithm to find the solution of a given Sudoku Board in the form of a 2D vector. 
The project also supports concurrency through the implementation of multithreading and asynchronous operations to handle various independent CPU-intensive sub-tasks, allowing multiple processes to make progress. 

A board can be of any size NxN, however, boards _4x4_, _6x6_, _9x9_, and _16x16_ lead to possible solutions where sub-grids are taken 
into account to ensure no number is repeated, coinciding with the rules of Sudoku. All other grid sizes do not account for 
repeating values within sub-grids. The vector is updated with the possible solutions if a solution is found. 

### Graphical User Interface

Secondly, the project goes further and creates a window displaying a board of size _9x9_ with the hints of a given Sudoku board. 
It allows a text file with values to be converted into a 2D vector. Once displayed, the user can select a given grid location 
and input a value between _1-9_ or _"spacebar"_ or _"."_ to remove the current value. To solve, the user presses _"enter"_. It's important to note that a board can have more than one solution depending on the number of hints given and their position on the board with a 
minimum of 17 positions needed to find a solution.

## Summary
To reliably test the performance of the program, we can use a [dataset](https://www.kaggle.com/datasets/radcliffe/3-million-sudoku-puzzles-with-ratings) containing over 3 million example Sudoku Boards of size _9x9_, with their accompanying solutions, given clues, and difficulty levels. The data was then aggregated based on their difficulty and average clues per board:

Difficulty | #Score | #Average Clues |
--- | --- | --- |
Average | 2 &gt; σ &ge; 0 |  24.4 | 
Easy | 4 &gt; σ &ge; 2 | 25.1 | 
Medium | 6 &gt; σ &ge; 4 | 24.5 | 
Hard | 8 &ge; σ &gt; 6 | 24.3 | 

Each row containing a puzzle was then parsed into its own CSV for testing and launching the application. Our algorithm was run against each category of test boards using two methods for solving: Sequential and Concurrent. The first approach loaded in the data set and solved each row with each traversal of our total boards. The second approach, assigned each board to its own thread when passing a board as a reference, before finally joining all threads. The execution time was then calculated for both methods while ignoring I/O operations.

## Execution Overview
The following chart highlights the execution times for multiple boards per difficulty rating, with and without the use of threads. Notably, easier boards with greater _clues_ resulted in faster execution times. It's also important to note that fewer clues may take longer to compute, since the necessary values to backtrack increases significantly. However, trivial approaches to solving these boards may actually prove less resource-intensive and challenging overall.

<img width="544" alt="Screen Shot 2024-04-13 at 6 04 28 AM" src="https://github.com/halaway/sudoku-solver/assets/31904474/8b3dff46-3d9b-4fa6-9f21-aa003c6445ab">



## Features

- Uses SDL Graphics to create a window and display a 9x9 grid.
- Multi-Threading Asynchronous Operations.

## Run 

To execute the _main.cpp_: 

```
g++ -std=c++17 main.cpp -o prog -lSDL2 -lSDL2_ttf -ldl
./prog
```


## Usage

<img width="300" alt="Screen Shot 2024-04-13 at 11 02 08 PM" src="https://github.com/halaway/sudoku-solver/assets/31904474/a90c3758-871d-419a-bb91-b3fcb64241dd" align = "left">

<img width="300" alt="Screen Shot 2024-04-13 at 11 08 26 PM" src="https://github.com/halaway/sudoku-solver/assets/31904474/d034fcb1-6218-48b2-8a75-a65140e9bda9">


## Contributing

If you have a suggestion for what should be improved, your contributions will be greatly appreaciated. Simply: 
1. Fork the Project
2. Create your Feature Branch 
3. Commit your Changes
4. Push to the Branch 
5. Open a Pull Request


## Authors 
@donnolis


## Note
There aren't sufficient error cases for using grids of larger or smaller sizes. Also, the window is of a certain width and height, 
but, future improvements can be made to account for changes in window size as well as for changes in the Board size greater than or less than _9_.
The "OpenSans-Regular.ttf" or any suitable font will also have to be downloaded to use. 

