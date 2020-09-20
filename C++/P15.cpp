/*
    @file P015.py
    @author Austin Vandegriffe
    @date 2020-07-24
    @brief A few solutions to Project Euler question 15
    @pre N/A
    @style K&R, and "one true brace style" (OTBS), and '_' variable naming
/////////////////////////////////////////////////////////////////////
    @references
      ## [1] https://projecteuler.net/problem=15
*/

#include <iostream> 
    /*
        * std::cout
        * std::endl
    */

#define __VANDEGRIFFE_TIMER
#include "Vandegriffe.h"
    /*
        Vandegriffe_Timer::TimeIt
    */

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~ Solutions to Problem 15 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
const int GRID_SIZE = 20;
uint64_t combinatorics(){
    // Every path from the upper left to lower right consists of
    //// 2N steps, N of which are down and N of which are right
    uint64_t path_count = 1;
    for(int i = 0; i < GRID_SIZE; ++i ){
        path_count *= (2*GRID_SIZE) - i;
        path_count /= i + 1;
    }
    return path_count;
}

uint64_t backward(){
    // Declare iterators.
    int i,j;
    // Each node has a count to the end. In an NxN grid there are (N+1)x(N+1) 
    //// nodes. We now build these paths dynamically.
    uint64_t grid[GRID_SIZE+1][GRID_SIZE+1];
    // Since we can only move down and right, the bottom and right boundary have
    //// only one path to take.
    for( i = 0; i < GRID_SIZE; ++i ){
        grid[GRID_SIZE][i] = grid[i][GRID_SIZE] = 1;
    }
    // Start counting backward from the lower right corner.
    for( i = GRID_SIZE - 1; i >= 0; --i ){
        for( j = GRID_SIZE - 1; j >= 0; --j ){
            grid[i][j] = grid[i+1][j] + grid[i][j+1];
        }
    }
    return grid[0][0];
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~ Define main() ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int main(){
    // Create timing object
    Vandegriffe_Timer::TimeIt timer;

    uint64_t output;
    timer.start();
    output = backward();
    timer.stop();
    std::cout << output << " in " << timer.lapse() << " seconds." << std::endl;    

    return 0;
}