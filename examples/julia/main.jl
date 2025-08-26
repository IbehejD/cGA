
include("../../julia_wrapper/algorithm_wrapper.jl")
using .AlgorithmWrapper

# Define a Julia fitness function matching the C signature: double (*Callback)(Gene, size_t)
function fitness_callback(gene::Ptr{UInt8}, n::Csize_t)::Cdouble
    # Convert the C array to a Julia array
    bits = unsafe_wrap(Array, gene, Int(n))
    # Example: count the number of 1s in the gene
    return sum(bits)
end

# Create a C-compatible function pointer
fitness_c = @cfunction(fitness_callback, Cdouble, (Ptr{UInt8}, Csize_t))

# Run the algorithm (example values)
using Base: Cint, Csize_t

generations = Cint(1000)
population_size = Csize_t(10)
gene_size = Csize_t(32)
AlgorithmWrapper.run(generations, gene_size, population_size, fitness_c)
