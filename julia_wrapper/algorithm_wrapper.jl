module AlgorithmWrapper

# Adjust the path to the shared library as needed
const libalgorithm = joinpath(@__DIR__, "..", "build", "libalgorithm.dylib")

# Define the type for the fitness callback
const FitnessCallback = Ptr{Cvoid}

# Wrap the 'run' function from the C library
function run(generations::Cint, gene_size::Csize_t, population_size::Csize_t, fitness_function::FitnessCallback)
    ccall((:run, libalgorithm), Cvoid,
        (Cint, Csize_t, Csize_t, FitnessCallback),
        generations, gene_size, population_size, fitness_function)
end

end # module
