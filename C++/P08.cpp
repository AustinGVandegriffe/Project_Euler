/*
    @file P08.py
    @author Austin Vandegriffe
    @date 2020-07-24
    @brief A few solutions to Project Euler question 8
    @pre N/A
    @style K&R, and "one true brace style" (OTBS), and '_' variable naming
/////////////////////////////////////////////////////////////////////
    @references
      ## [1] https://projecteuler.net/problem=8
*/

#include <iostream> 
    /*
        * std::cout
        * std::endl
    */
#include <fstream>  
    /*
        * std::ifstream
    */
#include <string>   
    /*
        * std::getline
        * std::string
    */
#include <vector>   
    /*
        * std::vector<T>
    */

#define __VANDEGRIFFE_TIMER
#include "Vandegriffe.h"
    /*
        Vandegriffe_Timer::TimeIt
    */

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~ Solutions to Problem 8 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
uint64_t run( std::vector<int>& contents ){
    int i,j;
    uint64_t prod   = 1,
             max    = 0;
    for(i = 0; i < contents.size()-13; ++i){
        prod = contents[i];
        for(j = 1; j < 13; ++j){
            prod *= contents[i+j];
            if(prod == 0){
                break;
            }
        }
        if( prod > max ){
            max = prod;
        }
    }
    return max;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~ Define main() ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int main(){
    // Create timing object
    Vandegriffe_Timer::TimeIt timer;

    std::vector<int> contents;

    // Read in matrix of data
    {std::ifstream fin("P08_input.txt");
        for (std::string line; std::getline(fin, line, '\n'); )
        {
            for(const char& i : line){
                contents.push_back( (int)( i - '0' ) );
            }
        }
    }

    uint64_t output;
    timer.start();
    for(int i = 0; i < 100; ++i)
        output = run(contents);
    timer.stop();
    std::cout << output << " in " << timer.lapse() << " seconds." << std::endl;    

    return 0;
}