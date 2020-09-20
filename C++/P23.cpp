/*
    @file P023.py
    @author Austin Vandegriffe
    @date 2020-07-24
    @brief A few solutions to Project Euler question 23
    @pre N/A
    @style K&R, and "one true brace style" (OTBS), and '_' variable naming
/////////////////////////////////////////////////////////////////////
    @references
      ## [1] https://projecteuler.net/problem=23
*/

#include <iostream> 
    /*
        * std::cout
        * std::endl
    */

#include <math.h>
    /*
        std::sqrt
    */

#define __VANDEGRIFFE_TIMER
#include "Vandegriffe.h"
    /*
        Vandegriffe_Timer::TimeIt
    */

#define __VANDEGRIFFE_PRIME
#include "ProjectEuler.h"


const int LBOUND = 24,
          UBOUND = 28123;
const project_euler::Prime_Generator PRIMES(UBOUND);
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~ Support Function(s) to Problem 23 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*
    THE MATHEMATICS:
        Let d(*) be the function which sums (improper)factors. Let p be prime, 
        then
            d(p) = 1 + p
        and 
            d(p^{t}) = 1 + p + ... + p^{t}

        \implies p*d(p^{t}) - d(p^{t}) = (p-1)*d(p^{t}) = p^{t+1} - 1
        \implies d(p^{t}) = \frac{p^{t+1} - 1}{p-1}

        Now, the fundamental theorem of arithmetic gives us, for every positive
        integer, a prime factorization and, hence, a "coprime product", i.e. for
        all positive integers z there exists a {c1, c2} \subset \mathbb{Z} such
        that z = c1*c2 (just take the product of half the primes for c1 and the
        product of the other half for c2). What is d(c1*c2)?

        d(z) = \sum\limits_{d|z} d = \sum\limits_{d1|c1}\sum\limits_{d2|c2} d2*d1
             = \sum\limits_{d2|c2} d2 * [\sum\limits_{d1|c1} d1]
             = [\sum\limits_{d1|c1} d1] * [ \sum\limits_{d2|c2} d2 ]
             = d(c1) * d(c2)
        
        Taking the coprimes to be p_{i}^{n_{i}} and \Pi_{j >= i+1} p_{j}^{n_{j}}
        we get the recursive formula
            d(n) = t(p_{1}^{n_{1}})*t(\Pi_{j >= 2} p_{j}^{n_{j}})
                 = t(p_{1}^{n_{1}})*t(p_{2}^{n_{2}})*t(\Pi_{j >= 3} p_{j}^{n_{j}})
                 ...
                 = \Pi_{j >= 1} t(p_{j}^{n_{j}})
                 = \Pi_{j >= 1} \frac{p_{j}^{n_{j}+1} - 1}{p_{j}-1}
        
*/
uint64_t factor_sum( uint64_t n ){
    uint64_t sum = 1;
    uint64_t p_sup_n_j;
    bool divisor(false);
    for( uint64_t const& p_j : PRIMES.get_prime_list() ){
        if( n <= 1){
            break;
        }
        p_sup_n_j = p_j;
        divisor = false;
        while( n % p_j == 0 && (divisor = true) ){
            p_sup_n_j *= p_j;
            n /= p_j;
        }
        if( divisor ){
            sum *= ( ( p_sup_n_j - 1 ) / (p_j - 1) );
        }
    }
    return sum;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~ Solutions to Problem 23 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
uint64_t run(){
    uint64_t i;
    std::vector<uint64_t> abundant;
    for( i = 1; i < UBOUND; ++i ){
        if( ( factor_sum(i) - i ) > i ){
            abundant.push_back(i);
        }
    }
    uint64_t t_sum = 0;
    size_t vsize = abundant.size(); // vector size
    int j,k;
    std::vector<bool> done(UBOUND+1, false);

    for( j = 0; i < vsize; ++j ){
        for( k = j; k < vsize; ++k){
            t_sum = abundant[j] + abundant[k];
            if( t_sum <= UBOUND ){
                done[t_sum] = true;
            } else {
                break;
            }
        }
    }

    uint64_t sum = 0;
    for( int i = 0; i <= UBOUND; ++i ){
        if( !done[i] ){
            sum += i;
        }
    }

    return sum;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~ Define main() ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int main(){
    // Create timing object
    Vandegriffe_Timer::TimeIt timer;

    std::cout.precision(100);

    long double i(1);
    std::cout << i/3 << std::endl;

    // uint64_t output;
    // timer.start();
    // output = run();
    // timer.stop();
    // std::cout << output << " in " << timer.lapse() << " seconds." << std::endl;    

    return 0;
}