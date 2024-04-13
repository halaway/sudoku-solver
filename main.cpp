#include <iostream>
#include <SDL2/SDL.h>       //SDL Library for initializing and shutdown function
#include <SDL2/SDL_image.h> //Images and Graphics
#include <SDL2/SDL_timer.h> //SDL Delay() functions
#include <SDL2/SDL_ttf.h>   //Fonts Display 

#include "Sudoko.h"         // Algorithm For Sudoku Board
#include "board.h"          // Board Display
#include <vector>
#include <string>

std::ifstream fin("file.txt"); //INPUT FILE UNSOLVED BOARD

std::ifstream file_name("tests/example10.csv"); // INPUT FILE EXAMPLE 3


//g++ -std=c++17 main.cpp -o prog -lSDL2 -lSDL2 -lSDL2_ttf -ldl
// ./prog


int main(int argc, char *argv[]){
    
    //Matrix Board
    std::vector<std::vector<std::string> > matrixBoard = CreateVect(GridSize);
    
    //Create 9 x 9 array from text file
    //matrixBoard = readIn(fin, 9);

    //Creating 9 x 9 array from CSV file
    matrixBoard = boardMatrix(file_name);



    //Create Sudoku Board Object 
    SudukoBoard gridBoard; 

    //Drawing 9 x 9 board 
    gridBoard.drawBoard(matrixBoard);

    //Keyboard Status 
    const Uint8* state = SDL_GetKeyboardState(NULL);

    //Track Cursor Position coordindates
    int xPos, yPos = 0;

    //EDITTED
    //Event Tracking 
    SDL_Event windowEvent;
    gridBoard.updateBoard(xPos, yPos, state, windowEvent);
    
  
    
    while(true){

        //Event Tracking 
        SDL_Event windowEvent;

        //Mouse Click Buttons
        Uint32 buttons;
        
        //Store Mouse click Coordinate
        buttons = SDL_GetMouseState(&xPos, &yPos);
        
        //Function pass reference to window event object
        if( SDL_PollEvent( &windowEvent ) ){
            //If some quit event has been triggered 
            if ( SDL_QUIT == windowEvent.type){
                break;
            }
        }

        //Update Board Accordingly & Check Board State
        if( gridBoard.pressedKeys(state) && !gridBoard.getSolvedState() ){
            gridBoard.updateBoard(xPos, yPos, state, windowEvent);
        }
    
        //Update Board Accordingly to Input 
        //gridBoard.updateBoard(xPos, yPos, state, windowEvent);

    }

}
