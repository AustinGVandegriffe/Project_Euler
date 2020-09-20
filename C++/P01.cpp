/*
    @file P01.py
    @author Austin Vandegriffe
    @date 2020-07-24
    @brief A few solutions to Project Euler question 1
    @pre N/A
    @style K&R, and "one true brace style" (OTBS), and '_' variable naming
/////////////////////////////////////////////////////////////////////
    @references
      ## [1] https://projecteuler.net/problem=1
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
//~~~~~ Solutions to Problem 1 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// @param n : Constant upper bound for iteration
// @return : sum of integers below n which are divisible by 3 or 5
int branched(int const& n){
    int sm = 0;
    for( int x = 0; x < n; ++x ){
        if( x % 3 == 0 || x % 5 == 0 ){
            sm += x;
        }
    }
    return sm;
}

// @param n : Constant upper bound for iteration
// @return : sum of integers below n which are divisible by 3 or 5
int ternary(int const& n){
    int sm = 0;
    for( int x = 0; x < n; ++x ){
        sm += ((x % 5 == 0) || (x % 3 == 0)) ? x : 0;
    }
    return sm;
}

// @param n : Constant upper bound for iteration
// @return : sum of integers below n which are divisible by 3 or 5
int branchless(int const& n){
    int sm = 0;
    for( int x = 0; x < n; ++x ){
        sm += ( x % 3 == 0 || x % 5 == 0 ) * x;
    }
    return sm;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~ Define main() ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int main(){
    // Create timing object
    Vandegriffe_Timer::TimeIt timer;

    // Create a jump table for function pointers
    typedef int (*fn_ptr)(int const&);
    fn_ptr implementations[] = {branched, ternary, branchless};

    int n = 1000;
    for(auto f : implementations){
        timer.start();
        for( int i = 0; i < 100000; ++i ){
            f(n);
        }
        timer.stop();
        std::cout << f(n) << " in " << timer.lapse() << " seconds." << std::endl;    
    }

    return 0;
}