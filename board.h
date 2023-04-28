#ifndef BOARD_H
#define BOARD_H


//Window Width and Height 
const int WIDTH = 450, HEIGHT = 500;
//const int WIDTH = 800, HEIGHT = 800;

//Grid Size
const int GridSize = 9;
//const int GridSize = 16;

class SudukoBoard{
public:

    //Constructor 
    SudukoBoard(){


        SDL_Init(SDL_INIT_EVERYTHING);
        TTF_Init();
        gFont = TTF_OpenFont("OpenSans-Regular.ttf", 30);

        //Window Initialize
        SDL_Window *window = SDL_CreateWindow( "Suduko Solver", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH,HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI );
        if ( NULL == window ){
            std::cout << "Could Not Create Window: " << SDL_GetError() << std::endl;
            exit(1);
        }
        //Renderer
        renderer = SDL_CreateRenderer(window, -1, 0);

        //Keyboard States
        const Uint8* state = SDL_GetKeyboardState(NULL);

        //Setting Color
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        //Clearing Screen
        SDL_RenderClear(renderer);

    }

    //Drawing N x N Grid
    void drawBoard( std::vector<std::vector<std::string> > &vect){

        //COPY    
        matrixBoard = vect;

        SDL_Rect rect;
        //width
        rect.w = 100;
        //Height
        rect.h = 100;

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        //Traverse 2D Vector
        for(int i = 0; i < GridSize; i++){
                for(int j = 0; j < GridSize; j++ ){
                    rect.x =  j * rect.w;
                    rect.y = i * rect.h;
                    SDL_SetRenderDrawColor(renderer, 0,0,0,0);
                    SDL_RenderDrawRect(renderer, &rect);
                    

                    //Create New Rectangle
                    SDL_Rect newRect;
                    newRect.x = j * 100;
                    newRect.y = i * 100;

                    newRect.h = 100;
                    newRect.w = 100;

                    //String value at index of Board
                    std::string str = matrixBoard[i][j];

                    //String to char pointer
                    char *c = toChar ( str );

                    //Create new SDL Surface
                    SDL_Surface * manyMessages = TTF_RenderText_Solid(gFont, c, black);
                    
                    //Create new SDL Textures
                    SDL_Texture *manyTextures = SDL_CreateTextureFromSurface(renderer,manyMessages);

                    //Render Copy
                    SDL_RenderCopy(renderer, manyTextures, NULL, &newRect);
                }
            }
            SDL_RenderPresent( renderer );
        
    }

    void updateBoard(int xPos, int yPos, const Uint8* state, SDL_Event windowEvent ){
        int rows = yPos / 50;
        int cols = xPos / 50;


        // Rectangle to update location
        SDL_Rect rect;
        rect.h = 100;
        rect.w = 100;

        //Setting Color
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        //Clearing Screen 
        SDL_RenderClear(renderer);


        //ONE IS ENTERED
        if(state [SDL_SCANCODE_1] ){ 
            matrixBoard[rows][cols] = "1";
        }
        //TWO IS ENTERED
        if(state [SDL_SCANCODE_2] ){
            matrixBoard[rows][cols] = "2";
        }
        
        //THREE IS ENTERED
        if(state [SDL_SCANCODE_3] ){
            matrixBoard[rows][cols] = "3";
        }

        //FOUR IS ENTERED 
        if(state [SDL_SCANCODE_4] ){
            matrixBoard[rows][cols] = "4";
        }

        //FIVE IS ENTERED
        if(state [SDL_SCANCODE_5] ){
            matrixBoard[rows][cols] = "5";
        }

        //SIX IS ENTERED
        if(state [SDL_SCANCODE_6] ){
            matrixBoard[rows][cols] = "6";
        }
        
        //SEVEN IS ENTERED
        if(state [SDL_SCANCODE_7] ){
            matrixBoard[rows][cols] = "7";
        }   

        //EIGHT IS ENTERED
        if(state [SDL_SCANCODE_8] ){
            matrixBoard[rows][cols] = "8";
        }

        //NINE IS ENTERED
        if(state [SDL_SCANCODE_9] ){
            matrixBoard[rows][cols] = "9";
        }

        //EMPTY SPACE
        if(windowEvent.button.button == SDL_SCANCODE_SPACE || windowEvent.button.button == SDL_SCANCODE_PERIOD){
            matrixBoard[rows][cols] = ".";
        }   


        //SOLVE FOR RETURN KEY
        if( windowEvent.button.button == SDL_SCANCODE_RETURN ){
            SudukoSolves(matrixBoard);    
        }

        rect.x = cols * 100;
        rect.y = rows * 100;

        SDL_SetRenderDrawColor(renderer, 0,0,0,0);
        SDL_RenderDrawRect(renderer, &rect);
        
        for(int i = 0; i < GridSize; i++){
                for(int j = 0; j < GridSize; j++ ){
                    rect.x =  j * rect.w;
                    rect.y = i * rect.h;
                    SDL_SetRenderDrawColor(renderer, 0,0,0,0);
                    SDL_RenderDrawRect(renderer, &rect);
                    
                    //Create New Rectangle
                    SDL_Rect newRect;
                    newRect.x = j * 100;
                    newRect.y = i * 100;

                    newRect.h = 100;
                    newRect.w = 100;

                    //String value at index of Board
                    std::string str = matrixBoard[i][j];

                    //String to char pointer
                    char *c = toChar ( str );

                    //Create new SDL Surface
                    SDL_Surface * manyMessages = TTF_RenderText_Solid(gFont, c, black);
                    
                    //Create new SDL Textures
                    SDL_Texture *manyTextures = SDL_CreateTextureFromSurface(renderer,manyMessages);

                    //Render Copy
                    SDL_RenderCopy(renderer, manyTextures, NULL, &newRect);
                }
            }

       SDL_RenderPresent( renderer );

    }

    //Destructor    
    ~SudukoBoard(){

        SDL_DestroyWindow( window );
        SDL_Quit();
    }
    
    
private:

    //Initial Font 
    TTF_Font *gFont;

    //Black Color
    SDL_Color black = {0,0,0};

    //Board Matrix
    std::vector<std::vector<std::string> > matrixBoard;

    //Window 
    SDL_Window *window;

    //Renderer
    SDL_Renderer *renderer;

};





#endif
