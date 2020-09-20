function main()

    fin::IOStream = open("Problem_008_input.txt","r");
    str::Array{SubString{String},1} = split(replace(read(fin, String), "\r\n"=>""), "");
    lst::Array{Int} = [parse(Int,x) for x in str];
    max::Int = 0
    for i ∈ 1:length(str)-12
        p = prod(lst[i:i+12])
        if p > max 
            max = p
        end
    end
    println(max)
end
main()
