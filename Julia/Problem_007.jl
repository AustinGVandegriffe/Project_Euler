using Primes

function main()
    x = 1
    for _ in 1:10001
        x = nextprime(x+1)
    end
    print(x)
end
main()