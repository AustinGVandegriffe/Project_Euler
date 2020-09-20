
function main()

    s::Int = 0
    for i = 1:1000-1
        if mod(i,3) == 0 || mod(i,5) == 0
            s += i
        end
    end

    println(s)

end

main()