/*
    @file P05.py
    @author Austin Vandegriffe
    @date 2020-07-24
    @brief A few solutions to Project Euler question 5
    @pre N/A
    @style K&R, and "one true brace style" (OTBS), and '_' variable naming
/////////////////////////////////////////////////////////////////////
    @references
      ## [1] https://projecteuler.net/problem=5
*/

#include <iostream> /*
                        * std::cout
                        * std::endl
                    */


#define __VANDEGRIFFE_TIMER
#include "Vandegriffe.h"/*
                            Vandegriffe_Timer::TimeIt
                        */

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~ Solutions to Problem 5 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
uint64_t run(){
    uint64_t lower   = 1,
        upper   = 1,
        result  = 0;
    lower = 2*3*5*7*11*13*17*19;

    for(int i = 2; i <= 20; ++i){
        upper *= i;
    }
    bool is_div;
    for( result = lower; result <= upper; ++result ){
        is_div = true;
        for( int j = 2; j <= 20; ++j ){
            if( result % j != 0 ){
                is_div = false;
                break;
            }
        }
        if( is_div ){
            break;
        }
    }
    return result;
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
    std::cout << output << " in " << timer.lapse() << " seconds." << std::endl;    

    return 0;
}