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


int main(int argc, char *argv[]){
    
    //Matrix Board
    std::vector<std::vector<std::string> > matrixBoard = CreateVect(GridSize);
    
    //Create 9 x 9 array from text file
    matrixBoard = readIn(fin, 9);

    //Create Sudoku Board Object 
    SudukoBoard gridBoard; 

    //Drawing 9 x 9 board 
    gridBoard.drawBoard(matrixBoard);

    //Keyboard Status 
    const Uint8* state = SDL_GetKeyboardState(NULL);

    //Track Cursor Position coordindates
    int xPos, yPos = 0;


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
    
        //Update Board Accordingly to Input 
        gridBoard.updateBoard(xPos, yPos, state, windowEvent);

    }

}
