#include <iostream>

//SDL Library for initializing and shutdown function
#include <SDL2/SDL.h>

//Images and Graphics
#include <SDL2/SDL_image.h>

//SDL Delay() functions
#include <SDL2/SDL_timer.h>

//Font Features
#include <SDL2/SDL_ttf.h>

#include <string>
#include <vector>
#include <stdio.h>
#include "Sudoko.h"


using namespace std;



//Window Width and Height 
const int WIDTH = 450, HEIGHT = 500;


//Grid Size
const int GridSize = 9;




/**
 * Function to Draw Grid and Display values within 2D Vector 
 * @param vect a 2D Vector 
 * @param rectBox a rectangle with starting coordinates
 * @param renderer pointer to SDL Renderer
 * @param gFont TTF Font with selected font 
 * @param bBlack changeable black color font
 * Draws 9X9 Board with values stored in vector
 */
void DrawBoard( std::vector<std::vector<std::string> > &vect, SDL_Rect &rectBox, SDL_Renderer *renderer, TTF_Font* gFont, SDL_Color bBlack){
   
    //Traverse 2D Vector
    for(int i = 0; i < GridSize; i++){
            for(int j = 0; j < GridSize; j++ ){
                rectBox.x =  j * rectBox.w;
                rectBox.y = i * rectBox.h;
                SDL_SetRenderDrawColor(renderer, 0,0,0,0);
                SDL_RenderDrawRect(renderer, &rectBox);
                

                //Create New Rectangle
                SDL_Rect newRect;
                newRect.x = j * 100;
                newRect.y = i * 100;

                newRect.h = 100;
                newRect.w = 100;

                //String value at index of Board
                std::string str = vect[i][j];

                //String to char pointer
                char *c = toChar ( str );

                //Create new SDL Surface
                SDL_Surface * manyMessages = TTF_RenderText_Solid(gFont, c, bBlack);
                
                //Create new SDL Textures
                SDL_Texture *manyTextures = SDL_CreateTextureFromSurface(renderer,manyMessages);

                //Render Copy
                SDL_RenderCopy(renderer, manyTextures, NULL, &newRect);

        }
    }

}



// g++ -std=c++17 main.cpp -o prog -lSDL2 -lSDL2_ttf -ldl
// ./prog

int main( int argc, char *argv[] ){


  
    //Testing a new Sudoku Board
  
    //Create New 2D Vector of size 9
    auto vect = CreateVect(GridSize);
 
    //Open text file containing sudoku board to be solved 
    std::ifstream fin("file.txt");

    //Create 2D vector from input file
    vect = readIn(fin, 9);


    //SDL Black Color
    SDL_Color black = {0,0,0};

    //Initializing SDL with all
    SDL_Init(SDL_INIT_EVERYTHING);
  
    TTF_Init();

    //Initialize font and set size 
    TTF_Font* gFont = TTF_OpenFont("OpenSans-Regular.ttf", 30);

    //Create Window
    SDL_Window *window = SDL_CreateWindow( "Suduko Solver", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH,HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI );
    if ( NULL == window ){
        //If window is null, something has gone wrong
        std::cout << "Could Not Create Window: " << SDL_GetError() << std::endl;
        return 1;
    }
   

   //New Renderer
   SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

    //Rectangle to create dimensions of each individual grid 
    SDL_Rect rectBox;
   
    //Width
    rectBox.w = 100;
    //Height
    rectBox.h = 100;

    //Unsigned 8 bit unsigned integer to track Keyboard Input
    const Uint8* state = SDL_GetKeyboardState(NULL);

    //Mouse Coordinates
    int x , y = 0;

    //Board Coard position
    int row, col;

    //Keep running until while break
    while( true ){
        
        //Event Tracking 
        SDL_Event windowEvent;

        //Mouse Click Buttons
        Uint32 buttons;
        
        //Store Mouse click Coordinate
        buttons = SDL_GetMouseState(&x, &y);
        
        //Function pass reference to window event object
        if( SDL_PollEvent( &windowEvent ) ){
            //If some quit event has been triggered 
            if ( SDL_QUIT == windowEvent.type){
                break;
            }
        }
        // ( 1 ) Create Window

        // ( 2 ) Handle Updates - Logic 

        // ( 3 ) Clear and Draw the screen 


        //Set Background Color to white
        SDL_SetRenderDrawColor(renderer, 255, 255, 255 , 0);
        
        //Clear Screen
        SDL_RenderClear( renderer );

        //Draw 9 x 9 Grid & Display Board
        DrawBoard(vect, rectBox, renderer,gFont, black);

        
        //Check Location of Mouse Click
        if(windowEvent.button.button == SDL_BUTTON_LEFT){      
            //std::cout<<"Left Mouse was Clicked at: ("<<x<<", "<<y<<")"<<endl;
        }

        //CHECKING FOR INPUT

        //ONE IS ENTERED
        if(state [SDL_SCANCODE_1] ){ 
            //std::cout<<"0 is being entered at: ("<<x<<", "<<y<<")"<<std::endl;
            //std::cout<<"fe"<<endl;
             row = y / 50;
             col = x / 50;
             vect[row][col] = "1";
        }
        //TWO IS ENTERED
        if(state [SDL_SCANCODE_2] ){
            row = y / 50;
            col = x / 50;
            vect[row][col] = "2";
        }
        
        //THREE IS ENTERED
        if(state [SDL_SCANCODE_3] ){
            row = y / 50;
            col = x / 50;
            vect[row][col] = "3";
        }

        //FOUR IS ENTERED 
        if(state [SDL_SCANCODE_4] ){
            row = y / 50;
            col = x / 50;
            vect[row][col] = "4";
        }

        //FIVE IS ENTERED
        if(state [SDL_SCANCODE_5] ){
            row = y / 50;
            col = x / 50;
            vect[row][col] = "5";
        }

        //SIX IS ENTERED
        if(state [SDL_SCANCODE_6] ){
            row = y / 50;
            col = x / 50;
            vect[row][col] = "6";
        }
        
        //SEVEN IS ENTERED
        if(state [SDL_SCANCODE_7] ){
            row = y / 50;
            col = x / 50;
            vect[row][col] = "7";
        }   

        //EIGHT IS ENTERED
        if(state [SDL_SCANCODE_8] ){
            row = y / 50;
            col = x / 50;
            vect[row][col] = "8";
        }

        //NINE IS ENTERED
        if(state [SDL_SCANCODE_9] ){
            row = y / 50;
            col = x / 50;
            vect[row][col] = "9";
        }

        //EMPTY SPACE
        if(windowEvent.button.button == SDL_SCANCODE_SPACE || windowEvent.button.button == SDL_SCANCODE_PERIOD){
            row = y / 50;
            col = x / 50;
            vect[row][col] = ".";
        }
       
        //If enter key is pressed, board will attempt solution
        if( windowEvent.button.button == SDL_SCANCODE_RETURN ){  
            SudukoSolves(vect);
        }



        SDL_RenderPresent( renderer );

    }
    SDL_DestroyWindow( window );
    SDL_Quit();


    return EXIT_SUCCESS;
}


