function main()
    for a in 1:500, b in 1:500
        if a + b + sqrt(a^2 + b^2) == 1000
            c = sqrt(a^2 + b^2)
            println([a,b,c])
            println(a*b*c)
            break
        end
    end
end
@time main()