using Primes

function main()
    max = 600851475143
    prime = 2
    max_prime = 0
    while prime <= sqrt(max)
        if mod(max,prime) == 0
            max_prime = prime
        end
        prime = nextprime(prime+1)
    end
    
    println(max_prime)

end

main()