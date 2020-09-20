/*
    @file P013.py
    @author Austin Vandegriffe
    @date 2020-07-24
    @brief A few solutions to Project Euler question 13
    @pre N/A
    @style K&R, and "one true brace style" (OTBS), and '_' variable naming
/////////////////////////////////////////////////////////////////////
    @references
      ## [1] https://projecteuler.net/problem=13
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
#include "BigInteger.h"
    /*
        * BigInteger
    */
#define __VANDEGRIFFE_TIMER
#include "Vandegriffe.h"
    /*
        Vandegriffe_Timer::TimeIt
    */

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~ Solutions to Problem 13 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
BigInteger run(){

    BigInteger total("0");

    std::ifstream fin("P13_input.txt");
        std::string line;
        
        while( std::getline(fin, line, '\n') ){
            total += BigInteger(line);
        }
    fin.close();

    return total;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~ Define main() ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int main(){
    // Create timing object
    Vandegriffe_Timer::TimeIt timer;

    BigInteger total("0");

    BigInteger output;
    timer.start();
    output = run();
    timer.stop();
    std::cout << output.operator std::string() << " in " << timer.lapse() << " seconds." << std::endl;    

    return 0;
}