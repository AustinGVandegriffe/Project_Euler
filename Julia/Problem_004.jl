function main()
    max::Int = 0
    prod::Int = 0
    for i = 100:999, j = 100:999
        prod = i*j
        if prod > max && string(prod) == reverse(string(prod))
            max = prod
        end
    end
    println(max)
end

main()