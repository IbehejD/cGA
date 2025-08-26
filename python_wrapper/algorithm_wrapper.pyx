from libc.stdlib cimport malloc, free
cdef extern from "cGA.c":
    ctypedef unsigned char Gene
    ctypedef double (*Callback)(Gene*, size_t)
    void run(int generations, size_t gene_size, size_t population_size, Callback fitness_function)

# Global variable to store the Python callback
cdef object py_fitness_callback = None

# Cython function adapting Python callback to C callback signature
cdef double c_fitness(unsigned char *x, size_t n) noexcept:
    cdef list bits = []
    cdef size_t i
    cdef unsigned char byte
    cdef int bit
    for i in range(n):
        byte = x[i // 8]
        bit = (byte >> (7 - (i % 8))) & 1
        bits.append(bit)
    bin_str = ''.join(str(bit) for bit in bits)
    try:
        return py_fitness_callback(bin_str)
    except Exception:
        import traceback
        traceback.print_exc()
        return float('-inf')



def call_algorithm(unsigned long generations, unsigned long gene_size, unsigned long population_size, function):
    global py_fitness_callback
    py_fitness_callback = function
    run(generations, gene_size, population_size, c_fitness)
