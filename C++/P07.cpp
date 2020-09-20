/*
    @file P07.py
    @author Austin Vandegriffe
    @date 2020-07-24
    @brief A few solutions to Project Euler question 7
    @pre N/A
    @style K&R, and "one true brace style" (OTBS), and '_' variable naming
/////////////////////////////////////////////////////////////////////
    @references
      ## [1] https://projecteuler.net/problem=7
*/

#include <iostream> 
    /*
        * std::cout
        * std::endl
    */
#include <math.h>
    /*
        * std::sqrt
    */

#define __VANDEGRIFFE_TIMER
#include "Vandegriffe.h"
    /*
        Vandegriffe_Timer::TimeIt
    */

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~ Make Prime Checker  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// A GOOD CHECKER IS THE MILLER-RABIN TEST, *NOT* IMPLEMENTED HERE
bool is_prime(uint64_t n){
    bool t_is_prime = true;
    if( n <= 1 ){
        t_is_prime = false;
    }else if( n <= 3 ){
        t_is_prime = true;
    }
    else{
        uint64_t sqrt_n = std::sqrt(n)+1;
        for( uint64_t i = 3; i < sqrt_n; i += 2){
            if ( n % i == 0 ){
                t_is_prime = false;
                break;
            }
        }
    }
    return t_is_prime;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~ Solutions to Problem 7 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
uint64_t run(){
    int n       = 19001,//10001,
        count   = 1; // Precount the prime 2
    uint64_t i = 3;
    bool not_done = true;
    while( not_done ){
        count += is_prime(i);
        not_done = ( count < n );
        i += 2*not_done;
    }
    return i;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~ Define main() ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int main(){
    // Create timing object
    Vandegriffe_Timer::TimeIt timer;

    uint64_t output;
    timer.start();
    for( int i = 0; i < 100; ++i )
        output = run();
    timer.stop();
    std::cout << output << " in " << timer.lapse() << " seconds." << std::endl;    

    return 0;
}