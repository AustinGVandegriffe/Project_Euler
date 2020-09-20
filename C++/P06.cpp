/*
    @file P06.py
    @author Austin Vandegriffe
    @date 2020-07-24
    @brief A few solutions to Project Euler question 6
    @pre N/A
    @style K&R, and "one true brace style" (OTBS), and '_' variable naming
/////////////////////////////////////////////////////////////////////
    @references
      ## [1] https://projecteuler.net/problem=6
*/

#include <iostream> /*
                        * std::cout
                        * std::endl
                    */
#include <math.h>

#define __VANDEGRIFFE_TIMER
#include "Vandegriffe.h"/*
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
//~~~~~ Solutions to Problem 6 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
uint64_t run(){
    int n = 100;
    uint64_t sum1 = n*(n+1)/2,
             sum2 = sum1*(2*n+1)/3;
    return std::pow(sum1,2) - sum2;
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