# Sudoku Solver
Applying Data Structures and SDL Graphics

## Dependencies
- Windows 10 / Mac
- c++11

## Description 

Firstly, this project uses a Backtracking algortithm to find the solution of a given Sudoku Board in a the form of a 2D vector. 
A board can be of any size NxN, however, boards _4x4_, _6x6_, _9x9_, and _16x16_ lead to possible solutions where sub-grids are taken 
into account to ensure no number is repeated, coinciding with the rules of Sudoku. All other grid sizes do not account for 
repeating values within sub-grids. If a solution is found, the vector is updated with the possible solutions. 

Secondly, the project goes a step further and creates a window displaying a board of size _9x9_ with the hints of a given Sudoku board. 
It allows for a text file with values to be converted into a 2D vector. Once diplayed, the user can select a given grid location 
and input a value between _1-9_ or _"spacebar"_ or _"."_ to remove current value. To solve, the user presses _"enter"_. It's important to note 
that a board can have more than one solution depending on the number of hints given and their position on the board with a 
minimum of 17 positions needed to find a solution.

## Features

- Uses SDL Graphics to create a window and display a 9x9 grid.

## Run 

To exectute the _main.cpp_, open the terminal and enter: 

- g++ -std=c++17 main.cpp -o prog -lSDL2 -lSDL2_ttf -ldl
- ./prog


## Usage


<img width="300" alt="Screen Shot 2023-01-21 at 7 24 53 AM" src="https://user-images.githubusercontent.com/31904474/213866683-88c50e86-8313-42d5-8c67-e394e533902f.png" align = "left">
<img width="300" alt="SudukSolvedSc" src="https://user-images.githubusercontent.com/31904474/213866651-be66bf47-4b53-4f19-b7eb-46a12f9d82bb.png">


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
but, future impovements can be made to account for changes in window size as well as for changes in the Board size greater than or less than _9_. 

