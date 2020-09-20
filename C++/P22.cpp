/*
    @file P022.py
    @author Austin Vandegriffe
    @date 2020-07-24
    @brief A few solutions to Project Euler question 22
    @pre N/A
    @style K&R, and "one true brace style" (OTBS), and '_' variable naming
/////////////////////////////////////////////////////////////////////
    @references
      ## [1] https://projecteuler.net/problem=22
*/

#include <iostream> 
    /*
        * std::cout
        * std::endl
    */
#include <string>
    /*
        * std::stoi
    */
#include <fstream>
    /*
        * std::ifstream
    */
#include <algorithm>
    /*
        * std::remove
        * std::sort
    */
#include <vector>
    /*
        std::vector
    */

#define __VANDEGRIFFE_TIMER
#include "Vandegriffe.h"
    /*
        Vandegriffe_Timer::TimeIt
    */

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~ Solutions to Problem 22 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
const int CHAR_OFFSET = 'A' - 1;
uint64_t run(){
    std::vector<std::string> storage;

    {std::ifstream fin("P22_input.txt");
        std::string line;
        while( std::getline(fin, line,',' ) ){
            line.erase( std::remove(line.begin(), line.end(), '"'), line.end() );
            storage.push_back(line);
        }
    }
    std::sort( storage.begin(), storage.end() );

    uint64_t t_sum;
    uint64_t sum = 0;

    int storage_size = storage.size();
    for( int i = 0; i < storage_size; ++i ){
        t_sum = 0;
        // std::cout << line << std::endl;
        for( char const& c : storage[i] ){
            t_sum += c - CHAR_OFFSET;
        }
        sum += ( (i+1) * t_sum );
    }
    return sum;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~ Define main() ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int main(){
    // Create timing object
    Vandegriffe_Timer::TimeIt timer;

    uint64_t output;
    timer.start();
    output = run();
    timer.stop();
    std::cout << output << " in " << timer.lapse()/1000 << " seconds." << std::endl;    

    return 0;
}