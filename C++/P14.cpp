/*
    @file P014.py
    @author Austin Vandegriffe
    @date 2020-07-24
    @brief A few solutions to Project Euler question 14
    @pre N/A
    @style K&R, and "one true brace style" (OTBS), and '_' variable naming
/////////////////////////////////////////////////////////////////////
    @references
      ## [1] https://projecteuler.net/problem=14
*/

#include <iostream> 
    /*
        * std::cout
        * std::endl
    */

#include <map>

#define __VANDEGRIFFE_TIMER
#include "Vandegriffe.h"
    /*
        Vandegriffe_Timer::TimeIt
    */

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~ Solutions to Problem 14 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int run( std::map<int, int>& storage ){
    int i, collatz_count, max = 0;
    uint64_t collatz;
    for( i = 1; i < 1000000; ++i ){
        collatz = i;
        collatz_count = 0;
        while( collatz > 1 ){
            if( storage.count(collatz) > 0 ){
                collatz_count += storage[collatz];
                collatz = 1;
            }else{
                if( collatz % 2 == 0 ){
                    collatz /= 2;
                }else{
                    collatz = 3*collatz + 1;
                }
                collatz_count += 1;
            }
        }
        storage[i] = collatz_count;
        if( collatz_count > storage[max] ){
            max = i;
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

    std::map<int, int> storage;

    uint64_t output;
    timer.start();
    output = run(storage);
    timer.stop();
    std::cout << output << " in " << timer.lapse() << " seconds." << std::endl;    

    return 0;
}