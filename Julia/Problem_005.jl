function main()

    num::Int = prod([2,3,5,7,11,13,17,19]);
    found::Bool = false
    while !found
        num += 1
        for j ∈ 2:20
            if num%j != 0
                found = false
                break
            end
            found = true
        end
    end

    println(num)

end
main()