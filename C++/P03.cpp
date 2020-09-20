/*
    @file P03.py
    @author Austin Vandegriffe
    @date 2020-07-24
    @brief A few solutions to Project Euler question 3
    @pre N/A
    @style K&R, and "one true brace style" (OTBS), and '_' variable naming
/////////////////////////////////////////////////////////////////////
    @references
      ## [1] https://projecteuler.net/problem=3
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
//~~~~~ Solutions to Problem 3 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
uint64_t run1(){
    uint64_t max = 0,
        n = 600851475143,
        sqrt_n = std::sqrt(n);
    for( uint64_t i = 2; i < sqrt_n; ++i ){
        if( is_prime(i) ){
            if( n % i == 0 ){
                max = i;
            }
        }
    }
    return max;
}

uint64_t run2(){
    uint64_t n = 600851475143;
    for( uint64_t i = 2; n > 1; ++i ){
        if( is_prime(i) ){
            while( n % i == 0 ){
                n /= i;
            }
        }
    }
    return i-1;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~ Define main() ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int main(){
    // Create timing object
    Vandegriffe_Timer::TimeIt timer;

    uint64_t output;
    timer.start();
    output = run1();
    timer.stop();
    std::cout << output << " in " << timer.lapse() << " seconds." << std::endl;    

    return 0;
}