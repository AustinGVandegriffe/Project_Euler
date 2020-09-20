"""
    @file P01.py
    @author Austin Vandegriffe
    @date 2020-07-24
    @brief A few solutions to Project Euler question 1
    @pre N/A
    @style K&R, and "one true brace style" (OTBS), and '_' variable naming
/////////////////////////////////////////////////////////////////////
    @references
      ## [1] https://projecteuler.net/problem=1
"""

###############################################################################
##### How Python's 'range' works ##############################################
###############################################################################
def my_range(start, end, step):
    '''
        Python's 'range' is called a *generator* and is a function that returns
        a value but maintains it's state.
    '''
    while start < end:
        yield start
        start += step

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#~~~~~ Solutions to Problem 1 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
def implementation1(n:int):
    sm:int = 0

    x = 0
    while x < n:
        if x % 3 == 0:
            sm += x
        elif x % 5 == 0:
            sm += x

        x += 1

    print(sm)

def implementation2(n:int):
    sm:int = 0

    for x in range(0,n,1):
        if x % 3 == 0 or x % 5 == 0:
            sm += x

    print(sm)

def implementation3(n:int):
    sm:int = 0

    for x in range(0,n,1):
        if x % 3 == 0 | x % 5 == 0:
            sm += x

    print(sm)


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#~~~~~ Define main() ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
def main():
    n = 1000
    for f in [implementation1, implementation2, implementation3]:
        f(n)

if __name__ == "__main__":
    main()