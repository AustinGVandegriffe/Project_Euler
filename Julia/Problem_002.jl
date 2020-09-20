

function fibonacci(max::Int,x::Int=1,y::Int=2,lst::Vector{Int}=Int[])
    if y > max
        return lst
    elseif mod(y,2) == 0
        append!(lst, y)
    end
    return fibonacci(max,y,x+y,lst)
end

function main()
    println(sum(fibonacci(4000000)))
end

main()