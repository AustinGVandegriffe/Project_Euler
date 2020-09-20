using Primes

function factor_count(num::Int)::Int
    count = 0
    for i in 1:Int(floor(sqrt(num)))
        if mod(num,i) == 0
            count += 1
        end
    end
    return count
end

function main()
    n = 1
    f = x -> Int(x*(x+1)/2)
    threshhold_check = prod(1:500)
    while true
        if factor_count(f(n)) == 500
            println(f(n))
            break
        end
        n += 1
    end
end
@time main()