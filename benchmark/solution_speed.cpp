#include "../Sudoko.h"          // Algorithm For Sudoku Board
#include <vector>
#include <string>
#include <mutex>
#include <queue>
#include <thread>               // Using Threads for Solving 



//g++ -std=c++17 solution_speed.cpp -o prog2 -lSDL2 -lSDL2 -lSDL2_ttf -ldl
// ./prog2

//std::ifstream testing_file("../tests/puzzlesList.csv");
std::ifstream testing_file("../benchmark/testing_speed/sudoku_0_2_score.csv"); 

// Runs Tests Using Threads
int main() {

    std::vector< std::vector<std::vector<std::string>> > puzzle;

    // Reading CSV to insert puzzle boards
    while (!testing_file.eof()) {
        std::vector<std::vector<std::string>> currentPuzzle = testCSV(testing_file);
        puzzle.push_back(currentPuzzle);
    }

     // Start timer
    auto start_time = std::chrono::steady_clock::now();
   // Creating an array of threads
    std::vector<std::thread> solver_threads;
    for ( auto& p : puzzle) {
        solver_threads.emplace_back([&p]() {
            SudukoSolves(p);
        });
    }

    // Join the solver threads
    for (auto& thread : solver_threads) {
        thread.join();
    }
    auto end_time = std::chrono::steady_clock::now();

    // Calculate total time
    auto total_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    std::cout << "Total time taken: " << total_time << " milliseconds" << std::endl;



    return 0;
}


//Runs Tests Without using Threads
int mainn(int argc, char *argv[]){
    
    // Array of puzzles to solve 
    std::vector< std::vector<std::vector<std::string>> > puzzle;

    // Reading CSV to insert puzzle boards
    while (!testing_file.eof()) {
        std::vector<std::vector<std::string>> currentPuzzle = testCSV(testing_file);
        puzzle.push_back(currentPuzzle);
    }

    // Begining Timer 
    auto start = std::chrono::steady_clock::now();

    for ( auto& puzzle_board : puzzle) {
       

        
        SudukoSolves(puzzle_board);
    }

    // Ending Timer for total excution time
    auto end = std::chrono::steady_clock::now();

   auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Total execution time: " << duration.count() << " milliseconds" << std::endl;

    
    

    //std::cout<<"hello"<<std::endl;
    


    return 1;
}