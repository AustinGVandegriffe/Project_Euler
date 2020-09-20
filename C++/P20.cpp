/*
    @file P020.py
    @author Austin Vandegriffe
    @date 2020-07-24
    @brief A few solutions to Project Euler question 20
    @pre N/A
    @style K&R, and "one true brace style" (OTBS), and '_' variable naming
/////////////////////////////////////////////////////////////////////
    @references
      ## [1] https://projecteuler.net/problem=20
*/

#include <iostream> 
    /*
        * std::cout
        * std::endl
    */

#include "BigInteger.h"
#include <string>

#define __VANDEGRIFFE_TIMER
#include "Vandegriffe.h"
    /*
        Vandegriffe_Timer::TimeIt
    */

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~ Solutions to Problem 20 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// It's not really readable but it's memory efficient! Recall that the upper
//// half of the matrix M is zero, i.e. not used.
int run(){
    int i, sum = 0;
    BigInteger x("100");
    for( i = 0; i < 100; ++i ){
        x *= (100-i);
    }

    std::string str(x.getNumber());
    //* Use char pointers
    char* end = &str[str.size() - 1];
    char* itr = &str[0];
    while( itr != end ){
        sum += *itr - '0';
        ++itr;
    }
    //*/
    /* Or string::iterator
    for( std::string::iterator itr = str.begin(); itr != str.end(); ++itr ){
        sum += *itr - '0';
    }
    //*/

    return sum;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~ Define main() ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int main(){
    // Create timing object
    Vandegriffe_Timer::TimeIt timer;

    int output;
    timer.start();
    output = run();
    timer.stop();
    std::cout << output << " in " << timer.lapse() << " seconds." << std::endl;   

    return 0;
}