/*
    @file P018.py
    @author Austin Vandegriffe
    @date 2020-07-24
    @brief A few solutions to Project Euler question 18
    @pre N/A
    @style K&R, and "one true brace style" (OTBS), and '_' variable naming
/////////////////////////////////////////////////////////////////////
    @references
      ## [1] https://projecteuler.net/problem=18
*/

#include <iostream> 
    /*
        * std::cout
        * std::endl
    */

#include "Eigen/unsupported/Eigen/MatrixFunctions"
#include <fstream>
#include <sstream>
#include <string>

#define __VANDEGRIFFE_TIMER
#include "Vandegriffe.h"
    /*
        Vandegriffe_Timer::TimeIt
    */

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~ Solutions to Problem 18 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// It's not really readable but it's memory efficient! Recall that the upper
//// half of the matrix M is zero, i.e. not used.
uint64_t run(Eigen::MatrixXd M){
    int i,j,
        r = M.rows();
    for( i = r - 1; i >= 0; --i ){
        for( j = 0; j < i; ++j ){
            if( r-i-1 == 0 ){
                M(r-i-1,r-i+j) = M(i-1,j) + ( M(i,j) < M(i,j+1) ? M(i,j+1) : M(i,j) );
            } else{
                M(r-i-1,r-i+j) = M(i-1,j) + ( M(r-i-2,r-i-1+j) < M(r-i-2,r-i+j) ? M(r-i-2,r-i+j) : M(r-i-2,r-i-1+j) );
            }
            
        }
    }
    return M(r-2,r-1);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~ Define main() ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int main(){
    // Create timing object
    Vandegriffe_Timer::TimeIt timer;

    Eigen::MatrixXd M;

    {std::ifstream fin("P18_input.txt");
        std::string item, line;
        std::stringstream ss("");

        int triangle_height = 0;
        while( std::getline(fin, line, '\n') ){
            ++triangle_height;
        }
        fin.clear();
        fin.seekg(0,fin.beg);

        M = Eigen::MatrixXd::Zero(triangle_height,triangle_height);

        int i,j;
        for( i = 0; std::getline(fin, line, '\n'); ++i )
        {
            ss.clear();
            ss << line;
            for( j = 0; std::getline(ss, item, ' '); ++j ){
                M(i,j) = std::stoi(item);
            }
            triangle_height += 1;
        }
    }

    int i = 0;
    uint64_t output;
    timer.start();
    for( i=0; i < 1; ++i ){
        output = run(M);
    }
    timer.stop();
    std::cout << output << " in " << timer.lapse() << " seconds." << std::endl;   

    return 0;
}