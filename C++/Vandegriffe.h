#ifndef __VANDEGRIFFE_H
#define __VANDEGRIFFE_H

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~ Creates a Program Timer ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#ifdef __VANDEGRIFFE_TIMER
    #include <chrono>
    namespace Vandegriffe_Timer{

        using namespace std::chrono;
        class TimeIt{
            private:
                high_resolution_clock::time_point m_start;
                high_resolution_clock::time_point m_end;
            public:
                void Timeit(){}

                void start(){
                    this->m_start = high_resolution_clock::now();
                }
                void stop(){
                    this->m_end = high_resolution_clock::now();
                }
                double lapse(){
                    return duration_cast<duration<double>>(this->m_end - this->m_start).count();
                }
                void display() const {
                    std::cout << "\n\nFinished in: " << duration_cast<duration<double>>(this->m_end - this->m_start).count() << std::endl; 
                }
        };
    };
#endif

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~ Track Heap Allocated Memory ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// THE FOLLOWING IS *NOT* THREAD SAFE
#ifdef __VANDEGRIFFE_TRACK_MEMORY
    #include <cstdlib>
    struct Allocations{
        uint64_t allocated = 0;
        uint64_t deallocated = 0;
        uint64_t Current_Usage() { return this->allocated - this->deallocated; }
        ~Allocations(){
            std::cout   << "PROGRAM SUMMARY: " << std::endl
                        << "-Allocated:     " << this->allocated << std::endl
                        << "-Deallocated:   " << this->deallocated << std::endl
                        << "-Leaked Memory: " << this->Current_Usage();
        }
    } MEMORY_TRACKER;


    void* operator new(size_t size) {
        size_t* p = (size_t*)std::malloc(size + sizeof(size_t));
        p[0] = size;    
        // std::cout << "ALLOCATING: " << size << std::endl;       // store the size in the first few bytes
        MEMORY_TRACKER.allocated += size;
        return (void*)(&p[1]); // return the memory just after the size we stored
    }

    void operator delete(void *ptr) noexcept {
        size_t *p = (size_t*)ptr; // make the pointer the right type
        size_t size = p[-1];      // get the data we stored at the beginning of this block
        
        // std::cout << "DELETING: " << size << std::endl;
        MEMORY_TRACKER.deallocated += size;

        void *p2 = (void*)(&p[-1]); // get a pointer to the memory we originally really allocated
        std::free(p2);                   // free it
    }
#endif

#endif