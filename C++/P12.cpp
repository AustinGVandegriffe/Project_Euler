// I WANT TO USE JSON

/*
    @file P012.py
    @author Austin Vandegriffe
    @date 2020-07-24
    @brief A few solutions to Project Euler question 12
    @pre N/A
    @style K&R, and "one true brace style" (OTBS), and '_' variable naming
/////////////////////////////////////////////////////////////////////
    @references
      ## [1] https://projecteuler.net/problem=12
*/

#include <iostream> 
    /*
        * std::cout
        * std::endl
    */

#define __VANDEGRIFFE_TIMER
#include "Vandegriffe.h"
    /*
        Vandegriffe_Timer::TimeIt
    */

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~ Solutions to Problem 12 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
uint64_t run(){
    return 0;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~ Define main() ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int main(){
    // Create timing object
    Vandegriffe_Timer::TimeIt timer;

    Eigen::MatrixXd M;

    // Read in matrix of data
    {std::ifstream fin("P11_input.txt");
        std::string item, line;
        std::stringstream ss;
        
        int r, c;
        fin >> r >> c;        
        M = Eigen::MatrixXd(r,c);
        
        std::getline(fin, line,'\n');
        
        int i, j;
        for ( i = 0; std::getline(fin, line, '\n'); ++i){
            ss.clear();
            ss << line;
            for( j = 0; std::getline(ss, item, ' '); ++j ){
                M(i,j) = std::stoi(item);
            }
            assert( j == r );
        }
    }

    uint64_t output;
    timer.start();
    output = run(M);
    timer.stop();
    std::cout << output << " in " << timer.lapse() << " seconds." << std::endl;    

    return 0;
}