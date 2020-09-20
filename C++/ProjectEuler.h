// #define __VANDEGRIFFE_PRIME
// #define __VANDEGRIFFE_FIBONACCI


#ifdef __VANDEGRIFFE_PRIME
    #include <cmath>
    #include <vector>
#endif

#ifdef __VANDEGRIFFE_FIBONACCI
    #include "Eigen/unsupported/Eigen/MatrixFunctions"
#endif


namespace project_euler{

    #ifdef __VANDEGRIFFE_PRIME
        class Prime_Generator{
        private:
            uint64_t p;
            std::vector<uint64_t> history;
        public:
            Prime_Generator() noexcept:
                p(1), history(1,2)
            {}
            Prime_Generator( uint64_t ubound ) noexcept:
                p(1), history(1,2)
            {
                while( this->next() <= ubound )
                {}
            }
            uint64_t const& next() noexcept{
                bool prime = false;

                std::vector<uint64_t>::iterator itr,
                                                start( this->history.begin() ),
                                                end( this->history.end() );
                do{
                    this->p += 2;
                    prime = true;
                    for( itr = start; itr != end; ++itr ){
                        if( this->p % *itr == 0 ){
                            prime = false;
                            break;
                        }
                    }
                }while( !prime );
                this->history.push_back(this->p);
                return this->p;
            }
            uint64_t const& getCurrentPrime() const noexcept{
                return this->p;
            }
            std::vector<uint64_t> const& get_prime_list() const noexcept{
                return this->history;
            }
        };

        bool is_prime(uint64_t n) noexcept{
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
    #endif

    #ifdef __VANDEGRIFFE_FIBONACCI
        class Fibonacci_Generator{
        private:
            Eigen::MatrixXd __M;
        public:
            Fibonacci_Generator() :
                __M(Eigen::MatrixXd(2,2))
            {
                this->__M << 1,1,1,0;
            }
            int operator()(int& n) const{
                return this->__M.pow(n+1)(1,1);
            }
        };
    #endif
}