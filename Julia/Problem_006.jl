function main()
    rng::UnitRange{Int} = 1:100
    println(sum(rng)^2 - sum(rng.^2))
end
main()