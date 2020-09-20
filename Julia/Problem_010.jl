using Primes

function main()
    x::Int = x = 2
    sm::Int = 0
    while x < 2000000
        sm += x
        x = nextprime(x+1)
    end
    println(sm)
end
@time main()