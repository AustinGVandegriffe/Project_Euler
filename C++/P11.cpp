/*
    @file P011.py
    @author Austin Vandegriffe
    @date 2020-07-24
    @brief A few solutions to Project Euler question 11
    @pre N/A
    @style K&R, and "one true brace style" (OTBS), and '_' variable naming
/////////////////////////////////////////////////////////////////////
    @references
      ## [1] https://projecteuler.net/problem=11
*/

#include <iostream> 
    /*
        * std::cout
        * std::endl
    */
#include "Eigen/unsupported/Eigen/MatrixFunctions"  
    /*
        * Eigen::Matrix<T, int r, int c>
    */
#include <string>
    /*
        * std::stoi
    */
#include <fstream>
    /*
        * std::ifstream
    */

#define __VANDEGRIFFE_TIMER
#include "Vandegriffe.h"
    /*
        Vandegriffe_Timer::TimeIt
    */

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~ Solutions to Problem 11 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static const int BOX_WIDTH = 4;
uint64_t run(Eigen::MatrixXd& M){
    uint64_t max    = 0,
             // we have four directions to check.
             path_products[4];
    int r = M.rows(),
        c = M.cols();
    int i,j,k;
    bool valid_col, valid_row, valid_box;
    for( i = 0; i < r; ++i ){
        for( j = 0; j < c; ++j ){
            for( k = 0; k < BOX_WIDTH; ++k ){
                path_products[k] = 1;
            }
            valid_col = i < r - BOX_WIDTH;
            valid_row = j < c - BOX_WIDTH;
            valid_box = valid_col && valid_row;
            for( k = 0; k < BOX_WIDTH; ++k ){
                // Column product
                if( valid_col ){
                    path_products[0] *= M( i+k, j );
                }
                // Row product
                if( valid_row ){
                    path_products[1] *= M( i, j+k );
                }
                // Check if we have a valid box
                if( valid_box ){
                    // Top-Left-Bottom-Right product
                    path_products[2] *= M( i+k, j+k );
                    // Bottom-Left-Top-Right product
                    path_products[3] *= M( i+4-k, j+k );
                }
            }
            for( const uint64_t& prod : path_products ){
                if( i > max ){
                    max = i;
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
        for ( i = 0; std::getline(fin, line, '\n'); ++i)
        {
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