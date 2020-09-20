/*
    @file P04.py
    @author Austin Vandegriffe
    @date 2020-07-24
    @brief A few solutions to Project Euler question 4
    @pre N/A
    @style K&R, and "one true brace style" (OTBS), and '_' variable naming
/////////////////////////////////////////////////////////////////////
    @references
      ## [1] https://projecteuler.net/problem=4
*/

#include <iostream> /*
                        * std::cout
                        * std::endl
                    */

#include <vector>   /*
                        * std::vector<T>
                    */

#define __VANDEGRIFFE_TIMER
#include "Vandegriffe.h"/*
                            Vandegriffe_Timer::TimeIt
                        */


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~ Make Palindrome Checker  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// THERE ARE MORE SOPHISTICATED ALGORITHMS AND DOMAIN RESTRICTIONS
bool is_palindrome(int n){
    std::vector<int> digits;
    while( n != 0 ){
        digits.push_back(n % 10);
        n /= 10;
    }
    short size = digits.size();
    short parse_limit = size/2;

    bool t_is_palindrome = true;
    for( int i = 0; i < parse_limit; ++i ){
        if( digits[i] != digits[size-i-1] ){
            t_is_palindrome = false;
            break;
        }
    }
    return t_is_palindrome;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~ Solutions to Problem 4 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int run(){
    int t_prod  = 0,
        max     = 0;
    for(int i = 100; i <= 999; ++i){
        for(int j = i; j <= 999; ++j){
            t_prod = i*j;
            if( is_palindrome( t_prod ) ){
                if( t_prod > max ){
                    max = t_prod;
                }
            }
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

    int output;
    timer.start();
    output = run();
    timer.stop();
    std::cout << output << " in " << timer.lapse() << " seconds." << std::endl;    

    return 0;
}